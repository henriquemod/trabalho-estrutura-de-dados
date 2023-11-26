typedef void (*Callback)(char entry[10]);
typedef void (*ReallocTicketCallback)(struct Ticket *ticket);

void render_tickets_menu(struct Flight *flights, int flights_size, struct Ticket *tickets, int tickets_size, Callback remove_callback, ReallocTicketCallback realloc_callback)
{
    system(CLEAR_SCREEN);
    system(CLEAR_SCREEN);
    print_menu_with_sub_options("UniVoos - Passagens", 2);
    printf("Escolha uma opção: ");
    int option;
    scanf("%d", &option);
    getchar();
    switch (option)
    {
    case 1:
        system(CLEAR_SCREEN);
        print_menu_header("Passagens - Lista");
        print_blank_line();
        if (tickets_size == 0)
        {
            print_no_results();
        }
        else
        {

            for (int i = 0; i < tickets_size; i++)
            {
                print_ticket_line(tickets[i]);
            }
        }
        print_bottom_menu();
        printf("Escolha uma opção: ");
        int option;
        scanf("%d", &option);
        getchar();
        break;
    case 2:
        system(CLEAR_SCREEN);
        if (flights_size == 0)
        {
            printf("Não há passagens cadastradas\n");
            printf("\n\nPressione ENTER para retornar ao continuar...");
            getchar();
            break;
        }
        struct Ticket *new_ticket = create_ticket(flights, flights_size);
        realloc_callback(new_ticket);
        break;
    case 3:
        system(CLEAR_SCREEN);
        bool res = remove_ticket(tickets, tickets_size);
        if (res)
        {
            system(CLEAR_SCREEN);
            remove_callback("ticket");
            tickets_size--;
            if (tickets_size == 0)
            {
                tickets = NULL;
            }
            else
            {
                tickets = (struct Ticket *)realloc(tickets, sizeof(struct Ticket) * (tickets_size));
            }
            printf("Passagem removida com sucesso\n\n");
            printf("\n\nPressione ENTER para retornar ao continuar...");
            getchar();
            system(CLEAR_SCREEN);
        }
        else
        {
            system(CLEAR_SCREEN);
            printf("Passagem não encontrada\n\n");
            printf("\n\nPressione ENTER para retornar ao continuar...");
            getchar();
            system(CLEAR_SCREEN);
        }
        break;
    case 4:
        system(CLEAR_SCREEN);
        return;
        break;
    case 9:
        exit(0);
        break;
    default:
        printf("Opção inválida\n");
        break;
    }
}
