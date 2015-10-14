/*
 * config.h
 *
 *  Created on: 25.01.2014
 *      Author: Michail Kurochkin
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define CONFIG_DELAY_POWER_DOWN 3000 // Интервал отключения питания сервера
#define CONFIG_DELAY_WAIT_POWER 5000 // Интервал появления питания после включения сервера
#define CONFIG_DELAY_POWER_BUTTON 600 // Время удержания кнопки питания сервера

#define CONFIG_DELAY_WAIT_FIRST_PING (1000 * 60 * 5) // Время ожидания загрузки сервера
#define CONFIG_DELAY_WAIT_PING 30000 // Максимальный интервал между пингами
#define CONFIG_PING_BYTE 'Y' // Байт интерпретируемый как PING от сервера


#endif /* CONFIG_H_ */
