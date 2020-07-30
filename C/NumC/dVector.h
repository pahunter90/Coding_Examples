#ifndef _DVECTOR_H
#define _DVECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dVector
{
	double * data;
	int length;
}
dVector;

// Initialize as blank, zeros, or ones
dVector* blankdVector(int n);
dVector* zerodVector(int n);
dVector* onesdVector(int n);
dVector* copydVector(dVector* v);

// Functions that edit the current vector
void appenddVector(dVector* v, double a);
void concatdVector(dVector* v1, dVector* v2);
void swapdVector(dVector* v, int elem1, int elem2);
void setdVector(dVector* v, int elem, double val);

// Add, scalar multiply, component multiply, scalar exponent
// These all return vector objects
dVector* adddVector(dVector* v1, dVector* v2);
dVector* scalardVector(double s, dVector* v);
dVector* multiplydVector(dVector* v1, dVector* v2);
dVector* exponentdVector(dVector* v, double e);

// In-place versions of the previous functions
void _adddVector(dVector* v1, dVector* v2);
void _scalardVector(double s, dVector* v);
void _multiplydVector(dVector* v1, dVector* v2);
void _exponentdVector(dVector* v, double e);

// Sum, count, dot product 
// These all return integers or integer arrays
double sumdVector(dVector* v);
int countdVector(dVector* v);
double* dotdVector(dVector* v1, dVector* v2);

// Print a vector to the console
void printdVector(dVector* v, int precision);

#endif
