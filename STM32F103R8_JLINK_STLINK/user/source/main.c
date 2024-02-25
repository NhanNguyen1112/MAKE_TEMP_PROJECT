
#include "main.h"

static void code_1(void)
{
	GPIOB_WRITE(8, LOW);
	GPIOB_WRITE(9, LOW);
	GPIOB_WRITE(10, LOW);
	GPIOB_WRITE(11, LOW);
}

static void code_2(void)
{
	uint8_t Count;
	for(Count=0; Count<=10; Count++)
	{
		GPIO_B8_BLINK();
		GPIO_B9_BLINK();
		GPIO_B10_BLINK();
		GPIO_B11_BLINK();
		Delay(10000);
	}

	GPIOB_WRITE(8, HIGH);
	GPIOB_WRITE(9, HIGH);
	GPIOB_WRITE(10, HIGH);
	GPIOB_WRITE(11, HIGH);
	Delay(30000);

	uint8_t Count2;
	for(Count2=0; Count2<=5; Count2++)
	{
		uint8_t Count_step;
		for(Count_step=0; Count_step<=3; Count_step++)
		{
			GPIOB_WRITE(8+Count_step, LOW);
			Delay(5000);
		}
		Delay(30000);
		for(Count_step=0; Count_step<=3; Count_step++)
		{
			GPIOB_WRITE(11-Count_step, HIGH);
			Delay(5000);
		}
		Delay(30000);
	}
}	
	

int main(void)
{
	CLOCK_GPIOB_ENABLE();
	GPIO_B8_SETOUTPUT();
	GPIO_B9_SETOUTPUT();
	GPIO_B10_SETOUTPUT();
	GPIO_B11_SETOUTPUT();
	
	while(1)
	{
		// code_1();
		code_2();
		
	}
}
