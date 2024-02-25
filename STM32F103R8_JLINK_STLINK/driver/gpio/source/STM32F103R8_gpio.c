
#include "STM32F103R8_gpio.h"

void CLOCK_GPIOB_ENABLE(void)
{
  RCC->RCC_APB2ENR |= (1UL<<3UL);
}

void GPIO_B8_SETOUTPUT(void)
{
  GPIOB->GPIO_CRH &= ~(0xFUL<<0);

  GPIOB->GPIO_CRH |= (0x3UL<<0); /* Output mode, max speed 50 MHz */
}

void GPIO_B9_SETOUTPUT(void)
{
  GPIOB->GPIO_CRH &= ~(0xFUL<<4);

  GPIOB->GPIO_CRH |= (0x3UL<<4); /* Output mode, max speed 50 MHz */
}

void GPIO_B10_SETOUTPUT(void)
{
  GPIOB->GPIO_CRH &= ~(0xFUL<<8);

  GPIOB->GPIO_CRH |= (0x3UL<<8); /* Output mode, max speed 50 MHz */
}

void GPIO_B11_SETOUTPUT(void)
{
  GPIOB->GPIO_CRH &= ~(0xFUL<<12);

  GPIOB->GPIO_CRH |= (0x3UL<<12); /* Output mode, max speed 50 MHz */
}

void GPIOB_WRITE(uint8_t PIN, HighLow_enum State)
{
  if(State==HIGH) GPIOB->GPIO_ODR |= (1UL<<PIN);
  else GPIOB->GPIO_ODR &= ~(1UL<<PIN);
}

void GPIO_B8_BLINK(void)
{
  GPIOB->GPIO_ODR ^= (1UL<<8UL);
}

void GPIO_B9_BLINK(void)
{
  GPIOB->GPIO_ODR ^= (1UL<<9UL);
}

void GPIO_B10_BLINK(void)
{
  GPIOB->GPIO_ODR ^= (1UL<<10UL);
}

void GPIO_B11_BLINK(void)
{
  GPIOB->GPIO_ODR ^= (1UL<<11UL);
}

void Delay(uint32_t Timer)
{
  uint32_t Count;
  uint32_t Count_2;
  for(Count=0; Count<=100; Count++)
	{
		for(Count_2=0; Count_2<=Timer; Count_2++);
	}
}


