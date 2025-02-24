
#include "fir.h"

// Coeffiecients for each FIR
const sc_uint<8> coef[5] = {
    18,
    77,
    107,
    77,
    18
};

// FIR Main thread
void fir::fir_main(void){
    // fir instances
    sc_int<16> taps[5];

    // Reset
    for (int i = 0; i < 5; i++){
        taps[i] = 0;
    }

    // initialize the handshake
    inp_rdy.write(0);
    outp_vld.write(0);
    outp.write(0);
    wait();

    // FIR filter
    while( true ) {
        sc_int<16> in_val;
        sc_int<16> out_val;

        // Read input into shift register
        for(int i = 4; i > 0; i--){
            taps[i] = taps[i-1];
        }
        taps[0] = in_val;

        // Perform multiply and accumulate
        for (int i = 0; i < 5; i++){
            out_val += coef[i] * taps[i];
        }

        // Write output
        outp.write(out_val);
        wait();
    }

}