#include<stdio.h>

enum state{OFF,ON,BLINK};



void lamp_off();
void lamp_on();
void lamp_blink();

void (*lamp_state)()=lamp_off;

enum state global_state=OFF;
int change_state=0;

int main(){
    
    while(1){
        if(global_state==OFF)
            lamp_state=lamp_off;
        if(global_state==ON)
            lamp_state=lamp_on;
        if(global_state==BLINK)
            lamp_state=lamp_blink;
        
        scanf("%d",&change_state);
        lamp_state();
     
        
    }

    return 0;
}

void lamp_on(){
    //printf("lamp on\n");
    global_state = ON;
    printf("lamp on\n");
    if(change_state)
        global_state = BLINK;
}
void lamp_off(){
    //printf("lamp off\n");
    global_state = OFF;
    printf("lamp off\n");

    if(change_state)
        global_state = ON;

}
void lamp_blink(){
   // printf("lamp blink\n");
    global_state = BLINK;
    printf("LAmp blink\n");
        if(change_state)
            global_state = OFF;
}
