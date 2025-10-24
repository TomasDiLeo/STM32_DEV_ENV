#ifndef LCD_NC_H
#define LCD_NC_H

#include "stm32f1xx_hal.h" // Ajusta esto según tu serie STM32 si no es F1

// Define the GPIO ports and pins for your LCD
#define RS_Pin 			GPIO_PIN_15
#define RS_GPIO_Port 		GPIOA
//#define RW_Pin 			GPIO_PIN_2
//#define RW_GPIO_Port 	GPIOA
#define EN_Pin 			GPIO_PIN_5
#define EN_GPIO_Port 		GPIOA
#define D4_Pin 			GPIO_PIN_3
#define D4_GPIO_Port 		GPIOB
#define D5_Pin 			GPIO_PIN_4
#define D5_GPIO_Port 		GPIOA
#define D6_Pin 			GPIO_PIN_5
#define D6_GPIO_Port 		GPIOB
#define D7_Pin 			GPIO_PIN_3
#define D7_GPIO_Port 		GPIOA

void lcd_init(void);
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_send_string(char *str);
void lcd_put_cur(int row, int col);
void lcd_clear(void);
void send_lcd_ASCII(char data);
void send_to_lcd(char data, int rs);

#endif // LCD_NC_H
