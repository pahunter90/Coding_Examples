#include"Vector.h"

int main()
{
	Vector* v1 = zeros(9);
	printf("v1 = ");
	print(v1);
	printf("\n");

	Vector* v2 = ones(9);
	printf("v2 = ");
	print(v2);
	printf("\n");

	Vector* v3 = add(v1,v2);
	printf("v1 = ");
	print(v1);
	printf("v2 = ");
	print(v2);
	printf("v3 = ");
	print(v3);
	printf("\n");

	v3 = add(v2,v3);
	printf("v1 = ");
	print(v1);
	printf("v2 = ");
	print(v2);
	printf("v3 = ");
	print(v3);
	printf("\n");

	Vector* v4 = scalar(10, v2);
	printf("v2 = ");
	print(v2);
	printf("v4 = ");
	print(v4);
	printf("\n");

	Vector* v5 = scalar(0,v4);
	printf("v4 = ");
	print(v4);
	printf("v5 = ");
	print(v5);
	printf("\n");

	Vector* v6 = multiply(v4,v3);
	printf("v3 = ");
	print(v3);
	printf("v4 = ");
	print(v4);
	printf("v6 = ");
	print(v6);
	printf("\n");

	Vector* v7 = exponent(v6, 2);
	printf("v6 = ");
	print(v6);
	printf("v7 = ");
	print(v7);
	printf("\n");

	Vector* v8 = exponent(v3,1);
	printf("v3 = ");
	print(v3);
	printf("v8 = ");
	print(v8);
	printf("\n");

	Vector* v9 = exponent(zeros(9),100000000);
	printf("v9 = ");
	print(v9);
	printf("\n");

	Vector* v10 = exponent(ones(9),100000000);
	printf("v10 = ");
	print(v10);
	printf("\n");
	
	Vector* v11 = exponent(zeros(9),-1);
	printf("v11 = ");
	print(v11);
	printf("\n");
	
	Vector* v12 = exponent(scalar(2,ones(9)),-400000000);
	printf("v12 = ");
	print(v12);
	printf("\n");

	concat(v11,v12);
	printf("v11 = ");
	print(v11);
	printf("v12 = ");
	print(v12);
	concat(v6,v7);
	printf("v6 = ");
	print(v6);
	printf("v7 = ");
	print(v7);

	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(v5);
	free(v6);
	free(v7);
	free(v8);
	free(v9);
	free(v10);
	free(v11);
	free(v12);

	return 0;
}
