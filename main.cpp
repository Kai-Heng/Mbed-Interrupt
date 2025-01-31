#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6 
#define BUTTON_3 p7 
#define BUTTON_4 p8 

#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11

//Define outputs

//Write your code here
DigitalOut red(RED_LED);
DigitalOut yellow(YELLOW_LED);
DigitalOut blue(BLUE_LED);

//Define interrupt inputs
//Write your code here
InterruptIn b1(BUTTON_1);
InterruptIn b2(BUTTON_2);
InterruptIn b3(BUTTON_3);
InterruptIn b4(BUTTON_4);



//Define ISRs for the interrupts
void button_1_handler(){
	
	//Write your code here
	red = !red;
	
}

void button_2_handler(){
	
	//Write your code here
	yellow = !yellow;
	
}

void button_3_handler(){
	
	//Write your code here
	blue = !blue;
	
}

void button_4_handler(){
	
	//Write your code here
	red = !red;
	yellow = !yellow;
	blue = !blue;
	
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
		
	//Initially turn off all LEDs
	//Write your code here
	red, yellow, blue = 0;

	//Interrupt handlers
	//Attach the address of the ISR to the rising edge
	//Write your code here
	b1.rise(&button_1_handler);
	b2.rise(&button_2_handler);
	b3.rise(&button_3_handler);
	b4.rise(&button_4_handler);
	

	
	//wait 100 ms
	while(1)
		wait_ms(100);
}

