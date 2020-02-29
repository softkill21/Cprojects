#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define CONST 50
#define MAX 10
int main()
{

    srand(time(NULL));   // Initialization, should only be called once.

    /**

    Declaracion de las variables

    */

    int i=0;
    int n=0;
    int m=0;
    int r;
    int cont=0;
    int contadorL;
    int posicion=0;
    int intents=10;
    FILE *file;
    char text[CONST];
    char letra;
    char nom[CONST];
    char esdevinar[CONST];
    bool trobat=false;
    char guardar[MAX][CONST];
    char adivinar[CONST];
    file = fopen("paraules.txt", "r");
    if (file)
    {

        while ((file != '\0') && (fgets (text, 60, file)!='\0'))
        {

        /**
        Mientras no estamos al final del fichero, guardamos las palabras del fichero en un array de doble dimension que luego lo vamos a utilizar para esdevinar las palabras.
        */

            strcpy(guardar[i], text);
            i++;

        }

        fclose(file);
    }
/*
    for(i=0; i<MAX; i++)
    {
        printf("Valor: %s",guardar[i]);
    }
*/
    /**
    Buscamos un valor random y despues utilizando ese numero buscamos la palabra que esta en la posicion de nuestro array. y despues la copiamos a un otro array

    */
    r=rand() % 9;

    //printf("\n\nValor random : %d",r);

    strcpy(adivinar,guardar[r]);

   // printf("\nValor: %s",adivinar);

    for(i = 1; adivinar[i] != '\0'; ++i)
    {
        cont++;
        printf(" X ");
    }




    printf("\n\n\n\n");

    for(i=0; i<cont; i++)
    {
        esdevinar[i]='X';
        printf("%c",esdevinar[i]);

    }

    printf("\n\n Benvingut/da al joc del penjat. Com et dius?\n");
    scanf("%s",nom);

    m = intents;
    contadorL=cont;

    /**
        Mientras no hemos encontrado la palabra y no hemos utilizado todos los intentos vamos a recorrer nuestro array intento adivinar la palabras de 1 letra en 1. Tenemos 10 intentos
        Si al final de esos no la hemos encontrado perdemos, si durante esos 10 la hemos encontrado entonces ganamos.
    */
    while(m>0 && !trobat)
    {


        printf(" Et queden %d intents. %s, quina lletra apostes?:\n",m,nom);
        scanf("%s",&letra);

        for(int j=0; j<cont; j++)
        {


            if(adivinar[j]==letra)
            {
                posicion=j;
                esdevinar[posicion]=letra;
                contadorL--;

            }


        }

        printf("\n\n\n");

        for(n=0; n<cont; n++)
        {
            printf("%c",esdevinar[n]);

        }

        m--;

        if(contadorL==0)
        {
            trobat=true;
        }
    }

    if(contadorL==0)
    {
        printf("\nHas ganado, la palabra era:\t %s",adivinar);
    }

    else
        printf("\nHas perdido, la palabra era:\t %s",adivinar);





}
