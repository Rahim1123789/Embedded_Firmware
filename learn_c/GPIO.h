/****************************************************************************************************************/
 void delayms(unsigned int mydelay)	 /* Using Timer '0' */
 {
  T0CTCR =0x00; 		   /* Configure T0 as Timer*/
  T0PR = 60000-1;		   /*Set Prescaler register to 60000 for 60MHZ Freq.  */
  T0TC = 0;				   /*Reset Timer Counter  */
  T0TCR =0x01;			   /*Enable Timer Counter Register  */
  while(T0TC < mydelay);   /*Wait untill user define time  */
  T0TCR = 0x01; 		   /*Desable Timer */
 }
/****************************************************************************************************************/

/***********************************Output Set-Reset*****************************************************************************/
 void pinWrite(int pinNr, int pinVal)
 {
  if(pinNr < 100)
  {
   (pinVal == 0)? (IO0CLR |= (1<<pinNr)): (IO0SET |= (1<<pinNr));
  }
  else if(100 < pinNr)
  {
	pinNr=pinNr-100;
   (pinVal == 0)? (IO1CLR |= (1<<pinNr)): (IO1SET |= (1<<pinNr));
  }
 }
/****************************************************************************************************************/

/*************************************Input pin-read*************************************************************/
 int pinRead(int pinNr)
 {
  int val;
  if(pinNr < 100)
  {
   (IO0PIN & (1<<pinNr))? (val=1): (val=0);
  }
  else if(100 < pinNr)
  {
   pinNr=pinNr-100;
   (IO1PIN & (1<<pinNr))? (val=1): (val=0);
  }
 return val;
 }
/****************************************************************************************************************/




