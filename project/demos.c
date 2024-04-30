/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawLine()
{
  for (int i = 0; i < 128; i++)
    drawPixel(i,i, COLOR_BLUE);
}

void drawLine2()
{
  for (int i = 0; i < 30; i++)
    drawPixel(i, 30-i, COLOR_PINK);
}

void fillTriangle()
{
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < i; j++) {
      drawPixel(j, i, COLOR_BEIGE);
    }
  }
}

void drawBox(u_char acol, u_char arow, u_char size, u_int color) {
  u_char max_col = acol + size;
  u_char max_row = arow + size;
  for (u_char col = acol - size; col < max_col; col++) {
    for (u_char row = arow - size; row < max_row; row++) {
      drawPixel(col, row, color); 
    }
  }
}

/** Initializes everything, clears the screen, draws "hello" and a square */
int mainTwo()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  
  short centerCol  =  screenWidth >> 1;
  short centerRow = screenHeight >> 1;
  int size = 30;
  for (short col = 0; col < size; col++) {
    for (short row = col; row < size; row++) {
        drawPixel(centerCol + col, centerRow + row, COLOR_WHITE);  // Draw dot in the lower right quadrant
        drawPixel(centerCol + col, centerRow - row, COLOR_WHITE);  // Draw dot in the upper right quadrant
        drawPixel(centerCol - col, centerRow + row, COLOR_WHITE);  // Draw dot in the lower left quadrant
        drawPixel(centerCol - col, centerRow - row, COLOR_WHITE);  // Draw dot in the upper left quadrant
      }
  }

  clearScreen(BLACK);

  // Comment out or remove old drawString function if not used
  // drawString5x7(20, 20, "hello, world", COLOR_GREEN, COLOR_RED);

  drawString8X12(20, 20, "Testing function", COLOR_GREEN, COLOR_RED);

  // Comment out or remove other drawing functions if not used or not defined
  drawLine();
  drawLine2();
  fillTriangle();
  drawBox(centerCol, centerRow, size, COLOR_VIOLET);

  fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
}
