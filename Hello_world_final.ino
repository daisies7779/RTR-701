#include <msp430.h>
int main()
{
  WDTCTL = WDTPW + WDTHOLD;
  
 // 1.4.aktivitāte 
 volatile unsigned int i=0;
 
 //Visus 8 pinus pasludinam par izejām
  P1DIR |= 0b11111111; 
 //pasludinam, ka visi pini tagad nav ieslēgti
  P1OUT &= ~0xFF; 
  
  //1.5 aktivitāte
  P2DIR &= ~0b00001000; 
  
  for( ; ; )
 {
   //1.1.aktivitāte
   //P1OUT |= 0b00000001; 
   
   //1.2.aktivitāte
   //iededzināt LED, kas pieslēgts P1.1.
   //P1OUT |= 0b00000010;
   
   //1.3.aktivitāte
   // Iededzināt P1.1. un P1.0
    P1OUT |= 0b00000011; 
   
   
   //1.4.aktivitāte
 
   
    //for(i=30000;i>1;i--);//aizture
   //pēc aiztures izslēdzam 1 LED
     //P1OUT &= ~00000001; 
   
   //for(i = 30000; i>1;i--); 
   
   //nokompilēt un ielādēt kontrolierī
   
  //kompaktākā versija
    P1OUT ^= 0b00000001;
    for(i = 30000; i>1;i--);   
  
   
   //1.5aktivitate skat modificéto versiju 1.6.
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

 //1.6.aktivitate
 //POGA nav nospiesta, LED7 un LED6 spid
 //POGA ir nospiesta LED7 un LED 6 nespid
 /*
 for(i=30000;i>1;i--);//aizture
    if ((P2IN&0b00001000) == 0b00001000)
 {
  P1OUT &= ~0b11000000;//izsleg 6. un 7.led

 }
 else
 {
  P1OUT |= 0b11000000;//ieslegt 6. un 7.led
 } 
*/

 //1.7.aktivitate
 //POGA nav nospiesta, LED7 un LED6 spid
 //POGA ir nospiesta LED7 un LED 6 nespid
 
 for(i=30000;i>1;i--);//aizture
    if ((P2IN&0b00001000) == 0b00001000)
 {
  P1OUT &= ~0b11000000;//izsleg 6. un 7.led
  P1OUT |= 0b00100000; //iesledz 5.lde

 }
 else
 {
  P1OUT |= 0b11000000;//ieslegt 6. un 7.led
  P1OUT &= ~0b00100000;//izsleg 5.led
 } 
   
   
 }
}
