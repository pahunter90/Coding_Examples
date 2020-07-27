#include"Matrix.h"

int main()
{
	printf("Create a 3x3 zero matrix\n");
	Matrix* M1 = zeroMatrix(3,3);
	printMatrix(M1);
	printf("\n");

	printf("Create a 3x3 matrix of ones\n");
	Matrix* M2 = onesMatrix(3,3);
	printMatrix(M2);
	printf("\n");

	printf("Create the 3x3 identity matrix\n");
	Matrix* M3 = I(3);
	printMatrix(M3);
	printf("\n");

	printf("Multiply I(3) by 5\n");
	Matrix* M4 = scalarMatrix(5,M3);
	printMatrix(M4);
	printf("\n");

	printf("Multiply 5*I(3) by 5 in place\n");
	_scalarMatrix(5,M4);
	printMatrix(M4);
	printf("\n");

	printf("Add 5*I(3) with ones(3)\n");
	Matrix* M5 = addMatrix(scalarMatrix(5,I(3)),onesMatrix(3,3));
	printMatrix(M5);
	printf("\n");

	printf("Add a matrix of 2's to the previous matrix in place\n");
	_addMatrix(M5,scalarMatrix(2,onesMatrix(3,3)));
	printMatrix(M5);
	printf("\n");

	free(M1);
	free(M2);
	free(M3);
	free(M4);
	free(M5);

	return 0;
}
