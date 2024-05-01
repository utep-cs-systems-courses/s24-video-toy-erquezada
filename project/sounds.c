#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void melody(int counter) {
  //specific pitch number
 int notes[] = {698, 587, 698, 587, 587, 0, 659, 0, 659, 0, 659, 0, 659, 659, 698, 587, 698, 587, 587};
  int numNotes = sizeof(notes) / sizeof(notes[0]);//array size
  // Play each note twice simultaneously
  int cycle;
  for (int i = 0; i < numNotes; i++) {
    //first note turn off red and on green
    P1OUT |= LED_GREEN;
    __delay_cycles(10000);
    P1OUT &= ~LED_RED;
    buzzer_set_period(notes[i]);
    __delay_cycles(1000);
    //little wait

    //the opposite lights
    P1OUT |= LED_RED;
    __delay_cycles(100000);
    P1OUT &= ~LED_GREEN;
    buzzer_set_period(notes[i]); 
    __delay_cycles(7000000);
  }
  //after notes , there both lights on , then off , and repeat cycle
  __delay_cycles(1000000);
  P1OUT &= ~LED_RED;
  P1OUT &= ~LED_GREEN;
  __delay_cycles(100000);
  P1OUT |= LED_GREEN;
  P1OUT |= LED_RED;
  if(counter == 3){return;}
  switch_init();
  melody(counter++);
}

void elGobiernoGobierna(int counter)
{ 
   drawCow();
  
  // Specific pitch numbers for the melody "Cypis - Gdzie jest biały węgorz"
  int notes[] = {
    659, 659, 880, 880, 988, 988, 880, 0, // G G A A H H A Pause
    784, 784, 659, 659, 880, 880, 784, 0, // F F G G A A F Pause
    659, 659, 659, 0,                     // G G G Pause
    659, 659, 880, 880, 988, 988, 880, 0, // G G A A H H A Pause
    784, 784, 659, 659, 880, 880, 784, 0, // F F G G A A F Pause
    659, 784, 880, 988, 988, 880, 784, 659, 659, 0, // G F A H H A F G G Pause
    659, 659, 880, 880, 988, 988, 880, 0, // G G A A H H A Pause
    784, 784, 659, 659, 880, 880, 784, 0, // F F G G A A F Pause
    659, 784, 880, 988, 988, 880, 784, 659, 659, 0, // G F A H H A F G G Pause
    880, 988, 988, 1047, 988, 880, 784, 880, 659, 659, 659, 0, // A H H C H A F A G G G Pause
    880, 988, 988, 1047, 988, 880, 784, 880, 659, 659, 659, 0, // A H H C H A F A G G G Pause
    659, 0, // G Pause
  };
  int numNotes = sizeof(notes) / sizeof(notes[0]); // Array size
   // Play each note twice simultaneously
  int cycle;
  for (int i = 0; i < numNotes; i++) 
  {
    //first note turn off red and on green
    P1OUT |= LED_GREEN;
    __delay_cycles(10000);
    P1OUT &= ~LED_RED;
    buzzer_set_period(notes[i]);
    __delay_cycles(1000000);
    //little wait

    //the opposite lights
    P1OUT |= LED_RED;
    __delay_cycles(100000);
    P1OUT &= ~LED_GREEN;
    buzzer_set_period(notes[i]); 
    __delay_cycles(700000);
  }
  //after notes , there both lights on , then off , and repeat cycle
  __delay_cycles(1000000);
  P1OUT &= ~LED_RED;
  P1OUT &= ~LED_GREEN;
  __delay_cycles(100000);
  P1OUT |= LED_GREEN;
  P1OUT |= LED_RED;
  if(counter == 2){return;}
  drawCow();
  elGobiernoGobierna(counter++);
}
