#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
	double x;
	double y;
};

struct person{
	struct point** points;
	int rad;
	int pos;
};

struct point* init_p(double x, double y){
	struct point* pnt = (struct point*)malloc(sizeof(struct point));
	pnt->x = x;
	pnt->y = y;
	return pnt;
}

struct person* init(int rad){
	struct person* p = (struct person*) malloc(sizeof(struct person));
	p->points = (struct point**) malloc(sizeof(struct point*)*1024);
	p->pos = -1;
	p->rad = rad;
	return p;
}

void walk(struct person* p, double x, double y){
	struct point* pnt = init_p(x,y);
	p->pos++;
	p->points[p->pos] = pnt;
}

double distance(struct point* p1, struct point* p2){
    double dx = abs((p2->x)-(p1->x));
    double dy = abs((p2->y)-(p1->y));
	return sqrt(dy*dy + dx*dx);
}

int check(struct point* p1, struct point* p2, double rad1, double rad2){
    double dist = distance(p1,p2);
    if (rad1+rad2 >= dist)
        return 1;
    else
        return 0;
}

double status(struct person* p1, struct person* p2){
	int i, j, p1_pos = -1, p2_pos = -1;
	for (i=0; i<=p1->pos; i++){
        for (j=0; j<=p2->pos; j++){
            if (check(p1->points[i], p2->points[j], p1->rad, p2->rad)){
                p1_pos = i;
                break;
            }
        }
            if (p1_pos != -1)
                break;
	}

	for (j=0; j<=p2->pos; j++){
        for (i=0; i<=p1->pos; i++){
            if (check(p1->points[i], p2->points[j],p1->rad, p2->rad)){
                p2_pos = j;
                break;
            }
        }
        if (p2_pos != -1)
            break;
	}
	if (p1_pos !=-1 && p2_pos != -1)
        printf("Person 1 sees person 2 in step %d. \nPerson 2 sees person 1 in step %d.", p1_pos, p2_pos );
	else
        printf("There is no such point");
}


int main(){
	struct person* p1 = init(2);
	struct person* p2 = init(1.5);
	walk(p1,0,2 );
	walk(p1,0.5,1.3);
	walk(p1,0.8,2);
	walk(p2,4,2);
	walk(p2,4,4);
	status(p1,p2);
	return 0;
}
