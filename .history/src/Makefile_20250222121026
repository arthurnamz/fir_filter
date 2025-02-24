# Define SystemC installation path (modify if needed)
SYSTEMC ?= /opt/systemc

# Library and Include Directories
LIB_DIRS = -L$(SYSTEMC)/lib-linux64
INCLUDE_DIRS = -I. -I$(SYSTEMC)/include

# Source and Header Files
HEADERS = fir.h tb.h
SOURCES = main.cc fir.cc tb.cc

# Executable Name
TESTS = main

# Libraries
LIBS = -lsystemc -lstdc++ -lm

# Compiler
CC = gcc
CFLAGS = -g -Wall -Wextra -fPIC

# Default Target
all: $(TESTS)
	./$(TESTS)
	@make cmp_result

# Build Rule
$(TESTS): $(SOURCES) $(HEADERS)
	$(CC) -o $@ $(SOURCES) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS)

# Clean Rule
clean:
	rm -f $(TESTS) *.o *.dat

# Compare Results with Golden Reference
GOLD_DIR = ./golden
GOLD_FILE = $(GOLD_DIR)/ref_output.dat

cmp_result:
	@echo "****************************************************************"
	@if diff -w $(GOLD_FILE) ./output.dat; then \
		echo "SIMULATION PASSED"; \
	else \
		echo "SIMULATION FAILED"; \
	fi
	@echo "****************************************************************"
