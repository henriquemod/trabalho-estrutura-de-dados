#ifndef FLIGHT_H
#define FLIGHT_H

struct Flight
{
    int flightNumber;
    struct Plane plane;
    char flightDate[10];
    char flightTime[10];
};

struct Flight *getFlights(struct Flight *flights)
{
    // No mock data for flights yet
}

struct Flight *create_flight(struct Plane *planes, int planes_size)
{
    struct Flight *flight = (struct Flight *)malloc(sizeof(struct Flight));

    if (flight == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Cadastro de voo \n\n");
    printf("Número do voo: ");
    scanf("%d", &flight->flightNumber);
    getchar();
    printf("Data do voo: ");
    scanf("%[^\n]", flight->flightDate);
    getchar();
    printf("Horário do voo: ");
    scanf("%[^\n]", flight->flightTime);
    getchar();

    int planeIndex;
    printf("Selecione uma aeronave: \n");
    for (int i = 0; i < planes_size; i++)
    {
        printf("%d - %s\n", i + 1, planes[i].model);
    }
    printf("Escolha uma opção: ");
    scanf("%d", &planeIndex);
    getchar();

    flight->plane = planes[planeIndex - 1];

    return flight;
}

bool remove_flight(struct Flight *flights, int flights_size)
{
    int flightNumber;
    printf("Digite o número do voo: ");
    scanf("%d", &flightNumber);
    getchar();

    for (int i = 0; i < flights_size; i++)
    {
        if (flights[i].flightNumber == flightNumber)
        {
            for (int j = i; j < flights_size - 1; j++)
            {
                flights[j] = flights[j + 1];
            }
            return true;
        }
    }
    return false;
}

#endif
