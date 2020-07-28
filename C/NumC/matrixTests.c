#include"Matrix.h"
#include<malloc.h>
#include"leak_detector_c.h"

int main()
{
	atexit(report_mem_leak);

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

	printf("Create a non-squre matrix\n");
	Matrix* M6 = onesMatrix(6,3);
	printMatrix(M6);
	printf("\n");

	printf("Transpose the previous matrix\nFirst to a new matrix\n");
	Matrix* M7 = transpose(M6);
	printMatrix(M7);
	printf("then in place\n");
	_transpose(M6);
	printMatrix(M6);

	free(M1);
	free(M2);
	free(M3);
	free(M4);
	free(M5);
	free(M6);
	free(M7);

	return 0;
}
