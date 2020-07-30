CC = gcc
CFLAGS = -g -Wall
OFLAGS = -lm

TARGETVEC = testvec
TARGETMAT = testmat
TARGETDVEC = testdvec

all: $(TARGETVEC) $(TARGETMAT) $(TARGETDVEC)

$(TARGETVEC): vectorTests.c Vector.c
	$(CC) $(CFLAGS) -o $(TARGETVEC) vectorTests.c Vector.c

$(TARGETMAT): matrixTests.c Matrix.c Vector.c
	$(CC) $(CFLAGS) -o $(TARGETMAT) matrixTests.c Matrix.c Vector.c

$(TARGETDVEC): dvectorTests.c dVector.c
	$(CC) $(CFLAGS) -o $(TARGETDVEC) dvectorTests.c dVector.c $(OFLAGS)

.PHONY: all
