#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "myDraws.h"

void state_advance(int state){ 
 switch (state) {
    case 1:
        demos();
      break;
    case 2:
       break;  
    case 3:
    default:   
      break;
  }
}
