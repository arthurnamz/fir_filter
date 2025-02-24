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
        start_time[i] = sc_time_stamp();
        do
        {
            wait();
        } while (!inp_rdy.read());
        inp_vld.write(0);
        
    }
}

void tb::sink() {
    sc_int<16> indata;

    // Extract clock period
    sc_clock *clk_p = dynamic_cast<sc_clock*>(clk.get_interface());
    clock_period = clk_p->period();
    
    // Declare a character array for the filename
    char output_file[256];  
    sprintf(output_file, "output.dat");  // Store the filename in the char array
    
    // Open the file for writing
    FILE *outfp = fopen(output_file, "w");  
    if (outfp == NULL) {
        printf("Couldn't open the output.dat file\n");
        exit(0);
    }
    
    // Initialize the port
    outp_rdy.write(0);
    
    double total_cycles = 0;
    // Read output coming from DUT
    for (int i = 0; i < 64; i++) {
        outp_rdy.write(1);
        do {
            wait();
        } while (!outp_vld.read());
        
        indata = outp.read();
        end_time[i] = sc_time_stamp();
        total_cycles += (end_time[i] - start_time[i]) / clock_period;
        outp_rdy.write(0);
        
        fprintf(outfp, "%d\n", indata.to_int());  // Corrected method call
        cout << i << ":\t" << indata.to_int() << endl;
    }

    // print latency
    printf("Average Latency: %f cycles\n", (double)total_cycles/64);

    // End of simulation
    fclose(outfp);
    sc_stop();
}

