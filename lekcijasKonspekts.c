//Kods atbilst lekcijas konspektam
// https://www.youtube.com/watch?v=7GkFkI_rw6M&feature=youtu.be

//definē ieeju/izeju kur 0 ir ieeja, bet 1 izeja, degs nultā un trešā diode
P1DIR = 0b00001001;
//reģists atbild par diodes iededzināšanu (izejas stāvokli), degs tikai nultā diode
P1OUT = 0b00000001;


#include <msp430.h>
void delay(void);
int main()
{
  WDTCTL = WDTPW + WDTHOLD;
  
  //pasludinam par izeju P1.0 un P1.6
  //bināri
  //P1DIR |= 0b01000001; 
  //heksadecimāli
  //P1DIR |= 0x41; 
  //ar konstanti
  P1DIR |= (BIT6+BIT0); 
  
  for(;;) {
  //Iespīdina diodi
  P1OUT |= BIT0;
  
  //aizsture
  delay();
  
  //Izslēdz tiko iespīdināto diodi
  P1OUT &= ~BIT0;
  delay();  
  }
  
  //alternatīva iepriekšējam for, kā mirgot plus pieskaita 6 diodi
  /*
  for(;;)
  {
  delay();  
  P1OUT ^= (BIT0+BIT6);  
  }
  
  */
  


  

}

void delay()
{
  volatile unsigned int n;
  for(n=0;n<60000;n++)
  {;}
}
