#include <msp430g2202.h>

int i, j;
int min = 0;
int hour = 0;
//
/* Function Declarations */
 void display(unsigned char);
void delay(unsigned long);
void indication(unsigned char, unsigned char);

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD; // disable watchdog
  BCSCTL1 = CALBC1_12MHZ;//set timer frequency 12MHz
  DCOCTL = CALDCO_12MHZ;//set timer frequency 12MHz
  
  P1DIR = 0xFF;
  P2DIR = 0b00001111;
  P1OUT = 0x00;
  P2OUT &= 0xF0;
  P2OUT |= 0x01;
  
  int digit_position =0;
  for(;;) 
  {  
    j = hour / 10;
    i = hour % 10;
    indication(j,1);
    delay(5000);
    indication(i,2);    
    delay(5000);
      
    j = min / 10;
    i = min % 10;    
    indication(j,3);
    delay(5000);
    indication(i,4);    
    delay(5000);
   
        
    min = min + 1;
    if (min == 60)
    {
      min = 0;   
      hour = hour + 1;
      if (hour == 24) hour = 0;
    }
    //digit_position = (digit_position+1)%4;    
    }
}


void display(unsigned char digit)
{
  if(digit==0) P1OUT = 0xF5;
  if(digit==1) P1OUT = 0x05;
  if(digit==2) P1OUT = 0x73;
  if(digit==3) P1OUT = 0x57;
  if(digit==4) P1OUT = 0x87;
  if(digit==5) P1OUT = 0xD6;
  if(digit==6) P1OUT = 0xF6;
  if(digit==7) P1OUT = 0x45;
  if(digit==8) P1OUT = 0xF7;
  if(digit==9) P1OUT = 0xD7;
}


void delay(unsigned long ms)
{
  unsigned long ims;
  for(ims = 0; ims < ms; ims++)
  {
   __delay_cycles(120);//aizture par 120 taktīm
   //šeit ir divi undescori!!!
  }
}


void indication(unsigned char digit34, unsigned char which_digit)
{
  P2OUT &= ~0x0F;
  display(digit34);
  if(which_digit==1) P2OUT |= 0b00000001;
  if(which_digit==2) P2OUT |= 0b00000010;
  if(which_digit==3) P2OUT |= 0b00000100;
  if(which_digit==4) P2OUT |= 0b00001000;
}
