#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
    //Dichiarazione variabili
    int i, k, j, r;
    char v1[10][10], alf[]={'A','B','C','D','E','F','G','H','I','L','M','N','O','P','Q','R','S','T','U','V','Z'};
    /*esegui un ciclo che riempe ogni elemento della matrice con "." eccetto v1[0][0]
    (posizione di partenza) che viene riempito con il carattere "A" */
    j=0;
    for (i=0;i<10;i++){
        for (k=0;k<10;k++){
            if (i==0&&k==0){
            v1[i][k]=alf[j];
            }
            else {
            v1[i][k]='.';
            }
        }
    }

    i=0;
    k=0;
    //j=1 perchè j=0 è già stato occupato con "A" nel precedente ciclo
    j=1;

    // estraggo casualmente un numero (da 0 a 1)
    srand((unsigned)time(NULL));
    r=rand()%2;

    /*esegui un ciclo che termina quando i=20
    cioè quando le lettere dell'array alf (alfabeto) sono state tutte prese dal vettore v1*/
    while (j<21){
        //esegui un ciclo se il numero random r==0
        while (r==0){
            /* esegui la if sottostante che impedisce, quando siamo nell'ultima riga della matrice,
            di spostarci ancora più in basso (i+1) (essendo finito lo spazio), che impedisce di assumere valori
            quando è occupata da un altra lettera e quando non ci sono più lettere dell'alabeto disponibili.
            Se la condizione non è soddisfatta allora genera un altro numero casuale ed esci dal ciclo quando r!=0*/
            if (i!=9&&v1[i+1][k]=='.'&&j!=21){
            v1[i+1][k]=alf[j];
            //printf("%c",v1[i+1][k]);
            i++;
            j++;
            r=rand()%4;
            }
            else {
            r=rand()%4;
            }
        }
        while (r==1){
            /* esegui la if sottostante che impedisce, quando siamo nell'ultima colonna della matrice,
            di spostarci ancora più a destra (k+1) (essendo finito lo spazio), che impedisce di assumere valori
            quando è occupata da un altra lettera e quando non ci sono più lettere dell'alabeto disponibili.
            Se la condizione non è soddisfatta allora genera un altro numero casuale ed esci dal ciclo quando r!=1*/
            if (k!=9&&v1[i][k+1]=='.'&&j!=21){
                v1[i][k+1]=alf[j];
                //printf("%c",v1[i][k+1]);
                k++;
                j++;
                r=rand()%4;
            }
            else{
                r=rand()%4;
            }
        }
        while (r==2){
            /* esegui la if sottostante che impedisce, quando siamo nella prima colonna della matrice,
            di spostarci ancora più a sinistra (k-1) (essendo finito lo spazio), che impedisce di assumere valori
            quando è occupata da un altra lettera e quando non ci sono più lettere dell'alabeto disponibili.
            Se la condizione non è soddisfatta allora genera un altro numero casuale ed esci dal ciclo quando r!=2*/
            if (k!=0&&v1[i][k-1]=='.'&&j!=21){
                v1[i][k-1]=alf[j];
                //printf("%c",v1[i][k-1]);
                k--;
                j++;
                r=rand()%4;
            }
            else{
                r=rand()%4;
            }
        }
        //esegui ciclo finchè numero causale r==3
        while (r==3){
            /* esegui la if sottostante che impedisce, quando siamo nella prima riga della matrice,
            di spostarci ancora più in alto (i-1) (essendo finito lo spazio), che impedisce di assumere valori
            quando è occupata da un altra lettera e quando non ci sono più lettere dell'alabeto disponibili.
            Se la condizione non è soddisfatta allora genera un altro numero casuale ed esci dal ciclo quando r!=3*/
            if (i!=0&&v1[i-1][k]=='.'&&j!=21){
                v1[i-1][k]=alf[j];
                //printf("%c",v1[i-1][k]);
                i--;
                j++;
                r=rand()%4;
            }
            else {
                r=rand()%4;
            }
        }
    }

    //stampa di tutto il vettore generato
    for (i=0;i<10;i++){
        for (k=0;k<10;k++){
            printf("%c",v1[i][k]);
        }
    printf("\n");
    }

    return 0;
    }






