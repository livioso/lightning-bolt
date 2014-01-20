#include <stdio.h>

#define PAGE_SIZE (4*1024)
#define BLOCK_SIZE (4*1024)
#define BCM2708_PERI_BASE 0x20000000
#define GPIO_CONTROLLER_BASE_OFFSET 0x200000
#define GPIO_CONTROLLER_BASE (BCM2708_PERI_BASE + GPIO_CONTROLLER_BASE_OFFSET)

volatile unsigned* gpio;
// GPIO setup macros. Always use INP_GPIO
// before using OUT_GPIO or SET_GPIO_ALT
#define INP_GPIO(g) *(gpio + ((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio + ((g)/10)) |= (1<<(((g)%10)*3))
#define SET_GPIO_ALT(g,a) *(gpio + (((g)/10))) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3))

#define GPIO_SET *(gpio + 7)
#define GPIO_CLR *(gpio + 10)

int main (int argc, char* argv[])
{ 
	printf("lightning bolt reporting for duty :)\n");
	return 0;
}