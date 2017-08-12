#ifndef _gpio_driver_h_
#define _gpio_driver_h_

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h> 
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Stevan Milic");
MODULE_DESCRIPTION("A gpio driver for the BBB");
MODULE_VERSION("0.1");

#define DEVICE_NAME "bbgpio"
#define CLASS_NAME  "bb"

#define GPIOS_LEN 65

enum Direction {IN, OUT};

struct Gpio {
	unsigned int id;
	unsigned int value;
	unsigned int direction;
	unsigned int irq;
	bool exported;
};

static ssize_t gpio_init(struct Gpio *, int pid);
static void gpio_exit(struct Gpio *);

static struct Gpio gpios[GPIOS_LEN];

static unsigned int gpio_value;

#endif
