#include <stdio.h>
#include <stdlib.h>
#define MAX_A 19

int main()
{
    int a[MAX_A]= {10,5,2,40,3,-99,2,3,4,5,6,7,8,-99,20,30,40,-99,-999};
    int minim=100;
    int suma=0;
    int sentinela1=-99;
    int sentinela2=-999;
    int mitjana=0;
    int contadorMitjana=0;

    int i=0;
    int j=0;


    while((a[i]!= sentinela2) )
    {
        suma=0;
        contadorMitjana=0;
        while((a[i]!=sentinela1))
        {

            suma=suma+a[i];
            contadorMitjana++;
            i++;
        }
        printf("\nValor suma %d",suma);
        mitjana=suma/contadorMitjana;


        if(minim>mitjana)
        {
            minim=mitjana;
        }
        printf("\nValor bloque %d",mitjana);
        i++;


    }



    printf("\nValor min %d",minim);

}



