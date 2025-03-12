#include "main.h"

int main(void) {
    init_gpio();
    
    volatile uint32_t delay_cycles = 250000u;
    
    while(1) {
        toggle_led();
        delay(delay_cycles);
    }
    return 0;
}


void init_gpio(void) {
    SET_PIN(RCC_AHB1ENR, 1);                               // Enable AHB1 bus
    
    delay(50000u);
    
    CLEAR_BITS(MODER(LED_PORT), 0x3 << (LED_PIN * 2));     // Clear mode bits for LED_PIN
    SET_BITS(MODER(LED_PORT), 0x1 << (LED_PIN * 2));       // Set as General Purpose Output
    
    RESET_PIN(OTYPER(LED_PORT), LED_PIN);                  // Set push-pull mode for led pin
    
    CLEAR_BITS(OSPEEDR(LED_PORT), 0x3 << (LED_PIN * 2));   // Clear speed bits
    SET_BITS(OSPEEDR(LED_PORT), 0x2 << (LED_PIN * 2));     // Set speed to Fast
    
    CLEAR_BITS(PUPDR(LED_PORT), 0x3 << (LED_PIN * 2));     // No pull-up, pull-down
}

void delay(volatile uint32_t cycles) {
    while(cycles --);
}

void toggle_led(void) {
    if (led_state() == 0u) {
        turn_led_on();
    } else {
        turn_led_off();
    }
}

uint8_t led_state(void) {
    return READ_BITS(ODR(LED_PORT), 1 << (LED_PIN));
}

void turn_led_on(void) {
    SET_PIN(ODR(LED_PORT), LED_PIN);
}

void turn_led_off(void) {
    RESET_PIN(ODR(LED_PORT), LED_PIN);
}

