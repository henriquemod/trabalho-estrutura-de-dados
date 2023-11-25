typedef void (*Callback)(char entry[10]);
typedef void (*ReallocFlightCallback)(struct Flight *flight);

void render_flights_menu(struct Plane *planes, int planes_size, struct Flight *flights, int flight_size, Callback remove_callback, ReallocFlightCallback realloc_callback)
{
    system(CLEAR_SCREEN);
    system(CLEAR_SCREEN);
    print_menu_with_sub_options("UniVoos - Voos", 1);
    printf("Escolha uma opção: ");
    int option;
    scanf("%d", &option);
    getchar();
    switch (option)
    {
    case 1:
        system(CLEAR_SCREEN);
        print_menu_header("Voos - Lista");
        print_blank_line();
        if (flight_size == 0)
        {
            print_no_results();
        }
        else
        {

            for (int i = 0; i < flight_size; i++)
            {
                print_flight_line(flights[i]);
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
        struct Flight *new_flight = create_flight(planes, planes_size);
        realloc_callback(new_flight);
        break;
    case 3:
        system(CLEAR_SCREEN);
        bool res = remove_flight(flights, flight_size);
        if (res)
        {
            system(CLEAR_SCREEN);
            remove_callback("flight");
            flight_size--;
            if (flight_size == 0)
            {
                flights = NULL;
            }
            else
            {

                flights = (struct Flight *)realloc(flights, sizeof(struct Flight) * (flight_size));
            }
            printf("Voo removido com sucesso\n\n");
            printf("\n\nPressione ENTER para retornar ao continuar...");
            getchar();
            system(CLEAR_SCREEN);
        }
        else
        {
            system(CLEAR_SCREEN);
            printf("Voo não encontrado\n\n");
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
