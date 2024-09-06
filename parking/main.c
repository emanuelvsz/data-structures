#include <stdio.h>
#include <stdlib.h>

#include "parking.h"
#include "display.h"

void show_menu()
{
    printf("=== Estacionamento ===\n");
    printf("1. Estacionar carro\n");
    printf("2. Retirar carro\n");
    printf("3. Mostrar carros estacionados\n");
    printf("4. Sair\n");
    printf("======================\n");
    printf("Escolha uma opção: ");
}

int main()
{
    Parking parking;
    init_parking(&parking);

    int option, car_id;

    while (1)
    {
        show_menu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite o ID do carro para estacionar: ");
            scanf("%d", &car_id);
            if (!park_car(&parking, car_id))
            {
                printf("Não foi possível estacionar o carro.\n");
            }
            break;
        case 2:
            printf("Digite o ID do carro para retirar: ");
            scanf("%d", &car_id);
            if (retrieve_car(&parking, car_id) == -1)
            {
                printf("Carro não encontrado.\n");
            }
            break;
        case 3:
            display_parked_cars(&parking);
            break;
        case 4:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }

    return 0;
}
