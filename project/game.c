#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

#define LED BIT6		/* note that bit zero req'd for display */
#define SW1 1
#define SW2 2
#define SW3 4
#define SW4 8
#define SWITCHES 15

int backGroundColor = BLACK;
int objectColor = WHITE;
int ballPositionInitial[] = {30, 10};
int ballDirectionInital[] = {1, 1};
int displayDimensions[] = {128, 160};

char playerScore = 0;

int rectangleDimension[] = {30, 5};
int ballDimension[] = {3, 3};

int playerPosition[] = {0, 145};
int ballPosition[] = { ballPositionInitial[0], ballPositionInitial[1], ballPositionInitial[0], ballPositionInitial[1]};

int playerDirection[] = {2, 0};
int ballDirection[] = {1, 1};

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init() /* setup switch */
{
  P2REN |= SWITCHES;  /* enables resistors for switches */
  P2IE |= SWITCHES;   /* enable interrupts from switches */
  P2OUT |= SWITCHES;  /* pull-ups for switches */
  P2DIR &= ~SWITCHES; /* set switches' bits for input */
  switch_update_interrupt_sense();
}

void drawRectangle(int position[], int dimensions[], int color)
{
  for (int x = position[0]; x < position[0] + dimensions[0]; x++) {
    for (int y = position[1]; y < position[1] + dimensions[1]; y++) {
      drawPixel(x, y, color);
    }
  }
}

void move(int position[], int dimension[]) {
  // Store the current position of the rectangle as old position
  int oldPosition[2] = {position[0], position[1]};

  // Clear the old rectangle from the screen
  drawRectangle(oldPosition, dimension, backGroundColor);

  // The new rectangle's position is implicit since the first and second indexes don't change
  // Draw the new rectangle at the updated position
  drawRectangle(position, dimension, objectColor);
}

void moveRectangle(int newPosition[], int newDimension[])
{
  int freedDimension[] = {newPosition[0] - newPosition[2], newDimension[1]};
  char isMovingLeft = 0;
  if (freedDimension[0] < 0) {
    isMovingLeft = 1;
    freedDimension[0] *= -1;
  }
  int freedPosition[] = {newPosition[2], newPosition[1]};
  if (isMovingLeft) {
    freedPosition[0] = newPosition[0] + newDimension[0];
  }
  drawRectangle(freedPosition, freedDimension, backGroundColor);
  drawRectangle(newPosition, newDimension, objectColor);
  newPosition[2] = newPosition[0];
}

int rangesOverlap(int range1[], int range2[])
{
    // Check if range1 overlaps with range2
    if (range1[0] <= range2[1] && range2[0] <= range1[1]) {
        // Ranges overlap
        return 1;
    } else {
        // Ranges do not overlap
        return 0;
    }
}

int boxesCollide(int boxPosition[], int boxDimensions[])
{
    // Calculate horizontal bounds for the first box
    int box1HorizontalBounds[] = {boxPosition[0], boxPosition[0] + boxDimensions[0]};
    // Check horizontal overlap for the first box
    int horizontalOverlap = rangesOverlap(box1HorizontalBounds);
    // Calculate vertical bounds for the first box
    int box1VerticalBounds[] = {boxPosition[1], boxPosition[1] + boxDimensions[1]};
    // Check vertical overlap for the first box
    int verticalOverlap = rangesOverlap(box1VerticalBounds);
    // Return true if both horizontal and vertical overlaps occur
    return horizontalOverlap && verticalOverlap;
}

void update_shape()
{
  drawChar5x7(displayDimensions[0] / 2 - 2, playerScore, objectColor, backGroundColor);
  moveRectangle(ballPosition, ballDimension);
  move(playerDirection, rectangleDimension);
}

void wdt_c_handler() {
  if (playerScore > 5) {
    return;
  }
  static int secCount = 1;
  secCount ++;
  if (secCount % 5 == 0) {
    secCount = 1;
    redrawScreen = 1;
    // update positions
    ballPosition[0] += ballDirection[0];
    ballPosition[1] += ballDirection[1];
    playerPosition[0] += playerDirection[0];
    playerPosition[1] += playerDirection[1];
    if ((ballPosition[0] <= 0) || (ballPosition[0] + ballDimension[0] >= displayDimensions[0])) {
      ballDirection[0] = -ballDirection[0];
    }
    if ( boxesCollide(playerPosition, rectangleDimension, ballPosition, ballDimension)) {
      ballDirection[1] = -1;
    }
    if (ballPosition[1] <= 0 || ballPosition[1] + ballDimension[1] >= displayDimensions[1]) {
      if (ballPosition[1] <= 0) {
        playerScore++;
      }
      // reposition ball
      ballPosition[0] = ballPositionInitial[0];
      ballPosition[1] = ballPositionInitial[1];
      // reset ball direction
      ballDirection[0] = ballDirectionInital[0];
      ballDirection[1] = ballDirectionInital[1];
    }
    if (playerPosition[0] <= 0 || playerPosition[0] + rectangleDimension[0] >= displayDimensions[0]) {
      playerDirection[0] = 0;
    }
  }
}

void main()
{
  P1DIR |= LED;		/**< Green led on when CPU on */
  P1OUT |= LED;
  configureClocks();
  buzzer_init();
  lcd_init();
  switch_init();
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  clearScreen(backGroundColor);
  // draw paddles
  drawRect(playerPosition, rectangleDimension, objectColor);
  // draw ball
  drawRect(ballPosition, ballDimension, objectColor);
  while (playerScore < 5) {
    if (redrawScreen) {
      redrawScreen = 0;
      update_shape();
    }
    P1OUT &= ~LED;	/* led off */
    or_sr(0x10);	/**< CPU OFF */
    P1OUT |= LED;	/* led on */
  }
  // game over
  clearScreen(backGroundColor);
  if (playerScore > 4) {
    drawString5x7(0, 0, "Player lost!", objectColor, backGroundColor);
  }
  P1OUT &= ~LED;	/* led off */
  or_sr(0x10);	/**< CPU OFF */
}

void switch_interrupt_handler() {
  char p2val = switch_update_interrupt_sense();
  switches = ~p2val & SWITCHES;
  if (switches & SW1) playerDirection[0] = -2;
  if (switches & SW2) playerDirection[0] = 2;
}

void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}