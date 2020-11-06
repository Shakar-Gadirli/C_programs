#include <stdio.h>
#include <stdlib.h>

struct student{
	int sno;
	char sname[20];
	int smark[4];
};

void print_str(struct student s[3]){
	for(int i=0;i<3;i++){
		printf(" sno: %d,  sname: %s\n",s->sno,s->sname[20]);
		for(int i=0;i<4;i++){
			printf("%d th lesson: %d\n",s->smark[i]);

		}



}

int main(){
	struct student s[3];
	for(int i=0;i<3;i++){
		printf("enter details\n");
		scanf("%d",&(s->sno));
		scanf("%s",s->sname[20]);
		printf("Enter marks;\n");
		for(int i=0;i<4;i++)
		{
			scanf("%d",&(s->smark[i]));

		}
	}

	print_str(struct student s[3]);
}
