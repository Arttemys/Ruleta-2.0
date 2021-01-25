#include "Prototype.h"

int main()
{
    int R, i=0, j, apuestas, el, el2,k, rojo = 0,negro = 0;
    int Juego[49];
    /* [0] - [1] = ROJO Y NEGRO
        [2] - [3] = PAR E IMPAR
        [4] - [5] = FALTA Y PASA
        [6] - [8] = COLUMNAS
        [9] - [11] = DOCENAS
        [12] - [49] = NUMEROS DEL 0 AL 36
    */
    int Rojo[] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    int Negro[] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    int Fichas[MAX_FICHAS] = {1,2,5,10,50,100};
    int Cfichas[MAX_FICHAS];
    int Rdo[MAX_FICHAS]; // Valor total de las Apuestas.

    printf(MAGENTA_T"Super Roullete 2020!!\n"RESET_COLOR);
    printf(CYAN_T"Comience el Juego, Buena suerte!\n");

    R = Rondas();
    float PerdidaRonda[R], GananciaRonda[R]; // CORREGIR HAY QUE INICIALIZAR EN 0
    int Rondas[R], SumaApuesta[R];
    int Ap[R];
    float RdoFinal[R];
    //printf("%d",R);
    Comienzo(PerdidaRonda, R);
    Comienzo(GananciaRonda, R);
    Comienzo(SumaApuesta,R);

    srand(getpid());

    // Comienza el juego
    for (i; i<R; i++){
        Comienzo(Juego,TAM_JUEGO);
        printf("Ronda %d de %d!\n",i+1,R);
            do{
                printf("Ingrese Cantidad de Apuestas que quiere hacer (MAX %d):\n",MAX_APUESTAS);
                printf("Si no quiere Realizar Apuestas en esta ronda coloque 0!\n");
                scanf("%d", &apuestas); // CANTIDAD DE APUESTAS
                if (apuestas == 0){break;}
            } while (apuestas > MAX_APUESTAS);
            for(j=0; j<apuestas; j++){
                printf("----------------------\n");
                printf("Apuesta %d\n",j+1);
                do {
                printf("Elija OPCION(1) o NUMERO(0)\n"); // OPCIONES DE APUESTA
                printf(">");
                scanf("%d",&el); // el == numero elegido (34)
                } while (el > 1);
                if (el == 0){
                    do {
                    printf("Elegir Numero a Apostar\n");
                    scanf("%d",&el2);
                    k = 12 + el2;
                    } while (el2 > 36 || el2 < 0);
                    /*for(int e=0; e<MAX_FICHAS; e++){
                        printf("Ingrese Cantidad de Fichas a Apostar:\t");
                        switch (e){
                            case 0:{printf("Ficha valor 1\n");}break;
                            case 1:{printf("Ficha valor 2\n");}break;
                            case 2:{printf("Ficha valor 5\n");}break;
                            case 3:{printf("Ficha valor 10\n");}break;
                            case 4:{printf("Ficha valor 50\n");}break;
                            case 5:{printf("Ficha valor 100\n");}break;
                        }
                        scanf("%d",&Cfichas[e]);
                    }*/
                } if (el == 1){
                    do{
                    printf("Elija la OPCION deseada:\n");
                    printf("2)Docenas.\n3)Columna.\n4)Falta y Pasa.\n5)Par e Impar.\n6)Color.\n");
                    scanf("%d",&el2);
                    } while (el2 > 6 || el2 < 2);
                    switch (el2) {
                        case 2: {printf("1)Docena 1\n2)Docena 2\n3)Docena 3\n");
                                 scanf("%d",&el2);
                            switch (el2) {
                                case 1: {k = 9;} break;
                                case 2: {k = 10;} break;
                                case 3: {k = 11;} break;
                            } break;
                        }
                        case 3: {printf("1)Columna 1\n2)Columna 2\n3)Colmuna 3\n");
                                 scanf("%d",&el2);
                            switch (el2){
                                case 1: {k = 6;} break;
                                case 2: {k = 7;} break;
                                case 3: {k = 8;} break;
                            }break;
                        }
                        case 4: {printf("1)Falta \n2)Pasa\n");
                                 scanf("%d",&el2);
                            switch (el2) {
                                case 1: {k = 4;} break;
                                case 2: {k = 5;} break;
                            }break;
                        }
                        case 5: {printf("1)Par\n2)Impar\n");
                                scanf("%d",&el2);
                            switch(el2) {
                                case 1: {k = 2;} break;
                                case 2: {k = 3;} break;
                            }break;
                        }

                        case 6: {printf("1)Rojo\n2)Negro\n");
                                scanf("%d",&el2);
                            switch (el2){
                                case 1: {k = 0;
                                        rojo++;} break;
                                case 2: {k = 1;
                                        negro++;} break;
                                }break;
                            }
                    }
                    /*for(int e=0; e<MAX_FICHAS; e++){
                        printf("Ingrese Cantidad de Fichas a Apostar:\t");
                        switch (e){
                            case 0:{printf("Ficha valor 1\n");}break;
                            case 1:{printf("Ficha valor 2\n");}break;
                            case 2:{printf("Ficha valor 5\n");}break;
                            case 3:{printf("Ficha valor 10\n");}break;
                            case 4:{printf("Ficha valor 50\n");}break;
                            case 5:{printf("Ficha valor 100\n");}break;
                        }
                        scanf("%d",&Cfichas[e]);
                    }*/
                }
                // FICHAS A ELEGIR
                for(int e=0; e<MAX_FICHAS; e++){
                    printf("Ingrese Cantidad de Fichas a Apostar:\t");
                    switch (e){
                        case 0:{printf("Ficha valor 1\n");}break;
                        case 1:{printf("Ficha valor 2\n");}break;
                        case 2:{printf("Ficha valor 5\n");}break;
                        case 3:{printf("Ficha valor 10\n");}break;
                        case 4:{printf("Ficha valor 50\n");}break;
                        case 5:{printf("Ficha valor 100\n");}break;
                        }
                    scanf("%d",&Cfichas[e]);
                    }
                    // cada vez que hay una apuesta se hace esto para que no se pierdan valores en CFichas
                    // CUENTA DE FICHAS
                    Fichas_Valor(Cfichas,Fichas,Rdo);
                    // PASAJE DE CUENTA A ARREGLO JUEGO5
                    for (int e=0; e<MAX_FICHAS; e++){
                    SumaApuesta[i] += Rdo[e];
                    }
                    for(int e=0; e<MAX_FICHAS; e++){
                        if (Rdo[e] != 0){
                            Juego[k] = Juego[k] + Rdo[e];
                    }
                }
            }
               /* Fichas_Valor(Cfichas,Fichas,Rdo);

                for(j=0; j<MAX_FICHAS; j++){
                    if (Rdo[j] != 0){
                        Juego[k] = Juego[k] + Rdo[j];
                    }
                }*/
                // TIRADA
                //srand(getpid());
                Rondas[i]=rand()%(36+1);
                printf("NO VA MAS!\n");
                printf("Salio el Numero %d ",Rondas[i]);
                    for (j=0; j<18; j++){
                        if (Rondas[i] == Rojo[j]){
                            printf(ROJO_T"ROJO\n"RESET_COLOR);
                            break;
                        } if (Rondas[i] == Negro[j]){
                            printf(NEGRO_T"NEGRO\n"RESET_COLOR);
                            break;
                        } if (Rondas[i] == 0){
                            printf(VERDE_T"VERDE\n"RESET_COLOR);
                            break;
                        }
                }

                printf("---------------------------------------\n");
                // CONTABILIDAD
                Rdo_Tirada(Rondas[i], Juego,GananciaRonda,PerdidaRonda,i,Rojo,Negro);

                for (j=0; j<R; j++){
                    printf("Perdida: %.2f\n", PerdidaRonda[j]);
                    printf("Ganacia: %.2f\n", GananciaRonda[j]);
                }
                // RESULTADO FINAL
                RdoMesa(GananciaRonda, PerdidaRonda, R, RdoFinal, i);

                for (j=0; j<R; j++){
                    Ap[j] = apuestas;
                }
                /*for (j=0; j<MAX_FICHAS; j++){
                    SumaApuesta[i] += Rdo[j];
                }*/

    }
                printf("\n");
                printf("---------------------------------------\n");
                printf("Promedio de Apuestas por Ronda :\t %.2f\n", PromedioApuestasRonda(Ap, R));
                ValorMayor(SumaApuesta,R);

                printf("\n");
                printf("---------------------------------------\n");
                printf("PORCENTAJE DE ELECCION COLOR(3)\n");
                PorcentajeColor (rojo, negro);
                printf("---------------------------------------\n");
                Consecutivo(Rojo,Negro,Rondas,i,R);
                printf("---------------------------------------\n");
                Multiplo(Rondas,R);
                printf("---------------------------------------\n");
                Primo(Rondas, R);

    return 0;
}
