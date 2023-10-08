#include "stm32f103x6.h"

#include "uart.h"
#include "led.h"
#include "command_parser.h"


char key;
char arr_rx[310];
uint16_t arr_last = 0;
uint8_t parse_str_flag = 0;



int main(void){
	uart2_rxtx_interrupt_init();
	led_init();

	while(1){
		if(parse_str_flag != 0){
			parse_string(arr_rx, arr_last);
			arr_last = 0;
			parse_str_flag = 0;
		}
	}
}


void TIM2_IRQHandler(void){
	TIM2->SR &=~ TIM_SR_UIF;
	led_off(0);
}

void TIM3_IRQHandler(void){
	TIM3->SR &=~ TIM_SR_UIF;
	led_off(1);
}

void USART2_IRQHandler(void){
	if(USART2->SR & USART_SR_RXNE){
		key = USART2->DR;
		arr_rx[arr_last] = key;
		arr_last++;
		if(key=='\r'||arr_last==310){
			parse_str_flag = 1;
		}
	}
}










