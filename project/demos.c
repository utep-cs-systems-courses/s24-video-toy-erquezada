#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "demos.h"
#include "led.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buzzer.h"
#include "stateMachine.h"

void fillTriangle() {
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < i; j++) {
      drawPixel(j, i, COLOR_BLUE);
    }
  }
}

void drawBox(u_char acol, u_char arow, u_char size, u_int color) {
  u_char max_col = acol + size;
  u_char max_row = arow + size;
  for (u_char col = acol; col < max_col; col++) {
    for (u_char row = arow; row < max_row; row++) {
      drawPixel(col, row, color);
    }
  }
}


void drawSquares() {
    clearScreen(COLOR_GRAY);
    int squareSize = 20; // Size of each square
    int gap = 5; // Gap between squares
    int startX = 50; // Starting X position for drawing squares
    int startY = 50; // Starting Y position for drawing squares

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if ((i + j) % 2 == 0) {
                fillRectangle(startX + (squareSize + gap) * i, startY + (squareSize + gap) * j, squareSize, squareSize, COLOR_BLACK);
            } else {
                fillRectangle(startX + (squareSize + gap) * i, startY + (squareSize + gap) * j, squareSize, squareSize, COLOR_WHITE);
            }
        }
    }
}

void fillScreen() {
    srand(time(NULL)); // Seed the random number generator
    __delay_cycles(10000);

    int counter = 0; // Counter to limit the number of iterations
    while (counter < 100) { // Terminate after 100 iterations
        int x = rand() % 10000;
        int y = rand() % 10000;
        int width = rand() % 20 + 5; // Random width between 5 and 25 pixels
        int height = rand() % 20 + 5; // Random height between 5 and 25 pixels
        int color = rand() % (COLOR_BLUE + 1); // Ensure random color falls within the valid range
        
        // Draw random filled rectangle
        fillRectangle(x, y, width, height, color);
        
        __delay_cycles(500000); // Adjust delay as needed for desired animation speed
        counter++; // Increment the counter
    }
}



void drawStonehenge() {
    clearScreen(COLOR_LIGHT_BLUE);
    // Draw a simplified representation of Stonehenge using basic shapes
    // Vertical stones
    // x = 60, y= 30, width = 20, height = 150
    // x = 100, 30, with = 20, height = 150
    fillRectangle(60, 30, 20, 150, COLOR_GRAY);
    fillRectangle(100, 30, 20, 150, COLOR_GRAY);
    fillRectangle(140, 30, 20, 150, COLOR_GRAY);
    // Horizontal stones
    fillRectangle(60, 110, 160, 20, COLOR_GRAY);
    fillRectangle(100, 110, 160, 20, COLOR_GRAY);
}

