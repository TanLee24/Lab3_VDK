/*
 * fsm_manual.c
 *
 *  Created on: Oct 16, 2025
 *      Author: LENOVO
 */
#include "fsm_mannual.h"

void fsm_manual_run()
{
	switch(mode)
	{
	  case 1:  // Autorun
		  fsm_automatic_run();
		  display_7SEG_automatic();
		  if(isButtonPressed(0) == 1) // Button 1 pressed
		  {
			setTimer(4, 50);
			mode = 2;
			count = 1;
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 |
					GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11, SET);
			setTimer(3, 50);
		  }
		  break;
	  case 2:  // Red light
		  if(isTimeExpired(4) == 1)
		  {
			  setTimer(4, 50);
			  HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			  HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
		  }
		  if(isButtonPressed(1) == 1) // Button 2 pressed
		  {
			  count++;
			  if (count > 99) count = 0;
		  }
		  if(isButtonPressed(2) == 1) // Button 3 pressed
		  {
			  timer_red = count * 1000;
			  count = 1;
		  }
		  display_7SEG_manual();
		  if(isButtonPressed(0) == 1) // Button 1 pressed
		  {
			  setTimer(4, 50);
			  mode = 3;
			  count = 1;
			  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
		  }
		  break;
	  case 3:  // Yellow light
		 if(isTimeExpired(4) == 1)
		 {
			 setTimer(4, 50);
			 HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			 HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
		 }
		 if(isButtonPressed(1) == 1) // Button 2 pressed
		 {
			 count++;
			 if (count > 99) { count = 0; }
		 }
		 if(isButtonPressed(2) == 1) // Button 3 pressed
		 {
			 timer_yellow = count*1000;
			 count = 1;
		 }
		 display_7SEG_manual();
		 if(isButtonPressed(0) == 1) // Button 1 pressed
		 {
			 setTimer(4, 50);
			 mode = 4;
			 count = 1;
			 HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			 HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
		 }
		 break;
	  case 4:  // Green light
		  if(isTimeExpired(4) == 1)
		  {
			  setTimer(4, 50);
			  HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			  HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
		  }
		  if(isButtonPressed(1) == 1) // Button 2 pressed
		  {
			  count++;
			  if (count > 99) { count = 0; }
		  }
		  if(isButtonPressed(2) == 1) // Button 3 pressed
		  {
			  timer_green = count*1000;
			  count = 1;
		  }
		  display_7SEG_manual();
		  if(isButtonPressed(0) == 1) // Button 1 pressed
		  {
			  mode = 1;
			  count = 1;
			  status1 = INIT;
			  status2 = INIT;
			  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
		  }
		  break;
	  default:
		  mode = 1;
		  break;
	}
}
