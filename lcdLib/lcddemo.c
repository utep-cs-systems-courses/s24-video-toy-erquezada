/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

drawLine()
{
  for (int i = 0; i < 128; i++)
    drawPixel(i,i, COLOR_BLUE);
}

drawLine2() {
  for (int i = 0; i < 30; i++)
    drawPixel(i, 30-i, COLOR_PINK);
}

fillTriangle() {
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < i; j++) {
      drawPixel(j, i, COLOR_BEIGE);
    }
  }
}

/** Initializes everything, clears the screen, draws "hello" and a square */
int main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(BLACK);

  //drawString5x7(20,20, "hello, world", COLOR_GREEN, COLOR_RED);
  drawString8X12(20,20, "Testing function", COLOR_GREEN, COLOR_RED);

  drawLine();
  drawLine2();
  fillTriangle();
  
  fillRectangle(30,30, 60, 60, COLOR_ORANGE);
  
}
