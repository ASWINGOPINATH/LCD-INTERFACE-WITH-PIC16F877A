/*
 * File:   lcd.c
 * Author: Anoop Mathew
 *
 * Created on December 1, 2023, 7:34 AM
 */

#include "lcd.h"

void LCD_Command(unsigned char cmd) {
    RS = 0;             // Command mode
    __delay_ms(2);      // Delay for stability
    
    // Sending higher nibble first
    D4 = (cmd >> 4) & 1;
    D5 = (cmd >> 5) & 1;
    D6 = (cmd >> 6) & 1;
    D7 = (cmd >> 7) & 1;
    
    EN = 1;             // Enable pulse
    __delay_ms(1);
    EN = 0;
    
    // Sending lower nibble
    D4 = cmd & 1;
    D5 = (cmd >> 1) & 1;
    D6 = (cmd >> 2) & 1;
    D7 = (cmd >> 3) & 1;
    
    EN = 1;             // Enable pulse
    __delay_ms(1);
    EN = 0;
}

void LCD_Init() {
    LCD_Command(0x02);      // Initialize in 4-bit mode
    LCD_Command(0x28);      // 2 lines, 5x8 matrix
    LCD_Command(0x0C);      // Display ON, cursor OFF
    LCD_Command(0x06);      // Auto-increment cursor
    LCD_Command(0x01);      // Clear display
    __delay_ms(2);
}

void LCD_Write_Char(unsigned char data) {
    RS = 1;             // Data mode
    __delay_ms(2);
    
    // Sending higher nibble first
    D4 = (data >> 4) & 1;
    D5 = (data >> 5) & 1;
    D6 = (data >> 6) & 1;
    D7 = (data >> 7) & 1;
    
    EN = 1;             // Enable pulse
    __delay_ms(1);
    EN = 0;
    
    // Sending lower nibble
    D4 = data & 1;
    D5 = (data >> 1) & 1;
    D6 = (data >> 2) & 1;
    D7 = (data >> 3) & 1;
    
    EN = 1;             // Enable pulse
    __delay_ms(1);
    EN = 0;
}

void LCD_Write_String(const char *str) {
    while (*str)
        LCD_Write_Char(*str++);
}
void LCD_Set_Cursor(short int row, short int column)
{
   
    short int position;
    if (row == 1)
        position = 0x80 + column - 1;   // Address of the first line
    else if (row == 2)
        position = 0xC0 + column - 1;   // Address of the second line
    
    LCD_Command(position);   // Set cursor position
}



