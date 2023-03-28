`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/12/2021 12:30:20 PM
// Design Name: 
// Module Name: ASCON64
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


module ASCON64(
input clk,rst,
input run,
input [63:0] Creg1,
input [63:0] Creg2,
input validi, 
output reqi,
input [63:0] DataI,
output OutV,
input reqo,
output [63:0] DataO,
output Alldone,CTvo,Tvo,reado,startADo,startTo,
output [31:0] Tb
);
wire enc;
wire [31:0] PTL,ADL;
wire start,startAD,startT;
wire [127:0] Key,Nonce;
wire [63:0] DataBlock;
wire [3:0] PTlen,ADlen;
wire [127:0] T;
wire [63:0] C;
wire CTv,Tv,read;

wire [1:0]Isel,Outsel;
wire Keyen,Keysel,Keyload;
wire Nonceen,Noncesel,Nonceload;
wire Blocken,Blocksel,Blockload;

assign PTL = Creg2 [63:32];
assign ADL = Creg2 [31:0];
assign enc = Creg1 [0];

assign startADo=startAD;
assign startTo=startT;
assign CTvo=CTv;
assign Tvo=Tv;
assign reado=read;
assign Tb = T[127:96];


ASCON_AEAD A1ascon (
clk,rst,start,startAD,startT,enc, 
Key,Nonce,
DataBlock,DataBlock,
PTlen,ADlen,
T,C,
CTv,Tv,read);


ASCONInRegF asocnINRF
(clk,rst,
DataI,
Isel,
Keyen,Keysel,Keyload,
Nonceen,Noncesel,Nonceload,
Blocken,Blocksel,Blockload,
Key,Nonce,
DataBlock);

ASCONOutRegF asconOUTRF
(clk,rst,
Outsel,
CTv,Tv,
C,
T,
DataO);

ASCON64cont asconcoontt (
//Pads
 clk,rst,
//Interface with buffer
 run,
 validi, 
 reqi,
 ADL,PTL,
//InRegF
Isel,
Keyen,Keysel,Keyload,
Nonceen,Noncesel,Nonceload,
Blocken,Blocksel,Blockload,
//LWC core
start, 
startAD,startT,
ADlen,PTlen,
CTv,Tv,read,
//OutRegF
Outsel,
OutV,Alldone);

endmodule
