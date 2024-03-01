#include "stm32f10x.h"
#include "utils/arm_isr_attr.h"
#include "utils/tiny_console/tiny_console.h"

extern console_t* console;
extern volatile uint8_t rcv_flag;

void ARM_IRQ USART1_IRQHandler(void)
{
    if (USART_GetITStatus(USART1, USART_IT_RXNE)) {
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
        console_input_char(console, USART_ReceiveData(USART1));
        rcv_flag = 1;
    }

    // asm volatile('')
}
