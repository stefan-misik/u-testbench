# Makefile for pc part of u-testbench
# Author: Stefan Misik (mail@stefanmisik.eu)

# Test results output type
OUTPUT = standard
# Test results format
FORMAT = text


PROJ	= u-testbench
SRC	= main.c


CFLAGS	    = -c   
LDFLAGS	    = -static
################################################################################
GIT_VERSION = $(shell git describe --dirty --always)
GIT_TAG = $(shell git describe --abbrev=0 --tags)

SRC += outputs/$(OUTPUT).c formats/$(FORMAT).c


EXECUTABLE = $(PROJ)

CFLAGS  += -D_DEBUG -ggdb -Wall
LDFLAGS += -ggdb   
OBJ = $(SRC:.c=.o)

.PHONY: all clean


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

%.o: %.c	
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	$(RM) $(EXECUTABLE) $(SRC:.c=.o)

