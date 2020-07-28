#include"Vector.h"

// Creates a black vector of length n (no values set)
Vector* blankVector(int n)
{
	Vector* v = (Vector*)malloc(sizeof(Vector));
	v->data = (int*)malloc(sizeof(int)*n);
	v->length = n;
	return v;
}

// Returns the location of a Vector with n elements all initiialized to 0
Vector* zeroVector(int n)
{
	Vector* v = blankVector(n);
	for (int i=0; i<v->length; i++)
	{
		v->data[i] = 0;
	}
	return v;
}

// Returns the location of a Vector with n elements all initiialized to 1
Vector* onesVector(int n)
{
	Vector* v = blankVector(n);
	for (int i=0; i<v->length; i++)
	{
		v->data[i] = 1;
	}
	return v;
}

// Returns a copy of the vector v
Vector* copyVector(Vector* v)
{
	Vector* vcopy = blankVector(v->length);
	for(int i=0; i<vcopy->length; i++)
	{
		vcopy->data[i] = v->data[i];
	}
	return vcopy;
}

// Adds the element a to the vector v
void appendVector(Vector* v, int a)
{
	v->data = (int*)realloc(v->data,sizeof(int)*++v->length);
	v->data[v->length-1] = a;
}

// Adds all of the elements of v2 into v1 and sets v2 to empty ([])
// If either v1 or v2 is null the function returns with no changes made
void concatVector(Vector* v1, Vector* v2)
{
	if (v1 == NULL || v2 == NULL)
	{
		return;
	}
	for(int i = 0; i < v2->length; i++)
	{
		appendVector(v1,v2->data[i]);
	}
	free(v2->data);
	v2->length = 0;
}

// Swaps the values in slot elem1 and elem2
// If unsuccessful v remains unchanged
void swapVector(Vector* v, int elem1, int elem2)
{
	if (elem1<0 || elem1>=v->length || elem2<0 || elem2>=v->length)
	{
		return;
	}
	int temp = v->data[elem1];
	v->data[elem1] = v->data[elem2];
	v->data[elem2] = temp;
}

// Sets the value of element elem to val
// If unsuccessful v remains unchanged
void setVector(Vector* v, int elem, int val)
{
	if(elem <0 || elem>=v->length)
	{
		return;
	}
	v->data[elem] = val;
}

// Adds to vectors (v1 + v2), and returns the location of the result
// returns NULL if the vectors are not of the same length
Vector* addVector(Vector* v1, Vector* v2)
{
	if (v1->length != v2->length)
	{
		return NULL;
	}
	Vector* v = zeroVector(v1->length);
	for(int i=0; i < v1->length; i++)
	{
		v->data[i] = v1->data[i] + v2->data[i];
	}
	return v;
}

// Adds v2 to v1 storing the result in v1
// If the vectors are not compatible returns without making changes
void _addVector(Vector* v1, Vector* v2)
{
	if (v1->length != v2->length)
	{
		return;
	}
	for (int i=0; i < v1->length; i++)
	{
		v1->data[i] += v2->data[i];
	}
}

// Returns the location of a Vector defined by s*v
Vector* scalarVector(int s, Vector* v)
{
	if(v==NULL)
	{
		return NULL;
	}
	if(s==0)
	{
		return zeroVector(v->length);
	}
	Vector* sv = zeroVector(v->length);
	for(int i=0; i < v->length; i++)
	{
		sv->data[i] = s*v->data[i];
	}
	return sv;
}

// Multiplies v by scalar s, storing the result in v
void _scalarVector(int s, Vector* v)
{
	if(v==NULL)
	{
		return;
	}
	for(int i=0; i < v->length; i++)
	{
		v->data[i] *= s;
	}
}

// Multiplies v1 and v2 component-wise, and returns the location of the result
Vector* multiplyVector(Vector* v1, Vector* v2)
{
	if (v1->length != v2->length)
	{
		return NULL;
	}
	Vector* v = zeroVector(v1->length);
	for(int i=0; i < v1->length; i++)
	{
		v->data[i] = v1->data[i] * v2->data[i];
	}
	return v;
}

// Multiplies v2 into v1 and stores the result in v1
void _multiplyVector(Vector* v1, Vector* v2)
{
	if(v1->length != v2->length)
	{
		return;
	}
	for(int i=0; i < v1->length; i++)
	{
		v1->data[i] *= v2->data[i];
	}
}

// Returns the location of the element-wise exponential v^e
// Allows non-negative exponents only
Vector* exponentVector(Vector* v, int e)
{
	if(v == NULL || e < 0)
	{
		return NULL;
	}
	Vector* ve = onesVector(v->length);
	for (int i=0; i < v->length; i++)
	{			
		for(int j = 1; j <= e; j++)
		{
			ve->data[i] *= v->data[i];
			if(ve->data[i] == 0 || ve->data[i] == 1)
			{
				break;
			}
		}
	}
	return ve;
}

// Computes the element-wise exponential v^e and stores in v
// Allows non-negative exponents only (v remains unchanged if negative)
void _exponentVector(Vector* v, int e)
{
	if(v == NULL || e == 1 || e < 0)
	{
		return;
	}
	int* temp = (int*)malloc(sizeof(int)*v->length);
	for(int i = 0; i < v->length; i++)
	{
		temp[i] = 1;
		for(int j = 1; j <= e; j++)
		{
			temp[i] *= v->data[i];
		}
		v->data[i] = temp[i];
	}
	free(temp);
}
	
// Returns the sum of the elements in v
int sumVector(Vector* v)
{
	int sum = 0;
	for (int i=0; i < v->length; i++)
	{
		sum += v->data[i];
	}
	return sum;
}

// Returns the number of elements in v not equal to 0
int countVector(Vector* v)
{
	int count = 0;
	for (int i=0; i < v->length; i++)
	{
		count += (v->data[i]!=0);
	}
	return count;
}

// Takes the dot product of two vectors (v1 & v2)
// Returns an integer array, the first element is the return value
// and the second element is an error checker (1 if no error, 0 if error)
int* dotVector(Vector* v1, Vector* v2)
{
	int* output = (int*)malloc(2*sizeof(int));
	output[0] = 0;
	output[1] = 1;
	if (v1->length != v2->length)
	{
		output[1] = 0;
		return output;
	}
	for (int i=0; i < v1->length; i++)
	{
		output[0] += v1->data[i] * v2->data[i];
	}
	return output;
}

// Prints a vector to the console as [a,b,c,d]
// if the location of vec is set to NULL, prints "NULL"
// A newline is printed at the end of the vector (or NULL)
void printVector(Vector* vec)
{
	if(vec == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("[");
		for(int i=0; i<vec->length-1; i++)
		{
			printf("%d,",vec->data[i]);
		}
		if(vec->length > 0)
		{
			printf("%d]\n",vec->data[vec->length-1]);
		}
		else
		{
			printf("]\n");
		}
	}
}


