#include <string.h>
#include <stdio.h>
 
int main()
{
    char s1[1000],s2[1000];  
    int i,j;
 
    printf("Enter  s11: ");
    scanf("%s", s1);
    printf("Enter  s12: ");
    scanf("%s", s2);
    j=strlen(s1);
    
    for(i=0;s2[i]!='\0';i++)  
    {
    	s1[i+j]=s2[i];
	}
	s1[i+j]='\0';
 
    // printf("combined two s1s ='%s'\n",s1);
    
    char temp;
    
    int n = strlen(s1);
    
    for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (s1[i] > s1[j]) {
            temp = s1[i];
            s1[i] = s1[j];
            s1[j] = temp;
         }
      }
   }
   
      printf("%s \n", s1);

    
 
    return 0;
}
