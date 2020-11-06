#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct coord{
	int x,y;
 };
struct person{
	struct coord** arr;
	int pos;
	int rad;
};

struct coord* init_coord(int x,int y){
	struct coord* c=(struct coord*)malloc(sizeof(struct coord));
	c->x=x;
	c->y=y;
	return c;
}

struct person* init_person(int rad){
	struct person* p=(struct person*)malloc(sizeof(struct person));
	p->arr=(struct coord**)malloc(sizeof(struct coord*)*30);
	p->pos=-1;
	p->rad=rad;
	return p;	
}

void move(struct person* p,int x,int y){
	struct coord* c=init_coord(x,y);
	p->pos=p->pos+1;
	p->arr[p->pos]=c;

}
int dist(struct coord* q,struct coord* f){
	int s_x=(f->x)-(q->x);
	int s_y=(f->y)-(q->y);
	 return sqrt(s_x*s_x+s_y*s_y);
	
}

int intersect(struct coord* q,struct coord* f,int r1,int r2){
	int d=dist(q,f);
	if(r1+r2>=d)
		return 1;
	else
		return 0;
}

void find(struct person* q,struct person* f){
	int q_pos=-1;
	int  f_pos=-1;
	for(int i=0;i<=q->pos;i++){
	for(int l=0;l<=f->pos;l++){
			if(intersect(q->arr[i],f->arr[l],q->rad,f->rad)){					      q_pos=i;
				break;
			}
		}
			if(q_pos!=-1)
			break;

	}
	for(int l=0;l<=f->pos;l++){
	for(int i=0;i<=q->pos;i++){
			if(intersect(q->arr[i],f->arr[l],q->rad,f->rad)){
			
				f_pos=l;
				break;
			}
		}
		if(f_pos!=-1)
			break;
	}
	if(q_pos!=-1 && f_pos!=-1){
		printf("P1 intersects p2 in step %d\n",q_pos);
		printf("P2 intersects p1 in step %d\n",f_pos);
	}
	else{
		printf("They don't see each other\n");
	}
}



int main(){

	struct person* q=init_person(2);
	struct person* f=init_person(1);
	move(q,3,1);
	move(q,2,7);
	move(q,8,5);
	move(f,1,2);
	move(f,4,5);
	move(f,5,7);
	
	find(q,f);
	return 0;
}
