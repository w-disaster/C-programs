#ifndef FUNZIONI_GENERALI_H_INCLUDED
#define FUNZIONI_GENERALI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
/* Queste funzioni sono state inserite in questa libreria perchè vengono chiamate indipendentemente
dal tipo di lista */
int Scelta();
bool Controllo(int tipo_out);
int Elementi_da_inserire(int par);

#endif // FUNZIONI_GENERALI_H_INCLUDED
