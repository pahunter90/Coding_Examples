#include "dVector.h"

// Creates a black vector of length n (no values set)
dVector* blankdVector(int n)
{
	dVector* v = (dVector*)malloc(sizeof(dVector));
	v->data = (double*)malloc(sizeof(double)*n);
	v->length = n;
	return v;
}

// Returns the location of a Vector with n elements all initiialized to 0
dVector* zerodVector(int n)
{
	dVector* v = blankdVector(n);
	for (int i=0; i<v->length; i++)
	{
		v->data[i] = 0.0;
	}
	return v;
}

// Returns the location of a Vector with n elements all initiialized to 1
dVector* onesdVector(int n)
{
	dVector* v = blankdVector(n);
	for (int i=0; i<v->length; i++)
	{
		v->data[i] = 1.0;
	}
	return v;
}

// Returns a copy of the vector v
dVector* copydVector(dVector* v)
{
	dVector* vcopy = blankdVector(v->length);
	for(int i=0; i<vcopy->length; i++)
	{
		vcopy->data[i] = v->data[i];
	}
	return vcopy;
}

// Adds the element a to the vector v
void appenddVector(dVector* v, double a)
{
	v->data = (double*)realloc(v->data,sizeof(double)*++v->length);
	v->data[v->length-1] = a;
}

// Adds all of the elements of v2 into v1 and sets v2 to empty ([])
// If either v1 or v2 is null the function returns with no changes made
void concatdVector(dVector* v1, dVector* v2)
{
	if (v1 == NULL || v2 == NULL)
	{
		return;
	}
	for(int i = 0; i < v2->length; i++)
	{
		appenddVector(v1,v2->data[i]);
	}
	free(v2->data);
	v2->length = 0;
}

// Swaps the values in slot elem1 and elem2
// If unsuccessful v remains unchanged
void swapdVector(dVector* v, int elem1, int elem2)
{
	if (elem1<0 || elem1>=v->length || elem2<0 || elem2>=v->length)
	{
		return;
	}
	double temp = v->data[elem1];
	v->data[elem1] = v->data[elem2];
	v->data[elem2] = temp;
}

// Sets the value of element elem to val
// If unsuccessful v remains unchanged
void setdVector(dVector* v, int elem, double val)
{
	if(elem <0 || elem>=v->length)
	{
		return;
	}
	v->data[elem] = val;
}

// Adds to vectors (v1 + v2), and returns the location of the result
// returns NULL if the vectors are not of the same length
// return dVector will have the precision of v1
dVector* adddVector(dVector* v1, dVector* v2)
{
	if (v1->length != v2->length)
	{
		return NULL;
	}
	dVector* v = blankdVector(v1->length);
	for(int i=0; i < v1->length; i++)
	{
		v->data[i] = v1->data[i] + v2->data[i];
	}
	return v;
}

// Adds v2 to v1 storing the result in v1
// If the vectors are not compatible returns without making changes
void _adddVector(dVector* v1, dVector* v2)
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
dVector* scalardVector(double s, dVector* v)
{
	if(v==NULL)
	{
		return NULL;
	}
	if(s==0)
	{
		return zerodVector(v->length);
	}
	dVector* sv = blankdVector(v->length);
	for(int i=0; i < v->length; i++)
	{
		sv->data[i] = s*v->data[i];
	}
	return sv;
}

// Multiplies v by scalar s, storing the result in v
void _scalardVector(double s, dVector* v)
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
dVector* multiplydVector(dVector* v1, dVector* v2)
{
	if (v1->length != v2->length)
	{
		return NULL;
	}
	dVector* v = blankdVector(v1->length);
	for(int i=0; i < v1->length; i++)
	{
		v->data[i] = v1->data[i] * v2->data[i];
	}
	return v;
}

// Multiplies v2 into v1 and stores the result in v1
void _multiplydVector(dVector* v1, dVector* v2)
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
dVector* exponentdVector(dVector* v, double e)
{
	if(v == NULL || e < 0)
	{
		return NULL;
	}
	dVector* ve = blankdVector(v->length);
	for (int i=0; i < v->length; i++)
	{
		ve->data[i] = pow(v->data[i],e);
	}
	return ve;
}

// Computes the element-wise exponential v^e and stores in v
// Allows non-negative exponents only (v remains unchanged if negative)
// for negative exponents use a vector such that v'[i] = 1/v[i]
void _exponentdVector(dVector* v, double e)
{
	if(v == NULL || e == 1 || e < 0)
	{
		return;
	}
	for(int i = 0; i < v->length; i++)
	{
		v->data[i] = pow(v->data[i],e);
	}
}
	
// Returns the sum of the elements in v
double sumdVector(dVector* v)
{
	double sum = 0;
	for (int i=0; i < v->length; i++)
	{
		sum += v->data[i];
	}
	return sum;
}

// Returns the number of elements in v not equal to 0
int countdVector(dVector* v)
{
	int count = 0;
	for (int i=0; i < v->length; i++)
	{
		count += (v->data[i]!=0);
	}
	return count;
}

// Takes the dot product of two vectors (v1 & v2)
// Returns a double array, the first element is the return value
// and the second element is an error checker (1.0 if no error, 0.0 if error)
double* dotdVector(dVector* v1, dVector* v2)
{
	double* output = (double*)malloc(2*sizeof(double));
	output[0] = 0.0;
	output[1] = 1.0;
	if (v1->length != v2->length)
	{
		output[1] = 0.0;
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
void printdVector(dVector* v, int precision)
{
	if(v == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("[");
		for(int i=0; i<v->length-1; i++)
		{
			printf("%.*f,",precision,v->data[i]);
		}
		if(v->length > 0)
		{
			printf("%.*f]\n",precision,v->data[v->length-1]);
		}
		else
		{
			printf("]\n");
		}
	}
}


