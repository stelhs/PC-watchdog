/*
 * init.h
 *
 *  Created on: 11.02.2012
 *      Author: Michail Kurochkin
 */

#ifndef INIT_H_
#define INIT_H_

#include "gpio.h"
#include "types.h"

void
init_hw(void);

#define CLEAR_WATCHDOG() { asm("wdr"); }

/**
 * Список всех использующихся GPIO
 */
enum mcu_gpios {
    MCU_GPIO_POWER_DOWN,
    MCU_GPIO_POWER_BUTTON,
    MCU_GPIO_POWER_STATE,
};

extern struct gpio gpio_list[];

#endif /* INIT_H_ */
