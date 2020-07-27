#ifndef _MATRIX_H
#define _MATRIX_H

#include<stdio.h>
#include<stdlib.h>
#include"Vector.h"

typedef struct Matrix
{
	Vector** data;
	int rows;
	int columns;
}
Matrix;

// Initializers
Matrix* zeroMatrix(int m, int n);
Matrix* onesMatrix(int m, int n);
Matrix* I(int n);
Matrix* copy(Matrix* M);

// Scalar multiplication and matrix addition
Matrix* scalarMatrix(int s, Matrix* M);
Matrix* addMatrix(Matrix* M1, Matrix* M2);
// Scalar multiplication and matrix addition without additional memory
void _scalarMatrix(int s, Matrix* M);
void _addMatrix(Matrix* M1, Matrix* M2);

// Print a matrix to the console
void printMatrix(Matrix* M);

#endif
