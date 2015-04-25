# Makefile for pc part of u-testbench
# Author: Stefan Misik (mail@stefanmisik.eu)

# Test results output type
OUTPUT = standard
# Test results format
FORMAT = text
# Tests
TESTS = $(shell cat testlist.txt)
# Other build results (e.g. .hex file if deploying on embedded platform)
OBR =


################################################################################
PROJ	= test
SRC	= 
CFLAGS  = -c   
LDFLAGS	= -static

GIT_VERSION = $(shell git describe --dirty --always)
GIT_TAG = $(shell git describe --abbrev=0 --tags)

SRC +=	testbench/testbench.c \
	testbench/outputs/$(OUTPUT).c \
	testbench/formats/$(FORMAT).c \
	$(addsuffix .c, $(TESTS)) \
	testlist.c

EXECUTABLE = $(PROJ)

CFLAGS  += -D_DEBUG -ggdb -Wall
LDFLAGS += -ggdb   
OBJ = $(SRC:.c=.o)

### Build testlist.c
COMMA =,
TESTVARPREFIX = testbenchtest_
define TESTLIST_C
#include "testbench/testbench.h"

 $(addprefix extern testbench_test_t $(TESTVARPREFIX), $(addsuffix ;
,$(TESTS)))

testbench_test_t * testbench_testlist[] = 
{
    $(addsuffix $(COMMA)
   ,$(addprefix &$(TESTVARPREFIX),$(TESTS)))(testbench_test_t *)0
};
endef
export TESTLIST_C

.PHONY: all clean postbuild


all: $(EXECUTABLE) postbuild

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

%.o: %.c	
	$(CC) $(CFLAGS) $< -o $@
	
testlist.c: testlist.txt
	@echo "$$TESTLIST_C" > testlist.c
	
clean:
	$(RM) $(EXECUTABLE) $(OBJ) $(OBR) testlist.c

################################################################################
# Here cen by done other post-build operation e.g. generation of .hex file

postbuild:
	@echo Build OK.