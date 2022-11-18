#include <stdio.h>
#include <stdlib.h>

typedef struct comida
{
    char *desayuno;
    char *almuerzo;
    char *merienda;
    char *cena;

    struct comida *siguiente;

} comida;
typedef comida *puntero_lista;

void imprimir_comidas(puntero_lista comienzo);
void borrar_comidas(puntero_lista *comienzo);
void crear_comidas(puntero_lista *comienzo);

int main()
{
    char carac;
    puntero_lista comienzo = NULL;

    do
    {
        printf("Presione \'c\' para poner su comida \'i\' para listar sus comidas y \'s\' para salir \n");
        do
        {
            carac = getchar();
        } while ((carac != 'c') && (carac != 'i') && (carac != 's'));
        if (carac == 'c')
            crear_comidas(&comienzo);
        if (carac == 'i')
            imprimir_comidas(comienzo);
    } while (carac != 's');
    borrar_lista(&comienzo);
    return 0;
}

void crear_comidas(puntero_lista *comienzo)
{
    puntero_lista p = malloc(sizeof(comida));
    p->siguiente = NULL;
    printf("Ingrese su desayuno \n");
    char *desayuno = (char *)malloc(10);
    scanf("%s", desayuno);
    p->desayuno = desayuno;
    printf("Ingrese su almuerzo \n");
    char *almuerzo = (char *)malloc(10);
    scanf("%s", almuerzo);
    p->almuerzo = almuerzo;
    printf("Ingrese su merienda\n");
    char *merienda = (char *)malloc(10);
    scanf("%s", merienda);
    p->merienda = merienda;
    printf("Ingrese su cena \n");
    char *cena = (char *)malloc(10);
    scanf("%s", &(p->cena));
    p->cena = cena;
    p->siguiente = *comienzo;
    *comienzo = p;
}

void imprimir_comidas(puntero_lista comienzo)
{
    while (comienzo != NULL)
    {
        printf("desayuno: %s \n", comienzo->desayuno);
        printf("almuerzo: %s \n", comienzo->almuerzo);
        printf("merienda: %s \n", comienzo->merienda);
        printf("cena: %s \n", comienzo->cena);
        break;
    }
}
void borrar_comidas(puntero_lista *comienzo)
{
    puntero_lista actual;
    while (*comienzo != NULL)
    {
        actual = *comienzo;
        *comienzo = (*comienzo)->siguiente;
        free(actual->desayuno);
        free(actual->almuerzo);
        free(actual->merienda);
        free(actual->cena);
        free(actual);
    }
}
