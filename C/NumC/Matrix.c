#include"Matrix.h"

// Initializes a matrix of size (m,n) with zeros
Matrix* zeroMatrix(int m, int n)
{
	Matrix* M = (Matrix*)malloc(sizeof(Matrix));

	M->data = (Vector**)malloc(sizeof(Vector*)*m);
	for (int i=0; i<m; i++)
	{
		M->data[i] = zeroVector(n);
	}
	M->rows = m;
	M->columns = n;

	return M;
}

// Initializes a matrix of size (m,n) with ones
Matrix* onesMatrix(int m, int n)
{	
	Matrix* M = (Matrix*)malloc(sizeof(Matrix));

	M->data = (Vector**)malloc(sizeof(Vector*)*m);
	for (int i=0; i<m; i++)
	{
		M->data[i] = onesVector(n);
	}
	M->rows = m;
	M->columns = n;

	return M;
}

// Initializes the (n,n) identity matrix
Matrix* I(int n)
{
	Matrix* M = zeroMatrix(n,n);

	for (int i=0; i<n; i++)
	{
		M->data[i]->data[i] = 1;
	}
	
	return M;
}

// Multiply a matrix M by scalar s
Matrix* scalarMatrix(int s, Matrix* M)
{
	if(M == NULL)
	{
		return NULL;
	}
	if (s == 0)
	{
		return zeroMatrix(M->rows, M->columns);
	}
	Matrix* sM = (Matrix*)malloc(sizeof(Matrix));
	sM->data = (Vector**)malloc(sizeof(Vector*)*M->rows);
	sM->rows = M->rows;
	sM->columns = M->columns;
	for(int i=0; i<sM->rows; i++)
	{
		sM->data[i] = scalarVector(s, M->data[i]);
	}
	return sM;
}

// Multiply M by s and store in M
void _scalarMatrix(int s, Matrix* M)
{
	if (M == NULL || s == 1)
	{
		return;
	}
	for(int i=0; i < M->rows; i++)
	{
		_scalarVector(s, M->data[i]);
	}
}

// Add M1 and M2 and store as a new matrix
// If M1 or M2 is null returns a copy of the other
// If M1 and M2 are of different sizes return NULL
Matrix* addMatrix(Matrix* M1, Matrix* M2)
{
	if (M1 == NULL)
	{
		return scalarMatrix(1, M2);
	}
	if (M2 == NULL)
	{
		return scalarMatrix(1, M1);
	}
	if (M1->rows != M2->rows || M1->columns != M2->columns)
	{
		return NULL;
	}
	Matrix* M = (Matrix*)malloc(sizeof(Matrix));
	M->data = (Vector**)malloc(sizeof(Vector*)*M1->rows);
	M->rows = M1->rows;
	M->columns = M1->columns;
	for(int i=0; i<M->rows; i++)
	{
		M->data[i] = addVector(M1->data[i],M2->data[i]);
	}
	return M;
}

// Add M1 and M2 and store result in M1
// If M1 and M2 are different sizes both matrices remain unchanged
void _addMatrix(Matrix* M1, Matrix* M2)
{
	if (M1 == NULL || M2 == NULL || M1->rows != M2->rows || M1->columns != M2->columns)
	{
		return;
	}
	for(int i=0; i < M1->rows; i++)
	{
		_addVector(M1->data[i], M2->data[i]);
	}
}

// Print a matrix to the console
void printMatrix(Matrix* M)
{
	if(M == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		for (int i=0; i<M->rows; i++)
		{
			if (i==0)
			{
				printf("[");
			}
			else
			{
				printf(" ");
			}
			
			for (int j=0; j<M->columns; j++)
			{
				if (j==0)
				{
					printf("%4d",M->data[i]->data[j]);
				}
				else
				{
					printf(",%4d",M->data[i]->data[j]);
				}
			}
			if (i<M->rows-1)
			{
				printf("\n");
			}
		}
		printf("]\n");
	}
}
