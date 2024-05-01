#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "demos.h"

void playNotes(int notes[], int numNotes) {
    for (int i = 0; i < numNotes; i++) {
        // Turn on LED_GREEN and turn off LED_RED
        P1OUT |= LED_GREEN;
        P1OUT &= ~LED_RED;
        buzzer_set_period(notes[i]);
        __delay_cycles(10000);

        // Turn on LED_RED and turn off LED_GREEN
        P1OUT |= LED_RED;
        P1OUT &= ~LED_GREEN;
        buzzer_set_period(notes[i]);
        __delay_cycles(6900000); // Combined delay for both notes
    }
    // Both lights off
    P1OUT &= ~(LED_RED | LED_GREEN);
    __delay_cycles(100000);
    // Both lights on
    P1OUT |= (LED_RED | LED_GREEN);
}

void melody(int counter) {
  int notes[] = {}; // short melody
    int numNotes = sizeof(notes) / sizeof(notes[0]);
    playNotes(notes, numNotes);
    if (counter == 3) return;
    switch_init();
    melody(counter + 1);
}

void bachPartita(int counter) {
    drawTree();

    int notes[] = {}; // theme from bach partita
    int numNotes = sizeof(notes) / sizeof(notes[0]); // Array size

    playNotes(notes, numNotes);
    if (counter == 2) return;
    drawTree();
    bachPartita(counter + 1);
}
