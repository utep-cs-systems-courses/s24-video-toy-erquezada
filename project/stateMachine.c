#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "demos.h"

void state_advance(int state){ 
 switch (state) {
    case 1:
      anotherMelody();
      animateTriangles();
      break;
    case 2:
       melody(1);
       drawAnimatedSquares();
       break;
    case 3:
      bachPartita(1);
      drawSquares();
      break;
    case 4:
       fillScreen();
       break;
    default:
      break;
  }
}
