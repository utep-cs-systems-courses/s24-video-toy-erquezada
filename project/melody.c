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
    drawAnimatedSquares();
    // Bach Melody with notes an octave higher
    int notes[] = {784, 0, 784, 0, 1568, 1480, 1319, 1175, 1047, 1319, 784, 0, 784, 0, 1175, 1047, 988, 880, 784, 0, 1175};
    int numNotes = sizeof(notes) / sizeof(notes[0]);
    playNotes(notes, numNotes);
    
    if (counter >= 2) {
        // Terminate recursion when counter reaches 2 or more
        return;
    }
    
    // Initialization step outside of recursion
    switch_init();
    
    // Recursive call with counter incremented
    melody(counter + 1);
    drawAnimatedSquares();
}

void bachPartita(int counter) {
    if (counter == 2) return; // Terminate recursion based on the desired condition
    
    drawSquares();
    
    // Theme from Bach Chaconne in D Minor
    int notes[] = {588, 698, 698, 784, 698, 660, 698, 784, 0, 880, 932, 1046, 1174, 1396, 1318, 0, 1318, 880, 0, 880};

    int numNotes = sizeof(notes) / sizeof(notes[0]); // Array size

    playNotes(notes, numNotes); // Play the melody
    
    bachPartita(counter + 1); // Recursive call with counter incremented
    
    drawSquares(); // Draw the piano after playing the melody
}

