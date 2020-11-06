#include<stdio.h>
#include<stdlib.h>
struct Emp{
	int eno;
	char ename[20];
	float esal;
};
int main(){
	struct Emp e;
	printf("Sizeof structure : %d\n",sizeof(e));
	printf("Sizeof structure: %d\n",sizeof(struct Emp));



return 0;
}
