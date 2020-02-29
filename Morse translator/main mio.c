#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define MAX_D 36
/**
@author Catalin Adelin Iovan
*/

struct Dictionar
{

    char letraYnum[2];
    char letraMorse[10];

} d[MAX_D];

/**
Accion con nuestra interficie de entrada para poder ver las opciones disponibles que tenemos
*/

void menu(void)
{


    printf("Bienvenido al traductor de morse \n");
    printf("Para traducir una palabra a morse, preta 0 \n");
    printf("Para traducir un fichero a morse preta 1 \n");
    printf("Para traducir un fichero de morse a espanol 2 \n");
    printf("Para salir pulse cualquier otro numero\n");

    printf("---------------------------------\n");

    printf("Introduzca una opcion\n");

}

/**
Primero, tenemos un struct donde almacenaremos dos tipos de datos
Letras,numeros por un lado, y despues la traduccion correspondiente a morse por otro lado.

Para crear esta estructura, primero leemos el fichero, despues hazta que no llegamos al final de fichero,
Dividiremos la frase primero hasta que encuentra un espacio ( aqui seria nuestra letra/num), y despues hazta que encuentra
el caracter *(aqui seria la traduccion del morse)

Procediremos de esta manera hazta llegamos al final de fichero
*/

void lecturaDictionari(struct Dictionar d[])
{

    FILE* fixDictionari;
    int j=0;
    char  line[500];

    fixDictionari = fopen("morse.txt", "r");
    while (fgets(line, sizeof(line), fixDictionari) != NULL)
    {
        const char* val1 = strtok(line, " ");
        const char* val2 = strtok(NULL, "*");
        strcpy(d[j].letraYnum,val1);
        strcpy(d[j].letraMorse,val2);

        j++;

        //printf("vALOR 1%s | vALOR 2 %s\n", val1, val2);
    }

    fclose(fixDictionari);


}

/**

Aqui, tenemos la primera parte de la accion que traducira las palabras dentro de un fichero
Tendra como entrada el dictionari, el texto que vamos a tener que traducir, y el fichero donde vamos a guardar las traducciones

La manera como funciona esta accion, como el texto que viene por entrada es una cadena de caracteres, procediremos desde el inicio hasta el final de esa cadena de letras,
comprobando letra por letra con las traducciones de esas letras respectivas dentro del registro dicionari

Contemplamos tambien unos casos especiales, como por ejemplo si es minuscula o mayuscula, puntos, comas, accentos, etc
Si es una letra dejaremos 3 espacios, si es el final de una palabra, 5 letras

*/

void traducirPalabraParaFix(struct Dictionar d[], char texto[],FILE *fixProba)
{



    char letra;
    int i=0;
    char msg[50];  /* allocate some space for string */

    for( i=0; i<strlen(texto); i++)
    {

        letra=texto[i];


        if(letra==' ')
        {
            printf("     ");
            fprintf(fixProba,"     ");

        }
        //a-z == A-Z
        if(letra>=97 && letra<=122)
        {
            letra=letra-32;
        }

        //a con accento y asi succesivamente
        if(letra==160)
        {
            letra=97;
        }
        if(letra==',' || letra=='.' || letra==';' || letra=='-')
        {
            letra=' ';
        }



        for(int j=0; j<MAX_D; j++)
        {
            if(letra==d[j].letraYnum[0] || letra+32==d[j].letraYnum[0])

            {

                sprintf(msg,"%s   ", d[j].letraMorse);
                fprintf(fixProba,msg);
                // printf(msg);
                //printf("%s   ", d[j].letraMorse);

            }

        }


    }

    fprintf(fixProba,"\n");

}

/**

Esta accion seria la complementaria de arriba, pero en este caso, traduciriamos de morse a texto normal
Tiene las mismas entradas que la otra, el registro diccionario, la cadena de texto y el fichero de salida.
A diferencia de la accion de arriba, procediremos a la inversa, esta vez comprobamos dentro del diccionario las traducciones a morse y cuando llegamos a algo parecido,
devolveremos la letra de esa mismo indice.

*/
void traducirPalabraParaFixCodificado(struct Dictionar d[], char texto[],FILE *fixProba2)
{


    char* segment;
    int i;
    segment = strtok(texto, " ");


    while(segment)
    {
        for(i=0; i<MAX_D; ++i)
        {
            if (!strcmp(segment, d[i].letraMorse))
            {

                fprintf(fixProba2,"%c",d[i].letraYnum[0]);
            }

        }




        segment = strtok(NULL, " ");
        fprintf(fixProba2," ");
    }



    fprintf(fixProba2,"\n");

}

