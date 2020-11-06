#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ARRAY of person struct elements
struct person{
	char name[20];
	char surname[20];
	int age;
};

struct person* create(char *name, char *surname, int age){
	struct person *p=(struct person*)malloc(sizeof(struct person));
	strcpy(p->name,name);
	strcpy(p->surname,surname);
	p->age=age;
	return p;
}

struct vector{
	struct person *buff;
	int count_people;
	int pos;
};

struct vector *init(int people_num){
	struct vector *v=(struct vector*)malloc(sizeof(struct vector));
	v->buff=(struct person*)malloc(sizeof(struct person)*people_num);
	v->count_people=people_num;
	v->pos=-1;
	return v;
}

int main(){
	struct person *p1=create("name1", "Surname1", 18);
	struct person *p2=create("name2", "Surname2", 28);
	struct person *p3=create("name3", "Surname3", 38);

	struct vector *v=init(3);
	v->pos+=3;
	v->buff[0]=*p1;
	v->buff[1]=*p2;
	v->buff[2]=*p3;

	for(int i=0; i<=v->pos; i++){
		v->buff[i].age+=2;
        
	}
	for(int i=0; i<=v->pos; i++){
		printf("%d\n" ,v->buff[i].age);
        printf("%s\n",v->buff[i].surname);
	}

	return 0;
}
