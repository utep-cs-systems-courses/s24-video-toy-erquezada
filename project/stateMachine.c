#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "myDraws.h"

void state_advance(int state){ 
 switch (state) {
    case 1:
      funnyFace();
      melody(2);
      clearScreen(COLOR_WHITE);
      break;
    case 2:
       dayHouse();
       break;
    case 3:
      elGobiernoGobierna(1);
      break;
    case 4:
      // clearScreen(COLOR_WHITE);
       mainScreen();
       break;
      
    default:
      
      break;
  }
}
