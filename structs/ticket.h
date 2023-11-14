#ifndef TICKET_H
#define TICKET_H

struct Ticket
{
    int ticketNumber;
    struct Flight flight;
    int flightGate;
};

void createTicket(struct Ticket *tickets, int size)
{
    system(CLEAR_SCREEN);

    struct Ticket *ticket = NULL;
    ticket = (struct Ticket *)malloc(sizeof(struct Ticket));
    if (ticket == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Cadastro de passagem aérea \n\n");

    printf("Numero da passagem: ");
    scanf("%[^\n]", ticket->ticketNumber);
    getchar();

    system(CLEAR_SCREEN);
    printf("Passagem confirmada!\n\n");
    printf("Numero da passagem: %s\n", ticket->ticketNumber);
    printf("Numero do voo: %d\n", ticket->flight.flightNumber);
    printf("\n\nPressione ENTER para retornar ao continuar...");
    getchar();
    system(CLEAR_SCREEN);

    tickets[size - 1] = *ticket;
}

#endif
