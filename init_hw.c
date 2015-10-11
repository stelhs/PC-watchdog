/*
 * init.c
 *
 *  Created on: 11.02.2012
 *      Author: Michail Kurochkin
 */

#include <stdio.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include "timers.h"
#include "timers.h"
#include "gpio.h"
#include "config.h"
#include "init_hw.h"
#include "uart.h"


/**
 * Конфигурирование всех GPIO
 */
struct gpio gpio_list[] = {
        { // MCU_GPIO_POWER_DOWN
            .direction_addr = (u8 *) &DDRC,
            .port_addr = (u8 *) &PORTC,
            .pin = 2,
            .direction = GPIO_OUTPUT,
            .output_state = 0
        },
        { // MCU_GPIO_POWER_BUTTON
            .direction_addr = (u8 *) &DDRC,
            .port_addr = (u8 *) &PORTC,
            .pin = 3,
            .direction = GPIO_OUTPUT,
            .output_state = 0
        },
        { // MCU_GPIO_POWER_STATE
            .direction_addr = (u8 *) &DDRD,
            .port_addr = (u8 *) &PORTD,
            .pin_addr = (u8 *) &PIND,
            .pin = 7,
            .direction = GPIO_INPUT,
            .output_state = 1
        },
        { // Завершающий элемент
            .direction_addr = NULL,
            .port_addr = NULL,
        },
};





/**
 * Инициализация аппаратной части
 */
void
init_hw(void)
{
    gpio_init_list(gpio_list);
    usart_init();
    timer2_init();
    wdt_enable(WDTO_2S); // Включаем вэтчдог
    sei();
}

