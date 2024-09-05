#include <stdio.h>
#include <stdlib.h>
#include "parking.h"
#include "display.h"

void display_parking_status(Parking *p)
{
    printf("-------------------------------------\n");
    printf("Vagas ocupadas(Beco 1): %d carros\n", size(&p->beco1));
    printf("Vagas ocupadas(Beco 2): %d carros\n", size(&p->beco2));
    printf("Fila de espera: %d carros\n", p->queue_size);
    printf("-------------------------------------\n\n");
}

void car_parked(int car_id, int beco)
{
    system("clear");
    printf("Carro %d estacionado no Beco %d\n", car_id, beco);
}

void car_retrieved(int car_id, int maneuvers)
{
    system("clear");
    printf("Carro %d retirado com %d manobras\n", car_id, maneuvers);
}

void no_space_available()
{
    system("clear");
    printf("Sem vagas disponíveis no momento. Deseja entrar na fila de espera? (S/N)\n");
}

void queue_added(int car_id)
{
    system("clear");
    printf("Carro %d adicionado à fila de espera\n", car_id);
}

void display_parked_cars(Parking *p)
{
    system("clear");
    printf("Carros Estacionados:\n");

    printf("Beco 1:\n");
    for (int i = 0; i < size(&p->beco1); i++)
    {
        int car_id = get_car(&p->beco1, i);
        printf("Carro ID: %d\n", car_id);
    }

    printf("Beco 2:\n");
    for (int i = 0; i < size(&p->beco2); i++)
    {
        int car_id = get_car(&p->beco2, i);
        printf("Carro ID: %d\n", car_id);
    }

    printf("-------------------------------------\n");
}
