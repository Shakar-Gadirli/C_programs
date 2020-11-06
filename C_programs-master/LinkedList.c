#include<stdio.h>
#include<stdlib.h>

struct node{
    
    int data;
    struct node* next;
};



struct node* create(int data){

    struct node* nn = (struct node*) malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}


void append(struct node* head, int data){

    struct node* nn = create(data);
    struct node* temp = head;

    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp->next = nn;
}

void traverse(struct node* head){
    struct node* temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("/n");
}





int main(){

    struct node* n1 = create(23);
    struct node* n2 = create(33);
    struct node* n3 = create(45);

    n1->next = n2;
    n2->next = n3;

    struct node* head = n1;

    append(head, 88);
    append(head, 99);

    traverse(head);

return 0;
}
