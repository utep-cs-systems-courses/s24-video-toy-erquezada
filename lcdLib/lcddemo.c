/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcddemo.h"

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
  u_char width = screenWidth; 
  u_char height = screenHeight;

  clearScreen(BLACK);

  // Comment out or remove old drawString function if not used
  // drawString5x7(20, 20, "hello, world", COLOR_GREEN, COLOR_RED);

  drawString8X12(20, 20, "Testing function", COLOR_GREEN, COLOR_RED);

  // Comment out or remove other drawing functions if not used or not defined
  // drawLine();
  // drawLine2();
  // fillTriangle();


  short centerCol = width / 2; // Center column for the hourglass
  short centerRow = height / 2; // Center row for the hourglass
  for (int col = 0; col < 20; col++) {
    for (int row = 0; row < 20; row++) {
      drawPixel(centerCol + col, centerRow + row, COLOR_PINK);
      drawPixel(centerCol + col, centerRow - row, COLOR_PINK);
      drawPixel(centerCol - col, centerRow - row, COLOR_PINK);
      drawPixel(centerCol - col, centerRow + row, COLOR_PINK);
    }
  }

  fillRectangle(30, 15, 30, 30, COLOR_ORANGE);
}
