/*
 * fsm_automatic.c
 *
 *  Created on: Oct 16, 2025
 *      Author: LENOVO
 */

#include "global.h"

void fsm_auto_run()
{
	switch (status1)
	{
		case INIT:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			status1 = AUTO_RED;
			setTimer(1, 500);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			if (isTimeExpired(1) == 1)
			{
				status1 = AUTO_GREEN;
				setTimer(1, 300);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			if (isTimeExpired(1) == 1)
			{
				status1 = AUTO_YELLOW;
				setTimer(1, 200);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
			if (isTimeExpired(1) == 1)
			{
				status1 = AUTO_RED;
				setTimer(1, 500);
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
				setTimer(2, 300);
				break;
			case AUTO_RED:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				if (isTimeExpired(2) == 1)
				{
					status2 = AUTO_GREEN;
					setTimer(2, 300);
				}
				break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
				if (isTimeExpired(2) == 1)
				{
					status2 = AUTO_YELLOW;
					setTimer(2, 200);
				}
				break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
				HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
				HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
				if (isTimeExpired(2) == 1)
				{
					status2 = AUTO_RED;
					setTimer(2, 500);
				}
				break;
			default:
				break;
		}
}
