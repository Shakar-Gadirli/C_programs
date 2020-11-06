#include <stdio.h>
#include <stdlib.h>
/*int add(int x,int y){
 int z=x+y;
 return z;


}


int multiply(int x,int y,int z){
	int m=z*x*y;
	return m;


}




int main(){
	int r1,r2,r3,r4;
	int (*ptr)(int,int);

	r1=add(10,20);
	r2=multiply(2,3,4);
	printf("%d %d",r1,r2);
	ptr=&add;
	r3=ptr(30,50);
	
	printf("r3 %d",r3);
	
	



	return 0;
}
*/

/*
struct Emp{
	int eno;
	char ename[20];
	float esal;



};

void main(){
	struct Emp* ptr;
	ptr=(struct Emp*)malloc(sizeof(struct Emp));
	if (ptr==NULL)
		printf("Out of memory\n");
	else
		printf("Enter emp details\n");
		scanf("%d %s %f",&ptr->eno,ptr->ename,&ptr->esal);
	printf("Emp no: %d Emp name: %s Emp sal: %f",ptr->eno,ptr->ename,ptr->esal);
	


}
*/





int main(){
	int capacity=5, *stack;
	stack=(int*)calloc(capacity,sizeof(int));
	for(int i=0;i<5;i++){
		scanf("%d",&stack[i]);
	
		printf("%d",*(stack+i));
	}
	capacity++;
	stack=(void*)realloc(stack,capacity*sizeof(int));
	printf("\n\n");
	for(int i=0;i<6;i++){
		scanf("%d",&stack[i]);

	
		printf("%d",*(stack+i));
	}




	return 0;
}


































