#include "Prototype.h"


int Rondas(){
    int R;
    do {
    printf("Ingrese Cantidad de Rondas a jugar (MAX 20):\n"RESET_COLOR);
    scanf("%d",&R);
    } while (R>=MAX_RONDAS);

     if (R == 0 || R < 0){
        printf("Ingrese un valor entre 1 y 20!\n");
        scanf("%d",&R);
     }

    return R;

}

void Comienzo (int A[], int x){ //CORREGIR TAMANO DE ARREGLO PARA USAR CON DISTINTOS

    int i;

    for(i=0; i<x; i++){
        A[i] = 0;
    }

}

void Fichas_Valor(int F[], int C[], int Rdo[]){
    int i;

    for (i=0; i<MAX_FICHAS; i++){
        Rdo[i] = F[i] * C[i];
    }

}
void Rdo_Tirada(int x, int Juego[], float GananciaRonda[], float PerdidaRonda[], int i, int Rojo[], int Negro[]){
    int j, n, d, contcolor = 0, contColum = 0, contDoc = 0, contParidad = 0, contFalPas = 0;
    d = x+12;

    // X == al numero que salio por tirada rand.
    for (j=0; j<TAM_JUEGO; j++){
        if (Juego[j] != 0){
            if (j >= 12){ // PLENO *35
                    if (j == d){ // se pone +12 por el tema que se iguala al index j de del arreglo juego
                        PerdidaRonda[i] += Juego[j] * 36;
                    } else {
                        GananciaRonda[i] += Juego[j];
                    }
            }
            if (j >=0 && j <= 5){
                if (j<2){ // ROJO Y NEGRO
                    for (n=0;n<18;n++){
                        if ((j == 0 && Rojo[n] == x) || (j == 1 && Negro[n] == x)){
                            PerdidaRonda[i] += Juego[j] * 2;
                        } else {
                            contcolor++;// contaor para ver cuantas veces no entra en el if
                            //GananciaRonda[i] += Juego[j]; //CORREGIR POR QUE DA ERROR, SUMA SIEMPRE QUE NO ENTRE EN EL ARREGLO ROJO O NEGRO
                        }
                        if (contcolor == 18){
                            GananciaRonda[i] += Juego[j];
                        }
                        /*if (j == 1 && Negro[n] == x){
                            PerdidaRonda[i] += Juego[j] * 2;
                        } else {
                            GananciaRonda[i] += Juego[j]; // LO MISMO
                        }*/
                    }
                }
                if (j>=2 && j<4){ // PAR E IMPAR
                    if (j == 2 && x%2 == 0 && x!=0) /*|| (j == 3 && x%2 != 0 && x!=0)*/{
                        PerdidaRonda[i] += Juego[j] * 2;
                    } else if (j == 3 && x%2 != 0 && x!=0){
                        PerdidaRonda[i] += Juego[j] * 2;
                    } else {
                        contParidad++;
                        //GananciaRonda[i] += Juego[j];
                    }
                    if (contParidad >= 1){
                        GananciaRonda[i] += Juego[j];
                    }
                   /* if (j == 3 && x%2 != 0 && x!=0) {
                        PerdidaRonda[i] += Juego[j] * 2;
                    } else {
                        GananciaRonda[i] += Juego [j];
                    }*/
                }
                if (j>=4 && j<6){ //FALTA Y PASA
                    if(((j==4 && x<19)||(j==5 && x>18)) && x!=0){
                        PerdidaRonda[i] += Juego[j] * 2;
                    } else if ((j==5 && x>18) && x!=0) {
                        PerdidaRonda[i] += Juego[j] * 2;
                    } else {
                        contFalPas++;
                        //GananciaRonda[i] += Juego[j];
                    }
                    if (contFalPas>=1){
                        GananciaRonda[i] += Juego[j];
                    }
                }
            }
            if (j>=6 && j<12){
                if (j<9){ // COLUMNAS
                    if((j==6 && (x%3)==1)/*||(j==7 && (x%3)==2)||(j==8 && (x%3)==0))*/ && x!=0) {
                        PerdidaRonda[i] += Juego[j] * 3;
                    } else if ((j==7 && (x%3)==2) && x!=0){
                        PerdidaRonda[i] += Juego[j] * 3;
                    } else if ((j==8 && (x%3)==0) && x!=0){
                        PerdidaRonda[i] += Juego[j] * 3;
                    } else {
                        contColum++; // CONTADOR PARA PODER VER SI ENTRA O NO EN ALGUNO DE LOS IF
                        //GananciaRonda[i] += Juego[j];
                    }
                    if (contColum >= 1){
                        GananciaRonda[i] += Juego[j];
                    }
                }
                if (j>=9 && j<12){ //DOCENAS
                    if ((j==9 && x<=12)/*||(j==10 && x>12 && x<=24)||(j==11 && x>24 && x<=36)) */&& x!=0){
                        PerdidaRonda[i] += Juego[j] * 3;
                    } else if ((j==10 && x>12 && x<=24) && x!=0){
                        PerdidaRonda[i] += Juego[j] * 3;
                    } else if ((j==11 && x>24 && x<=36) && x!=0){
                        PerdidaRonda[i] += Juego[j] * 3;
                    } else {
                        contDoc++;
                        //GananciaRonda[i] += Juego[j];
                        }
                    if (contDoc >= 1){
                        GananciaRonda[i] += Juego[j];
                        }
                    }
                }
            }
        }
    }
