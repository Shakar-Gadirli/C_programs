#include <stdio.h>
#include<stdlib.h>

int main(){
    FILE *file = fopen("dummy.txt","w");
    printf("write: \n");
    char buff[128];
    fgets(buff,128,stdin);
    fputs(buff,file);
    fclose(file);

return 0;
}
