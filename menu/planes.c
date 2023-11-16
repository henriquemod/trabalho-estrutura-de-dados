void renderPlanesMenu(struct Plane *planes)
{
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
    system(CLEAR_SCREEN);
    print_menu_with_sub_options("UniVoos - Aeronaves", options, size, subOptions, sub_options_size, 0);
    printf("Escolha uma opção: ");
    int option;
    scanf("%d", &option);
    getchar();
    switch (option)
    {
    case 1:
        system(CLEAR_SCREEN);
        print_menu_header("Aeronaves - Lista");
        for (int i = 0; i < 3; i++)
        {
            print_plane_line(planes[i]);
        }
        print_bottom_menu();
        printf("Escolha uma opção: ");
        int option;
        scanf("%d", &option);
        getchar();
        break;
    case 2:
        // renderFlightsMenu();
        break;
    case 3:
        // renderTicketsMenu();
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
