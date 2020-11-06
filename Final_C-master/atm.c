#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum states{
	IDLE,
	CARD_INSERTED,
	PIN_ENTERED,
	OPTION_SELECTED,
	AMOUNT_ENTERED
};

char action[64];

void idle_state();
void card_inserted_state();
void pin_entered_state();
void option_selected_state();
void amount_entered_state();

void (*atm_state)()=idle_state;
enum states state=IDLE;

void idle_state(){
	printf("\n-> IDLE STATE <-\n");
	printf("Please insert the card\n");
	fgets(action, 64, stdin);
	if(strcmp(action, "i am inserting my card\n")==0)
		state=CARD_INSERTED;
	printf("-> CARD IS INSERTED <-\n");
}

void card_inserted_state(){
	printf("\n-> PIN ENTERING EVENT <-\n");
	printf("Please enter the pin\n");
	fgets(action, 64, stdin);
	if(strcmp(action, "8754635\n")==0){
		state=PIN_ENTERED;
		printf("-> PIN IS ENTERED <-\n");
	}
	else{
		printf("Warning: PIN is wrong\n");
	}
}

void pin_entered_state(){
	printf("\n-> OPTION SELECTION EVENT <-\n");
	printf("Please select the option\n");
	fgets(action, 64, stdin);//ex.: fill mobile cash
	state=OPTION_SELECTED;
	printf("-> OPTION IS SELECTED <-\n");
}

void option_selected_state(){
	printf("\n-> AMOUNT ENTERING EVENT <-\n");
	printf("Enter the amount of money\n");
	fgets(action, 64, stdin);
	state=AMOUNT_ENTERED;
	printf("-> MONEY IS ENTERED <-\n");
}

void amount_entered_state(){
	printf("\n-> DISPATCHING EVENT <-\n");
	char actn[64];
	for(int i=0; i<=strlen(action)-1; i++){
		if(action[i]=='\n'){
			actn[i]='\0';
			break;
		}
		actn[i]=action[i];
	}
	printf("ATM is dispatching %s$\n", actn);
	printf("Money is dispatched\n");
	printf("Thanks for using our services!\n");
	state=IDLE;
}

int main(){
	while(1){
		switch(state){
			case IDLE:
				atm_state=idle_state;
				break;
			case CARD_INSERTED:
				atm_state=card_inserted_state;
				break;
			case PIN_ENTERED:
				atm_state=pin_entered_state;
				break;
			case OPTION_SELECTED:
				atm_state=option_selected_state;
				break;
			case AMOUNT_ENTERED:
				atm_state=amount_entered_state;
				break;
		}
		atm_state();
	}

	return 0;
}
