#include <msp430.h>
void play(int,int);
void delay(unsigned long);
int main(void) 
{
   WDTCTL = WDTPW + WDTHOLD;
   P2DIR &= ~0x30;
   P2REN |= 0x30;
   P2OUT |= 0x30;
   P2IES|= 0x30;
   P2IFG &= ~0x30;
   P2IE |= 0x30;
   __enable_interrupt();
   
   BCSCTL1 = CALBC1_12MHZ;// timer frequency 12MHz 
   DCOCTL = CALDCO_12MHZ;//

   //nokonfigure pikstula pinus ka izejas
   //P2DIR |= (BIT2+BIT3);

   //Samazinat skaljumu
   P2DIR &= ~(BIT2+BIT3);
   P2REN |= (BIT2+BIT3);

   //melodijas 
   P1DIR |= BIT0;
   
   
   for(;;)
   {
     //notis noteiktai melodijai un to ilgums
     play(1,4);
     play(2,2);
     play(1,4);
     play(4,2);
     play(3,1);
    }
  }

 void play(int n, int e)
 {
  unsigned int del;
  unsigned long laiks;
  volatile unsigned long i;
  volatile unsigned long j;

  if (n==1) del =47;
  if (n==2) del =43;
  if (n==3) del =38;
  if (n==4) del =36;
  if (n==5) del =32;
  if (n==6) del =28;
  if (n==7) del =25;
  if (e==1) laiks =100000;
  if (e==2) laiks =50000;
  if (e==4) laiks =25000;
  for (i = 0; i<laiks; i=i+del+del)
  {
    delay(del);
    P2OUT |= (BIT2+BIT3);
    delay(del);
    P2OUT &= ~(BIT2+BIT3);
    }
  }

void delay(unsigned long ms)
{
  unsigned long ims;
  for(ims = 0; ims<ms;ims++)
  {
    __delay_cycles(120);
    }
 }

 #pragma vector = PORT2_VECTOR
 __interrupt void P2_ISR(void)
 {
  switch(P2IFG&(BIT4+BIT5))
  {
    case BIT4:
     P2IFG &= ~BIT4;
     // jusu program
     play(1,4);
     play(2,4);
     play(3,4);
     play(4,4);
     play(5,4);
     play(6,4);
     play(7,4);
     break;
     case BIT5:
      P2IFG &= ~BIT5;
      // jusu program
      play(3,1);
     break;

     default:
      P2IFG = 0;
      break;
     
    }
  }


  
