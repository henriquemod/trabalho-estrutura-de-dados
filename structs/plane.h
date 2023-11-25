#ifndef PLANE_H
#define PLANE_H

struct Planes
{
    struct Plane *planes;
    void (*delete)(int index);
};

struct Plane
{
    char model[100];
    char manufacturer[100];
    int passengers_capacity;
    float length;
    float height;
    float speed;
    float altitude;
    float engine;
};

void *getPlanes(struct Plane *planes)
{
    struct Plane plane_1 = {"Boeing 747", "Boeing", 416, 70.6, 19.4, 988, 13100, 4};
    struct Plane plane_2 = {"Airbus A380", "Airbus", 853, 72.7, 24.1, 945, 13100, 4};
    struct Plane plane_3 = {"Boeing 777", "Boeing", 550, 73.9, 18.5, 950, 13100, 4};

    planes[0] = plane_1;
    planes[1] = plane_2;
    planes[2] = plane_3;
}

struct Plane *create_plane()
{
    struct Plane *plane = (struct Plane *)malloc(sizeof(struct Plane));

    if (plane == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Cadastro de aeronave \n\n");
    printf("Modelo: ");
    scanf("%[^\n]", plane->model);
    getchar();
    printf("Fabricante: ");
    scanf("%[^\n]", plane->manufacturer);
    getchar();
    printf("Capacidade de passageiros: ");
    scanf("%d", &plane->passengers_capacity);
    getchar();
    printf("Comprimento: ");
    scanf("%f", &plane->length);
    getchar();
    printf("Altura: ");
    scanf("%f", &plane->height);
    getchar();
    printf("Velocidade: ");
    scanf("%f", &plane->speed);
    getchar();
    printf("Altitude: ");
    scanf("%f", &plane->altitude);
    getchar();
    printf("Quantidade de motores: ");
    scanf("%f", &plane->engine);
    getchar();

    system(CLEAR_SCREEN);
    printf("Aeronave cadastrada com sucesso\n\n");
    printf("Aeronave: %s %s\n", plane->model, plane->manufacturer);
    printf("\n\nPressione ENTER para retornar ao continuar...");
    getchar();

    return plane;
}

bool remove_plane(struct Plane *planes, int planes_size)
{
    system(CLEAR_SCREEN);

    printf("Remover aeronave \n\n");

    printf("Modelo: ");
    char model[100];
    scanf("%[^\n]", model);
    getchar();

    bool found = false;
    for (int i = 0; i < planes_size; i++)
    {
        if (strcmp(planes[i].model, model) == 0)
        {
            found = true;
            for (int j = i; j < planes_size - 1; j++)
            {
                planes[j] = planes[j + 1];
            }
            break;
        }
    }

    return found;
}

void remove_plane(struct Plane *planes, int *planesSize)
{
    system(CLEAR_SCREEN);

    printf("Remover aeronave \n\n");

    printf("Modelo: ");
    char model[100];
    scanf("%[^\n]", model);
    getchar();

    bool found = false;
    for (int i = 0; i < planesSize; i++)
    {
        if (strcmp(planes[i].model, model) == 0)
        {
            found = true;
            for (int j = i; j < planesSize - 1; j++)
            {
                planes[j] = planes[j + 1];
            }
            break;
        }
    }

    if (found)
    {
        system(CLEAR_SCREEN);
        printf("Aeronave removida com sucesso\n\n");
        printf("\n\nPressione ENTER para retornar ao continuar...");
        getchar();
        planesSize--;
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
}

#endif
