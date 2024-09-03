#include <stdio.h>
#include "parking.h"
#include "ui/display.c"

int main()
{
    Parking parking;
    init_parking(&parking);

    int option, car_id;

    do
    {
        display_parking_status(&parking);
        printf("1. Estacionar carro\n2. Retirar carro\n3. Sair\nEscolha uma opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite o ID do carro: ");
            scanf("%d", &car_id);
            if (!park_car(&parking, car_id))
            {
                char choice;
                scanf(" %c", &choice);
                if (choice == 'S' || choice == 's')
                {
                    add_to_queue(&parking, car_id);
                }
            }
            break;
        case 2:
            printf("Digite o ID do carro: ");
            scanf("%d", &car_id);
            if (retrieve_car(&parking, car_id) == -1)
            {
                printf("Carro não encontrado nos becos.\n");
            }
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (option != 3);

    return 0;
}
