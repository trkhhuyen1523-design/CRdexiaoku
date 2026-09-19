#include <REGX52.H>
#include "intrins.h"

void Timer1Init()
{
    TMOD &= 0x0F;   
    TMOD |= 0x10;   
    TL1 = 0x66;     
    TH1 = 0xFC;     
    TF1 = 0;        
    TR1 = 1;       
    ET1 = 1;        
    EA = 1;       
    PT1 = 0;        
}