/**
Aqui tenemos la accion de traducir una palabra por teclado.
Tendra como entrada solo el diccionario, para tener donde mirar para poder hacer las traducciones.
Tambien tenemos una comprobacion de que el tamany del string introducido no sea superior a 15.
*/
void traducirPalabra(struct Dictionar d[])
{

    char texto[15];
    char letra;
    int i=0;

        printf("\nIntroduzca una palabra:\n");
        scanf("%[^\n]s",texto);
        getchar();

    if(strlen(texto)>15)
    {
        printf("Error!\nSupera el tamany permitido(15)!");

    }
    else
    {


        for( i=0; i<strlen(texto); i++)
        {

            letra=texto[i];


            if(letra==' ')
            {
                printf("     ");
            }
            //a-z == A-Z
            if(letra>=97 && letra<=122)
            {
                letra=letra-32;
            }

            //a con accento y asi succesivamente
            if(letra==160)
            {
                letra=97;
            }
            if(letra==',' || letra=='.' || letra==';' || letra=='-')
            {
                letra=' ';
            }



            for(int j=0; j<MAX_D; j++)
            {
                if(letra==d[j].letraYnum[0] || letra+32==d[j].letraYnum[0])

                {
                    printf("%s   ", d[j].letraMorse);
                }

            }

        }

    }

}

/**
Aqui tenemos la accion principal, que va abrir los documentos de texto y va a leer uno por uno las frases y las va a enviar la accion de arriba traducirPalabraParaFix
Tenemos como entrada el diccionari, para tener las traducciones a mana para ir mirando cual es la traduccion correspondiente de esa letra

El procedimiento, es igual que los anteriores, leemos linea por linea el fichero inicial , y despues las traducciones las guardamos en el otro fichero(fixProba)
*/
void traducirFicher(struct Dictionar d[])
{

    FILE *fixParaTraducir;
    char  line[500];
    FILE *fixProba;




    if((fixParaTraducir = fopen("original.txt", "r"))!=NULL)
    {

        if((fixProba=fopen("codificado.txt","w+"))!=NULL)
        {


            while (fgets(line, sizeof(line), fixParaTraducir) != NULL)
            {
                //const char* val1 = strtok(line, "\n");


                traducirPalabraParaFix(d,line,fixProba);

                //printf("\nvALOR 1:%s\n", val1);

            }



            fclose(fixParaTraducir);
            fclose(fixProba);

        }
        else
        {
            printf("File not found");
        }

    }
    else
    {
        printf("File not found");

    }

}
/**

Procedimiento parecido al de arriba, lo unico que en este caso tiene como entrada el fichero codificado y lo quieremos descodificar.
Funcionamiento completamente igual que el de arriba, misma entrada, mismo control de errores para los ficheros, mismas acciones internas.
*/
void traducirFicherCodificado(struct Dictionar d[])
{

    FILE *fixParaTraducir2;

    char  line[500];
    FILE *fixProba2;

      if((fixProba2=fopen("descodificat.txt","w"))!=NULL)
    {

        if((fixParaTraducir2 = fopen("codificado.txt", "r"))!=NULL)
        {




    while (fgets(line, sizeof(line), fixParaTraducir2) != NULL)
    {

       // const char* val1 = strtok(line, "\n");

        // printf("\nvALOR 1:%s\n", val1);
        traducirPalabraParaFixCodificado(d,line,fixProba2);

    }



    fclose(fixParaTraducir2);

    fclose(fixProba2);


        }
        else
        {
            printf("File not found");
        }

    }
    else
    {
        printf("File not found");

    }


}



/**
Aqui tenemos el main, que lo primero que hace es leer el fichero del diccionari y guarda en la memoria todas las traducciones.
Despues mediante el menu que tenemos podemos llegar a las diferentes opciones que tenemos como traducir una palabra, codificar un fichero, descodificar un fichero o salir

*/
int main()
{


    lecturaDictionari(d);
    menu();

    int opcion;

    scanf("%d",&opcion);
    getchar();

    while(opcion>=0 && opcion<=2)
    {

        if(opcion==0)
        {
        traducirPalabra(d);


        }

        else if(opcion==1)
        {
            printf("Fichero traducido correctamente\n");
            traducirFicher(d);
            printf("\nIntroduzca de nuevo una opcion\n");
        }


        else if(opcion==2)
        {
             printf("Fichero desencriptado correctamente\n");
            traducirFicherCodificado(d);
            printf("\nIntroduzca de nuevo una opcion\n");
        }

        else
        {
            printf("El programa ha acabado!");
        }


        scanf("%d",&opcion);
        getchar();




    }



}













