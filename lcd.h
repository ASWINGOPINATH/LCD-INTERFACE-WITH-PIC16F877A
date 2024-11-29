#ifndef LCD_H
#define LCD_H

#include <xc.h>

// Define your crystal frequency here
#define _XTAL_FREQ 4000000

// LCD pin connections
#define RS RC0
#define EN RC1
#define D4 RC2
#define D5 RC3
#define D6 RC4
#define D7 RC5

void LCD_Command(unsigned char cmd);
void LCD_Init();
void LCD_Write_Char(unsigned char data);
void LCD_Write_String(const char *str);
void LCD_Set_Cursor(short int row, short int column);
#endif /* LCD_H */
