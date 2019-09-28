#include "Lista_Coll.h"


punt_coll Iniz_Lista_coll(){
    // Inizializzo lis alla struttura vuota
    punt_coll lis;
    lis=NULL;
    return lis;
}
punt_coll Crea_lista_coll(int num_el_coll){
    //Testa punterà sempre al primo nodo della lista
    punt_coll testa=NULL;
    //paux viene usato per allocare spazio
    punt_coll paux;
    int i,el;
    for (i=0;i<num_el_coll;i++) {
    //Alloco memoria pari a quella che necessita una struttura di tipo lista_coll
    paux= (punt_coll)malloc(sizeof(struct lista_coll));

    printf("\nInserisci intero da inserire nella posizione %d: ",i);
    scanf("%d",&el);
    fflush(stdin);

    paux->num_coll=el;
    paux->next = testa;
    testa=paux;
    }
    return testa;
}

void Stampa_Lista_Coll(punt_coll punt_stampa){

    printf("\n\n----------------------------------------------------------------------------------");
    printf("\n\t\t\t\tLISTA:\n\n");
    for (;punt_stampa!=NULL;punt_stampa=punt_stampa->next){
        printf("%d ",punt_stampa->num_coll);
    }
    printf("\n\n----------------------------------------------------------------------------------");
}

punt_coll Ins_testa_coll(punt_coll punt_ins_testa){
    punt_coll nuovo_nodo_testa;

    //Alloco spazio sufficente per contenere una struttura di tipo lista_coll
    nuovo_nodo_testa=(punt_coll)malloc(sizeof(struct lista_coll));
    //Controllo che l'allocazione sia terminata con successo
    if (nuovo_nodo_testa==NULL){
        printf("\nMemoria insufficiente per l'allocazione di un nuovo nodo\n");
        return nuovo_nodo_testa;
    }
    //Insermiento nuovo numero
    printf("\nNumero da inserire in testa: ");
    scanf("%d",&nuovo_nodo_testa->num_coll);
    fflush(stdin);

    //Il next del nuovo nodo punta al primo già presente
    nuovo_nodo_testa->next=punt_ins_testa;
    //Sposto la testa al nuovo elemento
    punt_ins_testa=nuovo_nodo_testa;
    //Return il puntatore al primo elemento
    return nuovo_nodo_testa;
}
//Questa volta la funzione è void perchè non deve essere modificato il puntatore alla testa
void Ins_coda_coll(punt_coll punt_ins_coll){
    //Dichiaro un nuovo puntatore a struttura list_coll
    punt_coll nuovo_nodo_coda;
    //Alloco spazio sufficente per contenere una struttura di tipo lista_coll
    nuovo_nodo_coda=(punt_coll)malloc(sizeof(struct lista_coll));
    //Controllo che l'allocazione sia terminata con successo
    if (nuovo_nodo_coda==NULL){
        printf("\nMemoria insufficiente per l'allocazione di un nuovo nodo\n");
        exit(EXIT_FAILURE);
    }
    //Porto il puntatore passato come parametro all'ultimo nodo della lista
    for(;punt_ins_coll->next!=NULL;punt_ins_coll=punt_ins_coll->next){
    }
    //Insermiento nuovo numero
    printf("\nNumero da inserire in coda: ");
    scanf("%d",&nuovo_nodo_coda->num_coll);
    fflush(stdin);

    //Modifico il next del nuovo nodo facendolo puntare a che cosa punta il puntatore dell'ultimo elemento
    nuovo_nodo_coda->next=punt_ins_coll->next;
    //Faccio diventare l'ultimo nodo della lista il penultimo
    punt_ins_coll->next=nuovo_nodo_coda;
}

bool Ins_da_posizione_coll(punt_coll punt_pos_coll){
    int el_pos,el_nuovo;
    punt_coll nuovo_nodo_pos, punt_temp=punt_pos_coll;
    //Inserimento elemento esistente e nuovo elemento
    printf("\nElemento esistente: ");
    scanf("%d",&el_pos);

    //Pongo punt_temp=al puntatore alla testa passato come parametro e scorro tutta la lista finchè il next è !=0
    for(;punt_temp->next!=NULL;punt_temp=punt_temp->next){
        if (punt_temp->num_coll==el_pos){
            //Se è stata trovata corrispondenza alloco il nuovo nodo e controllo se c'è spazio sufficiente
            nuovo_nodo_pos=(punt_coll)malloc(sizeof(struct lista_coll));
            if (nuovo_nodo_pos==NULL){
                printf("\nMemoria insufficiente per l'allocazione di un nuovo nodo\n");
                exit(EXIT_FAILURE);
            }
            //Se ho trovato la corrispondenza faccio inserire il nuovo elemento e lo metto nel nuovo nodo
            printf("\nNuovo elemento: ");
            scanf("%d",&el_nuovo);
            nuovo_nodo_pos->num_coll=el_nuovo;

            //Il next del nuovo nodo lo faccio puntare al next del nodo in cui ho trovato corrispondenza
            nuovo_nodo_pos->next=punt_temp->next;
            //Il next del nodo in cui ho trovato corrispondenza lo faccio puntare al nuovo nodo
            punt_temp->next=nuovo_nodo_pos;

            return true;
        }
    }
    return false;
}
punt_coll Elimina_dalla_testa_coll(punt_coll elimina_testa_coll){
    punt_coll punt_temp;

    punt_temp=elimina_testa_coll;
    elimina_testa_coll=elimina_testa_coll->next;

    free(punt_temp);
    printf("\nElemento eliminato con successo\n\n");
    return (elimina_testa_coll);
}
void Elimina_dalla_coda_coll(punt_coll corr){
    punt_coll prec;
    //Scorri la lista finchè il next è diverso da null.
    //prec prende il puntatore corrente e successivamente incremento quest'ultimo. NB: prec manterrà sempre il nodo precendete del corrente
    for(prec=NULL;corr->next!=NULL;prec=corr,corr=corr->next){
    }
    //Elimino il nodo corrente con il next==NULL (fine della lista)
    free(corr);
    //Pongo il last dell'elemento precedente a NULL
    prec->next=NULL;
}
punt_coll Elimina_prima_occorrenza_coll(punt_coll punt_elimina_occ_coll){
    int el;
    punt_coll prec,corr;

    printf("\nInserisci numero da eliminare: ");
    scanf("%d",&el);
    fflush(stdin);

    corr=punt_elimina_occ_coll;
    //Scorri la lista finchè il next è diverso da NULL ED il numero è diverso dall'elemento inserito
    for(prec=NULL;corr->next!=NULL&&corr->num_coll!=el;prec=corr,corr=corr->next){
    };

    //Se prec==NULL vuol dire che è stata trovata la corrispondenza al numero della prima struttura
    if (prec==NULL){
        punt_elimina_occ_coll=punt_elimina_occ_coll->next;

    }
    else if(corr->next==NULL){
        //Se corr->next==NULL l'elemento non è stato trovato (è stata raggiunta la fine della lista)
        printf("\nL'elemento non e\' presente nella lista\n\n");
        return punt_elimina_occ_coll;
    }
    else{
        //Altrimenti è stata trovata corrispondenza nella coda
        prec->next=corr->next;
    }
    printf("\nL'elemento e\' stato eliminato con successo\n\n");
    //Elimina corr
    free(corr);
    //Ritorna il puntatore alla testa
    return (punt_elimina_occ_coll);

}


