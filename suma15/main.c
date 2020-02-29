#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_M 9/*
int main()
{
    int matriuA[MAX_M]={0,0,0,0,0,0,0,0,0};
    int matriuB[MAX_M]={0,0,0,0,0,0,0,0,0};
    int sumaA=0;
    int sumaB=0;
    int lecturaA;
    int lecturaB;
    bool trobatA=false;
    bool trobatB=false;



    printf("Introduzca valor para A\n");
    scanf("%d",&lecturaA);
    printf("Introduzca valor para B\n");
    scanf("%d",&lecturaB);
     if((lecturaA!=matriuA[lecturaA]) && (lecturaA!=matriuB[lecturaA])){
            matriuA[lecturaA]=lecturaA;
            sumaA=sumaA+lecturaA;
        }
         if((lecturaB!=matriuB[lecturaB])&& (lecturaB!=matriuA[lecturaB])){
            matriuB[lecturaB]=lecturaB;
            sumaB=sumaB+lecturaB;
        }



    while(!trobatA &&!trobatB)
    {
        printf("Introduzca valor para A\n");
        scanf("%d",&lecturaA);
        printf("Introduzca valor para B\n");
        scanf("%d",&lecturaB);

        if((lecturaA!=matriuA[lecturaA]) && (lecturaA!=matriuB[lecturaA])){
            matriuA[lecturaA]=lecturaA;
            sumaA=sumaA+lecturaA;
        }
         if((lecturaB!=matriuB[lecturaB])&& (lecturaB!=matriuA[lecturaB])){
            matriuB[lecturaB]=lecturaB;
            sumaB=sumaB+lecturaB;
        }

        if(sumaA==15 || sumaB>15){
            trobatA=true;
        }
        if(sumaB==15 || sumaA>15){
            trobatB=true;
        }


    }

    if(trobatA==true){
        printf("A ha ganado");
        for(int i=0;i<MAX_M;i++){
            printf("Valores A%d \t Valores B %d\n",matriuA[i],matriuB[i]);

        }
    }

    if(trobatB==true){
        printf("B ha ganado");
        for(int i=0;i<MAX_M;i++){
               printf("Valores A%d \t Valores B %d\n",matriuA[i],matriuB[i]);
        }
    }



}*/
