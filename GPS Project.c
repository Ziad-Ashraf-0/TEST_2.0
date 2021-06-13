#include "stdint.h"
#include "string.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
#include "TM4C123GH6PM.h"
#define BUFFER_LENGTH 127
#define pi 3.14159265358979323846

void delayMs(int n);
void delayUs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
double lantiude1;
double longitude1;
double lantiude2;
double longitude2;

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
int main(){
	double calcDistance;
	char distance1[10];
	initPORTF();
	LCD_init();
	UART5Init();
	
	
	while(1){
		       
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
