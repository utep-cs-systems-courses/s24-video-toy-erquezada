#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "lcddemo.h"

void state_advance(int state){ 
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
        main();
       break;
    default:
      break;
  }
}
