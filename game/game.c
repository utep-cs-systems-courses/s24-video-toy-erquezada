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

int playerPosition[] = {0, 145, 0, 145};
int ballPosition[] = {
  ballPositionInitial[0], ballPositionInitial[1], ballPositionInitial[0], ballPositionInitial[1]
};

int playerDirection[] = {2, 0};
int ballDirection[] = {1, 1};

static char 
switch_update_interrupt_sense()
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

void drawRect(int pos[], int dims[], int color) {
  for (int i = pos[0]; i < pos[0] + dims[0]; i++) {
    for (int j = pos[1]; j < pos[1] + dims[1]; j++) {
      drawPixel(i, j, color);
    }
  }
}