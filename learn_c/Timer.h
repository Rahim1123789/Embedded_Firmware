  void timer0_init()
  {
   T0CTCR = 0x0;
   T0PR = 59999;
   T0TCR =0x2;
  }
    
  void Enable_Timer()
  {
  VICIntEnable |=(1<<4);
  VICVectCntl0 =(1<<5) | 4;
  VICVectAddr0 = (unsigned)timer_isr;
  }
 



