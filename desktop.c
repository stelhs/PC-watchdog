/*
 * pump.c
 *
 *  Created on: 30 янв. 2015 г.
 *      Author: Michail Kurochkin
 */

#include "types.h"
#include "config.h"
#include "gpio.h"
#include "init_hw.h"

//struct desktop_timers Desktop_timers;


/**
 * Выключить или включить питание компьютера
 * @param state - 1- вкл, 0 - выкл
 */
void
desktop_set_power_down(u8 mode)
{
    gpio_set_state(&gpio_list[MCU_GPIO_POWER_DOWN], !mode);
}


/**
 * Выключить или включить кнопку питания компьютера
 * @param state - 1- вкл, 0 - выклtn
 */
void
desktop_set_power_button(u8 mode)
{
    gpio_set_state(&gpio_list[MCU_GPIO_POWER_BUTTON], mode);
}

