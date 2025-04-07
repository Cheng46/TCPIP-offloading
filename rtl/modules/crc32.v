`include "defines.v"

module crc32(
    input wire                          i_sys_clk,
    input wire                          i_rstn,

    input wire                          i_crc_en,
    input wire[`MII_DATA_WIDTH-1:0]     i_crc,

    output reg                          o_fcs_valid,
    output reg[               31:0]     o_fcs
);

    reg [31:0] lfsr_q, lfsr_c;
    reg        crc_en_prev;

    wire       crc_done;

    assign crc_done   =  ~i_crc_en && crc_en_prev;
    assign o_fcs      = (crc_done)? lfsr_q : 32'b0;

    always @(*) begin
        lfsr_c[ 0] = lfsr_q[24] ^ lfsr_q[30] ^ i_crc[0]; 
        lfsr_c[ 1] = lfsr_q[24] ^ lfsr_q[25] ^ lfsr_q[30] ^ lfsr_q[31] ^ i_crc[0] ^ i_crc[1];  
        lfsr_c[ 2] = lfsr_q[24] ^ lfsr_q[25] ^ lfsr_q[26] ^ lfsr_q[30] ^ lfsr_q[31] ^ i_crc[0] ^ i_crc[1] ^ i_crc[2];  
        lfsr_c[ 3] = lfsr_q[25] ^ lfsr_q[26] ^ lfsr_q[27] ^ lfsr_q[31] ^ i_crc[1] ^ i_crc[2] ^ i_crc[3]; 
        lfsr_c[ 4] = lfsr_q[24] ^ lfsr_q[26] ^ lfsr_q[27] ^ lfsr_q[28] ^ lfsr_q[30] ^ i_crc[0] ^ i_crc[2] ^ i_crc[3];
        lfsr_c[ 5] = lfsr_q[24] ^ lfsr_q[25] ^ lfsr_q[27] ^ lfsr_q[28] ^ lfsr_q[29] ^ lfsr_q[30] ^ lfsr_q[31] ^ i_crc[0] ^ i_crc[1] ^ i_crc[3];  
        lfsr_c[ 6] = lfsr_q[25] ^ lfsr_q[26] ^ lfsr_q[28] ^ lfsr_q[29] ^ lfsr_q[30] ^ lfsr_q[31] ^ i_crc[1] ^ i_crc[2];
        lfsr_c[ 7] = lfsr_q[24] ^ lfsr_q[26] ^ lfsr_q[27] ^ lfsr_q[29] ^ lfsr_q[31] ^ i_crc[0] ^ i_crc[2] ^ i_crc[3];  
        lfsr_c[ 8] = lfsr_q[ 0] ^ lfsr_q[24] ^ lfsr_q[25] ^ lfsr_q[27] ^ lfsr_q[28] ^ i_crc[0] ^ i_crc[1] ^ i_crc[3]; 
        lfsr_c[ 9] = lfsr_q[ 1] ^ lfsr_q[25] ^ lfsr_q[26] ^ lfsr_q[28] ^ lfsr_q[29] ^ i_crc[1] ^ i_crc[2];  
        lfsr_c[10] = lfsr_q[ 2] ^ lfsr_q[24] ^ lfsr_q[26] ^ lfsr_q[27] ^ lfsr_q[29] ^ i_crc[0] ^ i_crc[2] ^ i_crc[3]; 
        lfsr_c[11] = lfsr_q[ 3] ^ lfsr_q[24] ^ lfsr_q[25] ^ lfsr_q[27] ^ lfsr_q[28] ^ i_crc[0] ^ i_crc[1] ^ i_crc[3]; 
        lfsr_c[12] = lfsr_q[ 4] ^ lfsr_q[24] ^ lfsr_q[25] ^ lfsr_q[26] ^ lfsr_q[28] ^ lfsr_q[29] ^ lfsr_q[30] ^ i_crc[0] ^ i_crc[1] ^ i_crc[2];  
        lfsr_c[13] = lfsr_q[ 5] ^ lfsr_q[25] ^ lfsr_q[26] ^ lfsr_q[27] ^ lfsr_q[29] ^ lfsr_q[30] ^ lfsr_q[31] ^ i_crc[1] ^ i_crc[2] ^ i_crc[3];  
        lfsr_c[14] = lfsr_q[ 6] ^ lfsr_q[26] ^ lfsr_q[27] ^ lfsr_q[28] ^ lfsr_q[30] ^ lfsr_q[31] ^ i_crc[2] ^ i_crc[3];  
        lfsr_c[15] = lfsr_q[ 7] ^ lfsr_q[27] ^ lfsr_q[28] ^ lfsr_q[29] ^ lfsr_q[31] ^ i_crc[3];  
        lfsr_c[16] = lfsr_q[ 8] ^ lfsr_q[24] ^ lfsr_q[28] ^ lfsr_q[29] ^ i_crc[0];  
        lfsr_c[17] = lfsr_q[ 9] ^ lfsr_q[25] ^ lfsr_q[29] ^ lfsr_q[30] ^ i_crc[1]; 
        lfsr_c[18] = lfsr_q[10] ^ lfsr_q[26] ^ lfsr_q[30] ^ lfsr_q[31] ^ i_crc[2];  
        lfsr_c[19] = lfsr_q[11] ^ lfsr_q[27] ^ lfsr_q[31] ^ i_crc[3];  
        lfsr_c[20] = lfsr_q[12] ^ lfsr_q[28] ^ i_crc[0];  
        lfsr_c[21] = lfsr_q[13] ^ lfsr_q[29] ^ i_crc[1];  
        lfsr_c[22] = lfsr_q[14] ^ lfsr_q[24] ^ i_crc[0];  
        lfsr_c[23] = lfsr_q[15] ^ lfsr_q[24] ^ lfsr_q[25] ^ lfsr_q[30] ^ i_crc[0] ^ i_crc[1];  
        lfsr_c[24] = lfsr_q[16] ^ lfsr_q[25] ^ lfsr_q[26] ^ lfsr_q[31] ^ i_crc[1] ^ i_crc[2]; 
        lfsr_c[25] = lfsr_q[17] ^ lfsr_q[26] ^ lfsr_q[27] ^ i_crc[2] ^ i_crc[3]; 
        lfsr_c[26] = lfsr_q[18] ^ lfsr_q[24] ^ lfsr_q[27] ^ lfsr_q[28] ^ lfsr_q[30] ^ i_crc[0] ^ i_crc[3]; 
        lfsr_c[27] = lfsr_q[19] ^ lfsr_q[25] ^ lfsr_q[28] ^ lfsr_q[29] ^ lfsr_q[31] ^ i_crc[1]; 
        lfsr_c[28] = lfsr_q[20] ^ lfsr_q[26] ^ lfsr_q[29] ^ lfsr_q[30] ^ i_crc[2]; 
        lfsr_c[29] = lfsr_q[21] ^ lfsr_q[27] ^ lfsr_q[30] ^ lfsr_q[31] ^ i_crc[3];  
        lfsr_c[30] = lfsr_q[22] ^ lfsr_q[28] ^ lfsr_q[31] ^ i_crc[0]; 
        lfsr_c[31] = lfsr_q[23] ^ lfsr_q[29] ^ i_crc[1];  
    end

    always @ (posedge i_sys_clk or negedge i_rstn) begin 
        if (~i_rstn) begin 
            crc_en_prev <= 0;
        end 
        else begin 
            crc_en_prev <= i_crc_en;
        end 
    end 

    always @(posedge i_sys_clk or negedge i_rstn) begin
        if (~i_rstn) begin
            lfsr_q <= {32{1'b1}}; 
        end
        else begin
            lfsr_q <= i_crc_en ? lfsr_c : lfsr_q;
        end
    end
endmodule
