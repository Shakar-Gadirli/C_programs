#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* link;


};
struct node *head;

void append(){
	struct node* temp;
	struct node* p;
	temp=(struct node*) malloc(sizeof(struct node));
	 printf("Enter node element\n");
	 scanf("%d",&temp->data);

	 temp->link=NULL;

	 if(head==NULL){
		 head=temp;
	 }
	 else{
	 	  p=head;
		  while(p->link != NULL){
			p=p->link;
		  }
		 p->link=temp;
	 }
	 printf("\n");
}

void display(){
	struct node* temp;
	temp=head;
	if(temp==NULL)
		printf("List is empty\n");
	else
		while(temp!=NULL){
			printf("%d\t",temp->data);
			temp=temp->link;
		}
	printf("\n\n");


}

int length(){
	struct node* temp;
	int count=0;
	temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->link;
	}

	return count;

}

void delete(){
	struct node* temp;
	int ind;
	printf("Enter position of the node\n");
	scanf("%d",&ind);


	if(ind>length()){
		printf("Invalid index\n");
	}
	else if(ind==1){
		temp=head;
		head=temp->link;
		temp->link=NULL;
		free(temp);
	}

	else{
		struct node* p=head,*q;
		int i=1;
		while(i < ind-1){
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
		}



}



int main(){
	append();
	append();
	append();
	append();
	display();
	
	delete();

	display();
	


	return 0;
}
