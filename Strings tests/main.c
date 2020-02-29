#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEXT 50
#define MAX_A 26

struct Alfabet{

    char letra;
    int contador;
}a[MAX_A];

void lecturaAlfabet(){

  for(int i=0;i<MAX_A;i++){
    a[i].letra=('a' + i);
    a[i].contador=0;
   }

}

void cambiarMayuscula(char entrada[]){

    char textoTraducido[MAX_TEXT];

for(int i=0;i<strlen(entrada);i++){

    if(entrada[i]!= ' '){
        textoTraducido[i]=entrada[i];

        if(strlen(textoTraducido)>3)
        for(int j=0;j<strlen(textoTraducido);j++){
            textoTraducido[0]=textoTraducido[0]-32;
        }
    }

}

printf("Texto traducido %s",textoTraducido);

}


int letraMasRepetida(char entrada[], struct Alfabet a[MAX_A]){

    int maxim=0;

   for(int i=0;i<strlen(entrada);i++){
        for(int j=0;j<MAX_A;j++){
            if(entrada[i]==a[j].letra){
                a[j].contador++;
            }
        }
    }

    for(int i=0;i<MAX_A;i++){
        if(maxim<a[i].contador){
            maxim=a[i].contador;
            //letra=a[i].letra;
        }
    }

    return maxim;
}

int letraMasRepetidaLetra(char entrada[], struct Alfabet a[MAX_A]){

    int maxim=0;
    char letrax=' ';


    for(int i=0;i<MAX_A;i++){
        if(maxim<a[i].contador){
            maxim=a[i].contador;
            letrax=a[i].letra;
        }
    }

    return letrax;
}

int contarParaules(char entrada[]){

    int contadordeP=1;

     for(int i=0;i<strlen(entrada);i++){
         if(entrada[i]==' '){
            contadordeP++;
        }
    }

    return contadordeP;
}

int main()
{




    lecturaAlfabet();
    int max=0;
    char letrar=' ';

    char text[MAX_TEXT];
    int contadorP=0;
    int i=1;
    printf("Intro text\n");
    gets(text);

    contadorP=contarParaules(text);

    max=letraMasRepetida(text,a);
    letrar=letraMasRepetidaLetra(text,a);

    cambiarMayuscula(text);




    printf("Hay %d de letra %c\n",max,letrar);
    printf("hay %d palabras",contadorP);

}
