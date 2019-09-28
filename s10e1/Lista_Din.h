#ifndef LISTA_DIN_H_INCLUDED
#define LISTA_DIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

//Dinamica
typedef int tipoel;
struct list_din{
    tipoel *num_din;
    int last_din;
    int size_din;
};
typedef struct list_din Lista_dinamica;
Lista_dinamica LISTA_DIN;
//Funzione creazione lista
void Inizializz_Lista_Dinamica(Lista_dinamica **punt_iniz);
void Crea_lista_dinamica(Lista_dinamica **punt_crea,int num_el_din);
//Funzione realloc()
bool Raddoppio_din(Lista_dinamica **punt_real);
//Funzioni inserimento
void Inserimento_lista_din(Lista_dinamica **punt_ins);
void Ins_coda_din(Lista_dinamica **punt_coda);
//Funzione elimina
void Elimina_dalla_coda_din(Lista_dinamica **punt_elimina);
//Funzione stampa
void Stampa_lista_dinamica(Lista_dinamica *lista_dinamica);
#endif // LISTA_DIN_H_INCLUDED
