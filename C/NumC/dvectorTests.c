#include"dVector.h"

int main()
{
	printf("\nCreate a zero vector\n");
	dVector* v1 = zerodVector(9);
	printdVector(v1,4);
	printf("\n");

	printf("Set it to two decimal places\n");
	printdVector(v1,2);
	printf("\n");

	printf("Create a vector of ones\n");
	dVector* v2 = onesdVector(9);
	printdVector(v2,4);
	printf("\n");

	printf("Set it to no decimal places\n");
	printdVector(v2,0);
	printf("\n");

	printf("Add a vector of zeros and ones\n");
	dVector* v3 = adddVector(v1,v2);
	printdVector(v3,4);
	printf("\n");

	printf("Add ones to the previous vector in place\n");
	_adddVector(v3,v2);
	printdVector(v3,4);
	printf("\n");

	printf("Multiply ones by 10, then zero by mutiplying by 0 in place\n");
	dVector* v4 = scalardVector(10, v2);
	printdVector(v4,4);
	_scalardVector(0,v2);
	printdVector(v2,4);
	printf("\n");

	printf("Multiply a vector of 10s by a vector of 2s\n");
	dVector* v6 = multiplydVector(v4,v3);
	printdVector(v6,4);
	printf("\n");

	printf("Square the previous vector (component-wise)\n");
	dVector* v7 = exponentdVector(v6, 2);
	printdVector(v7,4);
	printf("\n");

	printf("Take the vector of 2s to the first power\n");
	dVector* v8 = exponentdVector(v3,1);
	printdVector(v8,4);
	printf("Then to the 6th power in place\n");
	_exponentdVector(v8,6);
	printdVector(v8,4);
	printf("\n");

	printf("Take a zero vector to the 100 millionth power\n");
	dVector* v9 = exponentdVector(zerodVector(9),100000000);
	printdVector(v9,4);
	printf("\n");

	printf("Take a ones vector to the 100 millionth power\n");
	dVector* v10 = exponentdVector(onesdVector(9),100000000);
	printdVector(v10,4);
	printf("\n");
	
	printf("Take a negative exponent of a vector returns NULL to avoid divide by zero\n");
	dVector* v11 = exponentdVector(zerodVector(9),-1);
	printdVector(v11,4);
	printf("\n");
	
	printf("Concatenate two vectors and ensure the second is empty\n");
	concatdVector(v6,v7);
	printdVector(v6,4);
	printdVector(v7,4);
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
