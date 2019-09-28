#ifndef LISTA_COLL_H_INCLUDED
#define LISTA_COLL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//STRUTTURA
struct Lista_coll{
int num_coll;
struct Lista_coll *next;
};
typedef struct Lista_coll Lista_coll;
//FUNZIONI PILA COLLEGATA
//Funzione inizializzazione
void Iniz_Lista_coll(Lista_coll **punt_iniz_coll);
//Funzioni inserimento
void Crea_lista_coll(Lista_coll **punt_crea);
void Ins_coda_coll(Lista_coll **punt_coda);
//Funzioni elimina
void Elimina_dalla_coda_coll(Lista_coll **elimina_coda_coll);
//Funzione stampa
void Stampa_Lista_Coll(Lista_coll *punt_stampa);
#endif // LISTA_COLL_H_INCLUDED
