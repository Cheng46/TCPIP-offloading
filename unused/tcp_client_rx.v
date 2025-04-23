`include "defines.v"

/******************************************************************************************************************************************************************
$Description :  There would be more than one tcp_client_tx modules, a tcp socket will be served by a pair of tcp_client and fix module.
******************************************************************************************************************************************************************/


module tcp_client_rx #(
    parameter FPGA_IP     = 32'hC0A80100,
    parameter FPGA_PORT   = 16'h5487
    parameter TWSE_IP     = 32'hEA006464,
    parameter TWSE_PORT   = 16'h2714,         // tcp port 10004
)(
    input wire                          i_sys_clk,
    input wire                          i_rstn,

    // from IP layer
    input wire                          i_segment_vld,
    input wire                          i_drop_segment,
    input wire[               31:0]     i_src_ip,
    input wire[               15:0]     i_segment_len_b,
    input wire[`MII_DATA_WIDTH-1:0]     i_segment_data,
    
    // to application layer
    output reg                          o_data_vld,
    output reg[`MII_DATA_WIDTH-1:0]     o_data,
    output reg                          o_ckecksum_done,
    output reg                          o_bad_data,
    output reg                          o_disconct,
    output wire                         o_drop_data,

    // to tcp_client_tx
    output reg                          o_trans_vld,   
    output reg[               31:0]     o_ack_num,
    output reg[               31:0]     o_seq_num,
    output reg[               31:0]     o_window,
    output reg                          o_is_conct,
    output reg                          o_is_finish,
    output reg                          o_is_reset,

    // to IP layer
    output wire                         o_drop_segment
);
    
  // =================================================================================================
  // TCPm header format
  //
  //	0          4          8      10              16                     24                    31
  //	--------------------------------------------------------------------------------------------
  //	|               Source Port                  |               Destination Port              |
  //	|                                            |                                             |
  //	--------------------------------------------------------------------------------------------
  //	|                                    Sequence Number                                       |
  //	|                                                                                          |
  //	--------------------------------------------------------------------------------------------
  //	|   Data   |      Reserved    |     Flag     |                   Window                    |
  //	|  offset  |         (6)      |              |                                             |
  //	--------------------------------------------------------------------------------------------
  //	|                Checksum                    |                  Urgent                     |
  //	|                                            |                  Pointer                    |
  //	--------------------------------------------------------------------------------------------
  //	|                          Options (if any - ignored)               |       Padding        |
  //	|                                                                   |      (if needed)     |
  //	--------------------------------------------------------------------------------------------
  //	|                                          Data                                            |
  //	|                                                                                          |
  //	--------------------------------------------------------------------------------------------
    
    localparam IDLE_STAGE   = 2'b00;
    localparam HEADER_STAGE = 2'b01;
    localparam TRANS_STAGE  = 2'b10;


    reg[1:0]    CUR_STAGE;
    reg[1:0]    NXT_STAGE;

    reg[11:0]   rx_cnt;
    reg[15:0]   src_port_latch;
    reg[15:0]   dst_port_latch;
    reg[31:0]   seq_num_latch;
    reg[31:0]   ack_num_latch;
    reg[ 3:0]   data_offset_latch;
    reg[ 5:0]   flag_latch;
    reg[15:0]   window_latch;
    reg[15:0]   checksum_latch;
    
    wire[11:0]  header_times  = {8'b0, data_offset_latch} << 3 - 12'b1; // how many times do we need to count to skip tcp header
                                                                        // the number in data offset is in 4 bytes (1 means 4 bytes)
                                                                        // we need to times 4 and times 8 (byte=>bit), and divide by 4 (we send 4bit in one transmsiion)
                                                                        // << 2, << 3, >> 2
    
    wire        check_failed;

    // ==============================================================================
    // IP header flag format
    //  bit   flag     description
    // ------------------------------------------------------------------------------
    //  5     URG      Urgent
    //  4     ACK      Acknowledgment	
    //  3     PSH      Push
    //  2     RST      Reset
    //  1     SYN      Synchronize
    //  0     FIN      Finish
    // ------------------------------------------------------------------------------
    
    wire is_conct   = flag_latch == 6'b010010;
    wire is_finish  = flag_latch == 6'b000001;
    wire is_reset   = flag_latch == 6'b000100;

    // ==============================================================================
    // TCP client FSM

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            CUR_STAGE <= IDLE_STAGE;
        end
        else begin 
            CUR_STAGE <= NXT_STAGE;
        end 
    end 

    always @(*) begin 
        if (~i_rstn) begin 
            NXT_STAGE = IDLE_STAGE;
        end 
        else begin 
            case (CUR_STAGE) 
                IDLE_STAGE: begin
                    if (i_segment_vld) begin  
                        NXT_STAGE = HEADER_STAGE;
                    end 
                    else begin 
                        NXT_STAGE = IDLE_STAGE;
                    end
                end 
                HEADER_STAGE: begin 
                    if (rx_cnt == header_times) begin 
                        NXT_STAGE = TRANS_STAGE;
                    end 
                    else begin 
                        NXT_STAGE = HEADER_STAGE;
                    end
                end 
                TRANS_STAGE: begin 
                    if (segment_done) begin 
                        NXT_STAGE = IDLE_STAGE;
                    end 
                    else begin 
                        NXT_STAGE = TRANS_STAGE;
                    end 
                end
                default: begin 
                end 
            endcase
        end 
    end 


    // ==============================================================================
    // Parse segment and send it to next layer 

    wire   is_TWSE        = (i_src_ip == TWSE_IP) && (src_ip_latch == TWSE_PORT) && (dst_port_latch == FPGA_PORT);
    wire   segment_done   = prev_segment_vld && ~i_segment_vld;
    assign o_drop_segment = (rx_cnt > 12'd8) && ~is_TWSE;               // to ip_rx, which means this is not our segment
    assign o_drop_data    = check_failed;                               // to fix, which means we sent wrong data

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || ~i_segment_vld) begin 
            src_port_latch    <= 16'b0;
            dst_port_latch    <= 16'b0;
            seq_num_latch     <= 32'b0;
            ack_num_latch     <= 32'b0;
            data_offset_latch <= 4'b0;
            flag_latch        <= 6'b0;
            window_latch      <= 16'b0;
            o_data_vld        <= 1'b0;
            o_data            <= 4'b0;
            rx_cnt            <= 12'b0;
        end 
        else begin 
            rx_cnt <= rx_cnt + 12'b1;
            if (rx_cnt > header_times) begin 
                o_data_vld <= 1'b1;
                o_data     <= i_segment_data;
            end
            case (rx_cnt) 
                12'd0, 12'd1, 12'd2, 12'd3: begin 
                    src_port_latch <= (src_port_latch << 4) | {12'b0, i_segment_data};
                end
                12'd4, 12'd5, 12'd6, 12'd7: begin 
                    dst_port_latch <= (dst_port_latch << 4) | {12'b0, i_segment_data};
                end 
                12'd8, 12'd9, 12'd10, 12'd11, 12'd12, 12'd13, 12'd14, 12'd15 : begin 
                    seq_num_latch <= (seq_num_latch << 4) | {28'b0, i_segment_data};
                end
                12'd16, 12'd17, 12'd18, 12'd19, 12'd20, 12'd21, 12'd22, 12'd23 : begin 
                    ack_num_latch <= (ack_num_latch << 4) | {28'b0, i_segment_data};
                end
                12'd24: begin 
                    data_offset_latch <= i_segment_data;
                end 
                12'd26: begin
                    flag_latch <= {i_segment_data[1:0], 4'b0};
                end 
                12'd27: begin 
                    flag_latch <= flag_latch | {2'b0, i_segment_data};
                end   
                12'd28, 12'd29, 12'd30, 12'd31: begin 
                    window_latch <= (window_latch << 4) | {12'b0, i_segment_data};
                end 
                12'd32, 12'd33, 12'd34, 12'd35: begin 
                    checksum_latch <= (checksum_latch << 4) | {12'b0, i_segment_data};
                end
                default: begin 
                end 
            endcase
        end
    end 


    always @(*) begin
        if (~i_rstn || (CUR_STAGE == IDLE_STAGE)) begin 
            o_trans_vld = 1'b0;
            o_seq_num   = 32'b0;
            o_ack_num   = 32'b0;
            o_window    = 16'b0;
            o_is_conct  = 1'b0;
            o_is_finish = 1'b0;
            o_is_reset  = 1'b0;
        end 
        else if ((CUR_STAGE == TRANS_STAGE) && segment_done) begin 
            o_trans_vld = 1'b1;
            o_seq_num   = seq_num_latch;
            o_ack_num   = ack_num_latch;
            o_window    = window_latch;
            o_is_conct  = is_conct; 
            o_is_finish = is_finish;
            o_is_reset  = is_reset;
        end 
    end

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            prev_segment_vld <= 1'b0;
        end 
        else begin 
            prev_segment_vld <= i_segment_vld;
        end 
    end

    // ==============================================================================
    // TCP checksum

    reg[15:0] checksum_temp;
    reg[15:0] checksum_sum;
    reg[ 1:0] checksum_cnt;
    reg[16:0] checksum_extend;

    reg[15:0] p_checksum_sum;
    reg[16:0] p_checksum_extend;


    wire check_failed = segment_done && ((checksum_extend[15:0] + checksum_latch) != 16'hFFFF);

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || ~i_segment_vld) begin 
            checksum_extend <= 17'b0;
            checksum_temp   <= 16'b0;
            checksum_sum    <= 16'b0;
            checksum_cnt    <= 2'b0;
        end 
        else if (rx_cnt == 12'd24) begin 
            checksum_extend <= {1'b0, checksum_sum} + {1'b0, p_checksum_sum};
        end
        else if (rx_cnt == 12'd25) begin 
            checksum_sum    <= checksum_sum + checksum_extend[16];
            checksum_extend <= 17'b0;
        end 
        else if ((rx_cnt < 12'd24) || (rx_cnt > 12'd27)) begin 
            checksum_cnt <= checksum_cnt + 2'b1;
            if (checksum_cnt == 2'b11) begin 
                checksum_extend <= {1'b0, checksum_sum} + {1'b0, checksum_temp[11:0], i_segment_data};
            end 
            else if (checksum_cnt == 2'b00) begin 
                checksum_temp   <= 16'b0 | {12'b0, i_segment_data};
                checksum_extend <= 17'b0;
                if (checksum_extend[16]) begin 
                    checksum_sum <= checksum_extend[15:0] + 16'b1;
                end 
                else begin 
                    checksum_sum <= checksum_extend[15:0];
                end
            end 
            else begin 
                checksum_temp <= (checksum_temp << 4) | {12'b0, i_segment_data};
            end 
        end
    end 

    // psuedo header checksum
    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || ~i_segment_vld) begin 
            p_checksum_extend <= 17'b0;
            p_checksum_sum    <= 16'b0;
        end 
        else if (rx_cnt == 12'd0) begin 
            p_checksum_extend <= {1'b0, i_src_ip[31:16]} + {1'b0, i_src_ip[15:0]};
        end 
        else if (rx_cnt == 12'd1) begin 
            p_checksum_extend <= p_checksum_extend + {1'b0, FPGA_IP[31:16]};
        end 
        else if (rx_cnt == 12'd2) begin 
            p_checksum_extend <= p_checksum_extend + {1'b0, FPGA_IP[15:0]};
        end 
        else if (rx_cnt == 12'd3) begin 
            p_checksum_extend <= p_checksum_extend + 17'h06;
        end 
        else if (rx_cnt == 12'd4) begin 
            p_checksum_extend <= p_checksum_extend + i_segment_len_b;
        end 
        else if (rx_cnt == 12'd5) begin 
            p_checksum_sum    <= p_checksum_extend[15:0] + {15'b0, p_checksum_extend[16]};
        end 
    end 
endmodule