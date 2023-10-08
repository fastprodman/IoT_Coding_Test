#ifndef UART_H_
#define UART_H_


#include "stm32f103x6.h"
#include "stdint.h"

#define SYS_FREQ		8000000
#define APB1_CLK		SYS_FREQ

#ifndef UART_BAUDRATE
#define UART_BAUDRATE	115200
#endif

#if UART_BAUDRATE < 1
#error <define positive boundrate>
#endif


void uart2_tx_init(void);
void uart2_rxtx_init(void);
char uart_read(USART_TypeDef *UARTx);
void uart_write(USART_TypeDef *UARTx, int ch);
void write_str(char* ch_arr, uint16_t size);




#endif /* UART_H_ */
