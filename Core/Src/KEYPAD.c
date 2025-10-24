#include "KEYPAD.h"

static void select_row(uint8_t row);

uint8_t keypad_read(void){
	for(uint8_t row = 0; row < 4; row++){
		HAL_Delay(1);
		select_row(row + 1);

		if (READ_PIN(COL_1) == GPIO_PIN_SET) return keymap[row][0];
		if (READ_PIN(COL_2) == GPIO_PIN_SET) return keymap[row][1];
		if (READ_PIN(COL_3) == GPIO_PIN_SET) return keymap[row][2];
		if (READ_PIN(COL_4) == GPIO_PIN_SET) return keymap[row][3];
	}
	return 0;
}

static void select_row(uint8_t row){
	WRITE_PIN(ROW_1, (row == 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	WRITE_PIN(ROW_2, (row == 2) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	WRITE_PIN(ROW_3, (row == 3) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	WRITE_PIN(ROW_4, (row == 4) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
