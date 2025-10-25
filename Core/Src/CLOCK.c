#include <CLOCK.h>
#include <stdio.h>

DateTime datetime = {
		.hours = 0,
		.minutes = 0,
		.seconds = 0,
		.date = 20,
		.month = 10,
		.year = 25
};

static RTC_HandleTypeDef *hrtc_ptr = NULL;

void clock_init(RTC_HandleTypeDef *hrtc) {
    hrtc_ptr = hrtc;

    clock_set_time(datetime.hours, datetime.minutes, datetime.seconds);
    clock_set_date(datetime.date, datetime.month, datetime.year);
}

static uint8_t clock_int_to_bcd(uint8_t integer) {
    return ((integer / 10) << 4) | (integer % 10);
}

void clock_set_time(uint8_t hours, uint8_t minutes, uint8_t seconds) {
    if (!hrtc_ptr) return;

    RTC_TimeTypeDef sTime = {0};
    sTime.Hours = clock_int_to_bcd(hours);
    sTime.Minutes = clock_int_to_bcd(minutes);
    sTime.Seconds = clock_int_to_bcd(seconds);

    if (HAL_RTC_SetTime(hrtc_ptr, &sTime, RTC_FORMAT_BCD) != HAL_OK) {
        Error_Handler();
    }
}

void clock_set_date(uint8_t date, uint8_t month, uint8_t year) {
    if (!hrtc_ptr) return;

    RTC_DateTypeDef sDate = {0};
    sDate.Date = clock_int_to_bcd(date);
    sDate.Month = clock_int_to_bcd(month);
    sDate.Year = clock_int_to_bcd(year);

    if (HAL_RTC_SetDate(hrtc_ptr, &sDate, RTC_FORMAT_BCD) != HAL_OK) {
        Error_Handler();
    }
}

void clock_update_datetime(void){
	if (!hrtc_ptr) return;

	RTC_TimeTypeDef gTime;
    RTC_DateTypeDef gDate;

    HAL_RTC_GetTime(hrtc_ptr, &gTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(hrtc_ptr, &gDate, RTC_FORMAT_BIN);

    datetime.hours = gTime.Hours;
    datetime.minutes = gTime.Minutes;
    datetime.seconds = gTime.Seconds;

    datetime.date = gDate.Date;
    datetime.month = gDate.Month;
    datetime.year = gDate.Year;
}
