#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "demos.h" // Assuming you have a drawCow function here

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
    int notes[] = {698, 587, 698, 587, 587, 0, 659, 0, 659, 0, 659, 0, 659, 659, 698, 587, 698, 587, 587};
    int numNotes = sizeof(notes) / sizeof(notes[0]);
    playNotes(notes, numNotes);
    if (counter == 3) return;
    switch_init();
    melody(counter + 1);
}

void elGobiernoGobierna(int counter) {
    drawCow();

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

    playNotes(notes, numNotes);
    if (counter == 2) return;
    drawCow();
    elGobiernoGobierna(counter + 1);
}
