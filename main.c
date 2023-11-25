#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INITIAL_PLANES_SIZE 0
#define INITIAL_TICKETS_SIZE 0
#define INITIAL_FLIGHTS_SIZE 0
#define MOCKED_PLANES_SIZE 3
#define DEVELOPMENT true

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

bool quit;
int num_planes_available;
int num_flights_available;
int num_tickets_available;

struct Plane *planes = NULL;
struct Flight *flights = NULL;
struct Ticket *tickets = NULL;

int main()
{
    quit = false;
    num_planes_available = INITIAL_PLANES_SIZE;
    num_flights_available = INITIAL_FLIGHTS_SIZE;
    num_tickets_available = INITIAL_TICKETS_SIZE;

    planes = (struct Plane *)malloc(sizeof(struct Plane) * num_planes_available);
    flights = (struct Flight *)malloc(sizeof(struct Flight) * num_flights_available);
    tickets = (struct Ticket *)malloc(sizeof(struct Ticket) * num_tickets_available);

    if (planes == NULL || tickets == NULL || flights == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    if (DEVELOPMENT == true)
    {
        planes = (struct Plane *)realloc(planes, sizeof(struct Plane) * MOCKED_PLANES_SIZE);
        struct Plane *planes_mock = get_planes();
        memcpy(planes, planes_mock, sizeof(struct Plane) * MOCKED_PLANES_SIZE);
        free(planes_mock);
        num_planes_available = MOCKED_PLANES_SIZE;
    }

    void realloc_planes_callback(struct Plane * new_plane)
    {
        num_planes_available++;
        planes = (struct Plane *)realloc(planes, sizeof(struct Plane) * num_planes_available);
        struct Plane planeToInsert = *new_plane;
        free(new_plane);
        planes[num_planes_available - 1] = planeToInsert;
    }

    void realloc_flights_callback(struct Flight * new_flight)
    {
        num_flights_available++;
        flights = (struct Flight *)realloc(flights, sizeof(struct Flight) * num_flights_available);
        struct Flight flightToInsert = *new_flight;
        free(new_flight);
        flights[num_flights_available - 1] = flightToInsert;
    }

    void realloc_tickets_callback(struct Ticket * new_ticket)
    {
        num_tickets_available++;
        tickets = (struct Ticket *)realloc(tickets, sizeof(struct Ticket) * num_tickets_available);
        struct Ticket ticketToInsert = *new_ticket;
        free(new_ticket);
        tickets[num_tickets_available - 1] = ticketToInsert;
    }

    void remove_callback(char entry[10])
    {
        if (strcmp(entry, "plane") == 0)
        {
            num_planes_available--;
            planes = (struct Plane *)realloc(planes, sizeof(struct Plane) * num_planes_available);
        }
        if (strcmp(entry, "ticket") == 0)
        {
            num_tickets_available--;
            tickets = (struct Ticket *)realloc(tickets, sizeof(struct Ticket) * num_tickets_available);
        }
        if (strcmp(entry, "flight") == 0)
        {
            num_flights_available--;
            flights = (struct Flight *)realloc(flights, sizeof(struct Flight) * num_flights_available);
        }
    }

    while (quit == false)
    {
        system(CLEAR_SCREEN);
        print_menu("UniVoos - Menu Principal");
        printf("Escolha uma opção: ");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            render_planes_menu(planes, num_planes_available, remove_callback, realloc_planes_callback);
            break;
        case 2:
            render_flights_menu(planes, num_planes_available, flights, num_flights_available, remove_callback, realloc_flights_callback);
            break;
        case 3:
            render_tickets_menu(flights, num_flights_available, tickets, num_tickets_available, remove_callback, realloc_tickets_callback);
            break;
        case 9:
            quit = true;
            break;
        }
    }

    return 0;
}
