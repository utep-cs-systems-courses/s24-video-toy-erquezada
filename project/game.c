#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"

#define LED BIT6
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1 | SW2 | SW3 | SW4)

int backGroundColor = COLOR_BLACK;
int objectColor = COLOR_WHITE;
int ballPositionInitial[] = {30, 10};
int ballDirectionInitial[] = {1, 1};
int displayDimensions[] = {128, 160};

char playerScore = 0;

int rectangleDimension[] = {30, 5};
int ballDimension[] = {3, 3};

int playerPosition[] = {64, 150};  // Centered horizontally at start
int ballPosition[] = {30, 10};

int playerDirection = 0;
int ballDirection[] = {1, -1};  // X and Y directions

void updateBallPosition() {
    // Update ball position based on its current direction
    ballPosition[0] += ballDirection[0];
    ballPosition[1] += ballDirection[1];

    // Check for collisions with the walls
    if (ballPosition[0] <= 0 || ballPosition[0] >= (displayDimensions[0] - ballDimension[0])) {
        ballDirection[0] = -ballDirection[0];  // Reverse X direction
    }
    if (ballPosition[1] <= 0) {
        ballDirection[1] = -ballDirection[1];  // Reverse Y direction
    }

    // Check for collision with the paddle
    if (ballPosition[1] >= (playerPosition[1] - ballDimension[1]) &&
        ballPosition[0] >= playerPosition[0] &&
        ballPosition[0] <= (playerPosition[0] + rectangleDimension[0])) {
        ballDirection[1] = -ballDirection[1];  // Reverse Y direction
    }

    // Check if the ball hits the bottom wall
    if (ballPosition[1] >= displayDimensions[1]) {
        // Reset ball to initial position and direction
        ballPosition[0] = ballPositionInitial[0];
        ballPosition[1] = ballPositionInitial[1];
        ballDirection[0] = ballDirectionInitial[0];
        ballDirection[1] = ballDirectionInitial[1];
        playerScore++;  // Increment score on loss
    }
}

void switch_interrupt_handler() {
    char p2val = P2IN;
    // Direction control
    if (!(p2val & SW1)) playerPosition[0] -= 2;  // Move left
    if (!(p2val & SW2)) playerPosition[0] += 2;  // Move right

    // Bound the paddle within the display
    if (playerPosition[0] < 0) {
        playerPosition[0] = 0;
    } else if (playerPosition[0] > (displayDimensions[0] - rectangleDimension[0])) {
        playerPosition[0] = displayDimensions[0] - rectangleDimension[0];
    }
}

void wdt_c_handler() {
    static int secCount = 0;
    secCount++;
    if (secCount % 10 == 0) {  // Update interval
        secCount = 0;
        updateBallPosition();  // Move the ball
        clearScreen(backGroundColor);
        drawRectangle(playerPosition, rectangleDimension, objectColor);  // Draw paddle
        drawRectangle(ballPosition, ballDimension, objectColor);  // Draw ball
    }
}

void main() {
    configureClocks();
    lcd_init();
    switch_init();
    enableWDTInterrupts();  // enable watchdog timer interrupts
    or_sr(0x18);  // CPU off, GIE on
}
