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
