#include "Lista_Coll.h"
int contatore;

punt_libro Iniz_Lista_coll(){
    // Inizializzo lis alla struttura vuota
    punt_libro lis;
    lis=NULL;
    return lis;
}

void Inserimento_libro(punt_libro punt_ins,int cont, int tipo){
    //Inserimento valori in base al tipo (se sto inserendo i numeri inziali o se ho deciso di registrare un altro libro)
    if (tipo==1){

        printf("\n\nInserisci il codice identificativo del libro %d: ",cont+1);
        scanf(" %s",punt_ins->cod_id);
        fflush(stdin);

        printf("\nInserisci il titolo del libro %d: ",cont+1);
        scanf(" %s",punt_ins->titolo);
        fflush(stdin);

        printf("\nInserisci l'autore del libro %d: ",cont+1);
        scanf(" %s",punt_ins->autore);
        fflush(stdin);

        printf("\nInserisci la casa editrice del libro %d: ",cont+1);
        scanf(" %s",punt_ins->casa_editrice);
        fflush(stdin);

        printf("\nInserisci il genere del libro %d: ",cont+1);
        scanf(" %s",punt_ins->genere);
        fflush(stdin);

        printf("\nInserisci l'anno di pubblicazione del libro %d: ",cont+1);
        scanf(" %d",&punt_ins->anno_pubb);

        printf("\nInserisci numero di pagine del libro %d: ",cont+1);
        scanf(" %d",&punt_ins->lung);
        fflush(stdin);

        printf("\nInserisci la valutazione del libro %d (min 1 max 10): ",cont+1);
        scanf(" %d",&punt_ins->feedback);
        fflush(stdin);
        printf("\n\n----------------------------------------------------------------------------------\n\n");
    }
    else{
        printf("\n\nInserisci il codice identificativo del nuovo libro:");
        scanf(" %s",punt_ins->cod_id);
        fflush(stdin);

        printf("\nInserisci il titolo del nuovo libro: ");
        scanf(" %s",punt_ins->titolo);
        fflush(stdin);

        printf("\nInserisci l'autore del nuovo libro");
        scanf(" %s",punt_ins->autore);
        fflush(stdin);

        printf("\nInserisci la casa editrice del nuovo libro: ");
        scanf(" %s",punt_ins->casa_editrice);
        fflush(stdin);

        printf("\nInserisci il genere del nuovo libro: ");
        scanf(" %s",punt_ins->genere);
        fflush(stdin);

        printf("\nInserisci l'anno di pubblicazione del nuovo libro: ");
        scanf(" %d",&punt_ins->anno_pubb);

        printf("\nInserisci numero di pagine del nuovo libro: ");
        scanf(" %d",&punt_ins->lung);
        fflush(stdin);

        printf("\nInserisci la valutazione del nuovo libro (min 1 max 10): ");
        scanf(" %d",&punt_ins->feedback);
        fflush(stdin);
        while (punt_ins->feedback<=0||punt_ins->feedback>10){
           printf("\nNumero non valido, reinserire: ");
           scanf(" %d",&punt_ins->feedback);
           fflush(stdin);
        }

        printf("\n\n----------------------------------------------------------------------------------\n\n");
    }
}

punt_libro Crea_lista_coll(int numero_libri){
    //Testa punterà sempre al primo nodo della lista
    punt_libro testa=NULL;
    //paux viene usato per allocare spazio
    punt_libro paux;

    for (contatore=0;contatore<numero_libri;contatore++) {
        //Alloco memoria pari a quella che necessita una struttura di tipo Libro
        paux= (punt_libro)malloc(sizeof(struct Libro));
        if (paux!=NULL){
            Inserimento_libro(paux,contatore,1);
        }
        else{
            printf("Memoria insufficente per la memorizzazione del libro %d",contatore+1);
            EXIT_FAILURE;
        }
        paux->next = testa;
        testa=paux;
    }
    return testa;
}

void Stampa_Lista_Coll(punt_libro punt_stampa){
    //Stampa a video della lista
    printf("\n\n----------------------------------------------------------------------------------");
    printf("\n\t\t\t\tLISTA:\n\n");
    for (;punt_stampa!=NULL;punt_stampa=punt_stampa->next){
        printf("\tCodice libro: %s\n\n",punt_stampa->cod_id);
        printf("\tTitolo: %s\n\n",punt_stampa->titolo);
        printf("\tAutore: %s\n\n",punt_stampa->autore);
        printf("\tCasa editrice: %s\n\n",punt_stampa->casa_editrice);
        printf("\tGenere: %s\n\n",punt_stampa->genere);
        printf("\tAnno di pubblicazione: %d\n\n",punt_stampa->anno_pubb);
        printf("\tNumero pagine : %d\n\n",punt_stampa->lung);
        printf("\tValutazione: %d\n\n",punt_stampa->feedback);
        printf("\n----------------------------------------------------------------------------------\n\n");
    }

}


