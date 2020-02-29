#include <stdio.h>
#include <stdlib.h>
#include "rutinas.h"
#include "tipos.h"


     /** RUTINA QUE IMPRIME POR PANTALLA EL MENU **/
     void menu(){
        printf("\n\t####################################################\n");
        printf("\t#\t\t\t\t\t\t   #");
        printf("\n\t#\t ARCHIVO PUERTO CONTENEDORES TEU\t   #\n");
        printf("\t#\t\t\t\t\t\t   #\n");
        printf("\t#\t1. Procesar Archivo\t\t\t   #\n");
        printf("\t#\t2. Mostrar Resultados\t\t\t   #\n");
        printf("\t#\t3. Salir\t\t\t\t   #\n");
        printf("\t#\t\t\t\t\t\t   #\n");
        printf("\t####################################################\n");
     }


    /** RUTINA PARA LEER CONTENIDO DE UN FICHERO Y GUARDARLO EN UNA MATRIZ **/
     int leerFichero(teu_t matriz[], int op){
        /*INICIALIZAR VARIABLES*/
        FILE *fpesos;
        int i=0;
        switch(op){
        case 1:
            fpesos =fopen(LISTA_1, "r");
            break;
        case 2:
            fpesos =fopen(LISTA_2, "r");
            break;

        }
        /*COMPORBAR LA APERTURA DEL FICHERO*/
         if(fpesos == NULL){
            printf("ERROR!");
            exit(EXIT_FAILURE);
        }else{
           // printf("El fichero se ha abierto correctamente!\n\n");
        }
        /*GUARDAR ELEMENTOS DEL FICHERO EN UNA MATRIZ*/
        while(!feof(fpesos)){
            fscanf(fpesos,"%i", &matriz[i].id);
            fscanf(fpesos,"%i", &matriz[i].peso);
            i++;
        }
        return i;
     }

     int leerFichero2(teu_t matriz[], int op,int nelem){
        /*INICIALIZAR VARIABLES*/
        FILE *fpesos;
        int i=0;

        switch(op){
        case 1:
            fpesos =fopen(LISTA_1, "r");
            break;
        case 2:
            fpesos =fopen(LISTA_2, "r");
            break;

        }
        /*COMPORBAR LA APERTURA DEL FICHERO*/
         if(fpesos == NULL){
            printf("ERROR!");
            exit(EXIT_FAILURE);
        }else{
           // printf("El fichero se ha abierto correctamente!\n\n");
        }
        /*GUARDAR ELEMENTOS DEL FICHERO EN UNA MATRIZ*/
        for(i=0;i<nelem;i++){
            fscanf(fpesos,"%i", &matriz[i].id);
            fscanf(fpesos,"%i", &matriz[i].peso);
        }
        return i;
     }



    /** ALGORISMO QUE ORDENA LA MATRIZ REFERENTE A UN PESO E ID FORMA DESCENDIENTE **/
        void ordenacion(teu_t matriz[], int nelem) {
             int i, j, pos;
             teu_t minim;
             for (i=0; i<nelem-1; i++) {
             minim = matriz[i];
             pos = i;
                 for (j=i+1; j<nelem; j++) {
                 if (matriz[j].peso > minim.peso) {
                     minim = matriz[j];
                     pos = j;
                     }
                 }
             matriz[pos] = matriz[i];
             matriz[i] = minim;
             }
        }




    /** RUTINA QUE BUSCA DONDE HAY EL MENOR PESO DE CADA SECCIÓN DEL BARCO **/
        int Busca_minimo(int sum0, int sum1, int sum2){
            int minim;
            int num=0;

            if(sum0 < sum1){
                minim = sum0;
                num=0;
            }else{
                minim = sum1;
                num=1;
            }
            if(minim > sum2){
                num=2;
            }
        return num;
        }


    /** RUTINA QUE BUSCA EL **/

        int repartir( barco_t barco[], teu_t contenedores_list[], int max){
            int i, total;
            i=0;
            int sum0, sum1,sum2, minimo, j,k,w, tot;
            tot=0;

                /* INICIALIZAR TABLERO BARCOS */
                for(i=0; i < 3; i++){
                    barco[i].cont[0] = contenedores_list[i];
                    barco[i].suma = contenedores_list[i].peso;
                }
                /*GUARDAMOS EL VALOR DE LA SUMA EN VARIABLES*/
                sum0= barco[0].suma;
                sum1= barco[1].suma;
                sum2= barco[2].suma;
                total = sum0 + sum1 + sum2;
                /*INDICES PARA CADA SECCIÓN DEL BARCO*/
                j=1;
                k=1;
                w=1;

                /*REPARTIMOS LOS CONTENEDORES*/
                while ((i<max)&&(total < MAX_PESO)&& (tot!=1)){
                    /*BUSCAMOS EL CONTENEDOR CON MENOR PESO*/
                    minimo = Busca_minimo(sum0, sum1, sum2);
                    tot = total;
                    switch(minimo){

                    case 0:
                        tot = tot + contenedores_list[i].peso;
                         if(tot > MAX_PESO){
                            tot=1;
                        }else{
                        barco[0].suma = barco[0].suma + contenedores_list[i].peso;
                        total = total + contenedores_list[i].peso;
                        barco[0].cont[j].id = contenedores_list[i].id;
                        barco[0].cont[j].peso = contenedores_list[i].peso;
                        i++;
                        j++;
                        }
                        break;

                    case 1:
                        tot = tot + contenedores_list[i].peso;
                         if(tot > MAX_PESO){
                            tot=1;
                        }else{
                        barco[1].suma = barco[1].suma + contenedores_list[i].peso;
                        total = total + contenedores_list[i].peso;
                        barco[1].cont[k].id = contenedores_list[i].id;
                        barco[1].cont[k].peso = contenedores_list[i].peso;
                        i++;
                        k++;
                        }
                        break;

                    case 2:
                        tot = tot + contenedores_list[i].peso;
                         if(tot > MAX_PESO){
                            tot=1;
                        }else{
                        barco[2].suma = barco[2].suma + contenedores_list[i].peso;
                        total = total + contenedores_list[i].peso;
                        barco[2].cont[w].id = contenedores_list[i].id;
                        barco[2].cont[w].peso = contenedores_list[i].peso;
                        i++;
                        w++;
                        }
                        break;
                    }
                    sum0= barco[0].suma;
                    sum1= barco[1].suma;
                    sum2= barco[2].suma;
                }
                    barco[0].cont[j].id = 0;
                    barco[1].cont[k].id = 0;
                    barco[2].cont[w].id = 0;

                return i;
            }


            int contador(barco_t barco[], int k){

            int i, cont;
            int id = 12;
            cont =0;
                for(i=0; id!=0; i++){
                    id=barco[k].cont[i].id;
                    if(id!=0)cont++;
                }
            return cont;
            }

            void mostrar_resultado(barco_t barco[], int carga){

            int cont0, cont1, cont2, peso0, peso1, peso2, peso_t, muelle;
            float media;

            cont0 = contador(barco,0);
            cont1 = contador(barco,1);
            cont2 = contador(barco,2);
            peso0 = peso_total(barco,0);
            peso1 = peso_total(barco,1);
            peso2 = peso_total(barco,2);
            peso_t = peso0 + peso1 + peso2;
            muelle= MAX -carga;
            media = (peso_t)/3;
            printf("\n\t Num. TEU DELANTE %i\t %i", cont0, peso0);
            printf("\n\t Num. TEU MEDIO %i\t %i", cont1, peso1);
            printf("\n\t Num. TEU DETRAS %i\t %i", cont2, peso2);
            printf("\n\t Num. TEU MUELLE %i\n", muelle);
            printf("\n\t PESO TOTAL BARCO %i\n", peso_t);
            printf("\n\t MEDIA TOTAL DE CADA SECCIÓN %.2f\n", media);


            mostrar_barco(barco);

            }

            int peso_total(barco_t barco[], int k){

                int i;
                int id =12;
                int peso =0;

                for(i=0; id != 0; i++){
                    id = barco[k].cont[i].id;
                    if(id != 0){
                    peso = peso + barco[k].cont[i].peso;
                    }
                }

                return peso;
            }

            void mostrar_barco(barco_t barco[]){

                int i =0;
                int id=12;
                int sum, id_0, id_1, id_2;
                sum=1;
                id_0=1;
                id_1=1;
                id_2=1;
                 printf("\n\n\t\t DELANTE\t\t  MEDIO\t\t\t  ATRAS\n\n");
                while(sum!=0){

                    /*Imprimir DELANTE*/
                    if(id_0!=0){
                        id = barco[0].cont[i].id;
                        if(id!=0){
                        printf("\t\t%i\t", barco[0].cont[i].id);
                        printf("%i\t", barco[0].cont[i].peso);
                        }else{
                            printf("\t\t\t\t");
                            id_0=0;
                        }
                    }else{
                            printf("\t\t\t\t");
                        }
                    printf("||");
                    /*IMPRIMIR MEDIO*/
                    if(id_1!=0){
                        id = barco[1].cont[i].id;
                        if(id!=0){
                        printf("\t%i\t", barco[1].cont[i].id);
                        printf("%i\t", barco[1].cont[i].peso);
                        }else{
                            printf("\t\t\t");
                            id_1=0;
                        }
                    }else{
                            printf("\t\t\t");
                        }
                    printf("||");
                    /*IMPRIMIR ATRAS*/
                    if(id_2!=0){
                        id = barco[2].cont[i].id;
                        if(id!=0){
                        printf("\t%i\t", barco[2].cont[i].id);
                        printf("%i\n", barco[2].cont[i].peso);
                        }else{
                            printf("\n");
                            id_2=0;
                        }
                    }else{
                            printf("\n");
                        }

                sum = id_0 + id_1 + id_2;
                i++;
                }

                printf("\t\t##########################################################\n");


            }







