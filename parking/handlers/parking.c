#include "parking.h"
#include <stdio.h>

void init_parking(Parking *p)
{
    init_stack(&p->beco1);
    init_stack(&p->beco2);
    p->queue_front = 0;
    p->queue_rear = -1;
    p->queue_size = 0;
}

int park_car(Parking *p, int car_id)
{
    if (!is_full(&p->beco1))
    {
        push(&p->beco1, car_id);
        car_parked(car_id, 1);
        return 1;
    }
    else if (!is_full(&p->beco2))
    {
        push(&p->beco2, car_id);
        car_parked(car_id, 2);
        return 1;
    }
    else
    {
        no_space_available();
        return 0;
    }
}

int retrieve_car(Parking *p, int car_id)
{
    int maneuvers = 0;
    Stack *beco;

    if (peek(&p->beco1) == car_id)
    {
        beco = &p->beco1;
    }
    else if (peek(&p->beco2) == car_id)
    {
        beco = &p->beco2;
    }
    else
    {
        return -1;
    }

    Stack temp_stack;
    init_stack(&temp_stack);

    while (peek(beco) != car_id)
    {
        push(&temp_stack, pop(beco));
        maneuvers++;
    }

    pop(beco);
    maneuvers++;

    while (!is_empty(&temp_stack))
    {
        push(beco, pop(&temp_stack));
    }

    car_retrieved(car_id, maneuvers);
    process_queue(p);

    return maneuvers;
}

int add_to_queue(Parking *p, int car_id)
{
    if (p->queue_size < MAX_QUEUE)
    {
        p->queue_rear = (p->queue_rear + 1) % MAX_QUEUE;
        p->wait_queue[p->queue_rear] = car_id;
        p->queue_size++;
        queue_added(car_id);
        return 1;
    }
    return 0;
}

int remove_from_queue(Parking *p)
{
    if (p->queue_size == 0)
        return -1;
    int car_id = p->wait_queue[p->queue_front];
    p->queue_front = (p->queue_front + 1) % MAX_QUEUE;
    p->queue_size--;
    return car_id;
}

void process_queue(Parking *p)
{
    while (p->queue_size > 0 && (is_empty(&p->beco1) || is_empty(&p->beco2)))
    {
        int car_id = remove_from_queue(p);
        park_car(p, car_id);
    }
}
