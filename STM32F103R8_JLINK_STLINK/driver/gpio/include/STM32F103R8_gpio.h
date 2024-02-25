
#ifndef __GPIO__
#define __GPIO__

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef enum 
{
  FALSE,
  TRUE
}TrueFalse_enum;

typedef enum
{
  LOW,
  HIGH
}HighLow_enum;

/*=============================================================
                      GPIO
=============================================================*/
typedef struct 
{
  volatile uint32_t GPIO_CRL;
  volatile uint32_t GPIO_CRH;
  volatile uint32_t GPIO_IDR;
  volatile uint32_t GPIO_ODR;
  volatile uint32_t GPIO_BSRR;
  volatile uint32_t GPIO_BRR;
  volatile uint32_t GPIO_LCKR;
}GPIO_typedef;

#define GPIOA_BASE_ADDRESS (0x40010800UL)
#define GPIOB_BASE_ADDRESS (0x40010C00UL)
#define GPIOC_BASE_ADDRESS (0x40011000UL)
#define GPIOD_BASE_ADDRESS (0x40011400UL)
#define GPIOE_BASE_ADDRESS (0x40011800UL)
#define GPIOF_BASE_ADDRESS (0x40011C00UL)
#define GPIOG_BASE_ADDRESS (0x40012000UL)

#define GPIOA ( (GPIO_typedef*)GPIOA_BASE_ADDRESS )
#define GPIOB ( (GPIO_typedef*)GPIOB_BASE_ADDRESS )
#define GPIOC ( (GPIO_typedef*)GPIOC_BASE_ADDRESS )
#define GPIOD ( (GPIO_typedef*)GPIOD_BASE_ADDRESS )
#define GPIOE ( (GPIO_typedef*)GPIOE_BASE_ADDRESS )
#define GPIOF ( (GPIO_typedef*)GPIOF_BASE_ADDRESS )
#define GPIOG ( (GPIO_typedef*)GPIOG_BASE_ADDRESS )
/*===========================================================*/

/*=============================================================
                       CLOCK
=============================================================*/
typedef struct 
{
  volatile uint32_t RCC_CR;
  volatile uint32_t RCC_CFGR;
  volatile uint32_t RCC_CIR;
  volatile uint32_t RCC_APB2RSTR;
  volatile uint32_t RCC_APB1RSTR;
  volatile uint32_t RCC_AHBENR;
  volatile uint32_t RCC_APB2ENR;
  volatile uint32_t RCC_APB1ENR;
  volatile uint32_t RCC_BDCR;
  volatile uint32_t RCC_CSR;
  volatile uint32_t RCC_AHBSTR;
  volatile uint32_t RCC_CFGR2;
}RCC_typedef;

#define RCC_BASE_ADDRESS (0x40021000UL)
#define RCC              ( (RCC_typedef*)RCC_BASE_ADDRESS )

/*===========================================================*/

/*=============================================================
                       GLOBAL FUNCTIONS
=============================================================*/
void CLOCK_GPIOB_ENABLE(void);
void GPIO_B8_SETOUTPUT(void);
void GPIO_B9_SETOUTPUT(void);
void GPIO_B10_SETOUTPUT(void);
void GPIO_B11_SETOUTPUT(void);
void GPIOB_WRITE(uint8_t PIN, HighLow_enum State);
void GPIO_B8_BLINK(void);
void GPIO_B9_BLINK(void);
void GPIO_B10_BLINK(void);
void GPIO_B11_BLINK(void);
void Delay(uint32_t Timer);
/*===========================================================*/

#endif /* __GPIO__ */

