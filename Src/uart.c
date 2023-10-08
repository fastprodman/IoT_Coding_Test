#include "uart.h"


static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BoudRate){
	return ((PeriphClk + (BoudRate/2U))/BoudRate);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BoudRate){
	USARTx->BRR = compute_uart_div(PeriphClk, BoudRate);
}

void uart2_tx_init(void){
//	PA2 init
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOA->CRL |= (3UL << GPIO_CRL_CNF2_Pos);
	GPIOA->CRL |= (3UL << GPIO_CRL_MODE2_Pos);

//	UART init
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	USART2->CR1 = USART_CR1_TE | USART_CR1_UE;
}

void uart2_rxtx_init(void){

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	GPIOA->CRL = (GPIOA->CRL |(1U<<9)|(1U<<8)|(1U<<11))&~(1U<<10);

	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	USART2->CR1 = USART_CR1_TE | USART_CR1_UE | USART_CR1_RE;
}

void uart2_rxtx_interrupt_init(void){

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	GPIOA->CRL = (GPIOA->CRL |(1U<<9)|(1U<<8)|(1U<<11))&~(1U<<10);

	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	NVIC_EnableIRQ(USART2_IRQn);

	USART2->CR1 = USART_CR1_RXNEIE | USART_CR1_TE | USART_CR1_UE | USART_CR1_RE;
}

void uart_write(USART_TypeDef *UARTx, int ch){
	while (!(UARTx->SR & USART_SR_TXE));
	UARTx->DR = (ch & 0xFF);
}

char uart_read(USART_TypeDef *UARTx){
	while(!(UARTx->SR & USART_SR_RXNE));
	return UARTx->DR;
}

void write_str(char* ch_arr, uint16_t size){
	for (int i = 0; i < (size); i++){
		uart_write(USART2, ch_arr[i]);
	}
}
