/*
 * Switch_int.h
 *
 *  Created on: Sep 14, 2019
 *      Author: User
 */

#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

#include "std_types.h"
#include "DIO_int.h"
#define Pushed 1
#define Released 0
void Switch_VoidInit();
u8 Switch_u8Pressed(u8 local_switch);

//Switches
#define Switch1 1
#define Switch2 2
#define Switch3 3
#define Switch4 4
#define Switch5 5
//***************************

#endif /* SWITCH_INT_H_ */
