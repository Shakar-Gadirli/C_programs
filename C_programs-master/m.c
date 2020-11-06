#include <stdio.h>
int main(){
	float grade=0, numberoftest=0,scoreentered=0,average=0;
	printf("press 0 if you want to exit\n\n");


	do{
		printf("Tests: %.0f Average: %.2f\n",numberoftest,average);
		
		printf("Enter your score: ");
		scanf("%f",&scoreentered);
		grade+=scoreentered;
		numberoftest++;
		average=grade/numberoftest;
		


	
	
	
	}while(scoreentered!=0);
	
	return 0;

}

