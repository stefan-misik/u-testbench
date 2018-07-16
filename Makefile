#!/usr/bin/make -f
# Makefile for pc part of u-testbench
# Author: Stefan Misik (mail@stefanmisik.eu)

# Module-Under Test
MUT     =
# Stubs
STUBSRC =
# Test Source Files
TESTSRC = $(sort $(wildcard tests/*.c) $(wildcard tests/*.cpp))

# Test results output type
OUTPUT = standard
# Test results format
FORMAT = text
# Other build results (e.g. .hex file if deploying on embedded platform)
OBR =


################################################################################
PROJ	= test
SRC	= 
CFLAGS  = -c   
LDFLAGS	= -static

# Grep the list of tests from the test source files
TESTS = $(foreach TEST,$(TESTSRC),\
$(shell grep -oP '^\s*TESTBENCH_TEST_CASE\(\K[a-zA-Z0-9_]+(?=,.*\)?)' $(TEST)))

SRC +=	testbench/testbench.c \
	testbench/outputs/$(OUTPUT).c \
	testbench/formats/$(FORMAT).c \
	$(TESTSRC) $(STUBSRC) _testlist.c $(MUT)

EXECUTABLE = $(PROJ)

CFLAGS  += -D_DEBUG -ggdb -Wall
LDFLAGS += -ggdb   
OBJ = $(addsuffix .o,$(basename $(SRC)))

# List of directories containing object files

################################################################################
### Build testlist.c
COMMA =,
TESTVARPREFIX = testbenchtest_
define TESTLIST_C
#include "testbench/testbench.h"

$(addprefix extern testbench_test_t $(TESTVARPREFIX), $(addsuffix ;
,$(basename $(TESTS))))

testbench_test_t * testbench_testlist[] = 
{
    $(addsuffix $(COMMA)
   ,$(addprefix &$(TESTVARPREFIX),$(basename $(TESTS))))(testbench_test_t *)0
};
endef
export TESTLIST_C
################################################################################

.PHONY: all clean postbuild


all: $(EXECUTABLE) postbuild

$(EXECUTABLE): $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $@

%.o: %.c	
	$(CC) $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@
	
_testlist.c: $(TESTSRC)
	@echo "$$TESTLIST_C" > $@
	
clean:
	$(RM) $(EXECUTABLE) $(OBJ) $(OBR) _testlist.c

################################################################################
# Here cen by done other post-build operation e.g. generation of .hex file

postbuild:
	@echo Build OK.
