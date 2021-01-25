#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED

//#includes
#include <stdio.h>
#include <stdlib.h>


//DEFINE
#define MAX_RONDAS 20
#define MAX_APUESTAS 10
#define MAX_FICHAS 6
#define TAM_JUEGO 49
#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"


//PROTOTIPOS
int Rondas();
void Comienzo (int [], int);
void Fichas_Valor(int [], int [], int []);
void Rdo_Tirada(int , int [],float [], float [], int, int [], int[]);
void RdoMesa(float [], float [], int, float [], int);
float PromedioApuestasRonda (int [], int );
void ValorMayor (int SumaApuesta [], int);
void PorcentajeColor (int , int);
void Consecutivo(int [], int [], int [], int , int);
void Multiplo (int [], int);
void Primo (int [],int);


#endif // PROTOTYPE_H_INCLUDED
