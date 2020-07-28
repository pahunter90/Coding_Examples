#include"Matrix.h"

// Creates a matrix of size (m,n), with no values set
Matrix* blankMatrix(int m, int n)
{
	Matrix* M = (Matrix*)malloc(sizeof(Matrix));
	M->data = (Vector**)malloc(sizeof(Vector*)*m);
	M->rows = m;
	M->columns = n;
	for(int i=0; i<M->rows; i++)
	{
		M->data[i] = blankVector(n);
	}
	return M;
}

// Initializes a matrix of size (m,n) with zeros
Matrix* zeroMatrix(int m, int n)
{
	Matrix* M = blankMatrix(m,n);
	for (int i=0; i<M->rows; i++)
	{
		for(int j=0; j<M->columns; j++)
		{
			M->data[i]->data[j] = 0;
		}
	}
	return M;
}

// Initializes a matrix of size (m,n) with ones
Matrix* onesMatrix(int m, int n)
{	
	Matrix* M = blankMatrix(m,n);
	for (int i=0; i<M->rows; i++)
	{
		for(int j=0; j<M->columns; j++)
		{
			M->data[i]->data[j] = 1;
		}
	}
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

// Returns a copy of the matrix M
Matrix* copyMatrix(Matrix* M)
{
	Matrix* Mcopy = blankMatrix(M->rows,M->columns);
	for(int i=0; i<Mcopy->rows; i++)
	{
		for(int j=0; j<Mcopy->columns; j++)
		{
			Mcopy->data[i]->data[j] = M->data[i]->data[j];
		}
	}
	return Mcopy;
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

// Return the transpose of M as a new matrix
Matrix* transpose(Matrix* M)
{
	Matrix* MT = (Matrix*)malloc(sizeof(Matrix));
	MT->data = (Vector**)malloc(sizeof(Vector*)*M->columns);
	MT->rows = M->columns;
	MT->columns = M->rows;
	for(int j=0; j < M->columns; j++)
	{
		MT->data[j] = (Vector*)malloc(sizeof(Vector));
		MT->data[j]->data = (int*)malloc(sizeof(int)*M->rows);
		MT->data[j]->length = M->rows;
		for(int i=0; i<M->rows; i++)
		{
			MT->data[j]->data[i] = M->data[i]->data[j];
		}
	}
	return MT;
}

// Transpose M in place
void _transpose(Matrix* M)
{
	int min_dim = M->rows*(M->rows <= M->columns) + M->columns*(M->rows > M->columns);
	for(int i=1; i<min_dim; i++)
	{
		for(int j=0; j<i; j++)
		{
			int temp = M->data[i]->data[j];
			M->data[i]->data[j] = M->data[j]->data[i];
			M->data[j]->data[i] = temp;
		}
	}
	if (M->rows > M->columns)
	{
		// Append the elements to the row corresponding to its column
		// Free the extra rows
		// Reallocate M->data to the new size
		for(int i=M->columns; i<M->rows; i++)
		{
			for(int j=0; j<i; j++)
			{
				appendVector(M->data[j],M->data[i]->data[j]);
			}
			free(M->data[i]);
		}
		M->data = (Vector**)realloc(M->data,sizeof(Vector*)*M->columns);
	}
	else if (M->rows < M->columns)
	{
		// Here must resize M->data first
		// And set vectors of the appropriate length
		// Add the elements
		// Then resize the rows
		M->data = (Vector**)realloc(M->data,sizeof(Vector*)*M->columns);
		for (int i=M->rows; i<M->columns; i++)
		{
			M->data[i] = blankVector(M->rows);
		}
		for(int i=0; i<M->rows; i++)
		{
			for(int j=M->rows; j<M->columns; j++)
			{
				M->data[j]->data[i] = M->data[i]->data[j];
			}
			M->data[i]->data = (int*)realloc(M->data[i]->data,sizeof(int)*M->rows);
		}
	}
	if(M->rows != M->columns)
	{
		int temp = M->rows;
		M->rows = M->columns;
		M->columns = temp;
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
