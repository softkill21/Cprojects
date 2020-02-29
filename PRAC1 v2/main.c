#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 1000
#define MIN 1



/**CORREGIR
El programa tiene que funcionar sin introducir nada por teclado
Hacer el modulo para que cuando se haga el aletorio, nos salga un rango de numero no tan grandes

**/



/*Generamos el vector de numeros random*/
void Generar_Vector_Aletorio(int v[],int v2[],int v3[], int elementos)
{
    int i, num_ale;

    for(i=0; i<elementos; i++)
    {
        num_ale = rand()%(elementos*100); /**se multiplica por 100 para que no se repita los numeros**/
        v[i]=num_ale;
        v2[i]=v[i];
        v3[i]=v[i];


    }


}



/*Funcion para listar por pantalla los vectores, tanto los generados como los ordenados*/
void Imprimir_Vector(int v[], int elementos)
{

    int i;
    printf("v=[ ");
    for(i=0; i<elementos; i++)
    {
        printf("%i  ", v[i]);
    }
    printf("]");
}

void imprimir_fichero(FILE *fsalida,int v[], int elementos)
{

    int i;
    fprintf(fsalida,"v=[ ");
    for(i=0; i<elementos; i++)
    {
        fprintf(fsalida,"%i  ", v[i]);
    }
    fprintf(fsalida,"]");
}







/* ORDENACIÓ PER SELECCIÓ */
void ordSeleccio(int v[], int nelem, int *num_intercambios, int *num_iteraciones)
{

    int i, j, pos, minim;
    // Límite de movimiento uno por uno de la subarray sin clasificar
    for (i=0; i<nelem-1; i++)
    {
        // Encuentra el elemento mínimo en la matriz sin clasificar
        minim = v[i];
        pos = i;
        for (j=i+1; j<nelem; j++)   /* Cerquem el minim */
        {
            if (v[j]<minim)
            {
                minim = v[j];
                (*num_intercambios)++;

                pos = j;
            }
            (*num_iteraciones)++;
        }
        v[pos] = v[i];
        v[i] = minim; /* Ubiquem el minim en la posició i */

    }
}

/* ORDENACIÓ PER INSERCIÓ */
void ordInsercio(int v[], int nelem, int *num_intercambios, int *num_iteraciones)
{
    int i, j, aux;
    for (i=1; i<nelem; i++)
    {
        aux = v[i];
        j = i-1;
        while (j>=0 && aux<v[j])
            /* Es fa la inserció
                Mueve elementos de v [0..i-1], que son
                mayor que aux, a una posición por delante
                de su posición actual */
        {
            v[j+1] = v[j];
            (*num_intercambios)++;
            j--;
        }
        (*num_iteraciones)++;
        v[j+1] = aux;
    }
}


void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

void quicksort(int list[],int m,int n, int *contador)
{
    (*contador)++;
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);


        }
        /* intercambio de los elementos */
        swap(&list[m],&list[j]);

        /* ordenacion de manera recursiva de la lista mas pequena */
        quicksort(list,m,j-1,contador);
        quicksort(list,j+1,n,contador);
    }
}


FILE *fsalida;

int main()
{
    int v[MAX];
    int v2[MAX];
    int v3[MAX];


    fsalida= fopen("sortida.txt", "w");

    int elementos, intercambios, iteraciones,contador;

    srand((int)time(NULL));
    elementos = 1000;
    intercambios=0;
    iteraciones=0;
    contador=0;


    // Generamos el vector y lo guardamos el mismo resultado en tres variables
    Generar_Vector_Aletorio(v,v2,v3, elementos);
    printf("\nEl vector [ORIGINAL] que a generado es: \n");
    Imprimir_Vector(v,elementos);


    fprintf(fsalida,"\nEl vector [ORIGINAL] que a generado es: \n");
    imprimir_fichero(fsalida,v,elementos);
    fprintf(fsalida,"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");



    //Empezamos el proceso de seleccion
    ordSeleccio(v,elementos, &intercambios, &iteraciones);


    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");


    printf("\n\nEl vector ordenado por Seleccion es: \n");
    Imprimir_Vector(v, elementos);


    printf("\n\n Numero de intercambios: %i", intercambios);
    printf("\n Numero de iteraciones: %i\n", iteraciones);

    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    //print en el fichero de la salida de seleccion
    fprintf(fsalida,"\n\nEl vector ordenado por Seleccion es: \n");
    imprimir_fichero(fsalida,v,elementos);
    fprintf(fsalida,"\n\n Numero de intercambios: %i", intercambios);
    fprintf(fsalida,"\n Numero de iteraciones: %i\n", iteraciones);
    fprintf(fsalida,"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    intercambios=0;
    iteraciones=0;

    //Empezamos el proces de insercion

    ordInsercio(v2,elementos, &intercambios, &iteraciones);
    printf("\n\nEl vector ordenado por Insercio es: \n");
    Imprimir_Vector(v2, elementos);

    printf("\n\n Numero de intercambios: %i", intercambios);
    printf("\n Numero de iteraciones: %i\n", iteraciones);
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    //print en fichero de los datos de la insercion

    fprintf(fsalida,"\n\nEl vector ordenado por Insercio es: \n");
    imprimir_fichero(fsalida,v2,elementos);
    fprintf(fsalida,"\n\n Numero de intercambios: %i", intercambios);
    fprintf(fsalida,"\n Numero de iteraciones: %i\n", iteraciones);

    fprintf(fsalida,"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    //Empezamos el proceso del quicksort
    quicksort(v3,0,elementos-1,&contador);
    printf("\n\nEl vector ordenado por Quicksort es: \n");
    Imprimir_Vector(v3,elementos);
    printf("\n\n Numero de contador: %d\n\n", contador);

    //print en fichero de los datos del quicksort

    fprintf(fsalida,"\n\nEl vector ordenado por Quicksort es: \n");
    imprimir_fichero(fsalida,v3,elementos);
    fprintf(fsalida,"\n\n Numero de contador: %d\n\n", contador);

    return 0;
}
