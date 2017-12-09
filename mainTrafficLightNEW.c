//TEJ3M mainTrafficLights.c
/*********************************************************************
Module:
 main()

Author - Shreyans Rishi
Date - June 13, 2014

Explain Operation of Program here:
Creates a traffic light simulator with pedestrian, adavanced green
 and Railway Crossing options.

Hardware Notes:
 * PIC used
     PIC24FV32KA302 operating at 8MHz
 * I/O ports used and hardware attached
     Output:
           RB6 - RB11 connected to different LEDs
           RB2 & RB3 - Connected to two red LEDs for railway crossing

********************************************************************/

/*******************************************************************
	Include Files
********************************************************************/

#include "p24FV32KA302.h"
#include "configBits.h"
#include "delay.h"
#define GREEN_DELAY 5000
#define YELLOW_DELAY 2000
#define RED_DELAY 3000

/*******************************************************************
	Symbolic Constants used by main()
********************************************************************/

//leave blank for now

/*******************************************************************
	Local Function Prototypes
********************************************************************/
void initTimer (void);
void greenEastWest ();
void greenNorthSouth ();
void yellowEastWest ();
void yellowNorthSouth();
void redEastWest ();
void redNorthSouth ();
void blankEastWest ();
void blankNorthSouth ();
void pedestrianEastWest ();
void pedestrianNorthSouth ();
void advancedGreenNorthSouth ();
void railwayLights ();
void regularLights();

//leave blank for now

/*******************************************************************
	Global Variable Declarations
********************************************************************/

// variables declared go here, before main ()

/*******************************************************************
	main() function
********************************************************************/

int main (void)
{
//initialize peripherals
initTimer();
//PORTB all outputs
TRISB=0;
// initialize PORTB
LATB=0;
//PORTA all digital inputs
TRISA=0xFF;
ANSA=0;


while(1)
{
while  (PORTAbits.RA0 == 0 && PORTAbits.RA1==0 && PORTAbits.RA2==0
&& PORTAbits.RA4==0)
regularLights();

while (PORTAbits.RA0 == 1 && PORTAbits.RA1==0 && PORTAbits.RA2==0
&& PORTAbits.RA4==0)
pedestrianEastWest();

while (PORTAbits.RA0 == 0 && PORTAbits.RA1==1 && PORTAbits.RA2==0
&& PORTAbits.RA4==0)
pedestrianNorthSouth();

while (PORTAbits.RA0 == 0 && PORTAbits.RA1==0 && PORTAbits.RA2==1
&& PORTAbits.RA4==0)
advancedGreenNorthSouth();

while (PORTAbits.RA0 == 0 && PORTAbits.RA1==0 && PORTAbits.RA2==0
&& PORTAbits.RA4==1)
railwayLights();
}
} // end mainTemplate.c

/*******************************************************************
	List of Functions
********************************************************************/

void greenEastWest (void)
{
LATBbits.LATB11=1; //EAST AND WEST GREEN
}


void greenNorthSouth(void)
{
LATBbits.LATB6=1; //NORTH AND SOUTH GREEN
}


void yellowEastWest (void)
{
LATBbits.LATB10=1; //EAST AND WEST YELLOW
}


void yellowNorthSouth (void)
{
LATBbits.LATB7=1; //NORTH AND SOUTH YELLOW
}


void redEastWest (void)
{
LATBbits.LATB9=1; //EAST AND WEST RED
}


void redNorthSouth (void)
{
LATBbits.LATB8=1; //NORTH AND SOUTH RED
}

void blankEastWest (void)
{
LATBbits.LATB11=0; //EAST AND WEST RED
LATBbits.LATB10=0; //EAST AND WEST YELLOW
LATBbits.LATB9=0; //EAST AND WEST GREEN
}

void blankNorthSouth (void)
{
LATBbits.LATB8=0; //NORTH AND SOUTH RED
LATBbits.LATB7=0; //NORTH AND SOUTH YELLOW
LATBbits.LATB6=0; //NORTH AND SOUTH GREEN
}

