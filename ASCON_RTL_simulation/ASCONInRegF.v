`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/12/2021 12:39:49 PM
// Design Name: 
// Module Name: InRegF
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


module ASCONInRegF
(
input clk,rst,
input [63:0] DataI,
input [1:0]Isel,
input Keyen,Keysel,Keyload,
input Nonceen,Noncesel,Nonceload,
input Blocken,Blocksel,Blockload,
output [127:0] Key,Nonce,
output [63:0] DataBlock
);

reg [127:0] Keyreg, Noncereg;
reg [63:0] Blockreg;

reg [127:0] Keyin, Noncein;
reg [63:0] Blockin;


reg [63:0] Keyb,Nonceb,Blockb;

assign Key = Keyin;
assign Nonce = Noncein;
assign DataBlock = Blockin;

always @(*) begin
    Keyb=64'b0;
    Nonceb=64'b0;
    Blockb=64'b0;
    case (Isel)
        2'd0:Keyb=DataI;
        2'd1:Nonceb=DataI;
        2'd2:Blockb=DataI;
        default:;
    endcase
end

always @(posedge clk, posedge rst) begin

    if (rst) begin
        Keyreg <= 128'b0;
        Noncereg <= 128'b0;
        Blockreg <= 64'b0;
        Keyin <= 128'b0;
        Noncein <= 128'b0;
        Blockin <= 64'b0;
    end
    
    else begin
        ///Key load
        if(Keyen) begin
            if (Keysel==0) Keyreg[127:64] <= Keyb;
            else Keyreg[63:0] <= Keyb;
        end    
        ///Key transfer 
        if (Keyload) Keyin <=Keyreg;
        
        ///Nonce load
        if(Nonceen) begin
            if (Noncesel==0) Noncereg[127:64] <= Nonceb;
            else Noncereg[63:0] <= Nonceb;
        end      
        ///Nonce transfer 
        if (Nonceload) Noncein <=Noncereg;
        
        ///Block load
        if (Blocken) Blockreg <= Blockb;
        ///Block transfer
        if (Blockload) Blockin <= Blockreg;         
    end
end
endmodule
