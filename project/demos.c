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


void animateTriangles() {
    clearScreen(COLOR_SKY_BLUE);
    int triangleHeight = 20; // Height of each triangle
    int startX = 50; // Starting X position for drawing triangles
    int startY = 50; // Starting Y position for drawing triangles
    int counter = 0; // Counter to limit the number of iterations

    while (counter < 100) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k < triangleHeight; k++) {
                    drawPixel(startX + k + i * (triangleHeight + 1), startY + j * (triangleHeight + 1) + k, rand() % (COLOR_BLUE + 1));
                }
            }
        }
        __delay_cycles(500000); // Adjust delay as needed for desired animation speed
        
        int x = rand() % 10000;
        int y = rand() % 10000;
        int width = rand() % 20 + 5; // Random width between 5 and 25 pixels
        int height = rand() % 20 + 5; // Random height between 5 and 25 pixels
        int color = rand() % (COLOR_BLUE + 1); // Ensure random color falls within the valid range
        
        // Draw random filled triangle
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                drawPixel(x + i, y + j, color);
            }
        }
        
        counter++; // Increment the counter
    }
}

void drawAnimatedSquares() {
    clearScreen(COLOR_SKY_BLUE);
    int squareSize = 20; // Size of each square
    int gap = 5; // Gap between squares
    int startX = 50; // Starting X position for drawing squares
    int startY = 50; // Starting Y position for drawing squares
    int counter = 0; // Counter to limit the number of iterations

    while (counter < 100) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if ((i + j + counter) % 2 == 0) {
                    fillRectangle(startX + (squareSize + gap) * i, startY + (squareSize + gap) * j, squareSize, squareSize, COLOR_BLACK);
                } else {
                    fillRectangle(startX + (squareSize + gap) * i, startY + (squareSize + gap) * j, squareSize, squareSize, COLOR_WHITE);
                }
            }
        }
        __delay_cycles(500000); // Adjust delay as needed for desired animation speed
        
        int x = rand() % 10000;
        int y = rand() % 10000;
        int width = rand() % 20 + 5; // Random width between 5 and 25 pixels
        int height = rand() % 20 + 5; // Random height between 5 and 25 pixels
        int color = rand() % (COLOR_BLUE + 1); // Ensure random color falls within the valid range
        
        // Draw random filled rectangle
        fillRectangle(x, y, width, height, color);
        
        counter++; // Increment the counter
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



