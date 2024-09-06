#ifndef PARKING_H
#define PARKING_H
#define MAX_QUEUE 10

#include "stack.h"


typedef struct {
    Stack beco1;
    Stack beco2;
    int wait_queue[MAX_QUEUE];
    int queue_front;
    int queue_rear;
    int queue_size;
} Parking;

void init_parking(Parking *p);
int park_car(Parking *p, int car_id);
int retrieve_car(Parking *p, int car_id);
int add_to_queue(Parking *p, int car_id);
int remove_from_queue(Parking *p);
void process_queue(Parking *p);
void display_status(Parking *p);

#endif
