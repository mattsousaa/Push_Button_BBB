/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2017 20:05:55
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 * =====================================================================================
 */

#include "gpio.h"

int flag;

/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/
#define TIME /*2000000*/ 2000000
#define TOGGLE (0x01u)

/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
static void delay();
static void toggle(gpioPort port, ucPinNumber pin);
	
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main(void){
	//unsigned int port=GPIO0, pin=27, dir=OUTPUT;
	//unsigned int port = GPIO1;
	//unsigned int pin1 = 21;
	//unsigned int pin2 = 22;
	//unsigned int pin3 = 23;
	//unsigned int pin4 = 24;
	//unsigned int dir = OUTPUT;

	flag=0x0;	
	/*-----------------------------------------------------------------------------
	 *  initialize GPIO module
	 *-----------------------------------------------------------------------------*/
	//gpioInitModule(port);
	//gpioInitModule(port);

	/*-----------------------------------------------------------------------------
	 *  initialize pin of mudule
	 *-----------------------------------------------------------------------------*/
	//gpioInitPin(port, pin);
	//gpioInitPin(port, pin1);


	gpioInitModule(GPIO1);
	gpioInitPin(GPIO1, 28); // acende led
	gpioSetDirection(GPIO1, 28, OUTPUT);
	
	gpioInitModule(GPIO1); 
	gpioInitPin(GPIO1, 12); // botão
	gpioGetDirection(GPIO1, 12);

	/*-----------------------------------------------------------------------------
	 *  set pin direction 
	 *-----------------------------------------------------------------------------*/
	//gpioSetDirection(port, pin, dir);

	while(1){
		if(gpioGetPinValue(GPIO1, 12)){
			gpioSetPinValue(GPIO1, 28, HIGH);
		}
		else{
			gpioSetPinValue(GPIO1, 28, LOW);
		}
	}
	
	//while(true){
	//	toggle(GPIO1, 28);
	//	delay();
	//	toggle(GPIO1, 28);
	//	delay();
	//}

/* ######################################################## */

	//gpioInitModule(port);

	//gpioInitPin(port, pin2);

	//gpioSetDirection(port, pin2, dir);

/* ######################################################## */

	//gpioInitModule(port);

	//gpioInitPin(port, pin3);

	//gpioSetDirection(port, pin3, dir);

/* ####################################/#################### */

	//gpioInitModule(port);

	//gpioInitPin(port, pin4);

	//gpioSetDirection(port, pin4, dir);

/* ######################################################## */
/*
	while(true){
		toggle(port, pin4);
		delay();
		toggle(port, pin4);
		delay();

		toggle(port, pin3);
		delay();
		toggle(port, pin3);
		delay();

		toggle(port, pin2);
		delay();
		toggle(port, pin2);
		delay();

		toggle(port, pin1);
		delay();
		toggle(port, pin1);
		delay();
	}

	return(0); */
} /* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  toggle
 *  Description:  				
 * =====================================================================================
 */


void toggle(gpioPort port, ucPinNumber pin){
	flag^=TOGGLE;

	if(flag)
		gpioSetPinValue(port, pin, HIGH);
	else
		gpioSetPinValue(port, pin, LOW);	
}		/* -----  end of function GPIO_toggle  ----- */


/*FUNCTION*-------------------------------------------------------
*
* Function Name : Delay
* Comments      :
*END*-----------------------------------------------------------*/
static void delay(){
	volatile unsigned int ra;
	for(ra = 0; ra < TIME; ra ++);
}

