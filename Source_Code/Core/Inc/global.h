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
#include "fsm_config.h"
#include "fsm_manual.h"
#include "traffic.h"

#define INIT 		1
#define AUTO_RED 	2
#define AUTO_GREEN 	3
#define AUTO_YELLOW 4
#define MANUAL_IDLE   0
#define MANUAL_RED    1
#define MANUAL_GREEN  2

extern int status1;
extern int status2;
extern int mode;
extern int timer_red;
extern int timer_yellow;
extern int timer_green;

extern int count;

extern int countdown1;
extern int countdown2;

extern int manual_status;



#endif /* INC_GLOBAL_H_ */
