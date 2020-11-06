#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    struct node* next;
    char data;
};

struct node* init(char data){
    struct node* s=(struct node*)malloc(sizeof(struct node));
    s->next=NULL;
    s->data=data;
    return s;
}

void push(struct node** s,char data){
    struct node* nn=init(data);
    if(*s==NULL){
        *s=nn;
        return;
    }
    nn->next=(*s);
    (*s)=nn;

}

int top(struct node** s){
    return (*s)->data;
}

void pop(struct node** s){
    if(*s==NULL)
        return;
   struct node* temp=(*s);
    (*s)=(*s)->next;
    free(temp);
}

int check(char a,char b){
    if((a=='(' && b==')') ||
        (a=='{' && b=='}')||
        (a=='[' && b==']')||
        (a=='<' && b=='>'))
        return 1;
    return 0;
}

int main(){
    char exp[128]="{<[(<>)]>}";

    struct node* s=NULL;
    int flag=1;

    for(long i=0;i<strlen(exp);i++){
        if(exp[i]==')'|| exp[i]==']' || exp[i]=='}' || exp[i]=='>'){
            if(check(top(&s),exp[i])){
                pop(&s);
            }
            else{
                flag=0;
            }

        }
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{' || exp[i]=='<'){
                push(&s,exp[i]);
        
        }

    }
    if(s==NULL && flag==1){
        printf("Right order\n");
    }
    else{
        printf("Wrong order\n");
    }

}
