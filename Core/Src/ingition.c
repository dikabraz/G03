/*
 * ingition.c
 *
 *  Created on: Aug 16, 2024
 *      Author: user
 */
#include "ignition.h"

uint16_t map_rpm[15] = {600, 800, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 7000, 8000};
uint16_t map_angle[15] = {0, 2, 3, 7, 12, 17, 21, 26, 30, 33, 35, 37, 40, 42, 45};

int rpm_conversion(int timer_counter){
	int rpm=0;
	rpm = timer_counter*6;
	rpm = 64000/rpm;
	rpm = rpm*60;
	return rpm;
}

int set_delay_by(int rpm){
	float angle_delay= 0, rpm_delay =0, angle= 0;

	if(rpm >= 600){
		for(int i =0; map_rpm[i]<rpm; i++){
			angle = map_angle[i];
		}
		angle_delay= rpm/60;
		rpm_delay= 64000/angle_delay; //1280 3000 25%
		angle_delay = rpm_delay/360;
		angle= angle*angle_delay;
		angle_delay = rpm_delay -angle;
		angle_delay = angle_delay - IGNITE_MS;

	} else {
		angle_delay= 130;
	}

	int pizdos = angle_delay;
	return pizdos;
}



//600rpm = 1066 counter
