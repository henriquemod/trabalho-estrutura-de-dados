void renderTicketsMenu()
{
    system(CLEAR_SCREEN);
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
    print_menu_with_sub_options("UniVoos - Passagens", options, size, subOptions, sub_options_size, 2);
    printf("Escolha uma opção: ");
    printf("Escolha uma opção: ");
    int option;
    scanf("%d", &option);
    getchar();
    switch (option)
    {
    case 1:
        // renderPlanesMenu();
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
