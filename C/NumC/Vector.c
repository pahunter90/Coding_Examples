#include"Vector.h"

// Returns the location of a Vector with n elements all initiialized to 0
Vector* zeros(int n)
{
	Vector* vec = (Vector*)malloc(sizeof(Vector));
	vec->data = (int*)malloc(sizeof(int)*n);
	vec->length = n;
	for (int i=0; i<n; i++)
	{
		vec->data[i] = 0;
	}
	return vec;
}

// Returns the location of a Vector with n elements all initiialized to 1
Vector* ones(int n)
{
	Vector* vec = (Vector*)malloc(sizeof(Vector));
	vec->data = (int*)malloc(sizeof(int)*n);
	vec->length = n;
	for (int i=0; i<n; i++)
	{
		vec->data[i] = 1;
	}
	return vec;
}

// Adds the element a to the vector v
void append(Vector* v, int a)
{
	v->data = (int*)realloc(v->data,sizeof(int)*++v->length);
	v->data[v->length-1] = a;
}

// Adds all of the elements of v2 into v1 and sets v2 to empty ([])
// If either v1 or v2 is null the function returns with no changes made
void concat(Vector* v1, Vector* v2)
{
	if (v1 == NULL || v2 == NULL)
	{
		return;
	}
	for(int i = 0; i < v2->length; i++)
	{
		append(v1,v2->data[i]);
	}
	free(v2->data);
	v2->length = 0;
}

// Swaps the values in slot elem1 and elem2
// If unsuccessful v remains unchanged
void swap(Vector* v, int elem1, int elem2)
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
void set(Vector* v, int elem, int val)
{
	if(elem <0 || elem>=v->length)
	{
		return;
	}
	v->data[elem] = val;
}

// Adds to vectors (v1 + v2), and returns the location of the result
// returns NULL if the vectors are not of the same length
Vector* add(Vector* v1, Vector* v2)
{
	if (v1->length != v2->length)
	{
		return NULL;
	}
	Vector* v = zeros(v1->length);
	for(int i=0; i < v1->length; i++)
	{
		v->data[i] = v1->data[i] + v2->data[i];
	}
	return v;
}

// Returns the location of a Vector defined by s*v
Vector* scalar(int s, Vector* v)
{
	if(s==0)
	{
		return zeros(v->length);
	}
	Vector* sv = zeros(v->length);
	for(int i=0; i < v->length; i++)
	{
		sv->data[i] = s*v->data[i];
	}
	return sv;
}

// Multiplies v1 and v2 component-wise, and returns the location of the result
Vector* multiply(Vector* v1, Vector* v2)
{
	if (v1->length != v2->length)
	{
		return NULL;
	}
	Vector* v = zeros(v1->length);
	for(int i=0; i < v1->length; i++)
	{
		v->data[i] = v1->data[i] * v2->data[i];
	}
	return v;
}

// Returns the location of the element-wise exponential v^e
Vector* exponent(Vector* v, int e)
{
	if(e == 0)
	{
		return ones(v->length);
	}
	int neg_pow = (e < 0);
	int pos_e = e;
	if (neg_pow)
	{
		pos_e = 0-pos_e;
	}
	Vector* ve = zeros(v->length);
	for (int i=0; i < v->length; i++)
	{
		if(v->data[i] == 0 && neg_pow)
		{
			return NULL;
		}
		if(v->data[i] > 1 && neg_pow)
		{
			ve->data[i] = 0;
			continue;
		}
		ve->data[i] = v->data[i];
		if(ve->data[i] == 1 || ve->data[i] == 0)
		{
			continue;
		}
		for(int j = 2; j<=pos_e; j++)
		{
			ve->data[i] = ve->data[i]*v->data[i];
		}
		if (neg_pow)
		{
			ve->data[i] = 1/ve->data[i];
		}
	}
	return ve;
}
	
// Returns the sum of the elements in v
int sum(Vector* v)
{
	int sum = 0;
	for (int i=0; i < v->length; i++)
	{
		sum += v->data[i];
	}
	return sum;
}

// Returns the number of elements in v not equal to 0
int count(Vector* v)
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
int* dot(Vector* v1, Vector* v2)
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
void print(Vector* vec)
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


