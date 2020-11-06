#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
void list_dirs(char* path,int rec){
     DIR *dir=opendir(path);
     struct dirent* dir_walk;
     char *new_path;
        if(!dir)
            return;
        while((dir_walk=readdir(dir))!=NULL){
            if(rec){
            //printf("%s\n",dir_walk->d_name);
                if(strcmp(dir_walk->d_name,".")!=0 && strcmp(dir_walk->d_name,".."));
                    printf("%s\n",dir_walk->d_name);

                    strcpy(new_path,path);
                    strcat(new_path,"/");
                    strcat(new_path,dir_walk->d_name);
                    list_dirs(new_path,rec);
        }
            else{
                printf("%s"

        }
    closedir(dir);
}

int main(int argc,*argv[]){

    if(argc<2)
        return;
        list_dirs("~");
    
    
    list_dirs(argv[1]);

return 0;
}
