#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEXT 50


void invertirPalabra(char entrada[],char salida[])
{

    int j=0;
    int k=strlen(entrada)-1;

    while(k!=0 && j!=strlen(entrada)-1)
    {

        salida[j]=entrada[k];
        j++;
        k--;

    }

}

void llegirPalabra(char entrada[], char returnado[])
{

    char textoIni[50];
    int i=0;
    int j=0;

    while(i<strlen(entrada) && entrada[i]!='.')
    {
        while(j<strlen(textoIni) && entrada[j]!=' '){
        returnado[i]=entrada[i];

        j++;
        }

        for(int i=0; i<strlen(returnado); i++)
    {


        printf("%c",returnado[i]);
    }

        i++;
    }


}
int main()
{


    char text[MAX_TEXT];
    int i=1;

    char textTrad[10];
    char textTrad2[10];

    printf("Intro text\n");
    gets(text);


    llegirPalabra(text,textTrad);

    invertirPalabra(textTrad,textTrad2);

    for(int i=0; i<strlen(textTrad2); i++)
    {


        printf("%c",textTrad2[i]);
    }



}
