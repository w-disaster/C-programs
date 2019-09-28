#ifndef LISTA_COLL_H_INCLUDED
#define LISTA_COLL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
//STRUTTURA
struct lista_coll{
int num_coll;
struct lista_coll *next;
};
typedef struct lista_coll *punt_coll;

//FUNZIONI LISTA COLLEGATA
punt_coll Iniz_Lista_coll();
punt_coll Crea_lista_coll(int num_el_coll);
//Funzioni inserimento
punt_coll Ins_testa_coll(punt_coll punt_ins_testa);
void Ins_coda_coll(punt_coll punt_ins_coll);
bool Ins_da_posizione_coll(punt_coll punt_pos_coll);
//Funzioni elimina
punt_coll Elimina_dalla_testa_coll(punt_coll elimina_testa_coll);
void Elimina_dalla_coda_coll(punt_coll elimina_coda_coll);
punt_coll Elimina_prima_occorrenza_coll(punt_coll corr);

void Stampa_Lista_Coll(punt_coll punt_stampa);
#endif // LISTA_COLL_H_INCLUDED
