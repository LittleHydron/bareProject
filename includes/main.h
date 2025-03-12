#ifndef MAIN_HH

#define MAIN_HH

#include <stdint.h>

#include "registers_mapping.h"

#define LED_PIN  2
#define LED_PORT GPIOB

void init_gpio(void);
void delay(volatile uint32_t cycles);
void toggle_led(void);
uint8_t led_state(void);
void turn_led_on(void);
void turn_led_off(void);

#endif // MAIN_HH

