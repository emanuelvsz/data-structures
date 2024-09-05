#ifndef DISPLAY_H
#define DISPLAY_H

#include "parking.h" 

void display_parking_status(Parking *p);
void car_parked(int car_id, int beco);
void car_retrieved(int car_id, int maneuvers);
void no_space_available();
void queue_added(int car_id); 
void display_parked_cars(Parking *p);

#endif
