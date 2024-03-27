#include <STC12C5A.H>
#include <string.h>
#include <stdlib.h>
#include "usart.h"
#include "timer.h"
#include "yundong.h"

extern uint16_t cout1,cout2,cout3;
/***************************************************
						前
***************************************************/
void qian()
{
	CW1 = 0;
	CW2 = 1;
}

/****************************************************
						后
****************************************************/
void hou()
{
	CW1 = 1;
	CW2 = 0;
}

/****************************************************
						直
****************************************************/
void jing(uint16_t Pace,uint8_t *flag)
{
	if(cout3 <= Pace)
	{
		EN1 = 1;
		EN2 = 1;
	}
	else
	{
		tingzhi();
		*flag = 0;
		cout3 = 0;		
	}
}
/*****************************************************
						右
*****************************************************/
void right(uint16_t Pace,uint8_t *flag)
{
	qian();
	if(cout2 <= Pace)
	{
		EN1 = 1;
		EN2 = 0;
	}
	else
	{
		tingzhi();
		*flag = 0;
		cout2 = 0;		
	}
}
/*****************************************************
	    				左
*****************************************************/
void left(uint16_t Pace,uint8_t *flag)
{
	qian();
	if(cout1 <= Pace)
	{
		EN1 = 0;
		EN2 = 1;
	}
	else
	{		
		tingzhi();
		*flag = 0;
		cout1 = 0;
	}
}

/*****************************************************
						停止
*****************************************************/
void tingzhi()
{
	EN1 = 0;
	EN2 = 0;
	delay_timer_ms(200);
}

/*****************************************************
						直进
*****************************************************/
void zhijing(uint16_t Pace,uint8_t *flag)
{
	qian();
	jing(Pace,flag);
}

/*****************************************************
						直退
*****************************************************/
void zhitui(uint16_t Pace,uint8_t *flag)
{
	hou();
	jing(Pace,flag);
}
/*****************************************************
					左(转回来)
*****************************************************/
void left_back(uint16_t Pace,uint8_t *flag)
{
	hou();
	if(cout1 <= Pace)
	{
		EN1 = 0;
		EN2 = 1;
	}
	else
	{	
		tingzhi();
		*flag = 0;
		cout1 = 0;
		qian();		
	}
}
/*****************************************************
					右(转回来)
*****************************************************/
void right_back(uint16_t Pace,uint8_t *flag)
{
	hou();
	if(cout2 <= Pace)
	{
		EN1 = 1;
		EN2 = 0;
	}
	else
	{	
		tingzhi();
		*flag = 0;
		cout2 = 0;			
		qian();
	}
}