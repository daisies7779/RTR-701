#include <msp430.h>
int main()
{
  WDTCTL = WDTPW + WDTHOLD;
  
 // 1.4.aktivitāte 
 //volatile unsigned int i=0;
 
 //Visus 8 pinus pasludinam par izejām
  P1DIR |= 0b11111111; 
 //pasludinam, ka visi pini tagad nav ieslēgti
  P1OUT &= ~0xFF; 
  
  //1.5 aktivitāte
  //P2DIR &= ~0b00001000; 
 
 for( ; ; )
 {
   //1.1.aktivitāte
   P1OUT |= 0b00000001; 
   
   //1.2.aktivitāte
   //iededzināt LED, kas pieslēgts P1.1.
   P1OUT |= 0b00000010;
   
   //1.3.aktivitāte
   // Iededzināt P1.1. un P1.0
   P1OUT |= 0b00000011; 
   
   
   //1.4.aktivitāte
  
   /*
   for(i=30000;i>1;i--);//aizture
   //pēc aiztures izslēdzam 1 LED
   P1OUT &= ~00000001; 
   
   for(i = 30000; i>1;i--); 
   
   //nokompilēt un ielādēt kontrolierī
   
  //kompaktākā versija
  // P1OUT ^= 0b00000001;
  // for(i = 30000; i>1;i--);   

   */
   
   //1.5aktivitate
   /*
   if ((P2IN&0b00001000) == 0b00001000)
 {
 P1OUT |= 0b10000000;//ieslēgt 7.led
 }
 else
 {
 P1OUT &= ~0b10000000;//izslēgt 7.led
 } 

   */
   
 }
}



//9lapaspuses uzdevumam kods
 P2SEL &= ~BIT7; //to use 2.7, 2.6 pins
 P2SEL &= ~BIT6; //to use 2.7, 2.6 pins

//likt beigās pēc aiztures
if(j==16),j=0;
