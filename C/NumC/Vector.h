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

// Initialize as zeros or ones
Vector* zeros(int n);
Vector* ones(int n);

// Functions that edit the current vector
void append(Vector* v, int a);
void concat(Vector* v1, Vector* v2);
void swap(Vector* v, int elem1, int elem2);
void set(Vector* v, int elem, int val);

// Add, scalar multiply, component multiply, scalar exponent
// These all return vector objects
Vector* add(Vector* v1, Vector* v2);
Vector* scalar(int s, Vector* v);
Vector* multiply(Vector* v1, Vector* v2);
Vector* exponent(Vector* v, int e);

// Sum, count, dot product 
// These all return integers or integer arrays
int sum(Vector* v);
int count(Vector* v);
int* dot(Vector* v1, Vector* v2);

// Print a vector to the console
void print(Vector* vec);

#endif
