#include<stdio.h>
#include<string.h>

struct profile{
	int data;
	char login[128];
	char password[128];

};


struct profile create(int data, char *login, char *password){
	struct profile p;
	p.data = data;
	strcpy(p.login, login);
	strcpy(p.password, password);
	return p;
} 


void view(struct profile p){
	printf("data: %d\n", p.data);
	printf("pass %s\n", p.login);
	printf("login %s\n", p.password);
}

int main(){

	struct profile p[100];

	p[0]  = create(123, "111", "222");
	p[1]  = create(432, "sim-sim", "321");
	p[2]  = create(432, "heee", "yreiuw");

	
	for(int i = 0; i < 3; i++){
	
		view(p[i]);	
	}



return 0;
}
