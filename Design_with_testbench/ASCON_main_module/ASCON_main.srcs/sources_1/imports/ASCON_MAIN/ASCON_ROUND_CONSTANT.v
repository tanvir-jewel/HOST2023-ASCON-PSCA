`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/26/2020 10:09:34 PM
// Design Name: 
// Module Name: ASCON_SBOX
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module ASCON_ROUND_CONSTANT (
input clk,rst,intial,inc,
input [3:0] constti,
output [7:0] constt
);

reg  [3:0] consttd;
reg [3:0] consttq;

always @(*) begin

case ({intial,inc})
2'b00: consttd = consttq ;
2'b01: consttd = consttq +1;
2'b10: consttd = constti;
2'b11: consttd = constti;
endcase

/*
if (intial)
consttd = constti;
else if (inc)
consttd = consttq +1;
else 
consttd = consttq ;
*/
end


always @(posedge clk , posedge rst) begin

if (rst)
consttq <= 4'b0000;
else
consttq <= consttd;

end


assign constt = {~consttq,consttq};
endmodule
