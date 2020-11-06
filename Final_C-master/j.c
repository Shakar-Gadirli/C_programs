#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 512

/*
 * THE CODES APPEND ALL THE TEXT FILES
 * TO THE FIRSTLY GIVEN FILE
 * HOW MANY FILES YOU WANT
*/

int main(int argc, char* argv[]){
	
	char name[20];
	strcpy(name, argv[1]);
	FILE *main = fopen(name, "a");
	
	for(int i = 2; i < argc; i++){
		strcpy(name, argv[i]);
		FILE *file = fopen(name, "r");
		
		char buff[SIZE];
		while(fgets(buff, SIZE, file)){
			fputs(buff, main);
		}
		fputs("\n",main);
		fclose(file);
	}
	fclose(main);
	return 0;
}
