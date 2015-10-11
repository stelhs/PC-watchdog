/*
 * pump.c
 *
 *  Created on: 30 янв. 2015 г.
 *      Author: Michail Kurochkin
 */

#include <avr/wdt.h>
#include "types.h"
#include "config.h"
#include "gpio.h"
#include "init_hw.h"
#include "desktop.h"

volatile struct desktop_timers Desktop_timers;


/**
 * Выключить или включить питание компьютера
 * @param state - 1- вкл, 0 - выкл
 */
void
desktop_set_power_down(u8 mode)
{
    gpio_set_state(&gpio_list[MCU_GPIO_POWER_DOWN], mode);
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


/**
 * Получить состояние питания компьютера
 */
int
desktop_get_power_state(void)
{
    return !gpio_get_state(&gpio_list[MCU_GPIO_POWER_STATE]);
}

/**
 * Перегрузить сервер
 * Функция завершится только при появлении питания сервера
 */
void
desktop_reboot(void)
{
    bool desktop_power_state = OFF;

    for (;;) {
        desktop_set_power_down(ON);
        Desktop_timers.power_down = CONFIG_DELAY_POWER_DOWN;
        while (Desktop_timers.power_down > 1) {
            wdt_reset();
        }
        desktop_set_power_down(OFF);
        Desktop_timers.power_down = 0;

        Desktop_timers.wait_power = CONFIG_DELAY_WAIT_POWER;
        while (Desktop_timers.wait_power > 1) {
            desktop_power_state = desktop_get_power_state();
            if (desktop_power_state) {
                Desktop_timers.wait_power = 0;
                return;
            }
            wdt_reset();
        }

        desktop_set_power_button(ON);
        Desktop_timers.power_down = CONFIG_DELAY_POWER_BUTTON;
        while (Desktop_timers.power_down > 1) {
            wdt_reset();
        }
        desktop_set_power_button(OFF);
        Desktop_timers.power_down = 0;

        Desktop_timers.wait_power = CONFIG_DELAY_WAIT_POWER;
        while (Desktop_timers.wait_power > 1) {
            desktop_power_state = desktop_get_power_state();
            if (desktop_power_state) {
                Desktop_timers.wait_power = 0;
                return;
            }
            wdt_reset();
        }
    }
}


