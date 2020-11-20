//binaars_skaitiitaajs
#include <msp430.h>
void delay(void);
int main(void) {
 WDTCTL = WDTPW + WDTHOLD;// StopWatchdogTim
 
 
 //P1DIR |= BIT0;//SetP1.0 to output direction
 //P1DIR |= BIT1;//SetP1.1 to output direction
 
 // pashi defineejiet P1.2  P1.7
 //Visus 8 pinus pasludinam par izejām
  P1DIR |= 0b11111111; 
  //pasludinam, ka visi pini tagad nav ieslēgti
   P1OUT &= ~0xFF; 
 
 //delay();

//P1OUT |= BIT4; 
 
volatile unsigned char j=0;
for(;;)
 {
 j++;
 P1OUT = j;
 delay();
 }
 
}
void delay(void)
//our written delay function
{
volatile unsigned int n;
for(n=0;n<60000;n++);
}
