`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/27/2020 11:35:19 AM
// Design Name: 
// Module Name: ASCON_AEAD
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


module ASCON_AEAD(
input clk,rst,start,startAD,
//input startT,enc,
input [127:0] key,nonce,
input [63:0] ADblock,PTblock,
input [3:0] PTlen,ADlen,
output [127:0] T,
output [63:0] CTblock,
output CTv,Tv,read
);



wire intial,inc;
wire [3:0] consti;
wire [63:0] Xi0,Xi1,Xi2,Xi3,Xi4,Xo0,Xo1,Xo2,Xo3,Xo4;





ASCON_CONTROLER  asconcont1(
 clk,rst,start,startAD,
 //startT,enc,
 key,nonce,
 PTlen,ADlen,
ADblock,PTblock,
 T,
CTblock,
CTv,
Tv,
read,

intial,inc,
consti,
 Xi0,Xi1,Xi2,Xi3,Xi4,
Xo0,Xo1,Xo2,Xo3,Xo4
    );
    
    
ASCON_DATAPATH ascondatapath1(
 clk,rst,intial,inc,
 consti,
 Xi0,Xi1,Xi2,Xi3,Xi4,
 Xo0,Xo1,Xo2,Xo3,Xo4
    
        );    

endmodule
