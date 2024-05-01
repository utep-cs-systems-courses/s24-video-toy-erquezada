#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "myDraws.h"
#include "led.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buzzer.h"
#include "stateMachine.h"

void drawLine(int x0, int y0, int x1, int y1, int color) {
    int dx = abs(x1 - x0), dy = abs(y1 - y0), sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1, err = dx - dy;
    while (1) {
        drawPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

void funnyFace() {
    // Draw glasses
    fillRectangle(20, 30, 30, 30, COLOR_BLACK);
    fillRectangle(80, 30, 30, 30, COLOR_BLACK);
    // Draw glasses connector
    for (int i = 0; i < 45; i++) {
        drawPixel(90 + i, 30, COLOR_BLACK);
        drawPixel(30 + i, 30, COLOR_BLACK);
        drawPixel(50 + i, 40, COLOR_BLACK);
    }
    // Draw nose
    for (int i = 0; i < 30; i++) {
        drawPixel(40 + i, 90 - i, COLOR_ORANGE);
        drawPixel(40 + i, 90, COLOR_ORANGE);
    }
    // Draw mouth
    for (int i = 0; i < 70; i++)
        drawPixel(30 + i, 120, COLOR_ORANGE);
    for (int i = 0; i < 5; i++) {
        drawPixel(30 - i, 120 - i, COLOR_ORANGE);
        drawPixel(97 + i, 120 - i, COLOR_ORANGE);
    }
}

void dayHouse() {
    int change = globalCounter();
    int astroSize = 30; // Size of the sun (square)
    // Draw the background
    fillRectangle(0, 0, 150, 180, change % 2 == 0 ? COLOR_BLUE : COLOR_SKY_BLUE);
    // Draw astro
    fillRectangle(10, 10, astroSize, astroSize, change % 2 == 0 ? COLOR_WHITE : COLOR_YELLOW);
    // Draw the house
    fillRectangle(40, 90, 75, 75, COLOR_CHOCOLATE); // Body of the house
    fillRectangle(60, 130, 20, 30, COLOR_RED);      // Door
    fillRectangle(55, 100, 50, 20, COLOR_GREEN);   // Window 1
    // Draw the roof (Triangle-like)
    int roofY = 90;
    for (int i = 0; i < 38; i++) {
        drawLine(40 + i, roofY, 77, 50 + i, COLOR_BROWN);
        drawLine(115 - i, roofY, 77, 50 + i, COLOR_BROWN);
    }
}

void mainScreen() {
    drawString5x7(10, 10, "TAKE A BREAK :D", COLOR_BLACK, COLOR_WHITE);
    drawString5x7(10, 50, "UNTIL THE SCREEN ", COLOR_DARK_GREEN, COLOR_WHITE);
    drawString5x7(10, 80, " IS TOTALLY RED :D", COLOR_DARK_GREEN, COLOR_WHITE);
    __delay_cycles(10000);
    while (1) {
        fillRectangle(rand() % 100000000, rand() % 100000000, 1, 1, COLOR_RED);
    }
}

void drawCow() {
    clearScreen(COLOR_GREEN);
    // Draw a simple representation of a cow using basic shapes
    // Body
    fillRectangle(30, 50, 90, 30, COLOR_BROWN);
    // Head
    fillRectangle(50, 30, 20, 20, COLOR_WHITE);
    fillRectangle(50, 30, 5, 5, COLOR_BLACK); // Eyes
    fillRectangle(65, 30, 5, 5, COLOR_BLACK);
    fillRectangle(55, 35, 10, 5, COLOR_BLACK); // Mouth
    // Legs
    for (int i = 0; i < 4; i++)
        fillRectangle(40 + i * 20, 80, 10, 20, COLOR_BLACK);
}
