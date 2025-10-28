/*
 * fsm_automatic.c
 *
 *  Created on: Oct 16, 2025
 *      Author: LENOVO
 */

#include "fsm_automatic.h"

void fsm_automatic_run()
{
	switch (status1)
	{
		case INIT:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			status1 = AUTO_RED;
			countdown1 = timer_red/1000;
			setTimer(1, 100);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			if (isTimeExpired(1) == 1)
			{
				countdown1--;
				setTimer(1, 100);
				if (countdown1 <= 0)
				{
					status1 = AUTO_GREEN;
					countdown1 = timer_green/1000;
				}
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			if (isTimeExpired(1) == 1)
			{
				countdown1--;
				setTimer(1, 100);
				if (countdown1 <= 0)
				{
					status1 = AUTO_YELLOW;
					countdown1 = timer_yellow/1000;
				}
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
			if (isTimeExpired(1) == 1)
			{
				countdown1--;
				setTimer(1, 100);
				if (countdown1 <= 0)
				{
					status1 = AUTO_RED;
					countdown1 = timer_red/1000;
				}
			}
			break;
		default:
			break;
	}

	switch (status2)
		{
			case INIT:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				status2 = AUTO_GREEN;
				countdown2 = timer_green/1000;
				setTimer(2, 100);
				break;
			case AUTO_RED:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				if (isTimeExpired(2) == 1)
				{
					countdown2--;
					setTimer(2, 100);
					if (countdown2 == 0)
					{
						status2 = AUTO_GREEN;
						countdown2 = timer_green/1000;
					}
				}
				break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				if (isTimeExpired(2) == 1)
				{
					countdown2--;
					setTimer(2, 100);
					if (countdown2 == 0)
					{
						status2 = AUTO_YELLOW;
						countdown2 = timer_yellow/1000;
					}
				}
				break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
				if (isTimeExpired(2) == 1)
				{
					countdown2--;
					setTimer(2, 100);
					if (countdown2 == 0)
					{
						status2 = AUTO_RED;
						countdown2 = timer_red/1000;
					}
				}
				break;
			default:
				break;
		}
}
