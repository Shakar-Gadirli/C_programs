#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;

};


struct node* init(int data){
    struct node* nn=(struct node*)malloc(sizeof(struct node*));
    nn->next=NULL;
    nn->data=data;
    return nn;
}
struct node* addtoempty(struct node* last,int data){
    struct node* nn=init(data);
    last=nn;
    last->next=last;
    return last;
}

struct node* addBegin(struct node* last,int data){
    struct node* nn=init(data); 
    if(last==NULL){
       return addtoempty(last,data);

    }
    nn->next=last->next;
    last->next=nn;
    return last;
}

struct node* addEnd(struct node* last,int data){
    struct node* nn=init(data);
    if(last==NULL)
        return addtoempty(last,data);
    
    nn->next=last->next;
    last->next=nn;
    last=nn;
    return last;
}

struct node* add_after(struct node* last,int item,int data){
    struct node* nn=init(data);
    struct node* temp=last->next;
 //   struct node* prev=last;
    temp=last->next;
    
    do{
        if(temp->data==item){
                nn->next=temp->next;
                temp->next=nn;

                if(temp==last)
                    last=temp;
                return last;
        }
        temp=temp->next;


    }while(temp!=last->next);

    printf("Not present in the list\n");

    return last;
}

void traverse(struct node* last){
    if(last==NULL)
        return;
    struct node* p=last;
    do{
        printf("%d\t",p->data);
        p=p->next;
    }while(p!=last->next);
}

int main(){
    struct node* last=NULL;
    addtoempty(last,4);
    traverse(last);
    addEnd(last,5);
    addEnd(last,6);
    addEnd(last,7);
    addEnd(last,8);
    traverse(last);

return 0;
}
