#ifndef _VECTOR_H
#define _VECTOR_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Vector
{
	int * data;
	int length;
}
Vector;

// Initialize as blank, zeros, or ones
Vector* blankVector(int n);
Vector* zeroVector(int n);
Vector* onesVector(int n);
Vector* copyVector(Vector* v);

// Functions that edit the current vector
void appendVector(Vector* v, int a);
void concatVector(Vector* v1, Vector* v2);
void swapVector(Vector* v, int elem1, int elem2);
void setVector(Vector* v, int elem, int val);

// Add, scalar multiply, component multiply, scalar exponent
// These all return vector objects
Vector* addVector(Vector* v1, Vector* v2);
Vector* scalarVector(int s, Vector* v);
Vector* multiplyVector(Vector* v1, Vector* v2);
Vector* exponentVector(Vector* v, int e);

// In-place versions of the previous functions
void _addVector(Vector* v1, Vector* v2);
void _scalarVector(int s, Vector* v);
void _multiplyVector(Vector* v1, Vector* v2);
void _exponentVector(Vector* v, int e);

// Sum, count, dot product 
// These all return integers or integer arrays
int sumVector(Vector* v);
int countVector(Vector* v);
int* dotVector(Vector* v1, Vector* v2);

// Print a vector to the console
void printVector(Vector* vec);

#endif
