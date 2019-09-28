#ifndef LISTA_STATICA_H_INCLUDED
#define LISTA_STATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define N 10
//statica
typedef int tipoel;
struct list_stat {
tipoel num[N];
int last;
};
typedef struct list_stat Lista_statica;
Lista_statica LISTA_STAT;

bool Full(int a);
void Inizializz_Lista_Statica(Lista_statica **punt_iniz);
void Inserimento(Lista_statica **punt_inserimento);
bool Isempty(Lista_statica *punt_empty);
void Ins_coda(Lista_statica **punt_coda);
void Elimina_dalla_coda(Lista_statica *punt_elimina_da_coda);
void Stampa_lista_statica(Lista_statica *lista_statica);
#endif // LISTA_STATICA_H_INCLUDED
