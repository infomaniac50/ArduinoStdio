/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 Modifications: Derek Chafin 2014
  Added serial getchar
  Replaced printf_begin with generic SERIAL_IN SERIAL_OUT macros

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

/**
 * @file printf.h
 *
 * Setup necessary to direct stdout to the Arduino Serial library, which
 * enables 'printf'
 */
#ifndef __UART_STDIO_H__
#define __UART_STDIO_H__
#ifdef ARDUINO
#include <Arduino.h>

int stdio_serial_putc( char c, FILE * )
{
  Serial.write( c );

  return c;
}

int stdio_serial_getc(FILE *)
{
  // getchar blocks so wait until data is available.
  while(!Serial.available()) {;}
  return Serial.read();
}

#define SERIAL_IN &stdio_serial_getc
#define SERIAL_OUT &stdio_serial_putc

#else
#error This example is only for use on Arduino.
#endif // ARDUINO

#endif // __UART_STDIO_H__