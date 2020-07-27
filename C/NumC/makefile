CC = gcc
CFLAGS = -g -Wall

TARGETVEC = testvec
TARGETMAT = testmat

all: $(TARGETVEC) $(TARGETMAT)

$(TARGETVEC): vectorTests.c Vector.c
	$(CC) $(CFLAGS) -o $(TARGETVEC) vectorTests.c Vector.c

$(TARGETMAT): matrixTests.c Matrix.c Vector.c
	$(CC) $(CFLAGS) -o $(TARGETMAT) matrixTests.c Matrix.c Vector.c

.PHONY: all