void RdoMesa(float Ganancia[], float Perdida[], int x, float Rdo[], int i){

    Rdo[i] = Ganancia[i] - Perdida[i];

    if (Rdo[i] == 0){
        printf(AMARILLO_T"MESA NO CONFORME\n"RESET_COLOR); //INGRESOS Y PERDIDAS EQUIVALENTES
    } else if (Rdo[i] > 0){
        printf(VERDE_T"MESA GANADORA\n"RESET_COLOR); // INGRESOS > PERDIDAS
    } else {
        printf(ROJO_T"MESA PERDEDORA\n"RESET_COLOR); // PERDIDAS > INGRESOS
    }

}
float PromedioApuestasRonda (int Ap[], int R){
    int j;
    float sumaApuesta = 0;
    float promApuesta;

    for (j=0; j<R; j++){
        sumaApuesta += Ap[j];
    }
    promApuesta = sumaApuesta/R;

    return promApuesta;

}

void ValorMayor (int SumaApuesta[], int R){

    int j, mayor = 0;

    for (j=0; j<R; j++){
        if (R == 1){
        printf("Apuesta de Mayor Valor Monetario $ %d y sucedio en la Ronda %d\n",SumaApuesta[0], j);
        }
        if (SumaApuesta[j] > SumaApuesta[mayor]){
            mayor = j;
            printf("Apuesta de Mayor Valor Monetario $ %d y sucedio en la Ronda %d\n",SumaApuesta[mayor], mayor);
        }
    }

}
void PorcentajeColor(int Rojo, int Negro){

    int porcentajeRojo;
    int porcentajeNegro;

    // printf("%d", Rojo);
    //printf("%d", Negro);
    if (Rojo == 0 && Negro == 0){
            printf("No se Hicieron Apuestas a COLOR\n");
    } else {
      porcentajeRojo = Rojo * 100 / (Rojo + Negro);
      porcentajeNegro = Negro * 100 / (Negro + Rojo);
      printf("%d\n",porcentajeRojo);
      printf("%d\n",porcentajeNegro);
    }



}
void Consecutivo(int Rojo[], int Negro[], int Rondas[], int i, int R ){

    int j;
    int Color[R];
    int contColor = 0, contMax = 0;

    if (R >= 5 && Rondas[i] !=0){
        for (j=0; j<R; j++){
                for(int e=0; e<18; e++){
                    if(Rondas[j] == Rojo[e]){
                        Color[j] = 0;
                    } else {
                        Color[j] = 1;
                    }
                }

        }
        for(j=0; j<R; j++){
        if (Color[j] == Color[j+1]){
            contColor++; // CONTADOR PARA VER SI SALIERON 5 SEGUIDOS O MAS
            if (contColor >= 4){
                contMax ++; // ES PARA VER CUANTAS VECES SALIERON 5 O MAS DEL MISMO COLOR
                printf("Hubo 5 colores iguales seguidos\n");
                break; // SE UTILZA PARA FRENAR EL CICLO POR QUE YA SALIERON 5 SEGUIDOS DEL MISMO COLOR
            }
        } else {
            contColor = 0;
            }
        }
        if (contMax == 0){
            printf("No salieron nunca 5 colores iguales seguidos !!\n");
        }
    } else {
        printf("NO SE HAN JUGADO MAS DE 5 RONDAS\n");
    }

}
void Multiplo (int Rondas[],int R){

    int j;
    int contMult = 0;

    for (j=0; j<R; j++){
        if(Rondas[j] % 10 == 0){
            contMult++;
        }
    }
    if (contMult == 0){
        printf("NUNCA SALIO EL 0 Y MULTIPLOS DE 10\n");
    } else {
        printf("SALIO AL MENOS UNA VEZ EL 0 O MULTIPLOS DE 10\n");
    }
}

void Primo (int Rondas[],int R){

    int j, contPrimo = 0;
    int NumePrimos[] = {2,3,5,7,11,13,17,19,23,29,31};

    for(j=0; j<R; j++){
        for (int e = 0; e<11; e++){
            if (Rondas[j] == NumePrimos[e]){
                contPrimo++;
            }
        }
    }
    printf("CANTIDAD DE NUMERO PRIMOS QUE SALIERON: %d", contPrimo);

}


