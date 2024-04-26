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

void drawLine2() {
  for (int i = 0; i < 30; i++)
    drawPixel(i, 30-i, COLOR_PINK);
}

void fillTriangle() {
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < i; j++) {
      drawPixel(j, i, COLOR_BEIGE);
    }
  }
}

void DrawHourglass(short size) {
    short cc = screenWidth / 2;  // Calculate center column of the screen
    short cr = screenHeight / 2; // Calculate center row of the screen

    for (short col = 0; col < size; col++) {
        for (short row = col; row < size; row++) {
            drawPixel(cc + col, cr + row, COLOR_WHITE);  // Draw dot in the lower right quadrant
            drawPixel(cc + col, cr - row, COLOR_WHITE);  // Draw dot in the upper right quadrant
            drawPixel(cc - col, cr + row, COLOR_WHITE);  // Draw dot in the lower left quadrant
            drawPixel(cc - col, cr - row, COLOR_WHITE);  // Draw dot in the upper left quadrant
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
  DrawHourglass(screenHeight / 4);  // Pass half of the screen height as size


  fillRectangle(30, 30, 60, 60, COLOR_ORANGE);
}
