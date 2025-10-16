/*
 * button.h
 *
 *  Created on: Oct 15, 2025
 *      Author: LENOVO
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NUM_OF_BUTTONS 3
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void readButton();
int isButtonPressed(int index);

#endif /* INC_BUTTON_H_ */
