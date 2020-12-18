#include <msp430.h>
int main(void) 
{
   WDTCTL = WDTPW + WDTHOLD;
   P1DIR |= BIT0;
   P2DIR |= (BIT2+BIT3);
   volatile unsigned int i;
   for(;;)
   {
     P1OUT ^= BIT0;
     P2OUT ^=  (BIT2+BIT3);
     //P2OUT ^=  ~(BIT2+BIT3); //izslegsana
     for(i=10000; i>1;i--);//aizture
    }
  }
