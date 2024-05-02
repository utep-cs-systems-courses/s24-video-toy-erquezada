#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "demos.h"
#include "switches.h"

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
    // Bach Melody
    int notes[] = {392, 0, 392, 0, 784, 740, 659, 587, 523, 659, 392, 0, 392, 0, 587, 523, 494, 440, 392, 0, 587};
    int numNotes = sizeof(notes) / sizeof(notes[0]);
    playNotes(notes, numNotes);
    if (counter == 2) return;
    switch_init();
    melody(counter + 1);
}

void bachPartita(int counter) {
    drawPiano();
    // Theme from Bach Chaconne in D Minor
    int notes[] = {294, 349, 349, 392, 349, 330, 349, 392, 0, 440, 466, 523, 587, 698, 659, 0, 659, 440, 0, 440};
    int numNotes = sizeof(notes) / sizeof(notes[0]); // Array size

    playNotes(notes, numNotes);
    if (counter == 2) return;
    drawPiano();
    bachPartita(counter + 1);
}
