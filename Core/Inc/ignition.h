/*
 * ignition.h
 *
 *  Created on: Aug 16, 2024
 *      Author: user
 */

#include "stm32g0xx_hal.h"


int calculate_rpm(int timer_counter);
int set_delay_by(int rpm);

#define IGNITE_MS 128