punt_libro Ins_nuovo(punt_libro punt_nuovo){
    punt_libro nuovo_nodo_testa;

    //Alloco spazio sufficente per contenere una struttura di tipo lista_coll
    nuovo_nodo_testa=(punt_libro)malloc(sizeof(struct Libro));
    //Controllo che l'allocazione sia terminata con successo
    if (nuovo_nodo_testa==NULL){
        printf("\nMemoria insufficiente per l'allocazione di un libro\n");
        return nuovo_nodo_testa;
    }
    //Insermiento nuovo numero
    Inserimento_libro(nuovo_nodo_testa,1,2);

    //Il next del nuovo nodo punta al primo già presente
    nuovo_nodo_testa->next=punt_nuovo;
    //Sposto la testa al nuovo elemento
    punt_nuovo=nuovo_nodo_testa;
    //Return il puntatore al primo elemento
    return nuovo_nodo_testa;
}

punt_libro Elimina_prima_occorrenza_coll(punt_libro punt_elimina_occ_coll){
    char el[N];
    punt_libro prec,corr;

    printf("\nInserisci codice identificativo del libro da eliminare: ");
    scanf(" %s",el);
    fflush(stdin);

    corr=punt_elimina_occ_coll;
    //Scorri la lista finchè il next è diverso da NULL ED il numero è diverso dall'elemento inserito
    for(prec=NULL;corr!=NULL&&(strcmp(corr->cod_id,el)!=0);prec=corr,corr=corr->next){
    };

    //Se prec==NULL vuol dire che è stata trovata la corrispondenza al numero della prima struttura
    if (prec==NULL){
        punt_elimina_occ_coll=punt_elimina_occ_coll->next;

    }
    else if(corr==NULL){
        //Se corr->next==NULL l'elemento non è stato trovato (è stata raggiunta la fine della lista)
        printf("\nIl libro non e\' presente nella lista\n\n");
        return punt_elimina_occ_coll;
    }
    else{
        //Altrimenti è stata trovata corrispondenza nella coda
        prec->next=corr->next;
    }
    printf("\nIl libro e\' stato eliminato con successo\n\n");
    //Elimina corr
    free(corr);
    //Ritorna il puntatore alla testa
    return (punt_elimina_occ_coll);

}

void Visualizza_Elemento(punt_libro punt_pos_coll){
    char el_pos[N];
    punt_libro punt_temp=punt_pos_coll;
    //Inserimento elemento esistente e nuovo elemento
    printf("\nCodice identificativo del libro da cercare: ");
    scanf(" %s",el_pos);

    //Pongo punt_temp=al puntatore alla testa passato come parametro e scorro tutta la lista finchè il next è !=0
    for(;punt_temp!=NULL&&(strcmp(punt_temp->cod_id,el_pos)!=0);punt_temp=punt_temp->next){
    }
    //Se temp==NULL sono arrivato alla fine della lista quindi non è stata trovata alcuna occorrenza
    if (punt_temp==NULL){
      printf("\nIl libro con codice identificativo %s non e\' presente nella lista\n\n",el_pos);
    }
    else
    {
        //Altrimenti stampo la struttura dove si trova attualmente punt_temp
        printf("\n\tCodice libro: %s\n\n",punt_temp->cod_id);
        printf("\tTitolo: %s\n\n",punt_temp->titolo);
        printf("\tAutore: %s\n\n",punt_temp->autore);
        printf("\tCasa editrice: %s\n\n",punt_temp->casa_editrice);
        printf("\tGenere: %s\n\n",punt_temp->genere);
        printf("\tAnno di pubblicazione: %d\n\n",punt_temp->anno_pubb);
        printf("\tNumero pagine : %d\n\n",punt_temp->lung);
        printf("\tValutazione: %d\n\n",punt_temp->feedback);
        printf("\n----------------------------------------------------------------------------------\n\n");
    }
}
void Stampa_Feedback(punt_libro punt_feed){
    int feed;
    bool flag=false;;
    punt_libro punt_rif;
    //Inserimento feedback da cercare tra i libri
    printf("\n\nInserisci feedback: ");
    scanf("%d",&feed);

    for(punt_rif=punt_feed;punt_rif!=NULL;punt_rif=punt_rif->next){
        //Se c'è occorrenza stampa la corrispondente struttura
        if (punt_rif->feedback==feed){
            printf("\n\tCodice libro: %s\n\n",punt_rif->cod_id);
            printf("\tTitolo: %s\n\n",punt_rif->titolo);
            printf("\tAutore: %s\n\n",punt_rif->autore);
            printf("\tCasa editrice: %s\n\n",punt_rif->casa_editrice);
            printf("\tGenere: %s\n\n",punt_rif->genere);
            printf("\tAnno di pubblicazione: %d\n\n",punt_rif->anno_pubb);
            printf("\tNumero pagine : %d\n\n",punt_rif->lung);
            printf("\tValutazione: %d\n\n",punt_rif->feedback);
            printf("\n----------------------------------------------------------------------------------\n\n");
            //flag==true significa che almeno un libro è stato trovato
            flag=true;
        }
    }
    if (flag==false){
        printf("Non sono stati trovati libri con valutazione: %d",feed);
    }

}
