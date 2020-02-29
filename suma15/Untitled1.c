#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_F 3
#define MAX_C 3

void mostrarTaulel(int matriuJoc[MAX_F][MAX_C])
{

    for(int i=0; i<MAX_F; i++)
    {
        for(int j=0; j<MAX_C; j++)
        {
            printf("%d\t",matriuJoc[i][j]);

        }
        printf("\n");

    }
}

bool comprobarMatriu(int matriuJoc[MAX_F][MAX_C], int entrada)
{
    bool comprobar=false;

    if((matriuJoc[0][0]==entrada && matriuJoc[1][0]==entrada && matriuJoc[2][0]==entrada ) ||
            (matriuJoc[0][0]==entrada && matriuJoc[0][1]==entrada && matriuJoc[0][2]==entrada ) ||
            (matriuJoc[1][0]==entrada && matriuJoc[1][1]==entrada && matriuJoc[1][2]==entrada ) ||
            (matriuJoc[0][0]==entrada && matriuJoc[1][1]==entrada && matriuJoc[2][2]==entrada ) ||
            (matriuJoc[0][2]==entrada && matriuJoc[1][2]==entrada && matriuJoc[2][2]==entrada ) ||
            (matriuJoc[2][0]==entrada && matriuJoc[2][1]==entrada && matriuJoc[2][2]==entrada ) ||
            (matriuJoc[0][2]==entrada && matriuJoc[1][1]==entrada && matriuJoc[2][0]==entrada ) ||
            (matriuJoc[0][1]==entrada && matriuJoc[1][1]==entrada && matriuJoc[2][1]==entrada ))
    {

        comprobar=true;
    }
    else
        comprobar=false;

    return comprobar;

}

int main()
{

    int matriuJoc[MAX_F][MAX_C]= {0,0,0,0,0,0};
    int jugador1=1;
    int jugador2=2;
    int fila1,fila2,col1,col2;
    bool A,B;


    printf("Introduzca una posicion para fila Jugador 1\n");
    scanf("%d",&fila1);

    printf("Introduzca una posicion para col Jugador 1\n");
    scanf("%d",&col1);


    printf("Introduzca una posicion para fila Jugador 2\n");
    scanf("%d",&fila2);

    printf("Introduzca una posicion para col Jugador 2\n");
    scanf("%d",&col2);

    matriuJoc[fila1][col1]=jugador1;
    matriuJoc[fila2][col2]=jugador2;

    mostrarTaulel(matriuJoc);

    A=comprobarMatriu(matriuJoc,jugador1);
    B=comprobarMatriu(matriuJoc,jugador2);

    while(!A && !B)
    {
        printf("Introduzca una posicion para fila Jugador 1\n");
        scanf("%d",&fila1);

        printf("Introduzca una posicion para col Jugador 1\n");
        scanf("%d",&col1);


        printf("Introduzca una posicion para fila Jugador 2\n");
        scanf("%d",&fila2);

        printf("Introduzca una posicion para col Jugador 2\n");
        scanf("%d",&col2);

        matriuJoc[fila1][col1]=jugador1;
        matriuJoc[fila2][col2]=jugador2;

        mostrarTaulel(matriuJoc);

        A=comprobarMatriu(matriuJoc,jugador1);
        B=comprobarMatriu(matriuJoc,jugador2);

    }

    if(A==true)
    {
        printf("A ha ganado");
    }
    if(B==true)
    {
        printf("B ha ganado");
    }







}

