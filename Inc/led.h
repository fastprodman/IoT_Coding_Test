/*
 * led.h
 *
 *  Created on: Oct 7, 2023
 *      Author: stasj
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f103x6.h"
#include "tim.h"
#include "uart.h"

#if LED_PIN0 < 9 || LED_PIN0 > 12
#error <choose led pin between 9 and 12>
#endif

#if LED_PIN1 < 9 || LED_PIN1 > 12
#error <choose led pin between 9 and 12>
#endif

#if LED_PIN0 == LED_PIN1
#error <choose different led pins>
#endif

void led_init(void);


void led_off(uint8_t led_id);
void led_on(uint8_t led_id, uint16_t time_ms);

#endif /* LED_H_ */
