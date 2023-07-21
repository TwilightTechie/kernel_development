# Reference : https://opensource.com/article/18/8/what-how-makefile
# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

#Line .PHONY = all clean defines phony targets all and clean.
.PHONY = all clean

CC = gcc                        # compiler to use

#LINKERFLAG = -lm

#SRCS := $(wildcard *.c): $(wildcard pattern) is one of the functions for filenames. In this case, all files with the .c extension will be stored in a variable SRCS.

SRCS := $(wildcard *.c)

#BINS := $(SRCS:%.c=%): This is called as substitution reference. In this case, if SRCS has values 'foo.c bar.c', BINS will have 'foo bar'.

BINS := $(SRCS:%.c=%)

all: ${BINS}

#%: %.o
#@echo "Checking.."
#${CC} ${LINKERFLAG} $< -o $@

%.o: %.c
	@echo "Creating object.."
	${CC} -c $<

clean:
	@echo "Cleaning up..."
	rm -rvf *.o ${BINS}
