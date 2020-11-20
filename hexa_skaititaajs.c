#include<msp430.h>
void delay(void);
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;
  P2DIR |= 0xF7;

   P2SEL &= ~BIT7; //to use 2.7, 2.6 pins
   P2SEL &= ~BIT6; //to use 2.7, 2.6 pins

  volatile unsigned char j = 0;
  for(;;)
  {
    
    P2OUT &= ~0xF7;
    if(j == 0)
    {
      P2OUT |= 0xF5;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 1)
    {
      P2OUT |= 0x05;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 2)
    {
      P2OUT |= 0x73;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 3)
    {
      P2OUT |= 0x57;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 4)
    {
      P2OUT |= 0x87;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 5)
    {
      P2OUT |= 0xD6;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 6)
    {
      P2OUT |= 0xF6;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 7)
    {
      P2OUT |= 0x45;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 8)
    {
      P2OUT |= 0xF7;
    }
    delay();
    P2OUT &= ~0xF7;
    j++;
    if(j == 9)
    {
      P2OUT |= 0xD7;
    }
    delay();
  }
}
   void delay(void)
//our written delay function
{
volatile unsigned int n;
for(n=0;n<60000;n++);
}
