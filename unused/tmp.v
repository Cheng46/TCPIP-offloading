    wire check_failed = (rx_cnt > 14'd39) && ((checksum_extend[15:0] + {15'b0, checksum_extend[16]})!= 16'hFFFF);

    always @(posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn || ~i_new_packet) begin 
            checksum_extend <= 17'b0;
            checksum_temp   <= 16'b0;
            checksum_sum    <= 16'b0;
            checksum_cnt    <= 2'b0;
        end 
        else if (rx_cnt <= 14'd39) begin 
            checksum_cnt <= checksum_cnt + 2'b1;
            if (checksum_cnt == 2'b11) begin 
                checksum_extend <= {1'b0, checksum_sum} + {1'b0, checksum_temp[11:0], i_ip_data};
            end 
            else if (checksum_cnt == 2'b00) begin 
                checksum_temp   <= 16'b0 | {12'b0, i_ip_data};
                checksum_extend <= 17'b0;
                if (checksum_extend[16]) begin 
                    checksum_sum <= checksum_extend[15:0] + 16'b1;
                end 
                else begin                                              // checksum_cnt == 2'b01 || checksum_cnt == 2'b10
                    checksum_sum <= checksum_extend[15:0];
                end
            end 
            else begin 
                checksum_temp <= (checksum_temp << 4) | {12'b0, i_ip_data};
            end 
        end
    end 