void regularLights (void)
{
blankNorthSouth();
blankEastWest();
greenEastWest();
redNorthSouth ();
delay (GREEN_DELAY);
blankEastWest();
yellowEastWest();
delay (YELLOW_DELAY);
blankEastWest();
redEastWest();
delay (RED_DELAY);
blankNorthSouth();
blankEastWest();
//Transition between East/West to North/South
blankNorthSouth();
blankEastWest();
greenNorthSouth();
redEastWest();
delay (GREEN_DELAY);
blankNorthSouth();
yellowNorthSouth();
delay (YELLOW_DELAY);
blankNorthSouth();
redNorthSouth();
delay (RED_DELAY);
}


void pedestrianEastWest (void)
{
blankNorthSouth();
blankEastWest();
redNorthSouth();
LATBbits.LATB10=1; //WEST YELLOW
delay(500);
LATBbits.LATB10=0; //WEST YELLOW
delay(500);
LATBbits.LATB10=1; //WEST YELLOW
delay(500);
LATBbits.LATB10=0; //WEST YELLOW
delay(500);
LATBbits.LATB10=1; //WEST YELLOW
delay(500);
LATBbits.LATB10=0; //WEST YELLOW
delay(500);
blankNorthSouth();
blankEastWest();
greenNorthSouth();
redEastWest();
delay (GREEN_DELAY);
blankNorthSouth();
yellowNorthSouth();
delay (YELLOW_DELAY);
blankNorthSouth();
redNorthSouth();
delay (RED_DELAY);
}

void pedestrianNorthSouth (void)
{
blankNorthSouth();
blankEastWest();
redEastWest();
LATBbits.LATB7=1; //NORTH YELLOW
delay (500);
LATBbits.LATB7=0; //NORTH YELLOW
delay (500);
LATBbits.LATB7=1; //NORTH YELLOW
delay (500);
LATBbits.LATB7=0; //NORTH YELLOW
delay (500);
LATBbits.LATB7=1; //NORTH YELLOW
delay (500);
LATBbits.LATB7=0; //NORTH YELLOW
delay (500);
blankNorthSouth();
blankEastWest();
}

void advancedGreenNorthSouth (void)
{
blankNorthSouth();
blankEastWest();
LATBbits.LATB6=1; //NORTH GREEN
LATBbits.LATB9=1; //EAST RED
delay(500);
LATBbits.LATB6=0; //NORTH GREEN
LATBbits.LATB9=1; //EAST RED
delay(500);
LATBbits.LATB6=1; //NORTH GREEN
LATBbits.LATB9=1; //EAST RED
delay(500);
LATBbits.LATB6=1; //NORTH GREEN
LATBbits.LATB9=1; //EAST RED
delay(500);
LATBbits.LATB6=0; //NORTH GREEN
LATBbits.LATB9=1; //EAST RED
delay(500);
LATBbits.LATB6=1; //NORTH GREEN
LATBbits.LATB9=1; //EAST RED
delay(500);
LATBbits.LATB6=0; //NORTH GREEN
LATBbits.LATB9=1; //EAST RED
delay(500);
}

void railwayLights (void)
{
blankEastWest();
blankNorthSouth();
LATBbits.LATB2=1; //LEFT RED
LATBbits.LATB3=0; //RIGHT RED
delay(1000);
LATBbits.LATB2=0; //LEFT RED
LATBbits.LATB3=1; //RIGHT RED
delay(1000);
LATBbits.LATB2=1; //LEFT RED
LATBbits.LATB3=0; //RIGHT RED
delay(1000);
LATBbits.LATB2=0; //LEFT RED
LATBbits.LATB3=1; //RIGHT RED
delay(1000);
LATBbits.LATB2=0; //LEFT RED
LATBbits.LATB3=0; //RIGHT RED
}




