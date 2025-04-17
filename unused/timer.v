

module timer#(
    parameter CNT_NUM   = 16'h34BC                  // 30 seconds clocks for 450HZ clock rate
)(
    input wire  i_sys_clk,
    input wire  i_rstn,
    input wire  i_cnt_en,                           // timer start counting from 0 to CNT_NUM
    output wire o_timeout   
);
    reg[36:0]    cnt;
    reg          timer_busy;

    assign o_timeout = (cnt == (CNT_NUM - 1)) && timer_busy;

    // ==============================================================================
    // timer counting signal
    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || ~timer_busy) begin 
            cnt        <= 37'b0;
        end  
        else if (i_cnt_en) begin 
            cnt        <= 37'b1;
            timer_busy <= 1'b1;
        end
        else if (timer_busy) begin 
            if (cnt == (CNT_NUM - 1)) begin 
                timer_busy <= 1'b0;
            end
            else begin 
                cnt  <= cnt + 37'b1;
            end
        end
    end 


endmodule