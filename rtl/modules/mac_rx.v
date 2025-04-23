`include "defines.v"


/*  mac_rx only received frame from eth_fifo queue only when arp_rx and ip_rx are all clear
*/
module mac_rx (
    input wire                                  i_sys_clk,
    input wire                                  i_rstn,
    input wire                                  i_len_fifo_empty,
    input wire                                  i_len_r_done,
    input wire                                  i_data_r_done,
    input wire[       `ETH_FRAME_WIdTH-1:0]     i_frame_len,
    input wire[       `FPGA_DATA_WIDTH-1:0]     i_frame_data, 

    input wire                                  i_arp_rx_busy,
    input wire                                  i_ip_rx_busy,

    input wire                                  i_ip_rx_drop,

    output reg                                  o_len_fifo_r_en,
    output reg[ $clog2(`LEN_FIFO_DEPTH)-1:0]    o_len_fifo_r_line,

    output reg                                  o_data_fifo_r_en,
    output reg[$clog2(`DATA_FIFO_DEPTH)-1:0]    o_data_fifo_r_line,
    output wire                                 o_data_fifo_r_stop,

    output reg[                        15:0]    o_eth_type,   
    output reg                                  o_bad_packet_en,
    output reg                                  o_bad_packet,
    output reg                                  o_new_packet_en,
    output reg[        `FPGA_DATA_WIDTH-1:0]    o_packet_data
);

    localparam IDLE_STAGE         = 2'b00;
    localparam LEN_STAGE          = 2'b01;
    localparam PARSE_STAGE        = 2'b10;
    localparam CHECK_STAGE        = 2'b11;

    reg[                         1:0]    CUR_STAGE;
    reg[                         1:0]    NXT_STAGE;

    reg[$clog2(`DATA_FIFO_DEPTH)-1:0]    frame_recieved_cnt;

    reg[                        47:0]    dst_mac_latch;
    reg[                        15:0]    eth_type_latch;
    reg                                  eth_parse_done;
    reg[        `ETH_FRAME_WIdTH-1:0]    frame_len_latch;
    //reg[                        31:0]    checksum_latch;
    
    wire                                 ip_rx_clear      = ~(i_arp_rx_busy || i_ip_rx_busy);



    // ==============================================================================
    // Frame data reading logic FSM

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            CUR_STAGE <= IDLE_STAGE;
        end 
        else begin 
            CUR_STAGE <= NXT_STAGE;
        end
    end 

    always @(posedge i_sys_clk or negedge i_rstn) begin
        if (~i_rstn || i_data_r_done || i_ip_rx_drop) begin 
            frame_len_latch         <= 0;
            frame_recieved_cnt      <= 0;
        end 
        else if (CUR_STAGE == LEN_STAGE) begin 
            frame_len_latch     <= i_frame_len;
        end 
        else if (CUR_STAGE == PARSE_STAGE) begin 
            frame_recieved_cnt  <= frame_recieved_cnt + 1;
        end 
    end 

    always @(*) begin
        if (~i_rstn) begin 
            o_len_fifo_r_en         = 0;
            o_len_fifo_r_line       = 0;
            o_data_fifo_r_en        = 0;
            o_data_fifo_r_line      = 0;
            o_data_fifo_r_stop      = 0;
        end 
        else begin 
            case (CUR_STAGE)
                    IDLE_STAGE: begin 
                        if ((i_len_fifo_empty == 1'b0) && ip_rx_clear) begin 
                            NXT_STAGE               = LEN_STAGE;
                            o_len_fifo_r_en         = 1;
                            o_len_fifo_r_line       = 1;
                            o_data_fifo_r_en        = 0;
                            o_data_fifo_r_line      = 0;
                            o_data_fifo_r_stop      = 0;
                        end
                        else begin 
                            NXT_STAGE               = CUR_STAGE;
                            o_len_fifo_r_en         = 0;
                            o_len_fifo_r_line       = 0;
                            o_data_fifo_r_en        = 0;
                            o_data_fifo_r_line      = 0;
                        end   
                    end
                    LEN_STAGE: begin 
                            NXT_STAGE           = PARSE_STAGE;
                            o_len_fifo_r_en     = 0;
                            o_len_fifo_r_line   = 0;
                            o_data_fifo_r_en    = 1;
                            o_data_fifo_r_line  = i_frame_len;
                        end 
                    PARSE_STAGE: begin 
                        if (i_data_r_done) begin 
                            NXT_STAGE           = CHECK_STAGE;
                            o_len_fifo_r_en     = 0;
                            o_len_fifo_r_line   = 0;
                            o_data_fifo_r_en    = 0;
                            o_data_fifo_r_line  = 0;
                        end 
                        else if (i_ip_rx_drop) begin 
                            NXT_STAGE           = IDLE_STAGE;
                            o_len_fifo_r_en     = 0;
                            o_data_fifo_r_en    = 1;
                            o_data_fifo_r_stop  = 1;
                        end
                        else begin 
                            NXT_STAGE           = CUR_STAGE;
                            o_len_fifo_r_en     = 0;
                            o_len_fifo_r_line   = 0;
                            o_data_fifo_r_en    = 1;
                        end                    
                    end 
                    CHECK_STAGE: begin 
                        NXT_STAGE               = IDLE_STAGE;
                        o_len_fifo_r_en         = 0;
                        o_len_fifo_r_line       = 0;
                        o_data_fifo_r_en        = 0;
                        o_data_fifo_r_line      = 0;
                    end
                    default : begin 
                        NXT_STAGE               = IDLE_STAGE;
                        o_len_fifo_r_en         = 0;
                        o_len_fifo_r_line       = 0;
                        o_data_fifo_r_en        = 0;
                        o_data_fifo_r_line      = 0;
                    end 
            endcase
        end 
    end 


    // ==============================================================================
    // Parse data link layer
    wire my_frame = (dst_mac_latch == `FPGA_MAC) || (dst_mac_latch == `BROADCAST);

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || (CUR_STAGE == IDLE_STAGE)) begin 
            dst_mac_latch         <= 48'b0;
            eth_type_latch        <= 16'b0;
            eth_parse_done        <= 1'b0;
            o_new_packet_en       <= 1'b0;
            o_packet_data         <= 8'b0;
            o_bad_packet_en       <= 1'b0;
            o_bad_packet          <= 1'b0;
            o_eth_type            <= 16'b0;
        end 
        else if (CUR_STAGE == PARSE_STAGE) begin
            if (eth_parse_done && my_frame) begin 
                if (~i_ip_rx_drop  && (frame_recieved_cnt < (frame_len_latch - 4))) begin 
                    o_new_packet_en <= 1'b1;
                    o_packet_data   <= i_frame_data;
                    o_eth_type      <= eth_type_latch;
                end 
                else begin 
                    o_new_packet_en <= 1'b0;
                    o_packet_data   <= 8'b0;
                    o_eth_type      <= 16'b0;
                end
            end 
            case (frame_recieved_cnt)
                14'd0, 14'd1, 14'd2, 14'd3, 14'd4, 14'd5, 14'd6, 14'd7: begin 
                end 
                14'd8, 14'd9, 14'd10, 14'd11, 14'd12, 14'd13:  begin 
                    dst_mac_latch             <= (dst_mac_latch << 8) | {40'b0, i_frame_data};
                end 
                14'd20: begin 
                    eth_type_latch            <= {8'b0, i_frame_data};
                end 
                14'd21: begin 
                    eth_type_latch            <= (eth_type_latch << 8) | {8'b0, i_frame_data};
                    eth_parse_done            <= 1'b1;
                end
                default: begin 
                end
            endcase  
        end
        else if (CUR_STAGE == CHECK_STAGE) begin 
            o_bad_packet_en <= 1'b1;
            o_bad_packet    <= fcs_comp != 32'b0;
            o_eth_type      <= eth_type_latch;
        end
    end 

    // ==============================================================================
    // CRC32
    // G(x)= x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x^1 + 1

    wire         fcs_en         = (CUR_STAGE == PARSE_STAGE) && (frame_recieved_cnt > 14'd7);
    wire         fcs_check      = CUR_STAGE == CHECK_STAGE;
    wire         fcs_comp_done;
    wire[31:0]   fcs_comp;
    wire[ 7:0]   fcs_data       = {i_frame_data[0], i_frame_data[1], i_frame_data[2], i_frame_data[3],
                                   i_frame_data[4], i_frame_data[5], i_frame_data[6], i_frame_data[7]};

    crc32 crc32_0(
        .i_sys_clk      (     i_sys_clk),
        .i_rstn         (        i_rstn),
        .i_crc_en       (        fcs_en),
        .i_data         (      fcs_data),
        .i_crc_done     (     fcs_check),
        .o_fcs          (      fcs_comp)
    );

    
endmodule 