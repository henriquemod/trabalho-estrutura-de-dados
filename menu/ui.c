#define SCREEN_WIDTH 80

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
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        printf("║▒▒\n");
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
            for (int j = 0; j < spaces; j++)
            {
                printf(" ");
            }
            printf("║▒▒\n");
            for (int j = 0; j < sub_options_size; j++)
            {
                printf("║    %d - %s", j + 1, subOptions[j]);
                int spaces = SCREEN_WIDTH - strlen(subOptions[j]) - 10;
                for (int k = 0; k < spaces; k++)
                {
                    printf(" ");
                }
                printf("║▒▒\n");
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
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");

    printf("║  9 - Sair");
    spaces = SCREEN_WIDTH - 12;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");

    printf("║");
    spaces = SCREEN_WIDTH - 2;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");

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

void print_menu(char *title, char *options[], int size)
{
    print_menu_header(title);
    printOptions(options, size);
    print_bottom_menu();
}

void print_menu_with_sub_options(char *title, char *options[], int size, char *subOptions[], int sub_options_size, int index)
{
    print_menu_header(title);
    print_options_with_sub_options(options, size, subOptions, sub_options_size, index);
    print_bottom_menu();
}

void print_plane_line(struct Plane plane)
{
    printf("║  %s - %s", plane.model, plane.manufacturer);
    int spaces = SCREEN_WIDTH - strlen(plane.model) - strlen(plane.manufacturer) - 7;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");
}

void print_flight_line(struct Flight flight)
{
    printf("║  %d - %s", flight.flightNumber, flight.plane.model);
    int spaces = SCREEN_WIDTH - strlen(flight.plane.model) - 8;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");
}

void print_ticket_line(struct Ticket ticket)
{
    char ticketNumber[10], flightGate[10];
    snprintf(ticketNumber, sizeof(ticketNumber), "%d", ticket.ticketNumber);
    snprintf(flightGate, sizeof(flightGate), "%d", ticket.flightGate);
    printf("║  %d - Portão: %d", ticket.ticketNumber, ticket.flightGate);
    int spaces = SCREEN_WIDTH - strlen(ticketNumber) - strlen(flightGate) - 15;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");
}

void print_no_results()
{
    printf("║  Nenhum resultado encontrado");
    int spaces = SCREEN_WIDTH - 31;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    printf("║▒▒\n");
}
