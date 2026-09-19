#include <REGX52.H>
#include "intrins.h"

void Timer0Init()		
{
		
	TMOD &= 0xF0;
	TMOD |= 0x01;			
	TL0 = 0x66;			
	TH0 = 0xFC;				
	TF0 = 0;
	TR0 = 1;				
	ET0=1;
	EA=1;
	PT0=0;
}
//void Timer0_Routine() interrupt 1
// {
//	  static unsigned int T0Count;
//	 TL0 = 0x66;			
//	 TH0 = 0xFC;
//	 T0Count++;
//	 
//	 if(T0Count>=1000)
//	 {
//		  P2_1=~P2_1;
//		 T0Count=0;
//	 }
//	 
//	
// }
 