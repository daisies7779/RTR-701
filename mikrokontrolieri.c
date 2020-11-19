//Lekcijas kods
#include <msp430.h>
int main()
{
  WDTCTL = WDTPW + WDTHOLD;
  volatile unsigned int j=0;
  P1DIR |= 0b10010001; 
  P2DIR &= ~0b00001000;
 for( ; ; )
 {
   //P1OUT ^= 0b00010001;
   for(j=30000;j>1;j--);//aizture
   if ((P2IN&0b00001000) == 0b00001000)
   {
     P1OUT |= 0b10000000;//ieslēgt 7.led
   }
   else
   {
     P1OUT &= ~0b10000000;
   }
   
 }
}
