#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista_Statica.h"

bool Full(int a){
    //Se il numero di elementi che vuoi inserire è uguale a N (indice max) allora hai raggiunto il limite
    if (a==N){
        return 1;
    }
    else {
        return 0;
    }
}
numeri Inizializz_Lista_Statica(){
    //Inizializzo le variabili ella struttura
    numeri listastat={0,0};
    return listastat;
}
void Inserimento(int b, numeri *punt_inserimento){
int i=0, el;
   for (i=0;i<b;i++){
        printf("\nInserisci intero da inserire nella posizione %d: ",i);
        //Inserisci nuovo elemento
        scanf("%d",&el);
        fflush(stdin);
        punt_inserimento->num[i]=el;
    }
    //Inizializzo il last
    punt_inserimento->last=i-1;
}
void Ins_testa(numeri *punt_testa){
    int i,testa;
    //Inserimento numero da aggiungere
    printf("\nNumero da inserire in testa: ");
    scanf("%d",&testa);
    fflush(stdin);

    punt_testa->last=punt_testa->last+1;
    for (i=punt_testa->last;i>0;i--){
        /*L'elemento corrente (partendo dall'ultimo) prende quello precedente:
        il valore del primo elemento non viene assunto dal secondo*/
        punt_testa->num[i]=punt_testa->num[i-1];
    }
    //Quindi posso aggiungere nel primo elemento il nuovo numero
    punt_testa->num[i]=testa;
    printf("\nElemento inserito correttamente");
}
void Ins_coda(numeri *punt_coda){
    int coda;
    //inserimento numero da aggiungere
    printf("\nNumero da inserire in coda: ");
    scanf("%d",&coda);
    fflush(stdin);
    //Inserisco il nuovo elemento sul last e lo incremento
    punt_coda->num[(punt_coda->last)+1]=coda;
    punt_coda->last=punt_coda->last+1;
    printf("\n\nElemento inserito correttamente");
}

bool Ins_da_posizione(numeri *punt_posiz){
    int i,k,el_pos,el_nuovo;
    //Inserimento elemento esistente e nuovo elemento
    printf("\nElemento esistente: ");
    scanf("%d",&el_pos);
    printf("\nNuovo elemento: ");
    scanf("%d",&el_nuovo);

    for (i=0;i<=punt_posiz->last;i++){
        if (punt_posiz->num[i]==el_pos){
            /*i si ferma.Dalla fine del vettore ogni elemento è uguale all'elemento precedente finchè k>=i+2. NB in ciclo fa prendere a num, quando k=i+2, quello ch è dentro k=i+1
            quindi k=i+1 e k=i+2 sono numeri uguali fino a quando a num nella posizione k=i+1 gli assegno il nuovo elemento da inserire*/
            for(k=(punt_posiz->last)+1;k>=i+2;k--){
                punt_posiz->num[k]=punt_posiz->num[k-1];
            }
            punt_posiz->num[k]=el_nuovo;
            punt_posiz->last=punt_posiz->last+1;
            return true;
        }
    }
    return false;
}
void Elimina_dalla_testa(numeri *punt_elimina_da_testa){
    int i;
    for(i=0;i<=punt_elimina_da_testa->last;i++){
        /*L'elemento corrente (partendo dal primo) prende il successivo:
        il valore del primo elemento non viene assunto da nessuno*/
        punt_elimina_da_testa->num[i]=punt_elimina_da_testa->num[i+1];
    }
    punt_elimina_da_testa->last=punt_elimina_da_testa->last-1;
}
void Elimina_dalla_coda(numeri *punt_elimina_da_coda){
    // Pongo a NULL l'ultimo elemento del vettore (corrispondente al numero last) e decremento il last
    punt_elimina_da_coda->num[punt_elimina_da_coda->last]=0;
    punt_elimina_da_coda->last--;
}

int Elimina_prima_occorrenza(numeri *punt_elimina_prima_occ){
    int i,k,el_da_canc;
    //Inserisco l'elemento da eliminare
    printf("\nElemento da eliminare: ");
    scanf("%d",&el_da_canc);
    /*Scorro il vettore e se c'è occorrenza da quell'indice in poi l'elemento corrente
    è uguale a quello successivo: l'ultimo elemento sarà uguale al penultimo quindi decremento il last*/
    for (i=0;i<punt_elimina_prima_occ->last;i++){
        if (punt_elimina_prima_occ->num[i]==el_da_canc){
            k=i;
            for (;i<punt_elimina_prima_occ->last;i++){
               punt_elimina_prima_occ->num[i]=punt_elimina_prima_occ->num[i+1];
            }
            punt_elimina_prima_occ->last-=1;
            return k;
        }
    }
    return -1;
}

void Stampa_lista_statica(numeri *lista_statica){
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




