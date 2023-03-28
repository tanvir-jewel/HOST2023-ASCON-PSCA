`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/27/2020 03:00:59 PM
// Design Name: 
// Module Name: ASCON_CONTROLER
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


module ASCON_CONTROLER_2rc(
input              clk,rst,start,startAD,startT,enc,
input      [127:0] key,nonce,
input        [3:0] PTlen,ADlen,
input       [63:0] ADblock,PTblock,
output     [127:0] T,
output      [63:0] CTblock,
output reg         CTv,
output reg         Tv,
output reg         read,

output reg        intial,inc,
output reg  [3:0] consti,
output reg [63:0] Xi0,Xi1,Xi2,Xi3,Xi4,
input      [63:0] Xo0,Xo1,Xo2,Xo3,Xo4
);
    
    
     reg  [5:0] cstate;
    reg [5:0] nstate;
    reg [63:0]datablock;
    reg [3:0]datalen;
    reg [127:0] keyreg;
    wire [63:0]pado,pado2;
    wire padv,padv2;
    reg lastassoq;
    wire startCT;
    wire startPT;
    
    ///////////////////////////////////////////////////////Start of FSM////////////////////////////////////////////////////////////////
    
    parameter idle =              6'b000000,
              intialize1  =       6'b000001,
              intialize2  =       6'b000010,
              intialize3  =       6'b000011,
              intialize4  =       6'b000100,
              intialize5  =       6'b000101,
              intialize6 =        6'b000110,
              intialize7  =       6'b000111,
              intialize8  =       6'b001000,
              intialize9  =       6'b001001,
              intialize10 =       6'b001010,
              intialize11 =       6'b001011,
              intialize12 =       6'b001100, 
              Associateddata1  =  6'b001101,
              Associateddata2  =  6'b001110,
              Associateddata3  =  6'b001111,
              Associateddata4  =  6'b010000,
              Associateddata5  =  6'b010001,
              Associateddata6  =  6'b010010,
              Plaintext1  =       6'b010011,
              Plaintext2  =       6'b010100,
              Plaintext3  =       6'b010101,
              Plaintext4  =       6'b010110,
              Plaintext5  =       6'b010111,
              Plaintext6  =       6'b011000, 
              ciphertext1  =      6'b011001,
              ciphertext2  =      6'b011010,
              ciphertext3  =      6'b011011,
              ciphertext4  =      6'b011100,
              ciphertext5  =      6'b011101,
              ciphertext6  =      6'b011110,
              Finlization1  =     6'b011111, 
              Finlization2  =     6'b100000, 
              Finlization3  =     6'b100001, 
              Finlization4  =     6'b100010, 
              Finlization5  =     6'b100011, 
              Finlization6  =     6'b100100, 
              Finlization7  =     6'b100101, 
              Finlization8  =     6'b100110, 
              Finlization9  =     6'b100111, 
              Finlization10 =     6'b101000,
              Finlization11 =     6'b101001, 
              Finlization12 =     6'b101010, 
              intializereg =      6'b101011;
    
   
    always@(*) 
    begin
    
    case (cstate)
    //idle
    6'b000000:begin
        intial = 0; inc = 0;
        consti = 4'b0000;
        Xi0 = 64'b0;
        Xi1 = 64'b0;
        Xi2 = 64'b0;
        Xi3 = 64'b0;
        Xi4 = 64'b0;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = 64'b0;
        datalen = 0;
        if (start)
            nstate = intializereg;
        else
            nstate = idle;
    end
    
    //intializereg
    6'b101011:begin
        intial = 1; inc = 0;
        consti = 4'b0000;
        Xi0 = 64'h80400c0600000000;
        Xi1 = key[127:64];
        Xi2 = key[63:0];
        Xi3 = nonce[127:64];
        Xi4 = nonce[63:0];
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
            datablock = ADblock;
            datalen = ADlen;
        end
        else begin
            datablock = PTblock;
            datalen = PTlen;
        end
        nstate = intialize2;
    end
    //intialize1  
    6'b000001:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
            datablock = PTblock;
            datalen = PTlen;
        end
        nstate = intialize2;
    end
    
    //intialize2
    6'b000010:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
             datablock = PTblock;
             datalen = PTlen;
        end
        nstate = intialize4;
    end
    
    //intialize3
    6'b000011:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
             datablock = PTblock;
             datalen = PTlen;
        end
        nstate = intialize4;
    end
   
    //intialize4
    6'b000100:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
             datablock = PTblock;
             datalen = PTlen;
        end
        nstate = intialize6;
    end
   
    //intialize5
     6'b000101:begin
         intial = 0; inc = 1;
         consti = 4'b0000;
         Xi0 = Xo0;
         Xi1 = Xo1;
         Xi2 = Xo2;
         Xi3 = Xo3;
         Xi4 = Xo4;
         CTv = 0;
         Tv = 0;
         read = 0;
         if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
         end
         else begin
             datablock = PTblock;
             datalen = PTlen;
         end
         nstate = intialize6;
    end
   
    //intialize6
    6'b000110:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
             datablock = PTblock;
             datalen = PTlen;
        end
        nstate = intialize8;
    end
   
    //intialize7
    6'b000111:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
             datablock = PTblock;
             datalen = PTlen;
        end
        nstate = intialize8;
    end
   
    //intialize8
    6'b001000:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
             datablock = PTblock;
             datalen = PTlen;
        end
        nstate = intialize10;
    end
           
    //intialize9
    6'b001001:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
             datablock = PTblock;
             datalen = PTlen;
        end
        nstate = intialize10;
    end
   
    //intialize10
    6'b001010:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
             datablock = ADblock;
             datalen = ADlen;
        end
        else begin
             datablock = PTblock;
             datalen = PTlen;
        end
        nstate = intialize12;
    end
   
    //intialize11
    6'b001011:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        if (startAD) begin
            datablock = ADblock;
            datalen = ADlen;
        end
        else begin
            datablock = PTblock;
            datalen = PTlen;
        end
        nstate = intialize12;
    end
   
    //intialize12
    6'b001100:begin
        intial = 1; inc = 0;
        Xi3 = Xo3 ^ keyreg [127:64];
        Tv = 0;
        read = 0;
        
        if (startAD)begin
            CTv = 0;
            nstate = Associateddata2;
            consti = 4'b0110;
            Xi0 = pado ^ Xo0; //ADblock ^ Xo0;
            Xi1 = Xo1;
            Xi2 = Xo2;
            Xi4 = Xo4 ^ keyreg [63:0];
            datablock = ADblock;
            datalen = ADlen;
        end
            
        else if (startPT && PTlen == 4'd8)begin
            CTv = 1;
            nstate = Plaintext2;
            consti = 4'b0110;
            Xi0 = CTblock;
            Xi1 = Xo1;
            Xi2 = Xo2;
            Xi4 = Xo4 ^ keyreg [63:0]^1;
            datablock = PTblock;
            datalen = PTlen;
        end
            
        else if (startPT && PTlen != 4'd8)begin
            CTv = 1;
            nstate = Finlization2;
            consti = 4'b0000;
            Xi0 = CTblock;
            Xi1 = Xo1 ^ keyreg [127:64];
            Xi2 = Xo2 ^ keyreg [63:0] ;
            Xi4 = Xo4 ^ keyreg [63:0]^1;
            datablock = PTblock;
            datalen = PTlen;
        end
        
        else if (startCT && PTlen == 4'd8)begin
            CTv = 1;
            nstate = ciphertext2;
            consti = 4'b0110;
            Xi0 = PTblock;
            Xi1 = Xo1 ;
            Xi2 = Xo2 ;
            Xi4 = Xo4 ^ keyreg [63:0]^1;
            datablock = PTblock;
            datalen = PTlen;
        end
        
        else if (startCT && PTlen != 4'd8)begin
            CTv = 1;
            nstate = Finlization2;
            consti = 4'b0000;
            Xi0 = pado2 ^ Xo0;
            Xi1 = Xo1 ^ keyreg [127:64] ;
            Xi2 = Xo2 ^ keyreg [63:0] ;
            Xi4 = Xo4 ^ keyreg [63:0]^1;
            datablock = PTblock;
            datalen = PTlen;
        end
     
        else begin //if (startFin)begin 
            CTv = 0;
            read = 0;
            nstate = Finlization2;
            consti = 4'b0000;
            Xi0 = CTblock;
            Xi1 = Xo1 ^ keyreg [127:64];
            Xi2 = Xo2 ^ keyreg [63:0] ;
            Xi4 = Xo4 ^ keyreg [63:0]^1;
            datablock = PTblock;
            datalen = PTlen;
        end
        
    end 
   
    //Associateddata1
    6'b001101:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        datalen = ADlen; 
        datablock = ADblock;
        //if(startAD) read = 1;
        //else read = 0;
        read=0;
        nstate = Associateddata2;
    end
   
    //Associateddata2
    6'b001110:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0; 
        //lastasso= padv;
        datalen = ADlen; 
        datablock = ADblock; 
        nstate = Associateddata4;
    end
   
    //Associateddata3 
    6'b001111:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = startAD;
        datalen = ADlen; 
        datablock = ADblock; 
        nstate = Associateddata4;
    end
   
    //Associateddata4
    6'b010000:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        nstate = Associateddata6;
        datalen = ADlen; 
        datablock = ADblock; 
    end
   
    //Associateddata5
    6'b010001:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        nstate = Associateddata6;
        datalen = ADlen; 
        datablock = ADblock; 
    end
   
    //Associateddata6
    6'b010010:begin
        intial = 1; inc = 0;   
        Xi3 = Xo3;
        Tv = 0;
        read = 0;
       if (lastassoq) begin 
            
            if (startPT && PTlen == 4'd8) begin    
                CTv = 1;
                datablock = PTblock;
                datalen = PTlen;
                nstate = Plaintext2;
                consti = 4'b0110;
                Xi0 = CTblock;
                Xi1 = Xo1;
                Xi2 = Xo2;
                Xi4 = Xo4 ^1;
            end
            
            else if (startPT && PTlen != 4'd8) begin   
                CTv = 1;
                datablock = PTblock;
                datalen = PTlen;
                nstate = Finlization2;
                consti = 4'b0000;
                Xi0 = CTblock;
                Xi1 = Xo1 ^ keyreg [127:64];
                Xi2 = Xo2 ^ keyreg [63:0] ;
                Xi4 = Xo4 ^1;
            end 
            
            else if (startCT && PTlen == 4'd8) begin
                CTv = 1;
                datablock = PTblock;
                datalen = PTlen;
                nstate = ciphertext2;
                Xi0 = PTblock;
                Xi1 = Xo1;
                Xi2 = Xo2;
                Xi4 = Xo4 ^ 1;
                consti = 4'b0110;
            end
            
            else if (startCT && PTlen != 4'd8) begin
                CTv = 1;
                datablock = PTblock;
                datalen = PTlen;
                nstate = Finlization2;
                Xi0 = pado2 ^ Xo0;
                Xi1 = Xo1 ^ keyreg [127:64];
                Xi2 = Xo2 ^ keyreg [63:0] ;
                Xi4 = Xo4 ^ 1;
                consti = 4'b0000;
            end
            
            else begin //if (startFin ) 
                 CTv = 0;
                 read = 0;
                datablock = PTblock;
                datalen = PTlen;
                nstate = Finlization2;
                consti = 4'b0000;
                Xi0 = CTblock;
                Xi1 = Xo1 ^ keyreg [127:64];
                Xi2 = Xo2 ^ keyreg [63:0] ;
                Xi4 = Xo4 ^ 1; 
            end
                
      end
          
      else begin
            CTv = 0;      
            nstate = Associateddata2;
            consti = 4'b0110;
            Xi0 = pado ^ Xo0;   
            Xi1 = Xo1;          
            Xi2 = Xo2;
            Xi4 = Xo4;
            datalen = ADlen; 
            datablock = ADblock; 
       end
        
    end
   
    //Plaintext1  
    6'b010011:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 1;
        datalen = PTlen; 
        datablock = PTblock; 
        nstate = Plaintext2;
    end
   
    //Plaintext2  
    6'b010100:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datalen = PTlen; 
        datablock = PTblock; 
        nstate = Plaintext4;
    end
   
    //Plaintext3  
    6'b010101:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datalen = PTlen; 
        datablock = PTblock;
        nstate = Plaintext4;
    end
   
    //Plaintext4  
    6'b010110:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datalen = PTlen; 
        datablock = PTblock;
        nstate = Plaintext6;
    end
   
    //Plaintext5  
    6'b010111:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datalen = PTlen; 
        datablock = PTblock;
        nstate = Plaintext6;
    end
   
    //Plaintext6  
    6'b011000:begin
        intial = 1; inc = 0;
        Xi3 = Xo3;
        Xi4 = Xo4;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        if (padv) begin
            Xi0 = pado  ^ Xo0;
            nstate = Finlization2;
            CTv =  startPT;
            consti = 4'b0000;
            Xi1 = Xo1 ^ keyreg [127:64];
            Xi2 = Xo2 ^ keyreg [63:0] ;
        end
        
        else begin 
            if (startPT) begin
                Xi0 = CTblock;
                nstate = Plaintext2;
                CTv = 1; 
                consti = 4'b0110;
                Xi1 = Xo1;
                Xi2 = Xo2;
            end
            else begin   
                Xi0 = pado  ^ Xo0;
                nstate = Finlization2;
                CTv = 0;
                consti = 4'b0000;
                Xi1 = Xo1 ^ keyreg [127:64];
                Xi2 = Xo2 ^ keyreg [63:0] ;
            end
        end
        
        
        /*
        else begin 
            if (startFin) begin
                Xi0 = pado  ^ Xo0;
                nstate = Finlization1;
                CTv = 0;
                consti = 4'b0000;
                Xi1 = Xo1 ^ keyreg [127:64];
                Xi2 = Xo2 ^ keyreg [63:0] ;
            end
            else begin   
                Xi0 = CTblock;
                nstate = Plaintext1;
                CTv = 1; 
                consti = 4'b0110;
                Xi1 = Xo1;
                Xi2 = Xo2;
            end
        end  */
    end          
      
        
   
    //ciphertext1 
    6'b011001:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0; 
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 1;
        datablock = PTblock;
        datalen = PTlen;
        nstate = ciphertext2;
    end
   
    //ciphertext2 
    6'b011010:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0; 
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = ciphertext4;
    end
   
    //ciphertext3 
    6'b011011:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0; 
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = ciphertext4; 
    end
   
    //ciphertext4 
    6'b011100:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0; 
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = ciphertext6; 
    end
   
    //ciphertext5 
    6'b011101:begin
        intial = 0; inc = 1;
        consti = 4'b0110;
        Xi0 = Xo0; 
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = ciphertext6;
    end
   
    //ciphertext6 
    6'b011110:begin
        intial = 1; inc = 0;
        Xi3 = Xo3;
        Xi4 = Xo4;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        if (padv) begin
            Xi0 = pado2 ^ Xo0;
            nstate = Finlization2;
            CTv = startCT;
            consti = 4'b0000;
            Xi1 = Xo1 ^ keyreg [127:64];
            Xi2 = Xo2 ^ keyreg [63:0] ;
            end
        else begin 
            if (startCT) begin
                Xi0 = pado;
                nstate = ciphertext2;
                CTv = 1; 
                consti = 4'b0110;
                Xi1 = Xo1;
                Xi2 = Xo2;
            end
            else begin  
                Xi0 = pado ^ Xo0;
                nstate = Finlization2;
                CTv = 0;
                consti = 4'b0000;
                Xi1 = Xo1 ^ keyreg [127:64];
                Xi2 = Xo2 ^ keyreg [63:0] ;
            end
        
        
        /*
            if (startFin) begin
                Xi0 = pado ^ Xo0;
                nstate = Finlization1;
                CTv = 0;
                consti = 4'b0000;
                Xi1 = Xo1 ^ keyreg [127:64];
                Xi2 = Xo2 ^ keyreg [63:0] ;
            end
            else begin  
                Xi0 = pado;
                nstate = ciphertext1;
                CTv = 1; 
                consti = 4'b0110;
                Xi1 = Xo1;
                Xi2 = Xo2;
            end*/
        end  
    end
        
       
   
    //Finlization1
    6'b011111:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2 ;
        Xi3 = Xo3;
        Xi4 = Xo4;
        Tv = 0;
        datablock = PTblock;
        datalen = PTlen;
        if (startPT ||startCT) read = 1;
        else read = 0;
        CTv = 0;
        nstate = Finlization2;
    end 
   
    //Finlization2
    6'b100000:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;  
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization4;
    end 
  
    //Finlization3
    6'b100001:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization4;
    end 
   
    //Finlization4
    6'b100010:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization6;
    end 
   
    //Finlization5
    6'b100011:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization6;
    end 
   
    //Finlization6
    6'b100100:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization8;
    end 
   
    //Finlization7
    6'b100101:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization8;
    end 
   
    //Finlization8
    6'b100110:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization10;
    end 
   
    //Finlization9
    6'b100111:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization10;
    end
   
    //Finlization10
    6'b101000:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization12;
    end
   
    //Finlization11
    6'b101001:begin
        intial = 0; inc = 1;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 0;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = Finlization12;
    end 
   
    //Finlization12
    6'b101010:begin
        intial = 1; inc = 0;
        consti = 4'b0000;
        Xi0 = Xo0;
        Xi1 = Xo1;
        Xi2 = Xo2;
        Xi3 = Xo3;
        Xi4 = Xo4;
        CTv = 0;
        Tv = 1;
        read = 0;
        datablock = PTblock;
        datalen = PTlen;
        nstate = idle;
    end 
    
    default:begin
            intial = 1; inc = 0;
            consti = 4'b0000;
            Xi0 = Xo0;
            Xi1 = Xo1;
            Xi2 = Xo2;
            Xi3 = Xo3;
            Xi4 = Xo4;
            CTv = 0;
            Tv = 1;
            read = 0;
            datablock = PTblock;
            datalen = PTlen;
            nstate = idle;
    end
    
    
    endcase
    end
    
     always @(posedge clk, posedge rst)
    begin
    if (rst)
    cstate <= 6'b000000;
    else
    cstate <= nstate;    
    end
    
    ///////////////////////////////////////////////////////END of FSM////////////////////////////////////////////////////////////////
    
    assign startCT = startT & ~enc;
    assign startPT = startT & enc;
    assign T = {Xo3,Xo4} ^ keyreg;
    assign CTblock = Xo0 ^ pado; 
    ASCONpadding asconpad1 ( datablock,datalen, pado,padv );
    ASCONpadding asconpad2 ( CTblock,datalen, pado2,padv2 );
    always @(posedge clk, posedge rst)
    begin
    if (rst) begin
        lastassoq <=0;
        keyreg <= 0;
    end
    else begin
        if (cstate == Associateddata2) lastassoq <= padv;
        if (cstate == intializereg) keyreg <= key;
    end    
    end
endmodule
