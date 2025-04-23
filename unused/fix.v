`include "defines.v"

module fix #(
    parameter USE_TIMEOUT = 1'b0,
    parameter TIMEOUT     = 16'h34BC          // 30 seconds for 450MHZ
)(
    input wire                          i_sys_clk,
    input wire                          i_rstn,
    input wire                          i_data_vld,
    input wire[`MII_DATA_WIDTH-1:0]     i_data,

    output reg                          o_connect_req,
    output reg                          o_data_vld,
    output reg[`MII_DATA_WIDTH-1:0]     o_data
);


    wire      beat_timeout;
    wire timer_set = USE_TIMEOUT && ;

    timer #( TIMEOUT
    )timer0(
        .i_sys_clk      (   i_sys_clk),
        .i_rstn         (      i_rstn),
        .i_cnt_en       (   timer_set),                          // timer start counting from 0 to CNT_NUM
        .o_timeout      (beat_timeout)  
    );

endmodule
