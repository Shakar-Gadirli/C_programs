#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40

struct vector{
        char *buff[SIZE];
        int size;
        int pos;
        int count;
};

struct vector* init(int size){
    struct vector* v=(struct vector*)malloc(sizeof(struct vector));
    v->buff[SIZE]=(char*)malloc(sizeof(char)*size);
    for(int i=0;i<size;i++){
        v->buff[i]=(char*)malloc(sizeof(char)*SIZE);
    }
    v->pos=-1;
    v->count=0;
    v->size=size;
    return v;
}

void add(struct vector* v,char *string){
    if(v->pos>=v->size-1)
        return;
    v->pos=v->pos+1;
    strcpy(v->buff[v->pos],string);
}

void delete(struct vector* v){
    if(v->pos<0)
        return;
    v->pos=v->pos-1;
}

void display(struct vector* v){
    if(v->pos<0)
        return;
    for(int i=0;i<=v->pos;i++){
        printf("%s  ",v->buff[i]);
    }   
    printf("\n");
}


int main(){
    struct vector* v=init(6);
    add(v,"Shakar,");
    add(v,"You");
    add(v,"will");
    add(v,"pass");
    add(v,"the");
    add(v,"exam");
    display(v);
    delete(v);
    delete(v);
    add(v,"this");
    add(v,"**** exam");
    display(v);
    return 0;
}
