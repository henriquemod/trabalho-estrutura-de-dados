typedef void (*Callback)(char entry[10]);
typedef void (*ReallocCallback)(struct Plane *plane);

void render_planes_menu(struct Plane *planes, int planes_size, Callback remove_callback, ReallocCallback realloc_callback)
{
    system(CLEAR_SCREEN);
    print_menu_with_sub_options("UniVoos - Aeronaves", 0);
    printf("Escolha uma opção: ");
    int option;
    scanf("%d", &option);
    getchar();
    switch (option)
    {
    case 1:
        system(CLEAR_SCREEN);
        print_menu_header("Aeronaves - Lista");
        print_blank_line();
        for (int i = 0; i < planes_size; i++)
        {
            print_plane_line(planes[i]);
        }
        print_bottom_menu();
        printf("Escolha uma opção: ");
        int option;
        scanf("%d", &option);
        getchar();
        system(CLEAR_SCREEN);
        break;
    case 2:
        system(CLEAR_SCREEN);
        struct Plane *new_plane = create_plane();
        realloc_callback(new_plane);
        break;
    case 3:
        system(CLEAR_SCREEN);
        bool res = remove_plane(planes, planes_size);
        if (res)
        {
            system(CLEAR_SCREEN);
            remove_callback("plane");
            planes_size--;
            if (planes_size == 0)
            {
                planes = NULL;
            }
            else
            {
                planes = (struct Plane *)realloc(planes, sizeof(struct Plane) * (planes_size));
            }
            printf("Aeronave removida com sucesso\n\n");
            printf("\n\nPressione ENTER para retornar ao continuar...");
            getchar();
            system(CLEAR_SCREEN);
        }
        else
        {
            system(CLEAR_SCREEN);
            printf("Aeronave não encontrada\n\n");
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
        system(CLEAR_SCREEN);
        exit(0);
        break;
    default:
        system(CLEAR_SCREEN);
        printf("Opção inválida\n");
        break;
    }
}
