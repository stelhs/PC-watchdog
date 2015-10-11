/*
 * main.c
 *
 *  Created on: 25.01.2014
 *      Author: Michail Kurochkin
 */

#include <stdio.h>
#include <avr/wdt.h>
#include "init_hw.h"
#include "config.h"
#include "uart.h"
#include "main.h"
#include "desktop.h"

volatile struct main_timers Main_timers;

int
main(void)
{
    char ch;
    init_hw();
    printf("Init - ok\r\n");

    Main_timers.wait_ping = CONFIG_DELAY_WAIT_FIRST_PING;

    for (;;) {
        if (Main_timers.wait_ping == 1) {
            printf("Server goes to reboot\r\n");
            desktop_reboot();
            printf("reboot success\r\n");
            Main_timers.wait_ping = CONFIG_DELAY_WAIT_FIRST_PING;
        }

        ch = usart_get();
        if (ch == CONFIG_PING_BYTE) {
            printf("ping received\r\n");
            Main_timers.wait_ping = CONFIG_DELAY_WAIT_PING;
        }
        wdt_reset();
    }
}

