#include "tb.h"

void tb::source() {
    // Reset 
    inp.write(0);
    rst.write(1);
    wait();
    rst.write(0);
    wait();

    // Send data
    sc_int<16> temp;

    //send stimulus to the fir
    for (int i = 0; i < 64; i++) {
        if ( i > 23  && i < 29 ) {
            temp = 256;
        } else {
            temp = 0;
        }
        inp.write(temp);
        wait();
    }
}

void tb::sink() {
    sc_int<16> indata;

    // Read output coming from DUT
    for (int i = 0; i < 64; i++) {
        indata = outp.read();
        wait();
        cout << i << ":\t" << indata.to_int() << endl;
    }

    // end of simulation
    sc_stop();
}
