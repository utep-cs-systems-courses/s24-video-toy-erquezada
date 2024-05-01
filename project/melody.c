#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

void melody(int counter) {
  int notes[] = {698, 587, 698, 587, 587, 0, 659, 0, 659, 0, 659, 0, 659, 659, 698, 587, 698, 587, 587};
  int numNotes = sizeof(notes) / sizeof(notes[0]);
  
  // Play each note twice simultaneously
  for (int i = 0; i < numNotes; i++) {
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    buzzer_set_period(notes[i]);
    __delay_cycles(10000);
    
    P1OUT |= LED_RED;
    P1OUT &= ~LED_GREEN;
    buzzer_set_period(notes[i]); 
    __delay_cycles(6900000); // Combined delay for both notes
  }
  
  // Both lights on, then off
  P1OUT &= ~(LED_RED | LED_GREEN);
  __delay_cycles(100000);
  P1OUT |= (LED_RED | LED_GREEN);
  
  if(counter == 3) return;
  
  switch_init();
  melody(counter + 1);
}


void elGobiernoGobierna(int counter)
{ 
   drawCow();
  
  // Specific pitch numbers
  int notes[] = {
    659, 659, 880, 880, 988, 988, 880, 0, 
    784, 784, 659, 659, 880, 880, 784, 0, 
    659, 659, 659, 0,                    
    659, 659, 880, 880, 988, 988, 880, 0, 
    784, 784, 659, 659, 880, 880, 784, 0, 
    659, 784, 880, 988, 988, 880, 784, 659, 659, 0, 
    659, 659, 880, 880, 988, 988, 880, 0, 
    784, 784, 659, 659, 880, 880, 784, 0, 
    659, 784, 880, 988, 988, 880, 784, 659, 659, 0, 
    880, 988, 988, 1047, 988, 880, 784, 880, 659, 659, 659, 0, 
    880, 988, 988, 1047, 988, 880, 784, 880, 659, 659, 659, 0, 
    659, 0, 
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
