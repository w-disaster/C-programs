#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista_Statica.h"

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
    //Inizializzo le variabili della struttura
    (*punt_iniz)->last=-1;
}
bool Isempty(Lista_statica *punt_empty){
    if (punt_empty->last==-1){
        return true;
    }
    return false;
}
void Inserimento(Lista_statica *punt_inserimento){
    int el, num_el,i=0,tmp,pos;
    printf("\n\nQuanti numeri vuoi inserire?: (min 1,max 9): ");
    scanf(" %d",&num_el);
    fflush(stdin);
    while (Full(punt_inserimento->last+num_el+1)||num_el<0){
        printf("\nNumero troppo grande o non supportato, reinserire: ");
        scanf("%d",&num_el);
        fflush(stdin);
    }
    if (num_el!=0){
        if (punt_inserimento->last==-1){
            punt_inserimento->last=num_el-1;
            tmp=punt_inserimento->last;
        }
        else {
            /*Dato che inseriamo sempre in testa, dobbiamo scorrere tutti gli elementi già presenti
            di n posizioni con n pari al numero di elementi che vogliamo inserire, quindi:
            1) viene preso il last corrente (pos) ed il last incrementato del nuovo numero di elementi ancora
            da inserire (tmp); 2) eseguo un ciclo dove il vettore alla posizione tmp prende il numero alla
            posizione pos, decrementandoli alla fine di una istanza.*/
            pos=punt_inserimento->last;
            punt_inserimento->last+=num_el-1;
            for (tmp=punt_inserimento->last;pos>=0;tmp--,pos--){
                punt_inserimento->num[tmp]=punt_inserimento->num[pos];
            }
            //Incremento infine tmp perchè è la posizione dove finalmente posso aggiungere i nuovi numeri
            tmp++;
        }
        for (;tmp>=0;tmp--){
            printf("\nInserisci numero (indice: %d) ",tmp);
            scanf("%d",&punt_inserimento->num[tmp]);
            fflush(stdin);
        }
        printf("\n\nNumero/i inserito/i con successo\n\n");
    }
}

void Ins_testa(Lista_statica *punt_testa){
    int testa,tmp;
    //inserimento numero da aggiungere
    if (Full(punt_testa->last+2)==false){
        printf("\nNumero da inserire: ");
        scanf("%d",&testa);
        fflush(stdin);
        //Sposto tutti gli elementi da pos n a n+1
        punt_testa->last++;
        //Se il vettore è vuoto inserisci in testa senza spostare tutti gli elementi del vettore
        if (punt_testa->last==0){
            punt_testa->num[punt_testa->last]=testa;
        }
        else {
            //Parti dal last ed ogni elemento è uguale a quello precedente
            for (tmp=punt_testa->last;tmp>0;tmp--){
                punt_testa->num[tmp]=punt_testa->num[tmp-1];
            }
            //Ora che tmp==0 inserisco il nuovo elemento
            punt_testa->num[tmp]=testa;
            printf("\n\nElemento inserito correttamente\n");
        }
    }
    else {
        printf("\n\nNon puoi inserire altri elementi perche\' hai esaurito lo spazio nel vettore\n\n");
    }
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
        printf("%d  ",lista_statica->num[i]);
    }
    printf("\n\tLast: %d\n",lista_statica->last);
    printf("\n\n----------------------------------------------------------------------------------");
}
