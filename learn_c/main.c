 #include<lpc214x.h>
 #include<stdint.h>

 #include "PLL.h"
 #include "GPIO.h"
 #include "UART.h"
 #include "Timer.h"

 
 __irq void timer_isr(void)
  {
   // my code here
	IO1PIN ^= (1<<0);
   //clear interrupt flag
   T0IR = 1;

   //end of intrrupt
   VICVectAddr = 0;
  }

 int main()
 {
  intPLL();
  timer0_init();
  Enable_Timer();
  IO1DIR |=(1<<0);
//  IODIR0 |= (0x01<<15);
//  delayms(200);
  intUART();
  T0MCR |= (1<<0);
  TxUART('X');
  TxUART('X');
  while(1)
  {
   puts("Rahim Pathan\n");
   delayms(2000);
  }
 
 
 
 
 
 
 
 }







