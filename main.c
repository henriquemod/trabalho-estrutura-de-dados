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

typedef void (*Callback)(char entry[10]);
typedef void (*ReallocCallback)(struct Plane *plane);

int main()
{
    int numPlanes = INITIAL_PLANES_SIZE;
    int numTickets = INITIAL_TICKETS_SIZE;
    int numFlights = INITIAL_FLIGHTS_SIZE;

    struct Plane *planes = NULL;
    struct Ticket *tickets = NULL;
    struct Flight *flights = NULL;

    planes = (struct Plane *)malloc(sizeof(struct Plane) * numPlanes);
    tickets = (struct Ticket *)malloc(sizeof(struct Ticket) * numTickets);
    flights = (struct Flight *)malloc(sizeof(struct Flight) * numFlights);

    if (planes == NULL || tickets == NULL || flights == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    getPlanes(planes);
    getTickets(tickets);
    getFlights(flights);

    void remove_callback(char entry[10])
    {
        if (strcmp(entry, "plane") == 0)
        {
            numPlanes--;
            planes = (struct Plane *)realloc(planes, sizeof(struct Plane) * numPlanes);
        }
        if (strcmp(entry, "ticket") == 0)
        {
            numTickets--;
            tickets = (struct Ticket *)realloc(tickets, sizeof(struct Ticket) * numTickets);
        }
        if (strcmp(entry, "flight") == 0)
        {
            numFlights--;
            flights = (struct Flight *)realloc(flights, sizeof(struct Flight) * numFlights);
        }
    }

    void realloc_callback(struct Plane * new_plane)
    {
        numPlanes++;
        planes = (struct Plane *)realloc(planes, sizeof(struct Plane) * numPlanes);
        struct Plane planeToInsert = *new_plane;
        free(new_plane);
        planes[numPlanes - 1] = planeToInsert;
    }

    bool quit = false;

    while (quit == false)
    {
        system(CLEAR_SCREEN);
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
            renderPlanesMenu(planes, numPlanes, remove_callback, realloc_callback);
            break;
        case 2:
            renderFlightsMenu(tickets, numTickets);
            break;
        case 3:
            renderTicketsMenu(tickets, numTickets);
            break;
        case 9:
            quit = true;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }

    return 0;
}
