#include <REGX52.H>
#include "Timer0.h"
#include "Timer1.h"
#include "DS1302.h"
#include "Delay1ms.h"
#include "Nixie.h"
#include "LCD1602.h"
#include "Key.h"
#include "UART.h"
/*****************************************/
/**
  * @brief  简短摘要 定义管脚
  * @param  Command 描述参数 无
  * @retval 描述返回 低电位亮
  */

sbit redshang = P1^0;
sbit greenshang = P1^1;
sbit yellowshang = P1^2;
sbit redxia = P1^3;
sbit greenxia = P1^4;
sbit yellowxia = P1^5;
sbit redzuo = P1^6;
sbit greenzuo = P1^7;
sbit yellowzuo = P2^0;
sbit redyou = P2^1;
sbit greenyou = P2^2;
sbit yellowyou = P2^3;
sbit Beep=P2^5;
/*****************************************/
int mumu = 0;//mumu==1进入紧急全红状态mumu==0则正常
unsigned char KeyNum=0;//根据按键去改变mumu状态,唯一途径
unsigned char LEDshuzi=1;//显示屏上的红绿灯数字
unsigned char signshuzi=0;//根据此数字转换红绿灯上的状态
unsigned int urgentshuzi=0;
//unsigned char i=0;
//unsigned int ll=0;
//unsigned char llp=0;
void main()
{  
	KeyNum=Key();//读取按键数字	
  signshuzi=0;//初始化	
	Timer0Init();//初始化	
	LCD_Init();//这个初始化只能执行一次		
	while(1)
	{
		KeyNum=Key();//读取按键数字	
			LCD_ShowNum(1,15,LEDshuzi,2);//实时显示红绿灯时间
		if(mumu==1)
	{
		

	}
	/*****************************************/
/**
  * @brief 简短摘要 紧急红绿灯
  * @param  Command 描述参数
  * @retval 描述返回
  */

//			if(ll>0&&ll<=10)//全红
//		{
//			redshang=0;
//			redxia=0;
//			redzuo=0;
//			redyou=0;
//			greenshang=1;
//			greenxia=1;
//      greenzuo=1;
//			greenyou=1;
//			yellowshang=1;
//			yellowxia=1;
//			yellowzuo=1;
//			yellowyou=1;
//			LEDshuzi=1;
//		}
		/*****************************************/
			
	 
		/*****************************************/
/**
  * @brief 简短摘要 主控红绿灯
  * @param  Command 描述参数
  * @retval 描述返回
  */
		if(mumu==0)
		{
			if(signshuzi<=100)//绿灯
			{
			greenzuo=1;
			greenyou=1;
			greenshang=0;
			greenxia=0;
			redzuo=0;
			redyou=0;
			redshang=1;
			redxia=1;
			yellowshang=1;
			yellowxia=1;
			yellowzuo=1;
			yellowyou=1;
			}
			if(signshuzi>11&&signshuzi<=15)//黄灯
			{
			greenshang=1;
			greenxia=1;
      greenzuo=1;
			greenyou=1;
			yellowshang=0;
			yellowxia=0;
			yellowzuo=1;
			yellowyou=1;
			redzuo=0;
			redyou=0;
			redshang=1;
			redxia=1;
			
			}
if(signshuzi>15&&signshuzi<=27)//红灯
      {
	    greenshang=1;
			greenxia=1;
      greenzuo=0;
			greenyou=0;
			yellowshang=1;
			yellowxia=1;
			yellowzuo=1;
			yellowyou=1;
			redzuo=1;
			redyou=1;
			redshang=0;
			redxia=0;
}
if(signshuzi>27&&signshuzi<=32)//红灯左黄
{
	    greenshang=1;
			greenxia=1;
      greenzuo=1;
			greenyou=1;
			yellowshang=1;
			yellowxia=1;
			yellowzuo=0;
			yellowyou=0;
			redzuo=1;
			redyou=1;
			redshang=0;
			redxia=0;	
	     ;
}
if(signshuzi>32)
{
	signshuzi=0;
}
		}
		/*****************************************/
		
		}
	
	}
void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;

    TL0 = 0x66;			
    TH0 = 0xFC;
    T0Count++;
//	beepbin++;
	if(T0Count>=1000)
	{
		LEDshuzi++;//显示屏上的红绿灯数字
		signshuzi++;
	
		T0Count=0;
		
	}

/*****************************************/
/**
  * @brief  简短摘要 声音中枢
  * @param  Command 描述参数
  * @retval 描述返回
  */




/*****************************************/

	/*****************************************/
/**
  * @brief 简短摘要 循环模块
  * @param  Command 描述参数
  * @retval 描述返回
  */

	
	/*****************************************/
	/*****************************************/
/**
  * @brief  简短摘要 模式转换
  * @param  Command 描述参数
  * @retval 描述返回
  */

	if(KeyNum==1)
	{
	   mumu=1;
			urgentshuzi++;
		if(urgentshuzi>=5000)
		{
			urgentshuzi=0;
			mumu=0;
		}
		if(mumu==1)
		{
			greenshang=1;
			greenxia=1;
      greenzuo=1;
			greenyou=1;
			yellowshang=1;
			yellowxia=1;
			yellowzuo=1;
			yellowyou=1;
			redzuo=0;
			redyou=0;
			redshang=0;
			redxia=0;	
			
		}
	}
	
	/*****************************************/
	
}