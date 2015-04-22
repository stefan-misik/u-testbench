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

.PHONY: all clean postbuild


all: $(EXECUTABLE) postbuild

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

%.o: %.c	
	$(CC) $(CFLAGS) $< -o $@
	
testlist.c: testlist.txt
	touch testlist.c
	
clean:
	$(RM) $(EXECUTABLE) $(OBJ) $(OBR) testlist.c

################################################################################
# Here cen by done other post-build operation e.g. generation of .hex file

postbuild:
	@echo Build OK.