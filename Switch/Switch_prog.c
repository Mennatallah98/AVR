	/*
	 * Switch_prog.c
	 *
	 *  Created on: Sep 14, 2019
	 *      Author: User
	 */
	#include "utils.h"
	#include <avr/io.h>
	#include "DIO_int.h"
	#include "Switch_priv.h"
	#include "Switch_config.h"
	#include "Switch_int.h"
u8 switch_ret=0;
	void Switch_VoidInit();

	u8 Switch_u8Pressed(u8 local_switch)
	{
		if(local_switch==Switch1)
		{
			#if (Switch1_type==PullDown)
				if(DIO_u8GetPin(Switch1_PIN)==DIO_HIGH)
					{
						switch_ret=Pushed;
					}
				else
				{
					switch_ret=Released;
				}
			#elif (Switch1_type==PullUp)
				if(DIO_u8GetPin(Switch1_PIN)==DIO_LOW)
				{
					switch_ret=Pushed;
				}
			else
			{
				switch_ret=Released;
			}
			#endif
		}
		if(local_switch==Switch2)
		{
			#if (Switch2_type==PullDown)
				if(DIO_u8GetPin(Switch2_PIN)==DIO_HIGH)
					{
						switch_ret=Pushed;
					}
				else
				{
					switch_ret=Released;
				}
			#elif (Switch2_type==PullUp)
				if(DIO_u8GetPin(Switch2_PIN)==Released)
				{
					switch_ret=Pushed;
				}
				else
				{
					switch_ret=Released;
				}
			#endif
		}
		if(local_switch==Switch3)
		{
			#if (Switch3_type==PullDown)
				if(DIO_u8GetPin(Switch3_PIN)==DIO_HIGH)
					{
						switch_ret=Pushed;
					}
				else
				{
					switch_ret=Released;
				}
			#elif (Switch3_type==PullUp)
				if(DIO_u8GetPin(Switch3_PIN)==Released)
				{
					switch_ret=Pushed;
				}
				else
				{
					switch_ret=Released;
				}
			#endif
		}
		if(local_switch==Switch4)
		{
			#if (Switch4_type==PullDown)
				if(DIO_u8GetPin(Switch4_PIN)==DIO_HIGH)
					{
						switch_ret=Pushed;
					}
				else
				{
					switch_ret=Released;
				}
			#elif (Switch4_type==PullUp)
				if(DIO_u8GetPin(Switch4_PIN)==Released)
				{
					switch_ret=Pushed;
				}
				else
				{
					switch_ret=Released;
				}
			#endif
		}
		if(local_switch==Switch5)
		{
			#if (Switch5_type==PullDown)
				if(DIO_u8GetPin(Switch5_PIN)==DIO_HIGH)
					{
						switch_ret=Pushed;
					}
				else
				{
					switch_ret=Released;
				}
			#elif (Switch5_type==PullUp)
				if(DIO_u8GetPin(Switch5_PIN)==Released)
				{
					switch_ret=Pushed;
				}
				else
				{
					switch_ret=Released;
				}
			#endif
		}
	return switch_ret;
	}
