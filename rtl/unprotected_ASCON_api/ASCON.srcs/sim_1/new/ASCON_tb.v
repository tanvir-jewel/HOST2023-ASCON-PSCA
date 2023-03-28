`timescale 1ns / 1ps
`define NULL 0 

module ASCON_tb;
reg clk,rst;
reg run;
reg [63:0] Creg1;
reg [63:0] Creg2;
reg validi;
wire reqi;
reg [63:0] DataI;
wire OutV;
reg reqo;
wire [63:0] DataO;
wire Alldone,CTvo,Tvo,reado,startADo,startTo;
wire [31:0] Tb;

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

initial begin
	inFile = $fopen("C:/My_Computer/Research/xilinx/ASCON/ip_sequence.txt", "r");
	// Please change your directory
	if(inFile == `NULL)
	begin
		$display("Could not open the stimulus file");
		$finish;
	end
	outFile = $fopen("C:/My_Computer/Research/xilinx/ASCON/op_sequence.txt", "w");
	// Please change your directory
end

ASCON64 DUT(
    .clk       (clk     ),
    .rst       (rst     ),
    .run       (run     ),
    .Creg1     (Creg1   ),
    .Creg2     (Creg2   ),
    .validi    (validi  ),
    .reqi      (reqi    ),
    .DataI     (DataI   ),
    .OutV      (OutV    ),
    .reqo      (reqo    ),
    .DataO     (DataO   ),
    .Alldone   (Alldone ),
    .CTvo      (CTvo    ),
    .Tvo       (Tvo     ),
    .reado     (reado   ),
    .startADo  (startADo),
    .startTo   (startTo ),
    .Tb        (Tb      )
);

initial 
begin  
		rst	= 1'b1; 
		repeat (4) 
		begin 
			@(posedge clk);  
		end 
		rst	= 1'b0; 
		clk_count <= clk_count + 20'd1; 
end 

initial
begin
    while(!$feof(inFile))
    begin
        scan = $fscanf(inFile, "%b %b %b %h %h %h %h\n", run, validi, reqo, Creg2[63:32], Creg2[31:0], Creg1, DataI);
        // Creg2 = plain length text [63:32]
        // Creg2 = plain length text [31:0]
        // Creg1 = only Creg1[0] need to be either 0 or 1
        // DataI = sequentially send key nonce and plaintext(maybe)
        @(posedge clk);
        clk_count <= clk_count + 20'd1;
        $fwrite(outFile, "%b %b %b %b %b %b %b %b %h %h\n", reqi, OutV, Alldone, CTvo, Tvo, reado, startADo, startTo, Tb, DataO);
    end
    $fclose(inFile);
    $fclose(outFile);
    $stop;
end


endmodule