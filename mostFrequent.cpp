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

//Define counters
volatile int count1 = 0;
volatile int count2 = 0;
volatile int count3 = 0;
volatile int countmax = 0;


void updateLEDs(){
    //Write your code here
    red = 0;
    yellow = 0;
    blue = 0;
    
    if(count1 == countmax) red = 1;
    if(count2 == countmax) yellow = 1;
    if(count3 == countmax) blue = 1;
}


//Define ISRs for the interrupts
void button_1_handler(){
	
	//Write your code here
	count1++;
	if(count1 > countmax) countmax = count1;
	updateLEDs();
	
}

void button_2_handler(){
	
	//Write your code here
	count2++;
	if(count2 > countmax) countmax = count2;
	updateLEDs();
	
}

void button_3_handler(){
	
	//Write your code here
	count3++;
	if(count3 > countmax) countmax = count3;
	updateLEDs();
	
}

void button_4_handler(){
	
	//Write your code here
	count1 = 0;
	count2 = 0;
	count3 = 0;
	countmax = 0;
	
	red = 0;
	yellow = 0;
	blue = 0;
	
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
		
	//Initially turn off all LEDs and set all the counters to 0
	
	//Write your code here
	button_4_handler();

	//Interrupt handlers
	
	//Write your code here
    b1.rise(&button_1_handler);
    b2.rise(&button_2_handler);
    b3.rise(&button_3_handler);
    b4.rise(&button_4_handler);
    
	//wait 100 ms
	while(1)
		wait_ms(100);
}
