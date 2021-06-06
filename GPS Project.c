#include "stdint.h"
#include "math.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
#include "TM4C123GH6PM.h"



void delayMs(int n);
void delayUs(int n);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
	

	void initPORTF(void){ 
	
		SYSCTL_RCGCGPIO_R |= 0x00000020;      // activate clock for port F        
		while ((SYSCTL_PRGPIO_R&0x20) == 0){};// allow time for clock to start
		GPIO_PORTF_LOCK_R = 0x4C4F434B;       // unlock GPIO Port F
                GPIO_PORTF_CR_R = 0x1F;               // allow changes to PF4-0
		GPIO_PORTF_AMSEL_R = 0x00;            // disable analog on PF
		GPIO_PORTF_PCTL_R = 0x00000000;       // 
		GPIO_PORTF_DIR_R = 0x0E;   	         	// PF4, PF0 in, PF3-1 out
		GPIO_PORTF_AFSEL_R = 0x00;            // disable alt funct on PF7-0
                GPIO_PORTF_PUR_R = 0x11;              // enable pull-up on PF0, PF4
		GPIO_PORTF_DEN_R = 0x1F;              // enable digital I/O on PF4-0		
	}
	
	
	
	
  int X1 =40;
  int Y1 =20;
  int X2 =100;
  int Y2 =200;
	float Z = 0;
	void Distance (uint32_t x1,uint32_t y1, uint32_t x2,uint32_t y2){
		   Z = sqrt((pow((y2-y1), 2))+(pow((x2-x1),2)));
	}




int main(){
	initPORTF();
	LCD_init();
	while(1){
		Distance(X1,Y1,X2,Y2);
	    	if(Z > 100){
			GPIO_PORTF_DATA_R = GREEN;			
			LCD_command(1); /* clear display */
		        LCD_command(0x80); /* lcd cursor location */
		        delayMs(500);
		  	LCD_data('1');
        		LCD_data('5');
        		LCD_data('0');
		  	delayMs(500);
			}
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
