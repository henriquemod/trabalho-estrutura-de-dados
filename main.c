#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INITIAL_PLANES_SIZE 3
#define INITIAL_TICKETS_SIZE 0
#define INITIAL_FLIGHTS_SIZE 0

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#include "structs/plane.h"
#include "structs/flight.h"
#include "structs/ticket.h"
#include "menu/ui.c"
#include "menu/planes.c"
#include "menu/tickets.c"
#include "menu/flights.c"

int main()
{
    struct Plane *planes = getPlanes();
    struct Ticket *tickets = getTickets();
    printf("| Menu Principal\n");
    struct Flight *flights = getFlights();

    int numPlanes = INITIAL_PLANES_SIZE;
    int numTickets = INITIAL_TICKETS_SIZE;
    int numFlights = INITIAL_FLIGHTS_SIZE;
    bool exit = false;

    system(CLEAR_SCREEN);

    while (exit == false)
    {
        char *options[] = {
            "Aeronaves",
            "Voos",
            "Passagens",
        };
        int size = sizeof(options) / sizeof(options[0]);
        print_menu("UniVoos - Menu Principal", options, size);
        printf("Escolha uma opção: ");
        int option;
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            renderPlanesMenu(planes);
            break;
        case 2:
            renderFlightsMenu();
            break;
        case 3:
            renderTicketsMenu();
            break;
        case 9:
            exit = true;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }

    return 0;
}
