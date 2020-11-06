#include<stdio.h>

int main(){

	int a, b;
	a = 5;
	b = 6;
	
	printf("%d\n", a);
	printf("%p\n", &a);
	
	printf("-------------\n");
	int *x;

	x = &a;

	printf("%p\n", x);
	printf("%p\n", &x);
	printf("%d\n", *x);
    //=================
	*x = 333;

	printf("%d\n",a);
    //===============
	
	int **y;
	y = &x;

	printf("%d\n", **y);


return 0;

}
