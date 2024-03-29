
#include "main.h"

void delay(void)
{
	for (uint32_t i = 0; i < 500000 / 2; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed;
	uint8_t count =0;

	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&GpioLed);

  while(1)
  {
    GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);

    delay();
    delay();
		delay();
    delay();
    delay();
		delay();		
  }
}
