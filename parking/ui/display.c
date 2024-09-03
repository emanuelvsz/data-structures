#include <stdio.h>
#include "parking.h"
#include "display.h"

void display_parking_status(Parking *p) {
    printf("Status do Estacionamento:\n");
    printf("Beco 1: %d carros\n", size(&p->beco1));
    printf("Beco 2: %d carros\n", size(&p->beco2));
    printf("Fila de espera: %d carros\n\n", p->queue_size);
}

void car_parked(int car_id, int beco) {
    printf("Carro %d estacionado no Beco %d\n", car_id, beco);
}

void car_retrieved(int car_id, int maneuvers) {
    printf("Carro %d retirado com %d manobras\n", car_id, maneuvers);
}

void no_space_available() {
    printf("Sem vagas disponíveis no momento. Deseja entrar na fila de espera? (S/N)\n");
}

void queue_added(int car_id) {
    printf("Carro %d adicionado à fila de espera\n", car_id);
}
