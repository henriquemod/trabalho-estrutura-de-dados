#ifndef FLIGHT_H
#define FLIGHT_H

struct Flight
{
    int flightNumber;
    struct Plane plane;
    char flightDate[11];
    char flightTime[6];
};

struct Flight *get_flights(struct Plane mock_plane)
{
    struct Flight *flights = (struct Flight *)malloc(sizeof(struct Flight) * 5);

    if (flights == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    flights[0].flightNumber = 1;
    flights[0].plane = mock_plane;
    strcpy(flights[0].flightTime, "11:00");
    strcpy(flights[0].flightDate, "10/10/2022");

    flights[1].flightNumber = 2;
    flights[1].plane = mock_plane;
    strcpy(flights[1].flightTime, "12:00");
    strcpy(flights[1].flightDate, "01/02/2022");

    flights[2].flightNumber = 3;
    flights[2].plane = mock_plane;
    strcpy(flights[2].flightTime, "15:30");
    strcpy(flights[2].flightDate, "20/03/2022");

    flights[3].flightNumber = 4;
    flights[3].plane = mock_plane;
    strcpy(flights[3].flightTime, "16:00");
    strcpy(flights[3].flightDate, "28/04/2021");

    flights[4].flightNumber = 5;
    flights[4].plane = mock_plane;
    strcpy(flights[4].flightTime, "12:30");
    strcpy(flights[4].flightDate, "11/05/2021");

    return flights;
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
    printf("Data do voo [dd/mm/yyyy]: ");
    scanf("%[^\n]", flight->flightDate);
    getchar();
    printf("Horário do voo [hh:mm]: ");
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
