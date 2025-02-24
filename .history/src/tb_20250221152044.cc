#include "tb.h"

void tb::source() {
    // Reset 
    inp.write(0);
    inp_vld.write(0);
    rst.write(1);
    wait();
    rst.write(0);
    wait();

    // Send data
    sc_int<16> outdata;

    //send stimulus to the fir
    for (int i = 0; i < 64; i++) {
        if ( i > 23  && i < 29 ) {
            outdata = 256;
        } else {
            outdata = 0;
        }
        inp_vld.write(1);
        inp.write(outdata);
        do
        {
            wait();
        } while (!inp_rdy.read());
        inp_vld.write(0);
        
    }
}

void tb::sink() {
    sc_int<16> indata;

    // write the code to check whether the simulation passed or failed
    char output_file, "./output.dat";
    outfp = fopen(output_file, "wb");
    if (outfp == NULL) {
        printf("Coudn't open %s\n", output_file);
        exit(0);
    // Read output coming from DUT
    for (int i = 0; i < 64; i++) {
        indata = outp.read();
        wait();
        cout << i << ":\t" << indata.to_int() << endl;
    }

    // end of simulation
    sc_stop();
}
