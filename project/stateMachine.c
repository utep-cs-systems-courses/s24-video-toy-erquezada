#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

// Function to determine the highest-priority button pressed
int getButtonPressed() {
    char p2val = P2IN; // Read input from port 2
    if (p2val & TOPS1 ? 0 : 1) return 1;
    if (p2val & TOPS2 ? 0 : 1) return 2;
    if (p2val & TOPS3 ? 0 : 1) return 3;
    if (p2val & TOPS4 ? 0 : 1) return 4;
    return 0; // No button pressed
}

void stateMachine() {
    int buttonPressed = getButtonPressed();

    switch (buttonPressed) {
        case 1: // Button 1: Play a melody
            anotherMelody();
            animateTriangles();
            buzzer_set_period(0);
            P1OUT &= ~LEDS;
            break;
        case 2: // Button 2: Trigger a random sound
            melody(1);
            drawAnimatedSquares();
            buzzer_set_period(0);
            P1OUT |= LEDS;
            break;
        case 3: // Button 3: Activate an alarm sound
            bachPartita(1);
            drawSquares();
            buzzer_set_period(0);
            P1OUT &= LEDS;
            break;
        case 4: // Button 4: Play a c major scale
            lastMelody();
            fillScreen();
            buzzer_set_period(0);
            P1OUT |= ~LEDS;
            break;
        default: // No button pressed
        // Reset buzzer and LEDs by default
            buzzer_set_period(0);
            P1OUT &= ~LEDS;
            break;
    }
}
