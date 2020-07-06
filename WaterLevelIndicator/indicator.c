/*
 * indicator.c
 *
 *  Created on: Sep 16, 2019
 *      Author: User
 */

#include <avr/io.h>
#include "DIO_int.h"
#include "std_types.h"
#include "utils.h"
#include "DIO_config.h"

void main()
{
	DIO_voidInit();
	u8 enb,up,down;
	u8 counter = 0;
	u8 up_down_flag =0; //0->going up   1->going down
	while (1)
	{
		//Buttons
		enb = DIO_u8GetPin(DIO_PIN40);
		up = DIO_u8GetPin(DIO_PIN39);
		down = DIO_u8GetPin(DIO_PIN38);

		if(DIO_u8GetPin(DIO_PIN40)==DIO_HIGH) //activating the buttons only if the enable is active
		{
			//Reading the up button and incrementing the counter till 4 only
			if(DIO_u8GetPin(DIO_PIN39)==DIO_HIGH)
			{
				up_down_flag =0;
				while(DIO_u8GetPin(DIO_PIN39)==DIO_HIGH){}
				if(counter>=4)
				{
					counter=4;
				}
				else
				{
					counter++;
				}
			}
			//********************************************************

			//Reading the down button and decrementing the counter till 0 only
			else if(DIO_u8GetPin(DIO_PIN38)==DIO_HIGH)
			{
				up_down_flag =1;
				while(DIO_u8GetPin(DIO_PIN38)==DIO_HIGH);
				if(counter==0)
				{
					counter=0;
				}
				else
				{
					counter--;
				}

			}
			//**********************************************************
		}


		//level indicators and filling indicators

		//level1->pin29
		//Level2->pin28
		//Level3->pin27
		//Level4->pin26

		//fill up->pin22
		//fill down->pin23

		if(counter==0)
		{
			DIO_voidSetPIN(DIO_PIN29,DIO_LOW);
			DIO_voidSetPIN(DIO_PIN28,DIO_LOW);
			DIO_voidSetPIN(DIO_PIN27,DIO_LOW);
			DIO_voidSetPIN(DIO_PIN26,DIO_LOW);
			if(DIO_u8GetPin(DIO_PIN40)==DIO_HIGH)
			{
				DIO_voidSetPIN(DIO_PIN22,DIO_HIGH);
				DIO_voidSetPIN(DIO_PIN23,DIO_LOW);
			}
		}

		if(counter==1)
		{
			DIO_voidSetPIN(DIO_PIN29,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN28,DIO_LOW);
			DIO_voidSetPIN(DIO_PIN27,DIO_LOW);
			DIO_voidSetPIN(DIO_PIN26,DIO_LOW);
			if(DIO_u8GetPin(DIO_PIN40)==DIO_HIGH)
			{
				DIO_voidSetPIN(DIO_PIN22,DIO_HIGH);
				DIO_voidSetPIN(DIO_PIN23,DIO_LOW);
			}
		}

		if(counter==2)
		{
			DIO_voidSetPIN(DIO_PIN29,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN28,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN27,DIO_LOW);
			DIO_voidSetPIN(DIO_PIN26,DIO_LOW);
			if(DIO_u8GetPin(DIO_PIN40)==DIO_HIGH)
			{
				DIO_voidSetPIN(DIO_PIN22,DIO_HIGH);
				DIO_voidSetPIN(DIO_PIN23,DIO_LOW);
			}
		}

		if(counter==3)
		{
			DIO_voidSetPIN(DIO_PIN29,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN28,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN27,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN26,DIO_LOW);
			if(DIO_u8GetPin(DIO_PIN40)==DIO_HIGH)
			{
				if(up_down_flag ==0)
				{
					DIO_voidSetPIN(DIO_PIN22,DIO_HIGH);
					DIO_voidSetPIN(DIO_PIN23,DIO_LOW);
				}
				else if(up_down_flag ==1)
				{
					DIO_voidSetPIN(DIO_PIN23,DIO_HIGH);
					DIO_voidSetPIN(DIO_PIN22,DIO_LOW);
				}
			}
		}

		if(counter==4)
		{
			DIO_voidSetPIN(DIO_PIN29,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN28,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN27,DIO_HIGH);
			DIO_voidSetPIN(DIO_PIN26,DIO_HIGH);
			if(DIO_u8GetPin(DIO_PIN40)==DIO_HIGH)
			{
				DIO_voidSetPIN(DIO_PIN23,DIO_HIGH);
				DIO_voidSetPIN(DIO_PIN22,DIO_LOW);
			}
		//****************************************************************
		}


	}
}
