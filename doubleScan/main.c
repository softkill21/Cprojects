#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ponerNulo(char entrada[])
{

    for (int i=0; i<50; i++)
    {
        entrada[i]=NULL;
    }

}

bool comprobarDiftong(char entrada[])
{
    bool contador=false;

    for (int i=0; i<50; i++)
        if(entrada[i]=='a' && entrada[i+1]=='e')
        {
            contador=true;
        }

    return contador;
}

int main()
{
    char textInitial[50];
    char palabra[50];
    int diftong=0;

    gets(textInitial);


    int i=0;

    while(textInitial[i]!= '-')
    {

        ponerNulo(palabra);

        while(textInitial[i]!=' ')
        {
            palabra[i]=textInitial[i];
            i++;
        }

        if(comprobarDiftong(palabra)){
            diftong++;
        }

        i++;
    }

    printf("hay %d diftongs",diftong);





}
