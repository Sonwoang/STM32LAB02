/*
 * Ex1.c
 *
 *  Created on: Dec 17, 2024
 *      Author: LENOVO
 */
#include "Ex1.h"

#define DIGIT1 0
#define DIGIT2 1

int status;

const uint8_t segmentValues[10] = {
    0b1111110,
    0b0110000,
    0b1101101,
    0b1111001,
    0b0110011,
    0b1011011,
    0b1011111,
    0b1110000,
    0b1111111,
    0b1111011
};

void display7SEG(int num) {
    if (num < 0 || num > 9) return;

    uint8_t segment = segmentValues[num];

    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (segment & 0x01) ? SET : RESET);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (segment & 0x02) ? SET : RESET);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (segment & 0x04) ? SET : RESET);
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (segment & 0x08) ? SET : RESET);
    HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (segment & 0x10) ? SET : RESET);
    HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (segment & 0x20) ? SET : RESET);
    HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (segment & 0x40) ? SET : RESET);
}

void Ex1Init() {
    status = DIGIT1;
}

void Ex1() {
    HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);

    switch (status) {
        case DIGIT1:
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
            status = DIGIT2;
            display7SEG(1);
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
            break;
        case DIGIT2:
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
            status = DIGIT1;
            display7SEG(2);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
            break;
    }
}

