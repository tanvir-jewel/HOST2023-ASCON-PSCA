# Testbench Instructions

## About
This testbench tests the functionality of the `ASCON_AEAD` module and will test any properly formatted test vector or series of vectors from an input text file

## Requirements

### Verilog Files
- `ASCON_AEAD.v`
    - `ASCON_CONTROLER.v`
        - `ASCONpadding.v`
    - `ASCON_DATAPATH.v`
        - `ASCON_ROUND_CONSTANT.v`
        - `ASCON_ROUND_FUNCTION.v`

### Text Files
- `translated_blocks.txt`


## Test Vector Encoding
The file `translator.py` converts the text file output from `genkat.py` from [pyascon](https://github.com/meichlseder/pyascon/tree/1ad51b091d2233a29beb2e7b5136f791cf5100ff) into the format required for this testbench. Output to a text file is not standard so assuming `python3 genkat.py Ascon-128` and `python3 translator.py > translated_blocks.txt` are both run, the file will be automatically generated from the known answer tests. To create your own test vector files, the general format is shown below.

```  
[Num Plaintext Blocks] [Last PT block length (bytes)] [Num AD Blocks] [Last AD block length (bytes)]

[Key]

[Nonce]

[Associated Data Blocks (One Block per Line)]

[Plaintext Block]       #PT and CT blocks come in pairs and if there are multiple blocks they interleave

[Corresponding Ciphertext Block]

[Tag]
```

4 annotated examples are also included

### No Associated Data or Plaintext
```
0 8 0 8     #0 plaintext blocks, default block length 8, 0 associated data blocks, default block length 8  
000102030405060708090A0B0C0D0E0F #128 bit key  
000102030405060708090A0B0C0D0E0F #128 bit nonce  
E355159F292911F794CB1432A0103A8A #128 bit tag  
```

### Associated Data with no Plaintext
```
0 8 2 2                          #0 PT blocks, default length 8, 2 AD blocks, last length 2  
000102030405060708090A0B0C0D0E0F #128 bit key  
000102030405060708090A0B0C0D0E0F #128 bit nonce  
0001020304050607                 #1st AD block (8 bytes)  
0809000000000000                 #2nd AD block 2 bytes 0x0809 with 0 padding for rest of bytes  
4B006A400B6DFB9777BC3446C2B7DC26 #128 bit tag  
```
### No Associated Data with Plaintext
```

2 3 0 8                          #2 PT blocks, last length 3, 0 AD blocks, default length 8  
000102030405060708090A0B0C0D0E0F #128 bit key  
000102030405060708090A0B0C0D0E0F #128 bit nonce  
0001020304050607                 #1st PT block (8 bytes)  
BC820DBDF7A4631C                 #1st CT block (8 bytes)  
08090A0000000000                 #2nd PT block 3 bytes 0x08090A with 0 padding for rest of bytes  
5B29880000000000                 #2nd CT block 3 bytes 0x5B2988 with 0 padding for rest of bytes  
02CF2EE93FF523BD068CE507C683116C #128 bit tag  
```
### Associated Data and Plaintext
```

3 6 3 2                          #3 PT blocks, last length 6, 3 AD blocks, last length 2  
000102030405060708090A0B0C0D0E0F #128 bit key  
000102030405060708090A0B0C0D0E0F #128 bit nonce  
0001020304050607                 #1st AD block (8 bytes)  
08090A0B0C0D0E0F                 #2nd AD block (8 bytes)  
1011000000000000                 #3rd AD block 2 bytes 0x1011 with 0 padding rest of bytes  
0001020304050607                 #1st PT block (8 bytes)  
77AA511159627C4B                 #1st CT block (8 bytes)  
08090A0B0C0D0E0F                 #2nd PT block (8 bytes)  
855E67F95B3ABF14                 #2nd CT block (8 bytes)  
1011121314150000                 #3rd PT block 6 bytes 0x101112131415 with 0 padding for rest of bytes  
90F306CD374B0000                 #3rd CT block 6 bytes 0x90F306CD374B with 0 padding for rest of bytes  
40554E927446842A6213BAA0AB8315CB #128 bit tag  
```