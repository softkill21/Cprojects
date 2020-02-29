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



void almacenarDatos(struct Libros* libro, FILE* fix)
{

    int dia,mes,any;
    char caracter;
    int contador =0;

    while (fscanf(fix,"%d/%d/%d %c", &dia,&mes,&any,&caracter) != EOF)
    {


        //printf("%d/%d/%d %c\n",dia,mes,any,caracter);
        libro[contador].doj.date=dia;
        libro[contador].doj.month=mes;
        libro[contador].doj.year=any;
        libro[contador].codigo=caracter;

        printf("Registro   : %d/%d/%d %c\n", libro[contador].doj.date,libro[contador].doj.month,libro[contador].doj.year,libro[contador].codigo);
        contador++;

    }

}

void contarLibros(struct Libros* libro, FILE* fix)
{
    fix=fopen("llibres.txt","r");

    int contm=0,conti=0,contt=0,contf=0,contb=0,contq=0;
    int contador=0;

    int dia,mes,any;
    char caracter;

    while (fscanf(fix,"%d/%d/%d %c", &dia,&mes,&any,&caracter) != EOF)
    {

         libro[contador].codigo=caracter;

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

        contador++;

    }

    printf("\nSe han prestado %d de medicina\n",contm);
    printf("Se han prestado %d de Informatica\n",conti);
    printf("Se han prestado %d de Mate\n",contt);
    printf("Se han prestado %d de Fisica\n",contf);
    printf("Se han prestado %d de Bio\n",contb);
    printf("Se han prestado %d de Quimica\n",contq);

}

void compararFechas(struct Libros* libro, FILE* fix)
{
    fix=fopen("llibres.txt","r");

    int dia,mes,any;
    int diad,mesd,anyd;

    int contador=0,contprestacs=0;

    char caracter;

    printf("\n\n\n Introduzca un dia mes any\n");
        scanf("%d",&diad);
        scanf("%d",&mesd);
        scanf("%d",&anyd);

    while (fscanf(fix,"%d/%d/%d %c", &dia,&mes,&any,&caracter) != EOF){

        libro[contador].doj.date=dia;
        libro[contador].doj.month=mes;
        libro[contador].doj.year=any;

        if(libro[contador].doj.date==diad && libro[contador].doj.month==mesd &&libro[contador].doj.year==anyd){
            contprestacs++;
        }

    }

    printf("\nEn ese dia %d se han prestado %d libros", diad,mesd,anyd,contprestacs);

    }

int main()
{
    FILE* fix;
    fix=fopen("llibres.txt","r");
    almacenarDatos(libro,fix);
    contarLibros(libro,fix);
    compararFechas(libro,fix);
    /*Procedimiento contar numero de libros*/

    fclose(fix);



}




