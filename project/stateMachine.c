#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "demos.h"

void state_advance(int state){ 
 switch (state) {
    case 1:
      fillTriangle();
      melody(2);
      clearScreen(COLOR_BLACK);
      break;
    case 2:
       drawPiano();
       break;
    case 3:
      bachPartita(1);
      drawStonehenge();
      break;
    case 4:
       fillScreen();
       break;
      
    default:
      
      break;
  }
}
