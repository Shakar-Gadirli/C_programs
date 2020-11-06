#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void robot_off_state();
void robot_on_state();
void robot_turned_left_state();
void robot_turned_right_state();
void robot_moved_ahead();

enum states{
	OFF,
	ON_WAITING,
	TURN_RIGHT,
	TURN_LEFT,
	MOVE
};

void(*func_ptr)()=robot_off_state;
enum states state=OFF;
char action[64];

void robot_off_state(){
	printf("\nROBOT IS OFF\n");
	fgets(action, 64, stdin);
	if(strcmp(action, "turn on\n")==0){
		state=ON_WAITING;
		printf("ROBOT IS ON\n");
	}
}

void robot_on_state(){
	fgets(action, 64, stdin);
	if(strcmp(action, "move right\n")==0){
		state=TURN_RIGHT;
		printf("ROBOT MOVED RIGHT\n");
	}
	else if(strcmp(action, "move left\n")==0){
		state=TURN_LEFT;
		printf("ROBOT MOVED LEFT\n");
	}
	else if(strcmp(action, "turn off\n")==0){
		state=OFF;
	}
	else if(strcmp(action, "move head\n")==0){
		state=MOVE;
		printf("ROBOT MOVED AHEAD\n");
	}
}

void robot_turned_left_state(){
	fgets(action, 64, stdin);
	if(strcmp(action, "move left\n")==0){
		state=TURN_LEFT;
		printf("ROBOT MOVED LEFT ONCE AGAIN\n");
	}
	else if(strcmp(action, "move right\n")==0){
		state=TURN_RIGHT;
		printf("ROBOT MOVED RIGHT\n");
	}
	else if(strcmp(action, "turn off")==0){
		state=OFF;
	}
	else if(strcmp(action, "move ahead\n")==0){
		state=MOVE;
		printf("ROBOT MOVED AHEAD\n");
	}
}

void robot_turned_right_state(){
	fgets(action, 64, stdin);
	if(strcmp(action, "move left\n")==0){
		state=TURN_LEFT;
		printf("ROBOT MOVED LEFT\n");
	}
	else if(strcmp(action, "move right\n")==0){
		state=TURN_RIGHT;
		printf("ROBOT MOVED RIGHT ONCE AGAIN\n");
	}
	else if(strcmp(action, "turn off\n")==0){
		state=OFF;
	}
	else if(strcmp(action, "move ahead\n")==0){
		state=MOVE;
		printf("ROBOT MOVED AHEAD\n");
	}
}

void robot_moved_ahead(){
	fgets(action, 64, stdin);
	if(strcmp(action, "move right\n")==0){
		state=TURN_RIGHT;
		printf("ROBOT MOVED RIGHT\n");
	}
	else if(strcmp(action, "move left\n")==0){
		state=TURN_LEFT;
		printf("ROBOT MOVED LEFT\n");
	}
	else if(strcmp(action, "move ahead\n")==0){
		state=MOVE;
		printf("MOVED AHEAD ONCE AGAIN\n");
	}
	else if(strcmp(action, "turn off\n")==0){
		state=OFF;
	}
}

int main(){
	while(1){
		switch(state){
			case OFF:
				func_ptr=robot_off_state;
				break;
			case ON_WAITING:
				func_ptr=robot_on_state;
				break;
			case  TURN_RIGHT:
				func_ptr=robot_turned_right_state;
				break;
			case TURN_LEFT:
				func_ptr=robot_turned_left_state;
				break;
			case MOVE:
				func_ptr=robot_moved_ahead;
				break;
			default:
				break;
		}
		func_ptr();
	}

	return 0;
}
