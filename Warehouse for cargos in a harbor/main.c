#include <stdio.h>
#include <stdlib.h>
#include "rutinas.h"
#include "tipos.h"

void menu(void);
int leerFichero(teu_t matriz[], int op);
void ordenacion(teu_t matriz[], int nelem);
int Busca_minimo(int sum0, int sum1, int sum2);


int main()
{
    teu_t contenedores_list[MAX];
    barco_t barco[3];
    int opcion, enter, carga, op,op1,op2, max,max1,max2;


    // Por defecto solo cargamos el fichero inicial.
    printf("Fichero inicial cargado : pesos.txt\n\n");
    max = leerFichero(contenedores_list,1);
    ordenacion(contenedores_list,max);
    carga=repartir(barco,contenedores_list, max);

    menu();



    printf("\n\tIntroduce la opcion: ");
    scanf("%i", &opcion);

    system(limpiar_pantalla);
    while(opcion != 3)
    {

        switch(opcion)
        {

        case 1:
            system(limpiar_pantalla);
            printf("\n\tHas elegido procesar archivo: \n");
            printf("\t Elige la mercancia:\n");
            printf("\t\t 1.Shushi  \n");
            printf("\t\t 2.Yatekomo \n");
            scanf("%i", &op);



            printf("Para todos los valores, pulse 1, si quiere establecer una cantidad, pulse 2: ");
            scanf("%i",&op1);

            if(op1==1)
            {

                max = leerFichero(contenedores_list,op);
                ordenacion(contenedores_list,max);
                carga=repartir(barco,contenedores_list, max);

            }
            else if(op1==2)
            {
                printf("\nIntroduzca la cantidad de datos que quiere selecconar: ");
                scanf("%i", &op2);
                if(op2>80)
                {
                    max1 = leerFichero2(contenedores_list,op,80);
                    ordenacion(contenedores_list,max1);
                    carga=repartir(barco,contenedores_list, max1);
                }
                else
                {
                    max1 = leerFichero2(contenedores_list,op,op2);
                    ordenacion(contenedores_list,max1);
                    carga=repartir(barco,contenedores_list, max1);
                }
            }


        printf("El fichero se ha abierto correctamente!\n\n");

        break;

    case 2:

        system(limpiar_pantalla);
        printf("\n\tHas elegido mostrar resultados: ");
        mostrar_resultado(barco, carga);
        break;
    }
    printf("\n\tPulsa 0 para volver al menu: ");
    scanf("%i", &enter);
    if(enter == 0)
    {
        system(limpiar_pantalla);
        menu();
        printf("\n\tIntroduce la opcion: ");
        scanf("%i", &opcion);
    }
    else if((enter!=0)&&(enter!=1)&&(enter!=2))
    {
        system(limpiar_pantalla);
        printf("\n\tSALIR!\n");
        exit(EXIT_FAILURE);
    }
}
system(limpiar_pantalla);
printf("\n\tSALIR!\n");
exit(EXIT_FAILURE);




return 0;
}
