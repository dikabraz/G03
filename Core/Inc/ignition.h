/*
 * ignition.h
 *
 *  Created on: Aug 16, 2024
 *      Author: user
 */
#ifndef __IGNITION_H
#define __IGNITION_H
#include "stm32g0xx_hal.h"

uint16_t map_rpm[15] = {600, 800, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 7000, 8000};
uint16_t map_angle[15] = {0, 2, 3, 7, 12, 17, 21, 26, 30, 33, 35, 37, 40, 42, 45};
int calculate_rpm(int timer_counter);
int set_delay_by(int rpm);

#define IGNITE_MS 128
#endif
