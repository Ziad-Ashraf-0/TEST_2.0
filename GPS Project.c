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

<<<<<<< HEAD
double deg2rad(double deg) {
  return (deg * pi / 180);
}
double rad2deg(double rad) {
  return (rad * 180 / pi);
} 
	
double distance(double lat1, double lon1, double lat2, double lon2) {
  double theta, dist;
  if ((lat1 == lat2) && (lon1 == lon2)) {
    return 0;
  }
  else {
    theta = lon1 - lon2;
    dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
    dist = acos(dist);
    dist = rad2deg(dist);
    dist = dist * 60 * 1.1515;
    dist = dist * 1609.344;
    return (dist);
  }
}
=======
void initPORTF(void){ 
	
		SYSCTL_RCGCGPIO_R |= 0x00000020;      // activate clock for port F        
		while ((SYSCTL_PRGPIO_R&0x20) == 0){};// allow time for clock to start
		GPIO_PORTF_LOCK_R = 0x4C4F434B;       // unlock GPIO Port F
    GPIO_PORTF_CR_R = 0x1F;               // allow changes to PF4-0
		GPIO_PORTF_AMSEL_R = 0x00;            // disable analog on PF
		GPIO_PORTF_PCTL_R = 0x00000000;       // 
		GPIO_PORTF_DIR_R = 0x0E;   	         	// PF3-1 out
		GPIO_PORTF_AFSEL_R = 0x00;            // disable alt funct on PF7-0
    GPIO_PORTF_PUR_R = 0x11;              // enable pull-up on PF0, PF4
		GPIO_PORTF_DEN_R = 0x1F;              // enable digital I/O on PF4-0		
	}
	
	void UART5Init(){
	  SYSCTL_RCGCUART_R |= 0x20;
		SYSCTL_RCGCGPIO_R |= 0x10;
		UART5_CTL_R &= ~UART_CTL_UARTEN;
		//Set BRD
		//BR = 9600 bits/sec
		//16*10*6 / (16*9600)= 104.16667
		UART5_IBRD_R = 104;
		UART5_FBRD_R = 11;
		
		UART5_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
		UART5_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
		
		GPIO_PORTE_AFSEL_R |= 0x30;
		GPIO_PORTE_PCTL_R = 0x00110000;
	  GPIO_PORTE_DEN_R |= 0x30;
	}

>>>>>>> 72a0f3ac75df05c9bdb8527ef714f3e61dcc4604

