#include "uart.h"

void tim2_start(uint16_t time_ms){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->ARR = (time_ms * 10) - 1;
	TIM2->PSC = 800 - 1;
	TIM2->CNT = 0;
	TIM2->DIER &=~ TIM_DIER_UIE;
	TIM2->CR1 |= TIM_CR1_OPM;
	TIM2->EGR |= TIM_EGR_UG;
	TIM2->SR &=~ TIM_SR_UIF;
	TIM2->CR1 |= TIM_CR1_CEN;
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
}

void tim3_start(uint16_t time_ms){
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->ARR = (time_ms * 10) - 1;
	TIM3->PSC = 800 - 1;
	TIM3->CNT = 0;
	TIM3->DIER &=~ TIM_DIER_UIE;
	TIM3->CR1 |= TIM_CR1_OPM;
	TIM3->EGR |= TIM_EGR_UG;
	TIM3->SR &=~ TIM_SR_UIF;
	TIM3->CR1 |= TIM_CR1_CEN;
	TIM3->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM3_IRQn);
}

