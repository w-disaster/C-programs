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
typedef struct list_din numeri_din;

numeri_din Crea_lista_dinamica(int num_el_din);
void Inserimento_lista_din(numeri_din *punt_inserimento_din, int fine);
bool Raddoppio_din(numeri_din *punt_lista_din);
//Funzioni inserimento
void Ins_testa_din(numeri_din *punt_ins_testa_din);
void Ins_coda_din(numeri_din *punt_ins_coda_din);
void Ins_da_posizione_din(numeri_din *punt_posiz_din);
//Funzioni elimina
void Elimina_dalla_testa_din(numeri_din *punt_elimina_da_testa_din);
void Elimina_dalla_coda_din(numeri_din *punt_elimina_da_coda_din);
void Elimina_prima_occorrenza_din(numeri_din *punt_elimina_prima_occ_din);

void Stampa_lista_dinamica(numeri_din *lista_dinamica);
#endif // LISTA_DIN_H_INCLUDED
