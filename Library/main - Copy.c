#include <stdio.h>
#include <string.h>
#include <stdlib.h>>

struct Libros
{
    char codigo;
    struct date
    {
        int date;
        int month;
        int year;
    } doj;
} libro[100];


int main()
{
    int contm=0,conti=0,contt=0,contf=0,contb=0,contq=0,contprestacs=0;
    int contador=0;
    int i=0;
    int diad,mesd,anyd;

    FILE *fix;
    char caracter;
    int dia,mes,any;

    fix=fopen("llibres.txt","r");

    printf("Introduzca un dia mes any\n");
    scanf("%d",&diad);
    scanf("%d",&mesd);
    scanf("%d",&anyd);


    while (fscanf(fix,"%d/%d/%d %c", &dia,&mes,&any,&caracter) != EOF)
    {

        //printf("%d/%d/%d %c\n",dia,mes,any,caracter);
        libro[contador].doj.date=dia;
        libro[contador].doj.month=mes;
        libro[contador].doj.year=any;
        libro[contador].codigo=caracter;
/*Procedimiento contar numero de libros*/
        if(libro[contador].codigo=='M')
        {
            contm++;
        }
        if(libro[contador].codigo=='I')
        {
            conti++;
        }
        if(libro[contador].codigo=='T')
        {
            contt++;
        }
        if(libro[contador].codigo=='F')
        {
            contf++;
        }
        if(libro[contador].codigo=='B')
        {
            contb++;
        }
        if(libro[contador].codigo=='Q')
        {
            contq++;
        }
/*Hasta aqui procedimiento contar numero de libros*/
/*Procedimiento de mostrar los libros segun dia*/
        if(libro[contador].doj.date==diad && libro[contador].doj.month==mesd &&libro[contador].doj.year==anyd){
            contprestacs++;
        }
/*Hasta aqui*/

        printf("Registro   : %d/%d/%d %c\n", libro[contador].doj.date,libro[contador].doj.month,libro[contador].doj.year,libro[contador].codigo);
        contador++;


    }
    printf("\nSe han prestado %d de medicina\n",contm);
    printf("Se han prestado %d de Informatica\n",conti);
    printf("Se han prestado %d de Mate\n",contt);
    printf("Se han prestado %d de Fisica\n",contf);
    printf("Se han prestado %d de Bio\n",contb);
    printf("Se han prestado %d de Quimica\n",contq);


    printf("\n\nEn ese dia %d/%d/%d se han prestado %d libros", diad,mesd,anyd,contprestacs);


    fclose(fix);
}




