#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};


struct node* init(int data){
    struct node* nn=(struct node*)malloc(sizeof(struct node));    
    nn->data=data;
    nn->next=NULL;
    return nn;
}
void append_end(struct node** head,int data){
    struct node* nn=init(data);
    if(*head==NULL){
        *head=nn;
        return;
    }
    struct node* p=*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=nn;
 }

void traverse(struct node** head){
    struct node* p=*head;
    while(p!=NULL){
      for(int i=0;i<20;i++){
        printf("%d\t",p->data);
        p=p->next;
      }
    printf("\n");
    }
}

void swap(struct node *a, struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

void bubbleSort(struct node** head) 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  
    /* Checking for empty list */
    if (*head == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = *head; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 







int main(){
    struct node* head=NULL;
    for(int i=0;i<100;i++){
      append_end(&head,i);
    }
    traverse(&head);
    bubbleSort(&head);
    traverse(&head);


    return 0;
}
