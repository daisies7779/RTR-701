#include<msp430.h>
void delay(void);
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;
  P2DIR |= 0xF7;

   P2SEL &= ~BIT7; //to use 2.7, 2.6 pins
   P2SEL &= ~BIT6; //to use 2.7, 2.6 pins

    //Vizsledzam LED lampinjas
  //P1DIR |= 0b11111111; 
 //pasludinam, ka visi pini tagad nav ieslēgti
 // P1OUT &= ~0xFF; 

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

    P2OUT &= ~0xF7;
    j++;
    if(j == 10)
    {
      P2OUT |= 0xE7;
    }
    delay();

    P2OUT &= ~0xF7;
    j++;
    if(j == 11)
    {
      P2OUT |= 0xB6;
    }
    delay();

    P2OUT &= ~0xF7;
    j++;
    if(j == 12)
    {
      P2OUT |= 0xF0;
    }
    delay();


    P2OUT &= ~0xF7;
    j++;
    if(j == 13)
    {
      P2OUT |= 0x37;
    }
    delay();

    P2OUT &= ~0xF7;
    j++;
    if(j == 14)
    {
      P2OUT |= 0xF2;
    }
    delay();

    P2OUT &= ~0xF7;
    j++;
    if(j == 15)
    {
      P2OUT |= 0xE2;
    }
    delay();
 j++;
    if(j==16)
      j=0;



    
  }
}
   void delay(void)
//our written delay function
{
volatile unsigned int n;
for(n=0;n<60000;n++);
}
