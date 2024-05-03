#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachine.h"



u_char screenWidth, screenHeight;

/* Function prototypes */
void state_advance(int state);
void drawLine();
void drawLine2();
void fillTriangle();
void drawHourGlass();
static char switch_update_interrupt_sense();
void switch_init();
void switch_interrupt_handler();

/* Main function */
void main() {
  configureClocks();
  screenWidth = screenWidth;
  screenHeight = screenHeight;
  lcd_init();

  clearScreen(BLACK);

  // Filling a rectangle
 // fillRectangle(30, 15, 30, 30, COLOR_ORANGE);

  switch_init(); // Initialize switches

  __enable_interrupt(); // Enable interrupts

  while(1); // Infinite loop

  return 0;
}

/* Function to advance state and control LCD display */
void state_advance(int state) { 
  clearScreen(BLACK); // Clear screen before drawing new state

  switch (state) {
    case 1:
      drawLine();
      break;
    case 2:
      drawLine2();
      break;
    case 3:
      fillTriangle();
      break;
    case 4: 
      drawHourGlass();
      break;
    default:
      break;
  }
}

/* Function to draw a diagonal line */
void drawLine() {
  for (int i = 0; i < 128; i++)
    drawPixel(i, i, COLOR_BLUE);
}

/* Function to draw a second diagonal line */
void drawLine2() {
  for (int i = 0; i < 30; i++)
    drawPixel(i, 30 - i, COLOR_PINK);
}

/* Function to fill a triangle */
void fillTriangle() {
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < i; j++) {
      drawPixel(j, i, COLOR_BEIGE);
    }
  }
}

/* Function to draw the initial display */
void drawHourGlass() {
  // Drawing initial text
  drawString5x7(20, 20, "Testing function", COLOR_GREEN, COLOR_RED);

  // Drawing a pattern
  u_char width = screenWidth;
  u_char height = screenHeight;
  short centerCol = width / 2;
  short centerRow = height / 2;
  for (int col = 0; col < 20; col++) {
    for (int row = 0; row < 20; row++) {
      drawPixel(centerCol + col, centerRow + row, COLOR_PINK);
      drawPixel(centerCol + col, centerRow - row, COLOR_PINK);
      drawPixel(centerCol - col, centerRow - row, COLOR_PINK);
      drawPixel(centerCol - col, centerRow + row, COLOR_PINK);
    }
  }
}

/* Function to initialize switches */
void switch_init() {
  P2REN |= SWITCHES;    // Enables resistors for switches
  P2IE |= SWITCHES;     // Enable interrupts from switches
  P2OUT |= SWITCHES;    // Pull-ups for switches
  P2DIR &= ~SWITCHES;   // Set switches' bits for input
  switch_update_interrupt_sense();
}

/* Function to handle switch interrupts */
void switch_interrupt_handler() {
  char p2val = switch_update_interrupt_sense();
  if (p2val & SW1 ? 0 : 1) {
    state_advance(1);
  } else if (p2val & SW2 ? 0 : 1) {
    state_advance(2);
  } else if (p2val & SW3 ? 0 : 1) {
    state_advance(3);
  } else if (p2val & SW4 ? 0 : 1) {
    state_advance(4);
  }
}

/* Function to update switch interrupt sense */
static char switch_update_interrupt_sense() {
  char p2val = P2IN;
  // Update switch interrupt to detect changes from current buttons
  P2IES |= (p2val & SWITCHES);   // If switch up, sense down
  P2IES &= (p2val | ~SWITCHES);  // If switch down, sense up
  return p2val;
}
