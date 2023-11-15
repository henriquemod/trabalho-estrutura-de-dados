#ifndef FLIGHT_H
#define FLIGHT_H

struct Flight
{
    int flightNumber;
    struct Plane plane;
    char flightDate[10];
    char flightTime[10];
};

struct Flight *getFlights()
{
    struct Flight *flights = NULL;
    flights = (struct Flight *)malloc(sizeof(struct Flight) * 0);
    if (flights == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return flights;
}

#endif
