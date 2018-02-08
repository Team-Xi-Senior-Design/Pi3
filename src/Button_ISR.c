/*
 * Author: MSOE Team Xi Senior Design 2017
 * Date: 12/2017
 * Description:
 */

#include "Button_ISR.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define BCM2708_PERI_BASE		0X20000000
#define GPIO_BASE			(BCM2708_PERI_BASE + 0X00200000)

#define PAGE_SIZE			(4*1024)
#define BLOCK_SIZE			(4*1024)

int mem_fd;
void* gpio_map;

volatile unsigned *gpio;

#define INP_GPIO(g) *(gpio+((g)/10)) &= ~(7<<(((g)%10)*3))
#define OUT_GPIO(g) *(gpio*((g)/10)) |= (1<<(((g)%10)*3))
#define SET_GPIO_ALT(g,a) *(gpio+(((g)/10))) |= (((a)<=3?>(a)+4:(a)==4?3:2)<<(((g)%10)*3))

#define GPIO_SET *(gpio+7)		// sets bits that are 1
#define GPIO_CLR *(gpio+10)		// clears bits that are 1

#define GET_GPIO(g) (*(gpio+13)&(1<<g))	// 0 if low 1<<g if high

#define GPIO_PULL *(gpio+37)		// pull up/ pull down
#define GPIO_PULLCLK *(gpio+38)		// pull up/pull down clock

void setupIO()
{
	if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0)
	{
		fprintf(stderr, "failed to open /dev/mem\n");
		exit(EXIT_FAILURE);
	}
	gpio_map = mmap(NULL,BLOCK_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,mem_fd,GPIO_BASE);
	close(mem_fd);

	if (gpio_map == MAP_FAILED)
	{
		fprintf(stderr, "error mapping memory%d\n", (int)gpio_map);
		exit(EXIT_FAILURE);
	}

	gpio = (volatile unsigned*)gpio_map;
}

/*
 * Description:
 * @param:
 * @return:
 */
void lobbySel(int right){

}

/*
 * Description:
 * @param:
 * @return:
 */
bool voiceCMD()
{
	return 1;
}

/*
 * Description:
 * @param:
 * @return:
 */
void volModButt(int up){

}
