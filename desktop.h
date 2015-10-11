/*
 * pump.h
 *
 *  Created on: 30 янв. 2015 г.
 *      Author: Michail Kurochkin
 */
#ifndef DESKTOP_H_
#define DESKTOP_H_

#include "timers.h"

/**
 * Таймеры для управления питанием сервера
 */
struct desktop_timers {
    t_counter power_down; // Счетчик отсутсвия питания сервера
    t_counter wait_power; // Счетчик ожидания появления питания
};
extern volatile struct desktop_timers Desktop_timers;

void
desktop_set_power_down(u8 mode);

void
desktop_set_power_button(u8 mode);

int
desktop_get_power_state(void);

void
desktop_reboot(void);


#endif /* DESKTOP_H_ */
