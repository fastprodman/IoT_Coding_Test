#include "stm32f103x6.h"

#include "uart.h"
#include "led.h"
#include "command_parser.h"


char key;





int main(void){
	uart2_rxtx_init();
	led_init();

	char arr_rx[310];
	uint16_t arr_last = 0;

	while(1){
		key = uart_read(USART2);
		arr_rx[arr_last] = key;
		arr_last++;
		if(key=='\r'||arr_last==310){

			parse_string(arr_rx, arr_last);

			arr_last = 0;
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










