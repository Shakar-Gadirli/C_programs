#include<stdio.h>
#include<string.h>

int main(){
	
	char str[200];
	int count = 0;
	printf("Enter the string:\n");
	scanf("%[^\n]s",str);
	
	// [^\n] MEANING = It means take one space
	// But until to a new line.

	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == ' ' && str[i+1] != ' '){
			count++;
		}
	}
	printf("\n");
	printf("Word count: %d\n",(count+1));
	return 0;
}
