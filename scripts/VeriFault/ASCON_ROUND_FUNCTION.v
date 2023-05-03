`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/26/2020 07:20:18 PM
// Design Name: 
// Module Name: ASCON_ROUND_FUNCTION
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


module ASCON_ROUND_FUNCTION(input [63:0] Xi0,Xi1,Xi2,Xi3,Xi4, input [7:0] Roundconstant, output [63:0] Xo0/*verilator public*/,Xo1/*verilator public*/,Xo2/*verilator public*/,Xo3/*verilator public*/,Xo4/*verilator public*/,
output [63:0] XsboxIN0, XsboxIN1, XsboxIN2, XsboxIN3,XsboxIN4,
output [63:0] Xsbox0, Xsbox1, Xsbox2, Xsbox3, Xsbox4, p0,p1,p2
 );


wire [63:0] Xark0,Xark1,Xark2,Xark3,Xark4,Xsb0,Xsb1,Xsb2,Xsb3,Xsb4;

assign Xark0 = Xi0;
assign Xark1 = Xi1;
assign Xark2 = Xi2 ^ {56'b0,Roundconstant};
assign Xark3 = Xi3;
assign Xark4 = Xi4;

ASCON_SBOX  asconsbox1(
Xark0,Xark1,Xark2,Xark3,Xark4,
Xsb0,Xsb1,Xsb2,Xsb3,Xsb4,
p0,p1,p2
            );

assign XsboxIN0 = Xark0;
assign XsboxIN1 = Xark1;
assign XsboxIN2 = Xark2;
assign XsboxIN3 = Xark3;
assign XsboxIN4 = Xark4;

assign Xsbox0 = Xsb0;
assign Xsbox1 = Xsb1;
assign Xsbox2 = Xsb2;
assign Xsbox3 = Xsb3;
assign Xsbox4 = Xsb4;

assign Xo0 = Xsb0 ^  { Xsb0[18:0],Xsb0[63:19] } ^ { Xsb0[27:0],Xsb0[63:28] };
assign Xo1 = Xsb1 ^  { Xsb1[60:0],Xsb1[63:61] } ^ { Xsb1[38:0],Xsb1[63:39] };
assign Xo2 = Xsb2 ^  { Xsb2[ 0:0],Xsb2[63: 1] } ^ { Xsb2[ 5:0],Xsb2[63: 6] };
assign Xo3 = Xsb3 ^  { Xsb3[ 9:0],Xsb3[63:10] } ^ { Xsb3[16:0],Xsb3[63:17] };
assign Xo4 = Xsb4 ^  { Xsb4[ 6:0],Xsb4[63: 7] } ^ { Xsb4[40:0],Xsb4[63:41] };

endmodule
