/*
 * software_timer.h
 *
 *  Created on: Oct 15, 2025
 *      Author: LENOVO
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

void setTimer(int index, int duration);
int isTimeExpired(int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
