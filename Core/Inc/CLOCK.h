#ifndef CLOCK_H
#define CLOCK_H

#include "stm32f1xx_hal.h"

typedef struct {
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;

	uint8_t date;
	uint8_t month;
	uint8_t year;
} DateTime;

// Function declarations
void clock_init(RTC_HandleTypeDef *hrtc);
void clock_set_time(uint8_t hours, uint8_t minutes, uint8_t seconds);
void clock_set_date(uint8_t date, uint8_t month, uint8_t year);
void clock_get_time(uint8_t *hours, uint8_t *minutes, uint8_t *seconds);
void clock_get_date(uint8_t *date, uint8_t *month, uint8_t *year);
uint8_t clock_int_to_bcd(uint8_t integer);

#endif // CLOCK_H
