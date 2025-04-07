`include "defines.v"


/*  mac_rx only received frame from eth_fifo queue only when arp_rx and ip_rx are all clear
*/
module mac_rx #(
    parameter ROUTER_MAC = 48'h107C4FA2A003,
    parameter FPGA_MAC   = 48'h00183E043329
)(
    input wire                                  i_sys_clk,
    input wire                                  i_rstn,
    input wire                                  i_len_fifo_empty,
    input wire                                  i_len_r_done,
    input wire                                  i_data_r_done,
    input wire[       `ETH_FRAME_WIdTH-1:0]     i_frame_len,
    input wire[        `MII_DATA_WIDTH-1:0]     i_frame_data, 

    input wire                                  i_arp_rx_busy,
    input wire                                  i_ip_rx_busy,

    input wire                                  i_ip_rx_drop,

    //input wire[$clog2(`DATA_FIFO_DEPTH)-1:0]    i_payload_len,    // from ip parser

    output reg                                  o_len_fifo_r_en,
    output reg[$clog2(`LEN_FIFO_DEPTH)-1:0]     o_len_fifo_r_line,

    output reg                                  o_data_fifo_r_en,
    output reg[$clog2(`DATA_FIFO_DEPTH)-1:0]    o_data_fifo_r_line,

    output reg[                        15:0]    o_eth_type,   
    output reg                                  o_bad_frame_en,
    output reg                                  o_bad_frame,
    output reg                                  o_new_frame_en,
    output reg[         `MII_DATA_WIDTH-1:0]    o_frame_data
);

    localparam IDLE_STAGE         = 2'b00;
    localparam LEN_STAGE          = 2'b01;
    localparam PARSE_STAGE        = 2'b10;
    localparam CHECK_STAGE        = 2'b11;

    reg[                         1:0]    CUR_STAGE;
    reg[                         1:0]    NXT_STAGE;

    reg[$clog2(`DATA_FIFO_DEPTH)-1:0]    frame_recieved_cnt;

    reg[                        47:0]    src_mac_latch;
    reg[                        47:0]    dst_mac_latch;
    reg[                        15:0]    eth_type_latch;
    reg                                  eth_parse_done;
    reg[        `ETH_FRAME_WIdTH-1:0]    frame_len_latch;
    reg[                        31:0]    checksum_latch;
    
    wire[       `ETH_FRAME_WIdTH-1:0]    data_trans_times = frame_len_latch << 2;
    wire                                 ip_rx_clear      = ~(i_arp_rx_busy || i_ip_rx_busy);



    // ==============================================================================
    // Frame data reading logic

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            CUR_STAGE <= IDLE_STAGE;
        end 
        else begin 
            CUR_STAGE <= NXT_STAGE;
        end
    end 

    always @(posedge i_sys_clk or negedge i_rstn) begin
        if (~i_rstn) begin 
            NXT_STAGE               <= IDLE_STAGE;
            o_len_fifo_r_en         <= 0;
            o_data_fifo_r_en        <= 0;
            o_data_fifo_r_line      <= 0;
            frame_recieved_cnt      <= 0;
        end 
        else begin 
            case (CUR_STAGE)
                    IDLE_STAGE: begin 
                        if ((i_len_fifo_empty == 1'b0) && ip_rx_clear) begin 
                            NXT_STAGE               <= LEN_STAGE;
                            o_len_fifo_r_en         <= 1;
                            o_len_fifo_r_line       <= 1;
                            o_data_fifo_r_en        <= 0;
                            o_data_fifo_r_line      <= 0;
                            frame_len_latch         <= 0;
                        end
                        else begin 
                            NXT_STAGE               <= CUR_STAGE;
                            o_len_fifo_r_en         <= 0;
                            o_len_fifo_r_line       <= 0;
                            o_data_fifo_r_en        <= 0;
                            o_data_fifo_r_line      <= 0;
                            frame_len_latch         <= 0;
                            frame_recieved_cnt      <= 0;
                        end   
                    end
                    LEN_STAGE: begin 
                        // if (i_len_r_done) begin                     
                            NXT_STAGE           <= PARSE_STAGE;
                            o_len_fifo_r_en     <= 0;
                            o_len_fifo_r_line   <= 0;
                            o_data_fifo_r_en    <= 1;
                            o_data_fifo_r_line  <= i_frame_len;
                            frame_len_latch     <= i_frame_len;
                        // end 
                        // else begin 
                        //     NXT_STAGE               <= CUR_STAGE;
                        //     o_len_fifo_r_en         <= 1;
                        //     o_len_fifo_r_line       <= 1;
                        //     o_data_fifo_r_en        <= 0;
                        //     o_data_fifo_r_line      <= 0;
                        //     frame_len_latch         <= 0;
                        // end
                    end 
                    PARSE_STAGE: begin 
                        if (i_data_r_done) begin 
                            NXT_STAGE           <= CHECK_STAGE;
                            frame_recieved_cnt  <= frame_recieved_cnt + 1;
                            o_len_fifo_r_en     <= 0;
                            o_len_fifo_r_line   <= 0;
                            o_data_fifo_r_en    <= 0;
                            o_data_fifo_r_line  <= 0;
                        end 
                        else begin 
                            NXT_STAGE           <= CUR_STAGE;
                            frame_recieved_cnt  <= frame_recieved_cnt + 1;
                            o_len_fifo_r_en     <= 0;
                            o_len_fifo_r_line   <= 0;
                            o_data_fifo_r_en    <= 1;
                            o_data_fifo_r_line  <= frame_len_latch;
                            frame_len_latch     <= frame_len_latch;
                        end                    
                    end 
                    CHECK_STAGE: begin 
                        NXT_STAGE               <= IDLE_STAGE;
                        o_len_fifo_r_en         <= 0;
                        o_len_fifo_r_line       <= 0;
                        o_data_fifo_r_en        <= 0;
                        o_data_fifo_r_line      <= 0;
                    end
                    default : begin 
                        NXT_STAGE               <= IDLE_STAGE;
                        o_len_fifo_r_en         <= 0;
                        o_len_fifo_r_line       <= 0;
                        o_data_fifo_r_en        <= 0;
                        o_data_fifo_r_line      <= 0;
                    end 
            endcase
        end 
    end 


    // ==============================================================================
    // Parse data link layer

    wire my_frame = eth_parse_done && (src_mac_latch == ROUTER_MAC) && ((dst_mac_latch == FPGA_MAC) || (dst_mac_latch == `BROADCAST));

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || (CUR_STAGE == IDLE_STAGE)) begin 
            src_mac_latch         <= 48'd0;
            dst_mac_latch         <= 48'd0;
            eth_type_latch        <= 16'd0;
            eth_parse_done        <= 1'b0;
            o_frame_data          <= 4'b0;
        end 
        else if (CUR_STAGE == PARSE_STAGE) begin
            case (frame_recieved_cnt)
                14'd0, 14'd1, 14'd2, 14'd3, 14'd4, 14'd5, 14'd6, 14'd7, 14'd8, 
                14'd9, 14'd10, 14'd11, 14'd12, 14'd13, 14'd14, 14'd15: begin 
                end 
                14'd16, 14'd17, 14'd18, 14'd19, 14'd20, 14'd21, 
                14'd22, 14'd23, 14'd24, 14'd25, 14'd26, 14'd27:  begin 
                    dst_mac_latch             <= (dst_mac_latch << 4) | {44'd0, i_frame_data};
                end 
                14'd28, 14'd29, 14'd30, 14'd31, 14'd32, 14'd33, 
                14'd34, 14'd35, 14'd36, 14'd37, 14'd38, 14'd39:  begin 
                    src_mac_latch             <= (src_mac_latch << 4) | {44'd0, i_frame_data};
                end 
                14'd40, 14'd41, 14'd42: begin 
                    eth_type_latch            <= (eth_type_latch << 4) | {12'd0, i_frame_data};
                end 
                14'd43: begin 
                    eth_type_latch            <= (eth_type_latch << 4) | {12'd0, i_frame_data};
                    eth_parse_done            <= 1;
                end
                default: begin 
                    if ((frame_recieved_cnt <= frame_len_latch) && (frame_recieved_cnt > (frame_len_latch - 8))) begin  // checksum bit
                        checksum_latch <=  (checksum_latch << 4) | {28'd0, i_frame_data};
                    end
                    else if (eth_parse_done && my_frame && ~(i_ip_rx_drop)) begin 
                        o_new_frame_en <= 1;
                        o_frame_data   <= i_frame_data;
                        o_eth_type     <= eth_type_latch;
                    end 
                end
            endcase  
        end
    end 

    // ==============================================================================
    // CRC32
    // G(x)= x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x^1 + 1

    wire crc_data_en    = (CUR_STAGE == PARSE_STAGE) && (frame_len_latch <= data_trans_times);
    wire fcs_comp_clear = CUR_STAGE == IDLE_STAGE;
    wire fcs_check      = CUR_STAGE == CHECK_STAGE;
    wire fcs_comp_done;
    wire[31:0]  fcs_comp;

    reg[31:0]   fcs_comp_latch;

    crc32 crc32_0(
        .i_sys_clk      (    i_sys_clk),
        .i_rstn         (       i_rstn),
        .i_crc_en       (  crc_data_en),
        .i_crc          ( i_frame_data),
        .o_fcs_valid    (fcs_comp_done),
        .o_fcs          (     fcs_comp)
    );

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (i_rstn || fcs_comp_clear) begin 
            fcs_comp_latch <= 0;
        end
        else if (fcs_comp_done) begin 
            fcs_comp_latch <= fcs_comp;
        end  
    end

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            o_bad_frame <= 0;
        end 
        else if (fcs_check) begin 
            o_bad_frame <= fcs_comp_latch == checksum_latch;
        end
    end 

    
endmodule 