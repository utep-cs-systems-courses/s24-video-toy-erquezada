#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "demos.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include <stddef.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void main()
{
     unsigned int seed = TA0R;
    srand(seed); 
    configureClocks();
    lcd_init();
    clearScreen(COLOR_WHITE);
    buzzer_init();    
   

    while(1)
    {
        switch_init();
        __delay_cycles(250000);
    }

    or_sr(0x18);
}

int globalCounter(){
  static int counter = 0;
  counter++;
  return counter;
}
