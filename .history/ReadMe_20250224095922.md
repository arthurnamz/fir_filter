# FIR Filter SystemC Implementation

## Overview

This project implements a Finite Impulse Response (FIR) filter using SystemC. The FIR filter processes input signals and produces output signals based on predefined coefficients. The design includes a testbench to validate the functionality of the FIR filter.

![System Overview](overview.png)

## Project Structure

The project consists of the following key files:

- **src/fir.cc**: Contains the implementation of the FIR filter.
- **src/fir.h**: Header file for the FIR filter module.
- **src/tb.cc**: Contains the testbench implementation that generates input signals and captures output signals.
- **src/tb.h**: Header file for the testbench module.
- **src/main.cc**: The main entry point of the simulation, where the FIR filter and testbench modules are instantiated and connected.
- **src/Makefile**: A Makefile to build the project and run the simulation.

## Building the Project

To build the project, ensure you have SystemC installed and set the `SYSTEMC` variable in the `Makefile` to point to your SystemC installation path. Then, run the following command in the terminal:
```bash
make
```

This will compile the source files and create an executable named `main`.

## Running the Simulation

After building the project, you can run the simulation with the following command:

```bash
./main
```

The simulation will generate an output file named `output.dat`, which contains the results of the FIR filter processing.

## Comparing Results

The project includes a mechanism to compare the simulation results with a golden reference output. Ensure you have a reference output file located in the `./golden` directory named `ref_output.dat`. After running the simulation, the results can be compared automatically by running:

```bash
make cmp_result
```

This will display whether the simulation passed or failed based on the comparison.

## Conclusion

This project demonstrates the implementation of a FIR filter using SystemC, along with a testbench for validation. The modular design allows for easy modifications and extensions to the filter's functionality.

For any questions or issues, please refer to the code comments or reach out for assistance.