void getData(double *la,double *lo){
		char n[10];
		char e[10];
		char nfinal[10];
		char nfinaltry[10];
		char efinal[10];
		char efinaltry[10];
		int i;
		int k;
		int j;
    char b[30];
		char *ptr3;
		char *ptr;
		char *ptrf;
		char *ptr2;
		double lon1;
		double lat1;
		
		
	
		
			
	
		
	while(UART5_read()!='L'){
	    UART5_read();
	
	}while(UART5_read()!='L'){
	    UART5_read();
	
	}for(i=0;i<30;i++){
		b[i]=UART5_read();
	}
		
	
	
	
	for(j=0;j<10;j++){
		n[j]=b[j+1];
	
		
	}
	
	for(k=0;k<10;k++){
		e[k]=b[k+14];
		
	}
	
	nfinal[0]=n[0];
	nfinal[1]=n[1];
	
	
	
	nfinaltry[0]=n[2];
	nfinaltry[1]=n[3];
	nfinaltry[2]=n[4];
	nfinaltry[3]=n[5];
	nfinaltry[4]=n[6];
	nfinaltry[5]=n[7];
	nfinaltry[6]=n[8];
	nfinaltry[7]=n[9];
	
	
	
    
    lat1 = strtod(nfinaltry, &ptr);
    lat1 = lat1/60;
    
    sprintf(nfinaltry , "%lf" , lat1);
    
    nfinal[2]=nfinaltry[1];
    nfinal[3]=nfinaltry[2];
    nfinal[4]=nfinaltry[3];
    nfinal[5]=nfinaltry[4];
    nfinal[6]=nfinaltry[5];
    nfinal[7]=nfinaltry[6];
    nfinal[8]=nfinaltry[7];
    
    
    
    
    *la = strtod(nfinal, &ptrf);
    
    
    
    
    efinal[0]=e[0];
    efinal[1]=e[1];
    efinal[2]=e[2];
    
    
    efinaltry[0]=e[3];
    efinaltry[1]=e[4];
    efinaltry[2]=e[5];
    efinaltry[3]=e[6];
    efinaltry[4]=e[7];
    efinaltry[5]=e[8];
    efinaltry[6]=e[9];
    
    
	
    
    lon1 = strtod(efinaltry, &ptr2);
    lon1 = lon1/60;
    
    
    sprintf(efinaltry , "%lf" , lon1);
    
    efinal[3]=efinaltry[1];
    efinal[4]=efinaltry[2];
    efinal[5]=efinaltry[3];
    efinal[6]=efinaltry[4];
    efinal[7]=efinaltry[5];
    efinal[8]=efinaltry[6];
    
    
    
    
     *lo = strtod(efinal, &ptr3);
	
	 
	
	
	  
		
	
	
	/*for(j=0;j<30;j++){
		if(j==15){LCD_command(0xC0);LCD_data(b[15]);}else
	  LCD_data(b[j]);
	}*/
		
}







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
void LCD_init(void){
  SYSCTL_RCGCGPIO_R |= 0x00000003;
	GPIO_PORTA_DIR_R = 0xE0;     //set PORTA pin 7-5 as output
	GPIO_PORTA_DEN_R = 0xE0;     //set PORTA pin 7-5 as digital pins
	GPIO_PORTB_DIR_R = 0xFF;     //set all PORTB pins as output for data
	GPIO_PORTB_DEN_R = 0xFF;     //set all PORTB pins as digital pins
	delayMs(20); /* initialization sequence */
	LCD_command(0x30);
  delayMs(5);
  LCD_command(0x30);
  delayUs(100);
  LCD_command(0x30);
  LCD_command(0x38); // set 8-bit data, 2-line, 5x7 font 
  LCD_command(0x06); // move cursor right */
  LCD_command(0x01); //clear screen, move cursor to home 
  LCD_command(0x0F); // turn on display, cursor blinking *
}

void LCD_command(unsigned char command)
{
GPIO_PORTA_DATA_R = 0; /* RS = 0, R/W = 0 */
GPIO_PORTB_DATA_R = command;
GPIO_PORTA_DATA_R = 0x80; /* pulse E */
delayUs(0);
GPIO_PORTA_DATA_R = 0;
if (command < 4)
delayMs(2); /* command 1 and 2 needs up to 1.64ms */
else
delayUs(40); /* all others 40 us */
}
void LCD_data(unsigned char data)
{
GPIO_PORTA_DATA_R = 0x20; /* RS = 1, R/W = 0 */
GPIO_PORTB_DATA_R = data;
GPIO_PORTA_DATA_R = 0x80 | 0x20; /* pulse E */
delayUs(0);
GPIO_PORTA_DATA_R = 0;
delayUs(40);
}

uint8_t UART5_ReadAvailable(void){
		return ((UART5_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
	}
	
	char UART5_read(){
	  while(UART5_ReadAvailable() != 1 );
		return UART5_DR_R & 0xFF;
	}
	
	
	void UART5_write(char c){
	  while((UART5_FR_R&UART_FR_TXFF) !=0 );
		UART5_DR_R = c;
	} 
/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}
/* delay n microseconds (16 MHz CPU clock) */
void delayUs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3; j++)
{} /* do nothing for 1 us */
}


/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/* Grant coprocessor access */
/* This is required since TM4C123G has a floating point coprocessor */
SCB->CPACR |= 0x00f00000;
}


