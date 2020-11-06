#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h> 
#define GREEN "\x1b[32m"
#define WHITE "\x1b[37m"
#define BLUE "\x1b[34m"
#define FILENAMESIZE 128

void rec_dirs(char* path, int rec){

    DIR* dir = opendir(path);
    struct dirent* dir_p;
    char new_path[FILENAMESIZE];
    struct stat stat_;
    char buff[512];

    if (!dir)
        return;
    

    printf(BLUE "\n%s : \n" WHITE,path);
    while((dir_p = readdir(dir)) != NULL){
        if(rec==1){ 
            if(strcmp(dir_p->d_name, ".") != 0 && strcmp(dir_p->d_name, "..") !=0 ){
            
                printf(GREEN "\t%s\n" WHITE, dir_p->d_name);
                
                strcpy(new_path, path);
                strcat(new_path, "/");
                strcat(new_path, dir_p->d_name);
                rec_dirs(new_path, 1);
            }
        }

        else if(rec==2){
            
            sprintf(buff,"%s/%s",path,dir_p->d_name);
            stat(buff,&stat_);
            printf(GREEN "%zu\t" WHITE,stat_.st_size);
            printf(GREEN "\t%s\n" WHITE,dir_p->d_name);

        }
        else if(rec==0){

            printf("%s\n", dir_p->d_name);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]){
    
    char cwd[FILENAMESIZE];

    if(argc < 2 && getcwd(cwd, sizeof(cwd)) != NULL)
        //nothing
        rec_dirs(cwd, 0);
    
    else if(argc == 2){
        //only path  
        rec_dirs(argv[1], 0);
    }

    if(argc == 3){
        
        if(strcmp(argv[1], "-R") == 0)
        
            rec_dirs(argv[2], 1);
        else if(strcmp(argv[1],"-a")==0)
            rec_dirs(argv[2],2);

    }

return 0;
}
