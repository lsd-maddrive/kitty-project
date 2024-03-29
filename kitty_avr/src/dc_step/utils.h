/*
 * utils.h
 *
 * Created: 11.03.2022 17:44:45
 *  Author: Michael
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define LEN_WHEEL 34
#define WID_WHEEL 34

uint8_t Digit(uint16_t d, uint8_t m);
uint16_t FindMiddleValue(uint16_t a, uint16_t b, uint16_t c);
uint16_t FindMaxValue(uint16_t a, uint16_t b, uint16_t c);
uint16_t FindMinValue(uint16_t a, uint16_t b, uint16_t c);

#endif /* UTILS_H_ */