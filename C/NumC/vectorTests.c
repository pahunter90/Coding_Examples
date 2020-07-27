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
	printVector(v1);
	printVector(v2);
	printVector(v3);
	printf("\n");

	printf("Add ones to the previous vector in place\n");
	_addVector(v3,v2);
	printVector(v1);
	printVector(v2);
	printVector(v3);
	printf("\n");

	printf("Multiply ones by 10, then zero by mutiplying by 0 in place\n");
	Vector* v4 = scalarVector(10, v2);
	printVector(v2);
	printVector(v4);
	_scalarVector(0,v2);
	printVector(v2);
	printf("\n");

	Vector* v6 = multiplyVector(v4,v3);
	printVector(v3);
	printVector(v4);
	printVector(v6);
	printf("\n");

	Vector* v7 = exponentVector(v6, 2);
	printVector(v6);
	printVector(v7);
	printf("\n");

	Vector* v8 = exponentVector(v3,1);
	printVector(v3);
	printVector(v8);
	_exponentVector(v8,6);
	printVector(v8);
	printf("\n");

	Vector* v9 = exponentVector(zeroVector(9),100000000);
	printVector(v9);
	printf("\n");

	Vector* v10 = exponentVector(onesVector(9),100000000);
	printVector(v10);
	printf("\n");
	
	Vector* v11 = exponentVector(zeroVector(9),-1);
	printVector(v11);
	printf("\n");
	
	concatVector(v6,v7);
	printVector(v6);
	printVector(v7);

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
