`include "defines.v"

/******************************************************************************************************************************************************************
$Description :  There would be more than one tcp_client_tx modules, a tcp socket will be served by a pair of tcp_client and fix module.
******************************************************************************************************************************************************************/


module tcp_client_tx #(
    parameter TIMEOUT_ACK = 32'd225_000;      // 500μs @ 450MHz
    parameter TARGET_IP   = 32'hEA006464,
    parameter TARGET_PORT = 16'h2714,         // port 10004
    parameter FPGA_IP     = 32'hC0A80100,
    parameter FPGA_PORT   = 16'h5487
)(
    input wire i_sys_clk,
    input wire i_rstn,

    // from IP layer
    input wire                          i_segment_vld,
    input wire[`MII_DATA_WIDTH-1:0]     i_segment_data,
    input wire   i_trans_grant,         // permit to transmit to ip layer

    // from tcp_client_rx
    input wire                          i_handshake,

    // from application layer
    input wire                          i_connect_req,
    input wire                          i_data_vld,
    input wire[`MII_DATA_WIDTH-1:0]     i_data,
    
    // to IP layer
    output reg                          o_trans_req,
    output reg[`MII_DATA_WIDTH-1:0]     o_segment_data,

    // to application layer
    output reg                          o_data_vld,
    output reg[`MII_DATA_WIDTH-1:0]     o_data,
    output reg                          o_connect_done          // send to application layer to inform socket channel been established

);
    
    localparam CONCT_STAGE =;
    localparam IDLE_STAGE  =;
    localparam REQ_STAGE   =;
    localparam TRANS_STAGE =;
    localparam WAIT_STAGE  =;                                   // waiting for window 


    reg[2:0]    CUR_STAGE;
    reg[2:0]    NXT_STAGE;

    reg[1:0]    handshake_cnt;
    reg         seq_num_latch;
    reg         ack_num;

    reg[4:0]    try_connect_cnt;                                // try 32 times
    reg[1:0]    fin_process;                                    // if we receive flag = fin, we need to 
                                                                // 1. send ack frame
                                                                // 2. send 
    // ==============================================================================
    // TCP client FSM

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            CUR_STAGE <= CONCT_STAGE;
        end
        else begin 
            CUR_STAGE <= NXT_STAGE;
        end 
    end 

    always @(*) begin 
        if (~i_rstn || (i_connect_req)) begin 
            NXT_STAGE = CONCT_STAGE;
        end 
        else begin 
            case (CUR_STAGE) 
                CONCT_STAGE: begin 
                    if (handshake_cnt)
                end 
                default: begin 
                end 
            endcase
        end 
    end 
    // ==============================================================================
    // Three way handshake
    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || (i_connect_req)) begin 
            handshake_cnt <= 2'b10;
            seq_num_latch <= 32'h87;
            o_trans_req   <= 1'b1;
        end 
        else if ()
    end 
    timer #(
        
    )hanshake_timer(

    )

endmodule