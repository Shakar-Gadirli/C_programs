#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
	double x;
	double y;
};

struct person{
	struct point** points;
	int pos;
};

struct point* init_p(double x, double y){
	struct point* pnt = (struct point*)malloc(sizeof(struct point));
	pnt->x = x;
	pnt->y = y;
	return pnt;
}

struct person* init(){
	struct person* p = (struct person*) malloc(sizeof(struct person));
	p->points = (struct point**) malloc(sizeof(struct point*)*1024);
	p->pos = -1;
	return p;
}

void walk(struct person* p, double x, double y){
	struct point* pnt = init_p(x,y);
	p->pos++;
	p->points[p->pos] = pnt;
}

double status(struct person* p){
	double dist=0, dx,dy;
	int i;
	for (i=0; i<p->pos; i++)
	{
	    dx = abs((p->points[i+1]->x)-(p->points[i]->x));
	    dy = abs((p->points[i+1]->y)-(p->points[i]->y));
		dist+=sqrt(dy*dy + dx*dx);
	}
	return dist;
}


int main(){
	struct person* p1 = init();
	 walk(p1,0,2 );
	walk(p1,3,6);
	walk(p1,3,8);
	printf("%.0f",status(p1));
	return 0;
}
