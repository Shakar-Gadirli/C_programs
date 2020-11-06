#include <stdio.h>

int max(int num1,int num2){

	int output;
	if ( num1>num2)
		output=num1;
	else 
		output=num2;

	return output;


}





int main(){
	int x,y,out;
	scanf("%d",&x);
	scanf("%d",&y);

	out=max(x,y);
	
	printf("Maximum number : %d",out);
	
	
	
	return 0;
}
