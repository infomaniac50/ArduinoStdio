#ifndef __LCD_STDIO_H__
#define __LCD_STDIO_H__

#ifdef ARDUINO
#include <Arduino.h>
#include <LiquidCrystal.h>

struct LCD_Info
{
  LiquidCrystal* stdio;
  int rows;
  int cols;
} lcd_info;

int stdio_set_lcd(LiquidCrystal* lcd, int cols, int rows)
{
  lcd_info.stdio = lcd;
  lcd_info.rows = rows;
  lcd_info.cols = cols;
}

int stdio_lcd_putchar( char c, FILE * ) {
  static byte line = 0;
  if (c == '\n' || c == 0) {
    // Assume 2 line displays for now.
    line++;
    lcd_info.stdio->setCursor(0, line);
    line %= lcd_info.rows - 1;
    return c;
  }

  lcd_info.stdio->write(c);

  return c;
}

#define LCD_OUT &stdio_lcd_putchar
#else
#error This example is only for use on Arduino.
#endif

#endif