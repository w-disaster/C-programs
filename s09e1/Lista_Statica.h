#ifndef LISTA_STATICA_H_INCLUDED
#define LISTA_STATICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define N 10
//statica
typedef int tipoel;
struct list_stat {
tipoel num[N];
int last;
};
typedef struct list_stat numeri;


bool Full(int a);
numeri Inizializz_Lista_Statica();
void Inserimento(int b, numeri *punt_inserimento);
//Funzioni inserimento
void Ins_testa(numeri *punt_testa);
void Ins_coda(numeri *punt_coda);
bool Ins_da_posizione(numeri *punt_posiz);
//Funzioni elimina
void Elimina_dalla_testa(numeri *punt_elimina_da_testa);
void Elimina_dalla_coda(numeri *punt_elimina_da_coda);
int Elimina_prima_occorrenza(numeri *punt_elimina_prima_occ);

void Stampa_lista_statica(numeri *lista_statica);
#endif // LISTA_STATICA_H_INCLUDED
