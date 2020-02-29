#include <stdio.h>
#include <stdlib.h>

void botellasVendidas(int tabla[5][12], int N)
{

    N=12;
    int opcion, i;
    int totalvinorojo=0,totalvinoblanco=0,totalvinorosado=0,totalcava=0,totalliquor=0;

    printf("Detalles ventas productos : \n");
    printf("\n1 - Vino tinto");
    printf("\n2 - Vino blanco");
    printf("\n3 - Vino rosado");
    printf("\n4 - Cavas");
    printf("\n5 - Licores\n");

    scanf("%d",&opcion);

    if(opcion==1)
    {


        for(i=0; i<12; i++)
        {
            totalvinorojo = tabla[i][0] + totalvinorojo;
        }

        printf("Ventas de vino negro son %d", totalvinorojo);
    }

    else if(opcion==2)
    {


        for(i=0; i<N; i++)
        {
            totalvinoblanco = (tabla[i][1] + totalvinoblanco);
        }

        printf("Ventas de vino blanco son %d", totalvinoblanco);
    }

    else if(opcion==3)
    {

        totalvinorosado= 0;

        for(i=0; i<N; i++)
        {
            totalvinorosado = (tabla[i][2] + totalvinorosado);
        }

        printf("Ventas de vino rosado son %d", totalvinorosado);
    }

    else if(opcion==4)
    {


        for(i=0; i<N; i++)
        {
            totalcava = (tabla[i][3] + totalcava);
        }

        printf("Ventas de cava son %d", totalcava);
    }

    else if(opcion==5)
    {

        totalliquor= 0;

        for(i=0; i<N; i++)
        {
            totalliquor = (tabla[i][4] + totalliquor);
        }

        printf("Ventas de licor son %d", totalliquor);
    }

    else
    {
        printf("Opcion no valida!");
    }

}

void mesesBotellas(int tabla[5][12], int N, int M)
{

    N=12;
    M=5;
    int numero,j;
    int ene=0,feb=0,mar=0,apr=0,may=0,jun=0,jul=0,ago=0,sep=0,oct=0,nov=0,dec=0;

    printf("Introduzca un valor :");
    scanf("%d",&numero);



    for(j=0; j<M; j++)
    {
        ene = tabla[0][j] + ene;
    }

    if(numero<ene)
    {
        printf("El mes de enero cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        feb = tabla[1][j] + feb;
    }

    if(numero<feb)
    {
        printf("El mes de febrero cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        mar = tabla[2][j] + mar;
    }

    if(numero<mar)
    {
        printf("El mes de marzo cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        apr = tabla[3][j] + apr;
    }

    if(numero<apr)
    {
        printf("El mes de april cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        may = tabla[4][j] + may;
    }

    if(numero<may)
    {
        printf("El mes de mayo cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        jun = tabla[5][j] + jun;
    }

    if(numero<jun)
    {
        printf("El mes de junio cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        jul = tabla[6][j] + jul;
    }

    if(numero<jul)
    {
        printf("El mes de julio cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        ago = tabla[7][j] + ago;
    }

    if(numero<ago)
    {
        printf("El mes de agosto cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        sep = tabla[8][j] + sep;
    }

    if(numero<sep)
    {
        printf("El mes de setiembre cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        oct = tabla[9][j] + oct;
    }

    if(numero<oct)
    {
        printf("El mes de octubre cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        nov = tabla[10][j] + nov;
    }

    if(numero<nov)
    {
        printf("El mes de novembre cumple la media\n");
    }

    for(j=0; j<M; j++)
    {
        dec = tabla[11][j] + dec;
    }

    if(numero<dec)
    {
        printf("El mes de diciembre cumple la media\n");
    }


}

void almacenarDatos(int tabla[5][12], int N, int M)
{
    N=12;
    M=5;
    int i,j;
    char c;

    FILE *fitxVins;
    fitxVins=fopen("Vins.txt", "r");

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            fscanf(fitxVins, "%d,", &tabla[i][j]);


        }
    }
    fclose(fitxVins);
}

void menu()
{

    printf("\nElige una opcion:\n");
    printf("\n1- Calcular la suma de ventas de todos los mesos de un producto en concreto");
    printf("\n2- Calcular en que mes se ha superado un numero especifico\n");

}

int main()
{
    int N=12;
    int M=5;
    int tabla_bebidas[M][N];

      int i,j,contador;

    FILE *fitxVins;
    fitxVins=fopen("Vins.txt", "r");

    almacenarDatos(tabla_bebidas, N, M);

    while(contador!=3){
        menu();
        scanf("%d",&contador);

        if(contador==1){
            botellasVendidas(tabla_bebidas,N);
        }
        else if(contador==2){
            mesesBotellas(tabla_bebidas,N,M);
        }
        else{
            printf("fuck");
        }
    }
}




