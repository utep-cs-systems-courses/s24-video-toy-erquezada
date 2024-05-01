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
      drawPixel(j, i, COLOR_BEIGE);
    }
  }
}

void drawBox(u_char acol, u_char arow, u_char size, u_int color) {
  u_char max_col = acol + size;
  u_char max_row = arow + size;
  for (u_char col = acol - size; col < max_col; col++) {
    for (u_char row = arow - size; row < max_row; row++) {
      drawPixel(col, row, COLOR_YELLOW);
    }
  }
}

void drawTree() {
    int change = globalCounter();
    // Draw the trunk
    fillRectangle(250, 100, 20, 80, COLOR_BROWN);
    
    // Draw the leaves
    fillRectangle(230, 50, 40, 40, COLOR_GREEN);
    fillRectangle(250, 40, 40, 40, COLOR_GREEN);
    fillRectangle(270, 50, 40, 40, COLOR_GREEN);
    fillRectangle(240, 80, 40, 40, COLOR_GREEN);
    fillRectangle(260, 80, 40, 40, COLOR_GREEN);
}


void mainScreen() {
    __delay_cycles(10000);

    while (1) {
        int x = rand() % 10000;
        int y = rand() % 10000;
        int width = rand() % 20 + 5; // Random width between 5 and 25 pixels
        int height = rand() % 20 + 5; // Random height between 5 and 25 pixels
        int color = rand() % COLOR_BLUE;
        
        // Draw random filled rectangle
        fillRectangle(x, y, width, height, color);
        
        __delay_cycles(500000); // Adjust delay as needed for desired animation speed
    }
}


void drawStonehenge() {
    clearScreen(COLOR_LIGHT_BLUE);
    // Draw a simplified representation of Stonehenge using basic shapes
    // Vertical stones
    fillRectangle(60, 30, 20, 150, COLOR_GRAY);
    fillRectangle(100, 30, 20, 150, COLOR_GRAY);
    fillRectangle(140, 30, 20, 150, COLOR_GRAY);
    // Horizontal stones
    fillRectangle(40, 120, 160, 20, COLOR_GRAY);
    fillRectangle(40, 160, 160, 20, COLOR_GRAY);
}

