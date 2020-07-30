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
	printf("\n");

	printf("Determinant of two 3x3 matrices with known values\n");
	Matrix* M8 = blankMatrix(3,3);
	setVector(M8->data[0],0,1);
	setVector(M8->data[0],1,3);
	setVector(M8->data[0],2,-3);
	setVector(M8->data[1],0,-3);
	setVector(M8->data[1],1,-5);
	setVector(M8->data[1],2,2);
	setVector(M8->data[2],0,-4);
	setVector(M8->data[2],1,4);
	setVector(M8->data[2],2,-6);
	Matrix* M9 = blankMatrix(3,3);
	setVector(M9->data[0],0,0);
	setVector(M9->data[0],1,1);
	setVector(M9->data[0],2,3);
	setVector(M9->data[1],0,-2);
	setVector(M9->data[1],1,-3);
	setVector(M9->data[1],2,-5);
	setVector(M9->data[2],0,4);
	setVector(M9->data[2],1,-4);
	setVector(M9->data[2],2,4);
	int* detM8 = determinant(M8);
	int* detM9 = determinant(M9);
	printf("Determinant of M8 = %d and should be %d\n",detM8[0],40);
	printf("Determinant of M9 = %d and should be %d\n",detM9[0],48);
	printf("\n");

	printf("Determinant of a 4x4 matrix with known value\n");
	Matrix* M10 = blankMatrix(4,4);
	setVector(M10->data[0],0,2);
	setVector(M10->data[0],1,0);
	setVector(M10->data[0],2,0);
	setVector(M10->data[0],3,1);
	setVector(M10->data[1],0,0);
	setVector(M10->data[1],1,1);
	setVector(M10->data[1],2,3);
	setVector(M10->data[1],3,-3);
	setVector(M10->data[2],0,-2);
	setVector(M10->data[2],1,-3);
	setVector(M10->data[2],2,-5);
	setVector(M10->data[2],3,2);
	setVector(M10->data[3],0,4);
	setVector(M10->data[3],1,-4);
	setVector(M10->data[3],2,4);
	setVector(M10->data[3],3,-6);
	int* detM10 = determinant(M10);
	printf("Determinant of M10 = %d and should be %d\n",detM10[0],32);
	printf("\n");

	printf("Determinant of a 10x10 matrix with random values (-5 <= x < 5)\n");
	Matrix* M11 = blankMatrix(10,10);
	for(int i=0; i<M11->rows; i++)
	{
		for(int j=0; j<M11->rows; j++)
		{
			setVector(M11->data[i],j,rand()%10-5);
		}
	}
	int* detM11 = determinant(M11);
	printMatrix(M11);
	printf("Determinant of M11 = %d\n",detM11[0]);
	printf("\n");

	free(M1);
	free(M2);
	free(M3);
	free(M4);
	free(M5);
	free(M6);
	free(M7);
	free(M8);
	free(M9);
	free(M10);
	free(M11);

	return 0;
}
