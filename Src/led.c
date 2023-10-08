#include "led.h"

#if LED_PIN0 < 9 || LED_PIN0 > 12
#error <choose led pin between 9 and 12>
#endif

#if LED_PIN1 < 9 || LED_PIN1 > 12
#error <choose led pin between 9 and 12>
#endif

#if LED_PIN0 == LED_PIN1
#error <choose different led pins>
#endif

void led_init(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	GPIOA->CRH &=~ (3U << ((LED_PIN0-8)*4+2));//6
	GPIOA->CRH |= (2U << ((LED_PIN0-8)*4));//4

	GPIOA->CRH &=~ (3U << ((LED_PIN1-8)*4+2));//10
	GPIOA->CRH |= (2U << ((LED_PIN1-8)*4));//8
}

void led_off(uint8_t led_id){
	if (led_id == 0){
		GPIOA->ODR &=~ (0x1UL << LED_PIN0);
		write_str("led_off: 0\r\n", 12);
	}

	if (led_id == 1){
		GPIOA->ODR &=~ (0x1UL << LED_PIN1);
		write_str("led_off: 1\r\n", 12);
	}
}

void led_on(uint8_t led_id, uint16_t time_ms){

	if (led_id == 0){
		GPIOA->ODR |= (0x1UL << LED_PIN0);
		tim2_start(time_ms);
	}

	if (led_id == 1){
		GPIOA->ODR |= (0x1UL << LED_PIN1);
		tim3_start(time_ms);
	}
}





