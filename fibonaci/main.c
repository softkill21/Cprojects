#include <stdio.h>
#include <stdlib.h>

//int counter;

int Fib (int n, int *counter)
{
    (*counter)++;
    if (n==0)
        return 0;
    if (n==1)
        return 1;

    return Fib(n-1, counter) + Fib(n-2, counter);


}


FILE *ft;

FILE *fsalida;


int main()
{

    int n;
    int cont=0;
    int traspaso;
    char guardo[10];
    int i;
    int bucle=0;

    fsalida= fopen("sortida.txt", "w");


    /* Obrim el fitxer de proves */
    if ((ft= fopen("proves.txt", "r")) == NULL)    /* Si hi ha error, retorna NULL */
    {
        printf("Error al abrir el fichero \n");
        exit(EXIT_FAILURE); /*Sortim del programa perquè hi ha error */
    }

    while(fgets(guardo, 10, ft) != NULL )
    {


        /*   fprintf(ft, "%d", n);*/
        fscanf(ft, "%d", &n );

        if(n<0)
        {
            cont++;
            printf("\nError, Linea del fichero : %d,  este numero no puede tener fibonaci  valor n  : %d ",cont,n);
            fprintf(fsalida,"\nError, Linea del fichero : %d,  este numero no puede tener fibonaci  valor n  : %d ",cont,n);
        }
        else
        {
            cont++;



            traspaso = Fib(n, &bucle);




            printf("\nvalor n : %d \t\t fibonaci : %d \t\t linea fichero: %d   \t\t bucles : %d ",n, traspaso,cont,bucle);


            fprintf(fsalida,"\nvalor n : %d \t\t fibonaci : %d \t\t linea fichero: %d   \t\t bucles : %d ",n, traspaso,cont,bucle);
        }


    }
    fclose (ft);
    fclose (fsalida);
}


