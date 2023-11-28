#define SCREEN_WIDTH 100

char *options[] = {
    "Aeronaves",
    "Voos",
    "Passagens",
};
char *subOptions[] = {
    "Listar",
    "Criar",
    "Remover",
    "Voltar",
};
int size = sizeof(options) / sizeof(options[0]);
int sub_options_size = sizeof(subOptions) / sizeof(subOptions[0]);

void print_blank_line()
{
    printf("║");
    int spaces = SCREEN_WIDTH - 2;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");
}

void end_of_line(int spaces)
{
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");
}

void print_menu_header(char *title)
{
    int count = 0;
    int titleLength = strlen(title);

    // mount top header menu
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        if (count == 0)
        {
            printf("╔");
            count++;
        }
        else if (count == SCREEN_WIDTH - 1)
        {
            printf("╗\n");
            break;
        }
        else
        {
            printf("═");
            count++;
        }
    }
    // mount title
    count = 0;
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        if (count == 0)
        {
            printf("║");
            count++;
        }
        else if (count == SCREEN_WIDTH - 1)
        {
            printf("║▒▒\n");
            break;
        }
        else if (count == (SCREEN_WIDTH - titleLength) / 2)
        {
            printf("%s", title);
            count += titleLength;
        }
        else
        {
            printf(" ");
            count++;
        }
    }
    // mount bottom header menu
    count = 0;
    for (int i = 0; i < SCREEN_WIDTH; i++)
    {
        if (count == 0)
        {
            printf("╠");
            count++;
        }
        else if (count == SCREEN_WIDTH - 1)
        {
            printf("╣▒▒\n");
            break;
        }
        else
        {
            printf("═");
            count++;
        }
    }
}

void printOptions(char *options[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("║  %d - %s", i + 1, options[i]);
        int spaces = SCREEN_WIDTH - strlen(options[i]) - 8;
        end_of_line(spaces);
    }
}

void print_options_with_sub_options(char *options[], int size, char *subOptions[], int sub_options_size, int index)
{
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            printf("║  ♦ - %s", options[i]);
            int spaces = SCREEN_WIDTH - strlen(options[i]) - 8;
            end_of_line(spaces);
            for (int j = 0; j < sub_options_size; j++)
            {
                printf("║    %d - %s", j + 1, subOptions[j]);
                int spaces = SCREEN_WIDTH - strlen(subOptions[j]) - 10;
                end_of_line(spaces);
            }
        }
        else
        {

            printf("║  ♦ - %s", options[i]);
            int spaces = SCREEN_WIDTH - strlen(options[i]) - 8;
            for (int j = 0; j < spaces; j++)
            {
                printf(" ");
            }
            printf("║▒▒\n");
        }
    }
}

void print_bottom_menu()
{
    printf("║");
    int spaces = SCREEN_WIDTH - 2;
    end_of_line(spaces);

    printf("║  9 - Sair");
    spaces = SCREEN_WIDTH - 12;
    end_of_line(spaces);

    printf("║");
    spaces = SCREEN_WIDTH - 2;
    end_of_line(spaces);

    printf("╚");
    spaces = SCREEN_WIDTH - 2;
    for (int j = 0; j < spaces; j++)
    {
        printf("═");
    }
    printf("╝▒▒\n");

    printf("  ");
    spaces = SCREEN_WIDTH - 2;
    for (int j = 0; j < spaces; j++)
    {
        printf("▒");
    }
    printf("▒▒\n\n");
}

void print_menu(char *title)
{
    print_menu_header(title);
    print_blank_line();
    printOptions(options, size);
    print_bottom_menu();
}

void print_menu_with_sub_options(char *title, int index)
{
    print_menu_header(title);
    print_blank_line();
    print_options_with_sub_options(options, size, subOptions, sub_options_size, index);
    print_bottom_menu();
}

void print_plane_line(struct Plane plane)
{
    printf("║  %s - %s", plane.model, plane.manufacturer);
    int spaces = SCREEN_WIDTH - strlen(plane.model) - strlen(plane.manufacturer) - 7;
    end_of_line(spaces);

    char passengers_capacity[10], speed[10], altitude[10];
    snprintf(passengers_capacity, sizeof(passengers_capacity), "%d", plane.passengers_capacity);
    snprintf(speed, sizeof(speed), "%.2f", plane.speed);
    snprintf(altitude, sizeof(altitude), "%.2f", plane.altitude);

    printf("║  Capacidade: %d pessoas | Velocidade: %.2fkm/h | Altitude: %.2fm", plane.passengers_capacity, plane.speed, plane.altitude);
    spaces = SCREEN_WIDTH - 57 - strlen(passengers_capacity) - strlen(speed) - strlen(altitude);
    end_of_line(spaces);
    print_blank_line();
}

void print_flight_line(struct Flight flight)
{
    char flightNumber[10];
    snprintf(flightNumber, sizeof(flightNumber), "%d", flight.flightNumber);
    printf("║  N. Voo: %d - Aeronave: %s", flight.flightNumber, flight.plane.model);
    int spaces = SCREEN_WIDTH - strlen(flight.plane.model) - strlen(flightNumber) - 25;
    end_of_line(spaces);

    printf("║  Data: %s | Horário: %s", flight.flightDate, flight.flightTime);
    spaces = SCREEN_WIDTH - 22 - strlen(flight.flightDate) - strlen(flight.flightTime);
    end_of_line(spaces);
    print_blank_line();
}

void print_ticket_line(struct Ticket ticket)
{
    char ticketNumber[10], flightNumber[10];
    snprintf(ticketNumber, sizeof(ticketNumber), "%d", ticket.ticketNumber);
    snprintf(flightNumber, sizeof(flightNumber), "%d", ticket.flight.flightNumber);
    printf("║  N: %d - N. Voo: %d - Portão: %s - Aeronave: %s - Data: %s - %s", ticket.ticketNumber, ticket.flight.flightNumber, ticket.flightGate, ticket.flight.plane.model, ticket.flight.flightDate, ticket.flight.flightTime);
    int spaces = SCREEN_WIDTH - strlen(ticketNumber) - sizeof(ticket.flightGate) - strlen(flightNumber) - strlen(ticket.flight.plane.model) - strlen(ticket.flight.flightDate) - strlen(ticket.flight.flightTime) - 52;
    end_of_line(spaces);
}

void print_no_results()
{
    printf("║  Nenhum resultado encontrado");
    int spaces = SCREEN_WIDTH - 31;
    end_of_line(spaces);
}
