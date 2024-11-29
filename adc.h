#ifndef ADC_H
#define ADC_H

#include <xc.h>

// Define your crystal frequency here
#define _XTAL_FREQ 4000000

// LCD pin connections
void ADC_Init();
unsigned int ADC_Read();
void LCD_ans(unsigned int a);

#endif /* LCD_H */
