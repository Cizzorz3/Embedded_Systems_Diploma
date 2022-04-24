
#include <stdint.h>
#include <stdio.h>

#define RCC_BASE       0x40021000
#define PORTA_BASE     0x40010800

#define RCC_APB2ENR    *(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH      *(volatile uint32_t *) (PORTA_BASE + 0x04)
#define GPIOA_ODR      *(volatile uint32_t *) (PORTA_BASE + 0x0c)

#define RCC_IOPAEN      (1<<2)

typedef union
{

  struct 
  {
    volatile unsigned int reserved:13;
    volatile unsigned int bit13:1;
    
  } bits;

  volatile unsigned int TotValU;

} RegODR_t;

volatile RegODR_t* RegODR = (volatile RegODR_t*)(PORTA_BASE + 0x0c);

int main(void)
{
  RCC_APB2ENR |= RCC_IOPAEN;
  GPIOA_CRH   &= 0xFF0FFFFF;
  GPIOA_CRH   |= 0x00200000;

    while(1)
    {
      RegODR->bits.bit13= 1;
      for( int i=0; i<5000; i++);
      RegODR->bits.bit13= 0;
      for( int i=0; i<5000; i++);
    }

  return 0;
}