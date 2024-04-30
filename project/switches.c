#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"

char state, switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense() {
    char p2val = P2IN;
    // Update switch interrupt to detect changes from current buttons
    P2IES |= (p2val & SWITCHES);  // If switch up, sense down
    P2IES &= (p2val | ~SWITCHES); // If switch down, sense up
    return p2val;
}

void switch_init() { // Setup switch
    P2REN |= SWITCHES; // Enables resistors for switches
    P2IE |= SWITCHES;  // Enable interrupts from switches
    P2OUT |= SWITCHES; // Pull-ups for switches
    P2DIR &= ~SWITCHES; // Set switches' bits for input
    switch_update_interrupt_sense();
    switch_interrupt_handler();
}

void switch_interrupt_handler() {
    char p2val = switch_update_interrupt_sense();

    // Determine which switch was pressed by using a switch-case statement
    switch(p2val & SWITCHES) {
        case SW1:  // If switch 1 is pressed
            state_advance(1);
            break;
        case SW2:  // If switch 2 is pressed
            state_advance(2);
            break;
        case SW3:  // If switch 3 is pressed
            state_advance(3);
            break;
        case SW4:  // If switch 4 is pressed
            state_advance(4);
            break;
        default:
            // Handle no switch pressed if needed
            break;
    }
}

