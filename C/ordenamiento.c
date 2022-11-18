#include <stdio.h>
#include <stdlib.h>

struct _agenda
{
    char nombree[20];
    int dato;
    struct _agenda *siguiente;
};

struct _agenda *primero, *ultimo;

void mostrar_menu();
void agregar_elemento(size_t *cont);
void borrar_lista(size_t *cont);
void mostrar_lista(size_t cont);
void ordenar_lista(size_t cont);

int main(void)
{
    char opcion, ch;
    size_t cont = 0;
    primero = (struct _agenda *)NULL;
    ultimo = (struct _agenda *)NULL;

    do
    {
        mostrar_menu();
        opcion = getchar();
        while ((ch = getchar()) != EOF && ch != '\n')
            ;
        switch (opcion)
        {
        case '1':
            agregar_elemento(&cont);
            break;
        case '2':
            printf("No disponible todavía!\n");
            break;
        case '3':
            mostrar_lista(cont);
            break;
        case '4':
            ordenar_lista(cont);
            break;
        case '5':
            exit(1);
        default:
            printf("Opción no válida\n");
            printf("\n Pulse una tecla para continuar...");
            getchar();
            break;
        }
    } while (opcion != '5');

    return 0;
}

void mostrar_menu()
{
    system("clear");
    printf("\n\n ===== Menu =====");
    printf("\n\n 1 - Agregar nombre y celular de usuario");
    printf("\n 2 - Borrar nombre y celular del usuario");
    printf("\n 3 - Mostrar lista de nombres y celulares");
    printf("\n 4 - Ordenar por orden alfabetico los nombres con los celulares");
    printf("\n 5 - Salir");

    printf("\n Escoge una opcion: ");
}

void agregar_elemento(size_t *cont)
{
    struct _agenda *nuevo;
    int ch;

    nuevo = (struct _agenda *)malloc(sizeof(struct _agenda));
    if (nuevo == NULL)
    {
        printf(" \n No hay memoria disponible");
    }
    printf("\n ===== Nuevo elemento =====");
    printf("\n Nombre :");
    scanf("%s", &nuevo->nombree);
    printf("\n Celular :");
    scanf("%d", &nuevo->dato);
    while ((ch = getchar()) != EOF && ch != '\n')
        ;

    nuevo->siguiente = NULL;

    if (primero == NULL)
    {
        printf("\n Primer elemento");
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {

        ultimo->siguiente = nuevo;

        ultimo = nuevo;
    }
    *cont += 1;
}

void mostrar_lista(size_t cont)
{
    struct _agenda *auxiliar;
    int i = 0;

    auxiliar = primero;
    printf("\n Mostrando la lista completa (total %lu):\n ", cont);
    while (auxiliar != NULL)
    {
        printf("\n nombre: %s", auxiliar->nombree);
        printf("\n numero: %d", auxiliar->dato);
        auxiliar = auxiliar->siguiente;
        i++;
    }
    if (i == 0)
    {
        printf("\n La lista esta vacia\n");
    }
    printf("\n Pulse una tecla para continuar...");
    getchar();
}

void borrar_lista(size_t *cont)
{
    size_t cont actual;
    while (*nuevo != NULL)
    {
        actual = *nuevo;
        *nuevo = (size_t)->siguiente;
        free(actual->nombree);
        free(actual->dato);
        free(actual);
    }

    void ordenar_lista(size_t cont)
    {
        printf("\n No desarrollado...");
        getchar();
    }
