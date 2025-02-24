#include <systemc.h>
#include "tb.h"

int sc_main(int argc, char* argv[]) {
    Testbench tb("Testbench");
    sc_start(100, SC_NS);
    return 0;
}
