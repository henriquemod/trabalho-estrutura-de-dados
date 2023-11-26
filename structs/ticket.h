#ifndef TICKET_H
#define TICKET_H

struct Ticket
{
    int ticketNumber;
    struct Flight flight;
    int flightGate;
};

struct Ticket *get_tickets(struct Flight mock_flight)
{
    struct Ticket *tickets = (struct Ticket *)malloc(sizeof(struct Ticket) * 5);

    if (tickets == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    tickets[0].ticketNumber = 1;
    tickets[0].flight = mock_flight;
    tickets[0].flightGate = 1;

    tickets[1].ticketNumber = 2;
    tickets[1].flight = mock_flight;
    tickets[1].flightGate = 1;

    tickets[2].ticketNumber = 3;
    tickets[2].flight = mock_flight;
    tickets[2].flightGate = 1;

    tickets[3].ticketNumber = 4;
    tickets[3].flight = mock_flight;
    tickets[3].flightGate = 1;

    tickets[4].ticketNumber = 5;
    tickets[4].flight = mock_flight;
    tickets[4].flightGate = 1;

    return tickets;
}

struct Ticket *create_ticket(struct Flight *flights, int flights_size)
{
    struct Ticket *ticket = (struct Ticket *)malloc(sizeof(struct Ticket));

    if (ticket == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Cadastro de passagem \n\n");
    printf("Número da passagem: ");
    scanf("%d", &ticket->ticketNumber);
    getchar();

    int flightIndex;
    printf("Selecione um voo: \n\n");
    for (int i = 0; i < flights_size; i++)
    {
        printf("%d - Voo N: %d | Data: %s - %s | Aeronave: %s\n", i + 1, flights[i].flightNumber, flights[i].flightDate, flights[i].flightTime, flights[i].plane.model);
    }
    printf("\nEscolha uma opção: ");
    scanf("%d", &flightIndex);
    getchar();

    ticket->flight = flights[flightIndex - 1];

    printf("Portão de embarque: ");
    scanf("%d", &ticket->flightGate);
    getchar();

    return ticket;
}

bool remove_ticket(struct Ticket *tickets, int tickets_size)
{
    int ticketNumber;
    printf("Digite o número da passagem: ");
    scanf("%d", &ticketNumber);
    getchar();

    for (int i = 0; i < tickets_size; i++)
    {
        if (tickets[i].ticketNumber == ticketNumber)
        {
            for (int j = i; j < tickets_size - 1; j++)
            {
                tickets[j] = tickets[j + 1];
            }
            return true;
        }
    }
    return false;
}

#endif
