#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct coord{
	float x,y;
};
struct person{
	struct coord** arr;
	int pos;
};
struct coord* init_coord(float x,float y){
	struct coord* c=(struct coord*)malloc(sizeof(struct coord));
	c->x=x;
	c->y=y;
	return c;
}

struct person* init_person(int size){
	struct person* p=(struct person*)malloc(sizeof(struct person));
	p->arr=(struct coord**)malloc(sizeof(struct person*)*size);	   p->pos=-1;
	return p;
}
void move(struct person* p,float x,float y){
	struct coord* c=init_coord(x,y);
	p->pos=p->pos+1;
	p->arr[p->pos]=c;
}

float distance(struct person* p){
	float d=0;
	float s_x;
	float s_y;
	for(int i=0;i<p->pos;i++){
		s_y=(p->arr[i+1]->y)-(p->arr[i]->y);
		s_x=(p->arr[i+1]->x)-(p->arr[i]->x);
		d=d+sqrt(s_x*s_x+s_y*s_y);

	}
	return d;

}

int  main(){
	struct person* q=init_person(28);
	move(q,4,6);
	move(q,9,12);
	move(q,15,19);
	printf("%.2f\n",distance(q));
	

return 0;


}
