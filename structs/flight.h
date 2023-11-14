#ifndef FLIGHT_H
#define FLIGHT_H

struct Flight
{
    int flightNumber;
    struct Plane plane;
    char flightDate[10];
    char flightTime[10];
};

#endif
