/*
 * GccApplication2.c
 *
 * Created: 16-May-19 3:25:02 PM
 * Author : JAYASREE
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA=0X0F; /*Make PORTA lower pins as o/p*/
	int period=2;
    /* Replace with your application code */
    while (1) 
    {
		/*Rotate Stepper motor clockwise with half step sequence*/
		for(int i=0;i<50;i++)
		{
			PORTA=0X09;
			_delay_ms(period);
			PORTA=0X08;
			_delay_ms(period);
			PORTA=0X0C;
			_delay_ms(period);
			PORTA=0X06;
			_delay_ms(period);
           PORTA=0X04; 
	       _delay_ms(period);
		   PORTA=0X02;
		   _delay_ms(period);
		   PORTA=0X03;
		   _delay_ms(period);
		   PORTA=0X01;
		   _delay_ms(period);
		}
          PORTA=0X09; /*Last step to initial position*/
		  _delay_ms(period);
		  _delay_ms(1000);
	 /*Rotate stepper motor Anti clockwise with Full step sequence*/
          for(int i=0;i<50;i++)
		  {
			  
			 PORTA=0X01;
			 _delay_ms(period);
			 PORTA=0X03;
			 _delay_ms(period);
			 PORTA=0X02;
			 _delay_ms(period);
			 PORTA=0X04;
			 _delay_ms(period);
			 PORTA=0X06;
			 _delay_ms(period);
			 PORTA=0X0C;
			 _delay_ms(period);
			 PORTA=0X08;
			 _delay_ms(period);
			 PORTA=0X09;
			 _delay_ms(period); 
		  }
		  PORTA=0X09; /*First step to initial position*/
		  _delay_ms(period);
		  _delay_ms(1000);
	}
}


