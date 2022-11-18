#include <stdio.h>
#include <stdlib.h>
#include <fstream>
int i;
int x;
int control;

struct comida
{
    int id;
    struct comida *next;
    float grasas;
    float carbohidratos;
    float proteinas;

} desayuno, almuerzo, merienda, cena;
typedef comida *puntero_lista;
struct comida *p = &desayuno;
char dia[20];
void leer_archivo(puntero_lista comienzo);
void borrar_comidas(puntero_lista *comienzo);

int main()
{
    char carac;
    puntero_lista comienzo = NULL;
    struct comida comidas[10];

    desayuno.next = &almuerzo;
    almuerzo.next = &merienda;
    merienda.next = &cena;
    printf("----------BIENVENIDO A SU CALENDARIO DE MACRONUTRIENTES DIARIAS----------\n");
    printf("Que dia es hoy?");
    scanf("%s", dia);

    printf("----------DESAYUNO----------\n");
    printf("Ingrese sus grasas consumidas en su desayuno ");
    scanf("%f", &desayuno.grasas);
    printf("Ingrese sus carbohidratos consumidas en su desayuno ");
    scanf("%f", &desayuno.carbohidratos);
    printf("Ingrese sus grasas consumidas en su desayuno ");
    scanf("%f", &desayuno.proteinas);
    printf("----------------------------\n");

    printf("----------ALMUERZO----------\n");
    desayuno.next = &almuerzo;
    printf("Ingrese sus grasas consumidas en su almuerzo ");
    scanf("%f", &almuerzo.grasas);
    printf("Ingrese sus carbohidratos consumidas en su almuerzo ");
    scanf("%f", &almuerzo.carbohidratos);
    printf("Ingrese sus grasas consumidas en su almuerzo ");
    scanf("%f", &almuerzo.proteinas);
    printf("----------------------------\n");

    printf("----------MERIENDA----------\n");
    almuerzo.next = &merienda;
    printf("Ingrese sus grasas consumidas en su merienda ");
    scanf("%f", &merienda.grasas);
    printf("Ingrese sus carbohidratos consumidas en su merienda ");
    scanf("%f", &merienda.carbohidratos);
    printf("Ingrese sus grasas consumidas en su merienda ");
    scanf("%f", &merienda.proteinas);
    printf("----------------------------\n");

    printf("----------CENA----------\n");
    merienda.next = &cena;
    printf("Ingrese sus grasas consumidas en su cena ");
    scanf("%f", &cena.grasas);
    printf("Ingrese sus carbohidratos consumidas en su cena ");
    scanf("%f", &cena.carbohidratos);
    printf("Ingrese sus grasas consumidas en su cena ");
    scanf("%f", &cena.proteinas);
    printf("----------------------------\n");

    system("@cls||clear");

    FILE *manejador_archivo = fopen("archivo.txt", "a");
    if (manejador_archivo == NULL)
    {
        printf("No fue posible abrir el archivo\n");
        return -1;
    }
    else
    {

        printf("----------DESAYUNO----------\n");
        printf("Sus grasas consumidas son : %f\n", desayuno.grasas);
        printf("Sus proteinas consumidas son : %f\n", desayuno.proteinas);
        printf("Sus carbohidratos consumidas son : %f\n", desayuno.carbohidratos);
        printf("----------------------------\n");
        printf("----------ALMUERZO----------\n");
        printf("Sus grasas consumidas son : %f\n", almuerzo.grasas);
        printf("Sus proteinas consumidas son : %f\n", almuerzo.proteinas);
        printf("Sus carbohidratos consumidas son : %f\n", almuerzo.carbohidratos);
        printf("----------------------------\n");
        printf("----------MERIENDA----------\n");
        printf("Sus grasas consumidas son : %f\n", merienda.grasas);
        printf("Sus proteinas consumidas son : %f\n", merienda.proteinas);
        printf("Sus carbohidratos consumidas son : %f\n", merienda.carbohidratos);
        printf("----------------------------\n");
        printf("----------CENA----------\n");
        printf("Sus grasas consumidas son : %f\n", cena.grasas);
        printf("Sus proteinas consumidas son : %f\n", cena.proteinas);
        printf("Sus carbohidratos consumidas son : %f\n", cena.proteinas);
        printf("----------------------------\n");

        fprintf(manejador_archivo, "---------DIA %s---------\n", dia);
        fprintf(manejador_archivo, "----------DESAYUNO----------\n");
        fprintf(manejador_archivo, "Sus grasas consumidas fueron %f\n", desayuno.grasas);
        fprintf(manejador_archivo, "Sus proteinas consumidas fueron %f\n", desayuno.proteinas);
        fprintf(manejador_archivo, "Sus carbohidratos consumidas fueron %f\n", desayuno.carbohidratos);
        fprintf(manejador_archivo, "----------ALMUERZO----------\n");
        fprintf(manejador_archivo, "Sus grasas consumidas fueron %f\n", almuerzo.grasas);
        fprintf(manejador_archivo, "Sus proteinas consumidas fueron %f\n", almuerzo.proteinas);
        fprintf(manejador_archivo, "Sus carbohidratos consumidas fueron %f\n", almuerzo.carbohidratos);
        fprintf(manejador_archivo, "----------MERIENDA----------\n");
        fprintf(manejador_archivo, "Sus grasas consumidas fueron %f\n", merienda.grasas);
        fprintf(manejador_archivo, "Sus proteinas consumidas fueron %f\n", merienda.proteinas);
        fprintf(manejador_archivo, "Sus carbohidratos consumidas fueron %f\n", merienda.carbohidratos);
        fprintf(manejador_archivo, "----------CENA----------\n");
        fprintf(manejador_archivo, "Sus grasas consumidas fueron %f\n", cena.grasas);
        fprintf(manejador_archivo, "Sus proteinas consumidas fueron %f\n", cena.proteinas);
        fprintf(manejador_archivo, "Sus carbohidratos consumidas fueron %f\n", cena.carbohidratos);
        fclose(manejador_archivo);
    }

    do
    {
        printf("Presione i para ver sus MACRONUTRIENTES ingeridos en el mes \'i\' y \'s\' para salir \n");
        do
        {
            carac = getchar();
        } while ((carac != 'i') && (carac != 's'));
        if (carac == 'i')
            leer_archivo(comienzo);
    } while (carac != 's');
    return 0;
}

void leer_archivo(puntero_lista comienzo)
{
    FILE *manejador_archivo = fopen("archivo.txt", "r");
    printf("", manejador_archivo);
    if (manejador_archivo == NULL)
    {
        printf("No fue posible abrir el archivo\n");
    }
}
