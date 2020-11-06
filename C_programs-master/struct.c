#include <stdio.h>
#include <string.h>
 struct Student{

	int age;
	char name[50];
	char spec[50];



}std;
 
void show(){
	std.age=18;
	scanf("%s",std.name);
	scanf("%s",std.spec);
	printf("Name: %s   Age: %d   Spec: %s",std.name,std.age,std.spec);

}

int  main(){
	show();	
}



/*

struct employee{

	char name[20];
	int salary;

}emp[5];






void input(){

	for(int i=0;i<3;i++){
		printf("Enter name of the employee\n");
		scanf("%s",emp[i+1].name);
		printf("Enter the salary of the employee\n");
		scanf("%d",&emp[i+1].salary);
	
	}


	for(int i=0;i<3;i++){

		printf("%d Name: %s Salary: %d  \n",i+1,emp[i+1].name,emp[i+1].salary);
	}
}


int main(){

	input();
	return 0;

}
*/


























