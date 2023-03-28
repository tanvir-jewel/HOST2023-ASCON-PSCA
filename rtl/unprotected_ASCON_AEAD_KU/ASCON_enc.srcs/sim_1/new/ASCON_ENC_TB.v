`timescale 1ns / 1ps
`define NULL 0 

module ASCON_ENC_TB;
reg clk,rst,start,startAD;
reg [127:0] key,nonce;
reg [63:0] ADblock,PTblock;
reg [3:0] PTlen,ADlen;
wire [127:0] T;
wire [63:0] CTblock;
wire CTv,Tv,read;

integer inFile, outFile, i;
integer scan;
reg	[19:0] clk_count; // For Tracing/Debugginh 

initial 
begin 
	clk	<= 1'b0; 
	clk_count <= 20'd0; 
end 
always 
begin 
	#1 clk <= ~clk;
end 
/*
initial begin
	inFile = $fopen("C:/My_Computer/Research/xilinx/ASCON_enc/ip_sequence.txt", "r");
	// Please change your directory
	if(inFile == `NULL)
	begin
		$display("Could not open the stimulus file");
		$finish;
	end
	outFile = $fopen("C:/My_Computer/Research/xilinx/ASCON_enc/op_sequence.txt", "w");
	// Please change your directory
end
*/
ASCON_AEAD DUT (clk, rst, start, startAD, 
                key, nonce,
                ADblock, PTblock,
                PTlen, ADlen,
                T, 
                CTblock,
                CTv, Tv, read
                );

initial 
begin  
    rst	= 1'b1;
    start = 1'b0;
    ///////////////////////////////////////////////////
    ///////////     KEY AND NONCE       ///////////////
    ///////////////////////////////////////////////////
    key =       128'h00000000_00000000_00000000_00000000;
    nonce =     128'h00000000_00000000_00000000_00000000;
    ///////////////////////////////////////////////////
    /////////// Associated Data Disable ///////////////
    ///////////////////////////////////////////////////
    startAD =   1'b0;
    ADblock =   64'h0000_0000_0000_0000;
    ADlen =     4'h0;
    ///////////////////////////////////////////////////
    /////////// Plain Text Data Disable ///////////////
    ///////////////////////////////////////////////////
    PTblock =   64'h0000_0000_0000_0000;
    PTlen =     4'h0;
    ///////////////////////////////////////////////////
    ////  AFTER RESET FUNCTIONAL SIMULATION START /////
    ///////////////////////////////////////////////////
    repeat (2)  
    @(posedge clk);  
    rst	=       1'b0; 
    start =     1'b1;
    ///////////////////////////////////////////////////
    ///////////     KEY AND NONCE       ///////////////
    ///////////////////////////////////////////////////
    key =       128'h00010203_04050607_08090A0B_0C0D0E0F;
    nonce =     128'h00010203_04050607_08090A0B_0C0D0E0F;
    ///////////////////////////////////////////////////
    // Associated Data kept Disable for Fault Analysis //
    ///////////////////////////////////////////////////
    startAD =   1'b0;
    ADblock =   64'h0000_0000_0000_0000;
    ADlen =     4'h0;
    /////////////////////////////////////////////////////
    // Plain Text kept Disable for Fault Analysis      //
    ///////////////////////////////////////////////////
    PTblock =   64'h0000_0000_0000_0000;
    PTlen =     4'h0;
    /////////////////////////////////////////////////////
end 

initial
begin
    while(1)
    begin
        @(posedge clk);
        if (!rst)
            clk_count <= clk_count + 20'd1;
        if (Tv == 1'b1) begin
            $write(" We arrived at the Final Round(12)");
            $display(" of the Finalization Stage of ASCON.");
            $display("Tag at %t, clock cycle = %d,  is %h", $time, clk_count, T);
            $stop;
        end
    end
end
endmodule
