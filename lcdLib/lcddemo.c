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

void DrawHourglass(short size, short cc, short cr, unsigned int color) {
    // Draw upper triangle
    for (short row = 0; row < size / 2; row++) {
        for (short col = 0; col <= row; col++) {
            drawPixel(cc + col, cr - row, color); // Right side of the upper triangle
            drawPixel(cc - col, cr - row, color); // Left side of the upper triangle
        }
    }
    // Draw lower triangle
    for (short row = 0; row <= size / 2; row++) {
        for (short col = 0; col < size / 2 - row; col++) {
            drawPixel(cc + col, cr + row, color); // Right side of the lower triangle
            drawPixel(cc - col, cr + row, color); // Left side of the lower triangle
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

  // Comment out or remove old drawString function if not used
  // drawString5x7(20, 20, "hello, world", COLOR_GREEN, COLOR_RED);

  drawString8X12(20, 20, "Testing function", COLOR_GREEN, COLOR_RED);

  // Comment out or remove other drawing functions if not used or not defined
  // drawLine();
  // drawLine2();
  // fillTriangle();

  // Draw the hourglass with the center of the screen as the center of the hourglass
  short hourglassSize = height / 2;
  short cc = width / 2; // Center column for the hourglass
  short cr = height / 2; // Center row for the hourglass
  unsigned int color = COLOR_WHITE; // Color of the hourglass
  DrawHourglass(hourglassSize, cc, cr, color);

  fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
}
