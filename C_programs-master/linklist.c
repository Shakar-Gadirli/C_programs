#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{
    char data[128];
	struct	node* next;



};

struct node* create(char data[128]){
    struct node p;
	struct node* nn=(struct node*) malloc(sizeof(struct node));
	nn->next=NULL;
    strcpy(p.data,data);
	return nn;


}

void append(struct node **head,char data){
	struct node *nn=create(data);
	if(*head==NULL){
		(*head=nn);
		return;
	}
	struct node* temp=*head;
	while(temp->next!=NULL){	
	}
	temp->next=nn;

}

void traverse(struct node *head){
	struct node *temp = head;
	while(temp!=NULL){
		printf("%s",data);
		temp = temp->next;


	}
	printf("\n");




int main(){
	struct node* head=NULL;
    
    traverse(head);
	

	traverse(head);
	return 0;
}

