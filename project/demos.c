#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

// Function prototypes
void drawLine();
void drawLine2();
void fillTriangle();
void drawHourglass();

// Draws a diagonal line from top-left to bottom-right
void drawLine() {
    for (int i = 0; i < screenWidth; i++) {
        drawPixel(i, i, COLOR_BLUE);
    }
}

// Draws a diagonal line from top-right to bottom-left
void drawLine2() {
    for (int i = 0; i < 30; i++) {
        drawPixel(i, 30 - i, COLOR_PINK);
    }
}

// Draws a filled right triangle
void fillTriangle() {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j <= i; j++) {
            drawPixel(j, i, COLOR_BEIGE);
        }
    }
}

// Draws an hourglass shape
void drawHourglass() {
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;
    int height = 40; // Height of each triangle of the hourglass

    // Top triangle
    for (int i = 0; i <= height; i++) {
        drawFastHLine(centerX - i, centerY - i, 2 * i, COLOR_CYAN);
    }

    // Bottom triangle
    for (int i = 0; i <= height; i++) {
        drawFastHLine(centerX - i, centerY + i, 2 * i, COLOR_CYAN);
    }
}

// Main function initializes hardware, clears the screen, and draws shapes
int main() {
    configureClocks();
    lcd_init();
    clearScreen(COLOR_BLACK);

    drawString8X12(20, 20, "Testing function", COLOR_GREEN, COLOR_RED);
    drawLine();
    drawLine2();
    fillTriangle();
    drawHourglass(); // Draw the hourglass on the screen
    fillRectangle(30, 30, 60, 60, COLOR_ORANGE);

    return 0;  // Added return statement for main function
}
