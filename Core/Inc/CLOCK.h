#ifndef CLOCK_H
#define CLOCK_H

#include "stm32f1xx_hal.h"

typedef enum {
	CLOCK_OK = 0,
    CLOCK_ERROR_INVALID_HOUR,
    CLOCK_ERROR_INVALID_MINUTE,
    CLOCK_ERROR_INVALID_SECOND,
    CLOCK_ERROR_INVALID_DATE,
    CLOCK_ERROR_INVALID_MONTH,
    CLOCK_ERROR_INVALID_YEAR,
	CLOCK_CRITICAL_ERROR
} Clock_Status_t;

typedef struct {
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;

	uint8_t date;
	uint8_t month;
	uint8_t year;
} DateTime;

extern DateTime datetime;

// Function declarations
void clock_init(RTC_HandleTypeDef *hrtc);
Clock_Status_t clock_set_time(uint8_t hours, uint8_t minutes, uint8_t seconds);
Clock_Status_t clock_set_date(uint8_t date, uint8_t month, uint8_t year);
void clock_update_datetime(void);

#endif // CLOCK_H
