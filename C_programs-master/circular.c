#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* create(int data){
	struct node* temp=(struct node*)malloc(sizeof(struct node));	    temp->data=data;
	temp->link=NULL;
}

void traverse(struct node* head){
	while(head!=NULL){
		printf("%d",head->data);
		head=head->link;
	}
	printf("\n");

}
int detect_loop(struct node** head){
	struct node *p=*head, *q=*head;
	while(p && q && q->link){
		p=p->link;
		q=q->link->link;
		if(p==q){
			return 1;

		}
	}
return 0;
}


int main(){
	struct node* node1=create(12);
	struct node* node2=create(34);
	struct node* node3=create(76);
	node1->link=node2;
	node2->link=node3;
	struct node* head=node1;
	node3->link=node1;
	printf((detect_loop(&head) ? "yes" : "no"));
	return 0;




}
