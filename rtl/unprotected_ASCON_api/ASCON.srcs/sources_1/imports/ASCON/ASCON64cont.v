`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/12/2021 12:31:07 PM
// Design Name: 
// Module Name: ASCON64cont
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


module ASCON64cont(
//Pads
input clk,rst,
//Interface with buffer
input run,
input valid, 
output reg req,
input [31:0] ADL,PTL,
//InRegF
output reg [1:0]Isel,
output reg Keyen,Keysel,Keyload,
output reg Nonceen,Noncesel,Nonceload,
output reg Blocken,Blocksel,Blockload,
//LWC core
output reg start, 
output startAD,startT,
output [3:0] ADlen,Tlen,
input CTv,Tv,read,
//OutRegF
output reg [1:0] Outsel,
output reg Outv,
output reg Alldone
);


parameter Idle       =   0,
          loadKey1   =   1,
          loadKey2   =   2,
          loadNonce1 =   3,
          loadNonce2 =   4,
          loadData   =   5,
          loadR      =   6,         
          loadKey1p  =   7,
          loadKey2p  =   8,
          loadNonce1p=   9,
          loadNonce2p=   10,
          loadDatap  =   11,
          Process    =   12,
          loadRb     =   13,   
          waitTv     =   14,
          Idledone   =   15;


reg [4:0] cstatei,nstatei;
reg [1:0] cstateo,nstateo;
reg signed [31:0] ADl, Tl;
//wire signed [15:0] ADl2,Tl2;
wire ADLr,PTLr;


assign ADlen  = ADl> 8 ? 8 :(ADl<=0 ? 0 : ADl);
assign Tlen   = Tl > 8 ? 8 : (Tl<=0 ? 0 : Tl);
assign startT = (ADl<=0 && Tl >0);
assign startAD = (ADl>0);
assign ADLr = read && startAD;
assign PTLr = read && startT;

always @(*) begin
    Isel=2'b0;
    Keyen=0;
    Keysel=0;
    Keyload=0;
    Nonceen=0;
    Noncesel=0;
    Nonceload=0;
    Blocken=0;
    Blocksel=0;
    Blockload=0;
    start=0;
    req=0;
    nstatei=Idle;
    nstateo=0;
    //ADLr=0;
    //PTLr=0;
    Outsel = 2'b00;
    Outv=0;
    Alldone = 0;
    
    case (cstatei)
        Idle: begin
            if (run) nstatei = loadKey1;
            else nstatei = Idle;
        end
    
        Idledone: begin
            if (run) nstatei = loadKey1;
            else nstatei = Idledone;
            Alldone = 1;
        end
    
        loadKey1: begin
            Keyen=1;
            Keysel=0;
            req=1;
            nstatei = loadKey2;
        end
    
        loadKey2: begin
            Keyen=1;
            Keysel=1;  
            req=1;    
            nstatei = loadNonce1;
        end
    
        loadNonce1: begin
            Nonceen=1;
            Noncesel=0;
            Keyload=1;
            req=1;
            Isel=2'd1;
            nstatei = loadNonce2;
        end
    
        loadNonce2: begin
            Nonceen=1;
            Noncesel=1;
            req=1;
            Isel=2'd1;
            nstatei = loadData;
        end
    
        loadData: begin
            Blocken=(Tl>0 || ADl>0);
            req=(Tl>0 || ADl>0);
            Nonceload =1;
            Isel=2'd2;
            nstatei = loadR;
        end
    
        loadR: begin
            Blockload=1;
            start=1;
            Blocken=(Tl>8 || ADl>8 || (startAD && Tl>0));
            Isel=2'd2;
            req=(Tl>8 || ADl>8 || (startAD && Tl>0));
            nstatei = (Tl>8 || ADl>8 || (startAD && Tl>0)) ? Process : loadKey1p;
        end
        
        loadRb: begin
            //Blockload=1;
            Blocken=(Tl>8 || ADl>8 || (startAD && Tl>0));
            Isel=2'd2;
            req=(Tl>8 || ADl>8 || (startAD && Tl>0));
            nstatei = (Tl>8 || ADl>8 || (startAD && Tl>0)) ? Process : loadKey1p;
        end
    
        Process: begin
            if (read) begin
                nstatei = loadRb;
                Blockload=1;
            end
            else begin
                nstatei = Process;
            end
        end
    
        loadKey1p: begin
            if (valid || run) begin ///can be run instead of valid.....
            Keyen=1;
            Keysel=0;
            req=1;
            nstatei = loadKey2p;
            end
            else begin
                nstatei = Idle;
            end
        end
    
        loadKey2p: begin
            Keyen=1;
            Keysel=1;  
            req=1;    
            nstatei = loadNonce1p;
        end
    
        loadNonce1p: begin
            Nonceen=1;
            Noncesel=0;
            Isel=2'd1;
            req=1;
            nstatei = loadNonce2p;
        end
    
        loadNonce2p: begin
            Nonceen=1;
            Noncesel=1;
            Isel=2'd1;
            req=1;
            nstatei = loadDatap;
        end
    
        loadDatap: begin
            Blocken=(PTL>0 || ADL>0);
            req=(PTL>0 || ADL>0);
            Isel=2'd2;
            nstatei = waitTv;
        end
        
        waitTv: begin
            if (Tv) begin
                nstatei = loadR;
                Nonceload =1;
                Keyload=1;
            end
            else nstatei = waitTv;
        end
    
    endcase
    
    case (cstateo)

        2'd0: begin
            if(CTv) nstateo = 2'd1;
            else if (Tv) nstateo = 2'd2;
            else nstateo = 2'd0;
        end
        
        2'd1: begin
            Outv =1;
            nstateo = 2'd0;
        end
        
        2'd2: begin
            Outv =1;
            Outsel=2'b01;
            nstateo = 2'd3;
        end
        
        2'd3: begin
            Outv =1;
            Outsel=2'b10;
            nstateo = 2'd0;
            if (cstatei == Idle) nstatei = Idledone;
        end
        
    endcase
end

always@(posedge clk, posedge rst)begin

    if (rst) begin
        cstatei <= Idle;
        cstateo <= 2'b0;
        ADl <= 32'b0;
        Tl <= 32'b0;
    end
    
    else begin
        cstatei <= nstatei;
        cstateo <= nstateo;
        if ((cstatei==loadKey1) || Tv) begin
            ADl <= ADL;
            Tl <= PTL;
        end
        if (ADLr) ADl <= ADl-8;
        if (PTLr) Tl <= Tl-8;
    end //else
end//always

endmodule
