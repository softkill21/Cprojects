#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    void traducirPalabra(struct Dictionar *d){


    char texto[100];
    char letra;
    int i=0;

printf("Introduzca un texto:\n");
    scanf("%[^\n]s",texto);



    for( i=0;i<strlen(texto);i++){

    letra=texto[i];

    //printf("Letra %c",letra);
    //printf("1:%c\n",d[i].letraYnum[0]);

    if(letra==' '){
        printf("     ");
    }
    //a-z == A-Z
    if(letra>=97 && letra<=122){
        letra=letra-32;
    }

    //a con accento y asi succesivamente
    if(letra==160){
        letra=97;
    }




        for(int j=0; j<36; j++)
        {

            if(letra==d[j].letraYnum[0] || letra+32==d[j].letraYnum)

            {


                printf("%s   ",d[j].letraMorse);
            }


        }


    }

    }

