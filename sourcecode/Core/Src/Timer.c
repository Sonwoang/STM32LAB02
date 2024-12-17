/*
 * Timer.c
 *
 *  Created on: Dec 17, 2024
 *      Author: LENOVO
 */
#include "Timer.h"

#define Size 10

int timer_flag[Size];
int timer_counter[Size];
int Cycle = 10;

void setTimer(int index, int duration){
	timer_counter[index] = duration / Cycle;
	timer_flag[index] = 0;
}

void TimerRun(int index){
	if(timer_counter[index] > 0){
		timer_counter[index]--;
		if(timer_counter[index] >= 0){
			timer_flag[index] = 1;
		}
	}
}

