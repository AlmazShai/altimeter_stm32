#include "dbgout.h"

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#include "stm32f1xx_hal.h"

static UART_HandleTypeDef huart1;

int dbgout_init(void)
{

	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
	    return -1;
	}
	return 0;
}

void dbgout_print(const char* format, ...)
{
    char buf[DBGOUT_TX_BUFFER_SIZE] = { 0 };
    int ret = 1;

    if (format == NULL)
    	return;

    va_list args;
    va_start(args, format);
    ret = vsprintf(buf, format, args);
    va_end(args);

    if (!ret)
    	return;

    strcat(buf, "\r\n");

    HAL_UART_Transmit(&huart1, (uint8_t*)buf, strlen(buf), 1000);
}

