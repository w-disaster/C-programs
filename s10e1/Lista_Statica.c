#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista_Statica.h"

//static int i;

bool Full(int a){
    //Se il numero di elementi che vuoi inserire è uguale a N (indice max) allora hai raggiunto il limite
    if (a>N){
        return true;
    }
    else {
        return false;
    }
}
void Inizializz_Lista_Statica(Lista_statica **punt_iniz){
    //Inizializzo le variabili ella struttura
    (*punt_iniz)->last=-1;
}
bool Isempty(Lista_statica *punt_empty){
    if (punt_empty->last==-1){
        return true;
    }
    return false;
}
void Inserimento(Lista_statica **punt_inserimento){
    int el, num_el,start;
    printf("\n\nQuanti numeri vuoi inserire?: (min 1,max 9): ");
    scanf(" %d",&num_el);
    fflush(stdin);
    (*punt_inserimento)->last++;

        while (Full((*punt_inserimento)->last+num_el)){
            printf("\nNumero troppo grande, reinserire: ");
            scanf("%d",&num_el);
            fflush(stdin);

        }
    /*Il costrutto for utilizza un doppio puntatore che modifica il last, quindi serve una variabile
    che indica il punto di partenza del ciclo: la chiamiamo start.*/

    start=(*punt_inserimento)->last;
    for ((*punt_inserimento)->last;(*punt_inserimento)->last<start+num_el;(*punt_inserimento)->last++){
        printf("\nInserisci intero da inserire nella posizione %d: ",(*punt_inserimento)->last);
        //Inserisci nuovo elemento
        scanf("%d",&el);
        fflush(stdin);
        (*punt_inserimento)->num[(*punt_inserimento)->last]=el;
    }
    (*punt_inserimento)->last--;
    printf("\n\nNumero/i inserito/i con successo\n\n");
}

void Ins_coda(Lista_statica **punt_coda){
    int coda;
    //inserimento numero da aggiungere
    if (Full((*punt_coda)->last+2)==false){
        printf("\nNumero da inserire: ");
        scanf("%d",&coda);
        fflush(stdin);
        //Incremento il last ed inserisco il nuovo elemento
        (*punt_coda)->last++;
        (*punt_coda)->num[(*punt_coda)->last]=coda;
        printf("\n\nElemento inserito correttamente\n");
    }
    else {
        printf("\n\nNon puoi inserire altri elementi perche\' hai esaurito lo spazio nel vettore\n\n");
    }
    //printf("Premi un tasto per continuare. . .\n");
}


void Elimina_dalla_coda(Lista_statica *punt_elimina_da_coda){
    // Pongo a NULL l'ultimo elemento del vettore (corrispondente al numero last) e decremento il last
    if (Isempty(punt_elimina_da_coda)==false){
        punt_elimina_da_coda->num[punt_elimina_da_coda->last]=0;
        punt_elimina_da_coda->last--;
        printf("\nL'elemento e\' stato eliminato con successo\n\n");
    }
    else {
        printf("\nNon e\' possibile eliminare un elemento perche\' la pila e\' vuota\n\n");
    }
}


void Stampa_lista_statica(Lista_statica *lista_statica){
    //Stampo la lista
    printf("\n\n----------------------------------------------------------------------------------");
    printf("\n\t\t\t\tLISTA:\n\n");
    printf("\tVettore: ");
    for (int i=0;i<=lista_statica->last;i++){
        printf("%d) %d\t",i,lista_statica->num[i]);
    }
    printf("\n\tLast: %d\n",lista_statica->last);
    printf("\n\n----------------------------------------------------------------------------------");
}




