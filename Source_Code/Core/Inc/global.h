/*
 * global.h
 *
 *  Created on: Oct 16, 2025
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "display7seg.h"
#include "fsm_automatic.h"

#define INIT 		1
#define AUTO_RED 	2
#define AUTO_GREEN 	3
#define AUTO_YELLOW 4

extern int status1;
extern int status2;

#endif /* INC_GLOBAL_H_ */
