#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define GIORNI_MAX 31
/*Due colleghi intendono fissare una riunione, pertanto devono identificare i giorni nei quali sono entrambi liberi da impegni.
A tale scopo, si realizzi un programma C che permetta a ciascuno di immettere le proprie disponibilità, e che identifichi i giorni nei quali entrambi sono liberi.
In particolare, in una prima fase il programma deve acquisire un elenco di numeri interi che indicano i giorni del mese in cui essi sono disponibili
e nella seconda fase il programma deve identificare e stampare i giorni in cui entrambi i colleghi sono disponibili. Corredare il programma con gli opportuni commenti. */

int main()
{
    // dichiarazione variabili
    int i, k, j,  conf, ris;
    int p_uno[GIORNI_MAX]={0}, p_due[GIORNI_MAX]={0};
    bool flag;
    // inserimento primo giorno disponibile persona n1
    printf("Persona n.1. Inserire il numero del giorno del mese corrente: ");
    scanf("%d", &p_uno[0]);
    fflush(stdin);
    flag=true;
    // eseguzione ciclo fino a che l'utente non ha altri giorni liberi
    for (i=1; flag==true; i++){

        printf("\nVuoi inserire ancora? (se si inserire 1 altrimenti 0) ");
        scanf("%d", &conf);
        flag=conf;

        if (flag==false){
            break;
        }
    // inserimento giorno
        printf("\nGiorno %d: ", i+1);
        scanf("%d", &p_uno[i]);
        fflush(stdin);
    // eseguzione ciclo fino a che viene inserito un numero di giorno esistente (>0,<=31)
        while (p_uno[i]==p_uno[i-1]||p_uno[i]<1||p_uno[i]>GIORNI_MAX) {
            if (p_uno[i]==p_uno[i-1]){
                printf("\nGiorno gia\' inserito, inserirne un altro: ");
                scanf("%d", &p_uno[i]);
                fflush(stdin);
            }
            if (p_uno[i]<1||p_uno[i]>GIORNI_MAX){
                printf("\nNumero giorno inesistente, reinserire: ");
                scanf("%d", &p_uno[i]);
                fflush(stdin);
            }
        }
    }

    /* Giorni persona n1
    k=0;
    while (k<i){
        printf("%d ", p_uno[k]);
        k++;
    }
    */

    // inserimento primo giorno disponibile persona n2
    printf("\n\nPersona n.2. Inserire il numero del giorno del mese corrente: ");
    scanf("%d", &p_due[0]);
    fflush(stdin);
    flag=true;
    // eseguzione ciclo fino a che l'utente non ha altri giorni liberi
    for (k=1; flag==true; k++){

        printf("\nVuoi inserire ancora? (se si inserire 1 altrimenti 0) ");
        scanf("%d", &conf);
        flag=conf;

        if (flag==false){
            break;
        }

        printf("\nGiorno: %d ", k+1);
        scanf("%d", &p_due[k]);
        fflush(stdin);
// eseguzione ciclo fino a che viene inserito un numero di giorno esistente (>0,<=31)
        while (p_due[k]==p_due[k-1]||p_due[k]<1||p_due[k]>GIORNI_MAX) {
            if (p_due[k]==p_due[k-1]){
                printf("\nGiorno gia\' inserito, inserirne un altro: ");
                scanf("%d", &p_due[k]);
                fflush(stdin);
            }
            if (p_due[k]<1||p_due[k]>GIORNI_MAX){
                printf("\nNumero giorno inesistente, reinserire: ");
                scanf("%d", &p_due[k]);
                fflush(stdin);
            }
        }
    }

    /* giorni persona n2
    k=0;
    while (k<i){
        printf("%d ", p_due[k]);
        k++;
    }
    */

    // j prende k cioè gli elementi (k-1) del vettore p_due
    j=k;
    ris=0;
    printf("\nPer il colloquio potete incontrarvi nel/i giorno/i : ");
    // se il vettore p_uno è stato compilato esegui il ciclo
    while (i>=0){

        while (k>=0){
        // L'ultimo elemento del vettore p_uno (i-1) rimane fisso mentre k diminuisce scorrendo il vettore p_due dall'ultimo elemento al primo cercando una corrispondenza
        if (p_uno[i-1]==p_due[k-1]){
        ris= printf(" %d ", p_uno[i-1]);
        }
        k--;
        }
    // k prende j, in particolare k è pronto a rientrare nel while (k>=0) dopo aver decrementato la i, cioè l'elemento (i-1) del vettore
    k=j;
    i--;
    }

    // se ris è vuoto vuol dire che non è stata trovata alcuna corrispondenza
    if (ris==0)
        printf("Nessuna corrispondenza trovata");

    printf("\n");
    return 0;
}
