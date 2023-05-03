verilator -cc ASCON_AEAD.v -f input.vc --Mdir build -o simu --exe veriraptor.cpp
 make -C build/ -f VASCON_AEAD.mk simu
./build/simu 


