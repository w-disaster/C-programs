#ifndef FUNZIONI_GENERALI_H_INCLUDED
#define FUNZIONI_GENERALI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#define fflush(stdin) while(getchar()!='\n')
#endif


/* Queste funzioni sono state inserite in questa libreria perchè vengono chiamate indipendentemente
dal tipo di lista */
int Scelta();
int Controllo();
int Elementi_da_inserire(int par);
void Continua();
#endif // FUNZIONI_GENERALI_H_INCLUDED
