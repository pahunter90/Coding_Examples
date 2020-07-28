#include"Vector.h"

int main()
{
	printf("\nCreate a zero vector\n");
	Vector* v1 = zeroVector(9);
	printVector(v1);
	printf("\n");

	printf("Create a vector of ones\n");
	Vector* v2 = onesVector(9);
	printVector(v2);
	printf("\n");

	printf("Add a vector of zeros and ones\n");
	Vector* v3 = addVector(v1,v2);
	printVector(v3);
	printf("\n");

	printf("Add ones to the previous vector in place\n");
	_addVector(v3,v2);
	printVector(v3);
	printf("\n");

	printf("Multiply ones by 10, then zero by mutiplying by 0 in place\n");
	Vector* v4 = scalarVector(10, v2);
	printVector(v4);
	_scalarVector(0,v2);
	printVector(v2);
	printf("\n");

	printf("Multiply a vector of 10s by a vector of 2s\n");
	Vector* v6 = multiplyVector(v4,v3);
	printVector(v6);
	printf("\n");

	printf("Square the previous vector (component-wise)\n");
	Vector* v7 = exponentVector(v6, 2);
	printVector(v7);
	printf("\n");

	printf("Take the vector of 2s to the first power\n");
	Vector* v8 = exponentVector(v3,1);
	printVector(v8);
	printf("Then to the 6th power in place\n");
	_exponentVector(v8,6);
	printVector(v8);
	printf("\n");

	printf("Take a zero vector to the 100 millionth power\n");
	Vector* v9 = exponentVector(zeroVector(9),100000000);
	printVector(v9);
	printf("\n");

	printf("Take a ones vector to the 100 millionth power\n");
	Vector* v10 = exponentVector(onesVector(9),100000000);
	printVector(v10);
	printf("\n");
	
	printf("Take a negative exponent of a vector (returns NULL because using ints)\n");
	Vector* v11 = exponentVector(zeroVector(9),-1);
	printVector(v11);
	printf("\n");
	
	printf("Concatenate two vectors and ensure the second is empty\n");
	concatVector(v6,v7);
	printVector(v6);
	printVector(v7);
	printf("\n");

	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(v6);
	free(v7);
	free(v8);
	free(v9);
	free(v10);
	free(v11);

	return 0;
}
