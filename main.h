/*
 * main.h
 *
 *  Created on: 12 окт. 2015 г.
 *      Author: Michail Kurochkin
 */
#ifndef MAIN_H_
#define MAIN_H_


/**
 * Таймеры для основной программы
 */
struct main_timers {
    t_counter wait_ping; // таймер ожидания PING сообщения от сервера
};
extern volatile struct main_timers Main_timers;


#endif /* MAIN_H_ */
