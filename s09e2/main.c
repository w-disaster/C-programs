#include <stdio.h>
#include <stdlib.h>
#include "Lista_Coll.h"
#include "Funzioni_generali.h"
int main()
{
    int ins;
    punt_libro testa;

    //Inserimento quantità libri da registrare
    ins=Elementi_da_inserire();
    //FUNZIONE CREA LISTA: viene allocata la memoria necessaria per contenere ins strutture
    testa=Crea_lista_coll(ins);
    if (Controllo(1)==true){
        //FUNZIONE NUOVO LIBRO
        testa=Ins_nuovo(testa);
    }
    if (Controllo(2)==true){
        //FUNZIONE ELIMINA LIBRO
        testa=Elimina_prima_occorrenza_coll(testa);
    }
    if (Controllo(3)==true){
        //FUNZIONE VISUALIZZA ELEMENTO
        Visualizza_Elemento(testa);
    }
    if(Controllo(4)==true){
        //FUNZIONE STAMPA
        Stampa_Lista_Coll(testa);
    }
    if(Controllo(5)){
        //FUNZIONE VISUALIZZA LIBRI CON UN CERTO FEEDBACK
        Stampa_Feedback(testa);
    }
    return 0;
}
