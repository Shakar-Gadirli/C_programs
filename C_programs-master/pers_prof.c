#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
	int data;
	char pass[20];
	char login[20];
};

struct person init(int data,char *login,char *pass){
	struct person p;
	p.data=data;
	strcpy(p.pass,pass);
	strcpy(p.login,login);
	return p;
}

struct person view(struct person p){
	printf("data : %d\n",p.data);
	printf("login %s\n",p.login);
	printf("pass %s\n",p.pass);
}

int main(){
	struct person p[100];
	p[0]=init(123,"jhg","886");
	p[1]=init(142,"hui","954");
	p[2]=init(828,"wjih","099");
	for(int i=0;i<3;i++){
		view(p[i]);
	}

}
