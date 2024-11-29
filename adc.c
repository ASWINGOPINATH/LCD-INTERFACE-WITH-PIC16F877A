/*
 * File:   adc.c
 * Author: aswin
 *
 * Created on 1 December, 2023, 12:01 PM
 */


#include <xc.h>
#include"lcd.h"
#define _XTAL_FREQ 4000000
void ADC_Init() {
    ANSEL = 0b00000001; // Set AN0 pin as analog input
    ADCON0 = 0b10000001; // Select ADC channel AN0 and enable ADC
    ADCON1 = 0b00000000; // VREF+ is VDD, VREF- is VSS, left-justified result
}

unsigned int ADC_Read() {
    // Start ADC conversion
    ADIF = 0;
    ADON = 1;
    __delay_ms(1);
    GO_nDONE = 1;
    while (ADIF == 0); // Wait for conversion to complete
    GO = 0;
    __delay_ms(1);
    return ((ADRESH << 8) + ADRESL); // Return 10-bit ADC result
    //return ADRESH;
}

void LCD_ans(unsigned int a) {
    short int v, x, y, z;
    v = a % 10;
    a = a / 10;
    x = a % 10;
    a = a / 10;
    y = a % 10;
    a = a / 10;
   z = a % 10;
   LCD_Write_Char(z+48);
   LCD_Write_Char(y+48);
   LCD_Write_Char(x+48);
   LCD_Write_Char(v+48);
}
