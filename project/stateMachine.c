#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "demos.h"

void state_advance(int state){ 
 switch (state) {
    case 1:
      fillTriangle();
      melody(2);
      clearScreen(COLOR_WHITE);
      break;
    case 2:
       drawTree();
       break;
    case 3:
      bachPartita(1);
      break;
    case 4:
      // clearScreen(COLOR_WHITE);
       mainScreen();
       break;
      
    default:
      
      break;
  }
}
