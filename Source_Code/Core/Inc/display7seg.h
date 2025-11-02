/*
 * display7seg.h
 *
 *  Created on: Oct 16, 2025
 *      Author: LENOVO
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#define EN0	0
#define EN1	1

void display7SEG1(int num);
void display7SEG2(int num);
void display_7SEG_automatic();
void display_7SEG_manual();

extern int enable7SEG;

#endif /* INC_DISPLAY7SEG_H_ */
