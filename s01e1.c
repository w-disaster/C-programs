/* Scrivere un programma C che dichiari una variabile per ogni tipo studiato (usando anche i qualificatori short, long, signed e unsigned),
ne stampi il valore e l’occupazione di memoria in byte. Utilizzare TUTTI gli argomenti della funzione printf() studiati e TUTTE le diverse varianti
(modificatore, campoMinimo, precisione, modificatoreLunghezza). Per ogni chiamata alla funzione printf(), mostrare a video anche il numero di caratteri
che quest’ultima ha stampato (Aiuto: la funzione printf() restituisce un valore). Stampare inoltre il valore minimo e il
valore massimo ammissibile per ogni tipo utilizzato. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


int main()
{
/* dichiarazione variabili, assegnazione valori*/
    char lett= 'r';
    unsigned char un_lett= 'A';
    short int num_short_int= -54;
    unsigned short int un_num_short_int = 90;
    int num_int= 33;
    unsigned int un_num_int= 1245;
    long int num_lg_int= -2556677;
    unsigned long int un_lg_num_int= 123456;
    long long int num_lg_lg_int= 7869352;
    unsigned long long un_lg_lg_num_int= 5673452;
    float num_float= 65.9;
    double num_doub= 3.7452;
    long double num_long_double= 2.1532;
    int lunghezza;

    /* ne stampo i valori, l'occupazione in Byte, il valore minimo e massimo ammissibili per tipo  ed applico diverse varianti
    (modificatore, campoMinimo, precisione, modificatoreLunghezza */

    // variabile char
    lunghezza = printf("Char:%2c,\t\t\t Byte:%2.1d,\t\t Valore min: %d,\t\t  Valore max: %d", lett, sizeof(lett), CHAR_MIN, CHAR_MAX);
    printf("\t\t  Caratteri stampati: %d \n\n", lunghezza);

    // variabile unsigned char
    lunghezza = printf("Unsigned char:%2.1c,\t\t Byte: %d,\t\t\t\t\t\t  Valore max: %u ", un_lett, sizeof(un_lett),  UCHAR_MAX);
    printf("\t\t  Caratteri stampati: %d \n\n", lunghezza);

    // variabile short int
    lunghezza = printf("Short int: %-2.1d,\t\t\t Byte: %d,\t\t Valore min: %d,\t\t  Valore max: %d ", num_short_int, sizeof(num_short_int), SHRT_MIN, SHRT_MAX);
    printf("\t\t  Caratteri stampati: %d \n\n", lunghezza);

    // variabile unsigned short
    lunghezza = printf("Unsigned short int:%d,\t\t Byte: %d,\t\t\t\t\t\t  Valore max: %u ", un_num_short_int, sizeof(un_num_short_int), USHRT_MAX);
    printf("\t\t  Caratteri stampati: %d \n\n", lunghezza);

    // variabile int
    lunghezza = printf("Int: %d,\t\t\t Byte: %-2d,\t\t Valore min: %d,\t  Valore max: %d ", num_int, sizeof(num_int), INT_MIN, INT_MAX);
    printf("\t  Caratteri stampati: %d \n\n", lunghezza);

    // variabile unsigned int
    lunghezza = printf("Unsigned int: %2d,\t\t Byte: %d,\t\t\t\t\t\t  Valore max: %u", un_num_int, sizeof(un_num_int), UINT_MAX);
    printf("\t  Caratteri stampati: %d \n\n", lunghezza);

    // variabile long int
    lunghezza = printf("Long int: %5d,\t\t Byte: %d,\t\t Valore min: %ld,\t  Valore max: %ld", num_lg_int, sizeof(num_lg_int), LONG_MIN, LONG_MAX);
    printf("\t  Caratteri stampati: %d \n\n", lunghezza);

    // variabile unsigned long int
    lunghezza = printf("Unsigned long int: %2o,\t Byte: %d,\t\t\t\t\t\t  Valore max: %u", un_lg_num_int, sizeof(un_lg_num_int), ULONG_MAX);
    printf("\t  Caratteri stampati: %d \n\n", lunghezza);

    // variabile long long int
    lunghezza = printf("Long long int: %7lld,\t\t Byte: %d,\t\t Valore min: %lld,Valore max: %lld", num_lg_lg_int, sizeof(num_lg_lg_int), LONG_LONG_MIN, LONG_LONG_MAX);
    printf(" Caratteri stampati: %d \n\n", lunghezza);

    // variabile unsigned long long int
    lunghezza = printf("Unsigned long long int: %-8lld,Byte: %d,\t\t\t\t\t\t  Valore max: %llu", un_lg_lg_num_int, sizeof(un_lg_lg_num_int), ULONG_LONG_MAX);
    printf("Caratteri stampati: %d \n\n", lunghezza);

    // variabile float
    lunghezza = printf("Float: %g,\t\t\t Byte: %d,\t\t Valore min: %e,\t  Valore max: %e", num_float, sizeof(num_float), FLT_MIN, FLT_MAX);
    printf("\t  Caratteri stampati: %d \n\n", lunghezza);;

    // variabile double
    lunghezza = printf("Double: %f,\t\t Byte: %d,\t\t Valore min: %d,\t\t  Valore max: %d", num_doub, sizeof(num_doub), SHRT_MIN, SHRT_MAX);
    printf("\t\t  Caratteri stampati: %d \n\n", lunghezza);

    //variabile long double
    lunghezza= printf("Long double %g,\t", num_long_double);
    lunghezza= printf(" Byte: %d,\t\t Valore min: %d, \t  Valore max: %d", sizeof(num_long_double), LONG_MIN, LONG_MAX);
    printf("\t  Caratteri stampati: %d \n\n", lunghezza);

    system("pause");
    return 0;
}
