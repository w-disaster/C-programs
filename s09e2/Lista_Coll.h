#ifndef LISTA_COLL_H_INCLUDED
#define LISTA_COLL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define N 20
//STRUTTURA
struct Libro{
char cod_id[N];
char titolo[30];
char autore[N];
char casa_editrice[N];
char genere[N];
int anno_pubb;
int lung;
int feedback;
struct Libro *next;
};
typedef struct Libro *punt_libro;

//FUNZIONI LISTA COLLEGATA
punt_libro Iniz_Lista_coll();
punt_libro Crea_lista_coll(int numero_libri);

void Inserimento_libro(punt_libro punt_ins,int cont,int tipo);

void Stampa_Feedback(punt_libro punt_feed);

punt_libro Ins_nuovo(punt_libro punt_nuovo);

punt_libro Elimina_prima_occorrenza_coll(punt_libro punt_elimina_occ_coll);
void Stampa_Lista_Coll(punt_libro punt_stampa);
void Visualizza_Elemento(punt_libro punt_pos_coll);
void Inserisci_e_Controlla(punt_libro punt, int selezione);
#endif // LISTA_COLL_H_INCLUDED
