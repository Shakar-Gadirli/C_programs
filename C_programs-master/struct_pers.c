#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
	int x_pos,y_pos;
	int age;
	char name[20];
};
struct person init(int age,char *name){
	struct person p;
	p.age=age;
	strcpy(p.name,name);
	p.x_pos=0;
	p.y_pos=0;
	return p;

}
void move(struct person *p,int x,int y){
	(*p).x_pos+=x;
	(*p).y_pos+=y;

}
void get_status(struct person p){
	printf("%s\n",p.name);
	printf("age: %d\n",p.age);
	printf("x: %d y: %d\n",p.x_pos,p.y_pos);




}
int main(){
	struct person pr=init(19,"Paul");
	get_status(pr);

	move(&pr,2,5);
	get_status(pr);
	//printf("\n\n\n");

	move(&pr,10,15);
	get_status(pr);

return 0;
}
