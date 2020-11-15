#ifndef ADRESSES_H
#define ADRESSES_H

#include "types.h"

// Define the base addresses for peripherals
#define PERIPH_BASE     ((uint32_t) 0x40000000)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE (PERIPH_BASE + 0x08000000)

#define RCC_BASE        (AHBPERIPH_BASE + 0x1000)
#define FLASH_BASE      (AHBPERIPH_BASE + 0x2000)

#define GPIOA_BASE      (AHB2PERIPH_BASE)
#define GPIOB_BASE      (AHB2PERIPH_BASE + 0x400)
#define GPIOC_BASE      (AHB2PERIPH_BASE + 0x800)
#define DMA1_BASE       (AHBPERIPH_BASE)

#define TIM6_BASE       (PERIPH_BASE + 0x1000)
#define TIM14_BASE      (PERIPH_BASE + 0x2000)
#define SYSCFG_BASE     (PERIPH_BASE + 0x10000)
#define EXTI_BASE       (SYSCFG_BASE + 0x400)
#define SPI1_BASE       (SYSCFG_BASE + 0x3000)
#define USART1_BASE     (PERIPH_BASE + 0x13800)
#define USART2_BASE     (PERIPH_BASE + 0x4400)

#define STK_BASE        ((uint32_t) 0xE000E010)
#define NVIC_BASE       ((uint32_t) 0xE000E100)

#define RCC             ((rcc_t     *)  RCC_BASE)
#define FLASH           ((flash_t   *)  FLASH_BASE)
#define GPIOA           ((gpio_t    *)  GPIOA_BASE)
#define GPIOB           ((gpio_t    *)  GPIOB_BASE)
#define GPIOC           ((gpio_t    *)  GPIOC_BASE)
#define DMA1            ((dma_t     *)  DMA1_BASE)
#define TIM6            ((tim_t     *)  TIM6_BASE)
#define TIM14           ((tim_t     *)  TIM14_BASE)
#define SYSCFG          ((syscfg_t  *)  SYSCFG_BASE)
#define EXTI            ((exti_t    *)  EXTI_BASE)
#define SPI1            ((spi_t     *)  SPI1_BASE)
#define USART1          ((usart_t   *)  USART1_BASE)
#define USART2          ((usart_t   *)  USART2_BASE)
#define NVIC            ((nvic_t    *)  NVIC_BASE)
#define STK             ((systick_t *)  STK_BASE)
typedef struct 
{
  uint32_t CR;
  uint32_t CFGR;
  uint32_t CIR;
  uint32_t APB2RSTR;
  uint32_t APB1RSTR;
  uint32_t AHBENR;
  uint32_t APB2ENR;
  uint32_t APB1ENR;
  uint32_t BDCR;
  uint32_t CSR;
  uint32_t AHBRSTR;
  uint32_t CFGR2;
  uint32_t CFGR3;
  uint32_t CR2; 
} rcc_t;

typedef struct
{
	uint32_t ACR;
	uint32_t KEYR;
	uint32_t OPTKEYR;
	uint32_t SR;
	uint32_t CR;
	uint32_t AR;
	uint32_t RESERVED;
	uint32_t OBR;
	uint32_t WRPR;
} flash_t;

typedef struct 
{
  uint32_t CFGR1;
  uint32_t reserved0;
  uint32_t EXTICR1;
  uint32_t EXTICR2;
  uint32_t EXTICR3;
  uint32_t EXTICR4;
} syscfg_t;

typedef struct
{
  uint32_t IMR;
  uint32_t EMR;
  uint32_t RTSR;
  uint32_t FTSR;
  uint32_t SWIER;
  uint32_t PR;
} exti_t;

typedef struct 
{
  uint32_t CR1;
  uint32_t CR2;
  uint32_t SR;
  uint32_t DR;
  uint32_t CRCPR;
  uint32_t RXCRCR;
  uint32_t TXCRCR;
}spi_t;

typedef struct {
  uint32_t MODER;
  uint32_t OTYPER;
  uint32_t OSPEEDR;
  uint32_t PUPDR;
  uint32_t IDR;
  uint32_t ODR;
  uint32_t BSRR;
  uint32_t LCKR;
  uint32_t AFRL;
  uint32_t AFRH;    
} gpio_t;

typedef struct
{
	uint32_t ISR;
	uint32_t IFCR;
	uint32_t CCR1;
	uint32_t CNDTR1;
	uint32_t CPAR1;
	uint32_t CMAR1;
	uint32_t RESERVED1;
	uint32_t CCR2;
	uint32_t CNDTR2;
	uint32_t CPAR2;
	uint32_t CMAR2;
	uint32_t RESERVED2;
	uint32_t CCR3;
	uint32_t CNDTR3;
	uint32_t CPAR3;
	uint32_t CMAR3;
	uint32_t RESERVED3;
	uint32_t CCR4;
	uint32_t CNDTR4;
	uint32_t CPAR4; 
	uint32_t CMAR4;
	uint32_t RESERVED4;
	uint32_t CCR5;
	uint32_t CNDTR5;
	uint32_t CPAR5;
	uint32_t CMAR5;
} dma_t;


typedef struct {
  uint32_t CR1;
  uint32_t CR2;
  uint32_t SMCR;
  uint32_t DIER;
  uint32_t SR;
  uint32_t EGR;
  uint32_t CCMR1;
  uint32_t CCMR2;
  uint32_t CCER;
  uint32_t CNT;
  uint32_t PSC;
  uint32_t ARR; // Reset value is 0xFFFF
}tim_t;

typedef struct {
  uint32_t CR1;
  uint32_t CR2;
  uint32_t CR3;
  uint32_t BRR;
  uint32_t GTPR;
  uint32_t RTOR;
  uint32_t RQR;
  uint32_t ISR;
  uint32_t ICR;
  uint32_t RDR;
  uint32_t TDR;
}usart_t;

typedef struct {
  uint32_t ISER;
  uint32_t reserved0[19];
  uint32_t ICER;
  uint32_t reserved1[4];
  uint32_t ISPR;
  uint32_t reserved3[19];
  uint32_t ICPR;

}nvic_t;

typedef struct{
  uint32_t CSR;
  uint32_t RVR;
  uint32_t CVR;
  uint32_t CALIB;
} systick_t;

#endif
