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
        // loop through planes and print them
        system(CLEAR_SCREEN);
        for (int i = 0; i < 3; i++)
        {
            printf("Aeronave: %s %s\n", planes[i].model, planes[i].manufacturer);
            printf("Capacidade de passageiros: %d\n", planes[i].passengers_capacity);
            printf("Comprimento: %.2f\n", planes[i].length);
            printf("Altura: %.2f\n", planes[i].height);
            printf("Velocidade: %.2f\n", planes[i].speed);
            printf("Altitude: %.2f\n", planes[i].altitude);
            printf("Quantidade de motores: %.2f\n", planes[i].engine);
            printf("\n");
        }

        system(CLEAR_SCREEN);
        printf("╔═══════════════════════════════════════╗\n");
        printf("║  Aeronaves - Lista                    ║▒▒\n");
        printf("╠═══════════════════════════════════════╣▒▒\n");
        printf("║                                       ║▒▒\n");
        for (int i = 0; i < 3; i++)
        {
            // how cat the size of the string to make it fit?
            int size = strlen(planes[i].model) + strlen(planes[i].manufacturer) + 1;
            int spaces = 39 - size - 10;
            printf("║Aeronave: %s %s", planes[i].model, planes[i].manufacturer);
            for (int j = 0; j < spaces; j++)
            {
                printf(" ");
            }
            printf("║▒▒\n");
            printf("║Capacidade de passageiros: %d\n", planes[i].passengers_capacity);
            printf("║Comprimento: %.2f\n", planes[i].length);
            printf("║Altura: %.2f\n", planes[i].height);
            printf("║Velocidade: %.2f\n", planes[i].speed);
            printf("║Altitude: %.2f\n", planes[i].altitude);
            printf("║Quantidade de motores: %.2f\n", planes[i].engine);
            printf("╠───────────────────────────────────────╣▒▒\n");
        }
        printf("║                                       ║▒▒\n");
        printf("║   9 - Sair                            ║▒▒\n");
        printf("║                                       ║▒▒\n");
        printf("╚═══════════════════════════════════════╝▒▒\n");
        printf("  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n");
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
