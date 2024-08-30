/*
 * ingition.c
 *
 *  Created on: Aug 16, 2024
 *      Author: user
 */
#include "ignition.h"

uint16_t map_rpm[15] = {600, 800, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 7000, 8000};
uint16_t map_angle[15] = {0, 2, 5, 7, 12, 17, 21, 26, 30, 33, 35, 37, 40, 42, 45};

uint32_t calculate_rpm(uint32_t timer_counter){
	uint32_t rpm=0;
	if(timer_counter <= 10000){
	rpm = timer_counter*6;
	rpm = 64000/rpm;
	rpm = rpm*60;
	return rpm;
	} else {
		return 0;
	}
}

uint32_t set_delay_by_rpm(uint32_t rpm){

	uint32_t angle_dl=0, rpm_delay =0, angle= 0;
	float f_temp=0;
	for(int i =0; map_rpm[i]<=rpm; i++){
		angle = map_angle[i];
	}
	angle_dl= rpm/60;
	rpm_delay= 64000/angle_dl;
	f_temp = angle_dl/360;
	f_temp = angle*f_temp;
	angle_dl = rpm_delay -f_temp;
	angle_dl = angle_dl-128;
	return angle_dl;
}






//600rpm = 1066 counter
