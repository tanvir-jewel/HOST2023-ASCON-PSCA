import numpy as np

# This program takes input of sbox and parity signatures of the sbox and find the number of faults in the ASCON permuatation.
with open('op_sequence.txt', 'r') as f:
    num_lines = len(f.readlines())
    print("Total number of lines in the file:", num_lines)
data = np.loadtxt('op_sequence.txt', dtype=str, delimiter=' ', max_rows=num_lines)

fault_count = 0
fault_in_rount = 0
for j in range(0,num_lines):
    Xsbox0 = data[j][0]
    Xsbox1 = data[j][1]
    Xsbox2 = data[j][2]
    Xsbox3 = data[j][3]
    Xsbox4 = data[j][4]
    p0 = data[j][5]
    p1 = data[j][6]
    p2 = data[j][7]
    print(j)
    fault_in_line= 0
    for i in range(0,64):
        print(j)
        print(i)
        parity_out = p0[i]+p1[i]+p2[i]
        # Combine the bits into a 5-bit binary string
        sbox_input= Xsbox0[i]+Xsbox1[i]+Xsbox2[i]+Xsbox3[i]+Xsbox4[i]

        # Convert binary string to integer
        sbox_input = int(sbox_input, 2)


        # Convert integer to hexadecimal string
        sbox_input_hex = hex(sbox_input)[2:]

        if sbox_input_hex == '0' and parity_out == '110':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '1' and parity_out == '110':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '2' and parity_out == '110':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '3' and parity_out == '000':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '4' and parity_out == '110':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '5' and parity_out == '110':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '6' and parity_out == '011':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '7' and parity_out == '101':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '8' and parity_out == '000':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '9' and parity_out == '000':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == 'a' and parity_out == '101':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == 'b' and parity_out == '011':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == 'c' and parity_out == '011':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == 'd' and parity_out == '011':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == 'e' and parity_out == '011':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == 'f' and parity_out == '101':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '10' and parity_out == '000':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '11' and parity_out == '101':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '12' and parity_out == '101':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '13' and parity_out == '110':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '14' and parity_out == '000':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '15' and parity_out == '101':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '16' and parity_out == '000':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '17' and parity_out == '011':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '18' and parity_out == '110':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '19' and parity_out == '011':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '1a' and parity_out == '110':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '1b' and parity_out == '101':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '1c' and parity_out == '101':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '1d' and parity_out == '000':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '1e' and parity_out == '000':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        elif sbox_input_hex == '1f' and parity_out == '011':
            print("No fault occurred!" + "    sbox input=" + sbox_input_hex + "    parity_out=" + parity_out )
        else:
            print("Fault Occoured")
            fault_count = fault_count+1
            fault_in_line = fault_in_line+1
    print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
    print("Total fault in " + str(j+1) + ", is: "+ str(fault_in_line))
    print("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%")
    if (fault_in_line>0):
        fault_in_rount = fault_in_rount+1

print("Total number of fault occurred= "+ str(fault_count))

print("Total number of Round affected by fault = "+ str(fault_in_rount))
