`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/12/2021 12:39:49 PM
// Design Name: 
// Module Name: OutRegF
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


module ASCONOutRegF(
input clk,rst,
input [1:0] Outsel,
input CTv,Tv,
input [63:0] C,
input [127:0] T,
output reg [63:0] DataOut
);

reg [63:0] Blockout;
reg [127:0] Tagout;

always @(*) begin
DataOut=64'b0;
    case(Outsel)
        2'd0: DataOut = Blockout;
        2'd1: DataOut = Tagout[127:64];
        2'd2: DataOut = Tagout[63:0];
        default:;
    endcase
end

always @(posedge clk, posedge rst) begin
    if(rst) begin
        Blockout <= 64'b0;
        Tagout <= 128'b0;
    end
    
    else begin
        if (CTv) Blockout <= C;
        if (Tv) Tagout <= T;
    end
end

endmodule
