#ifndef TICKET_H
#define TICKET_H

struct Ticket
{
    int ticketNumber;
    struct Flight flight;
    int flightGate;
};

struct Ticket *getTickets(struct Ticket *tickets)
{
    // No mock data for tickets yet
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
    printf("Selecione um voo: \n");
    for (int i = 0; i < flights_size; i++)
    {
        printf("%d - %d\n", i + 1, flights[i].flightNumber);
    }
    printf("Escolha uma opção: ");
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
