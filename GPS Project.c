//liberaries
#include "stdint.h"
#include "string.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"

//defines
#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
#include "TM4C123GH6PM.h"
#define BUFFER_LENGTH 127
#define pi 3.14159265358979323846

//prototypes
void delayMs(int n);
void delayUs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
double lantiude1;
double longitude1;
double lantiude2;
double longitude2;

int main(){
	double calcDistance;
	char distance1[10];
	initPORTF();
	LCD_init();
	UART5Init();
	while(1)
	{	       
		GPIO_PORTF_DATA_R = GREEN;			
		LCD_command(1); /* clear display */
		LCD_command(0x80); /* lcd cursor location */
		delayMs(1000);
		getData(&lantiude1,&longitude1); 
		delayMs(3000);
		getData(&lantiude2,&longitude2);
		delayMs(3000);
		calcDistance = distance( lantiude1, longitude1, lantiude2,  longitude2);
		delayMs(3000);
		sprintf(distance1 , "%lf" , calcDistance);
		delayMs(1000);
		LCD_data(distance1[0]);
		LCD_data(distance1[1]);
		LCD_data(distance1[2]);
		LCD_data(distance1[3]);
		LCD_data(distance1[4]);
	}		
}
