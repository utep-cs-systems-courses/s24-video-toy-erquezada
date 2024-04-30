#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "demos.h"

void state_advance(int state){ 
 switch (state) {
    case 1:
        drawBox();
      break;
    case 2:
        fillTriangle();
       break;  
    case 3:
        demos();
    default:   
      break;
  }
}
