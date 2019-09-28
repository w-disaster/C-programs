#include "Lista_Coll.h"

void Iniz_Lista_coll(Lista_coll **punt_iniz_coll){
    // Inizializzo come vuota la pila
    (*punt_iniz_coll)=NULL;
}
void Crea_lista_coll(Lista_coll **punt_crea){
    //Se non è stato inserito ancora alcun elemento, testa punta a NULL
    Lista_coll *testa=(*punt_crea);
    //paux viene usato per allocare spazio
    Lista_coll *paux;
    int i,k=0,el,num_el_coll;

    printf("\nQuanti numeri vuoi inserire?: ");
    scanf("%d",&num_el_coll);
    //k è una variabile che indica all'utente in che posizione del vettore verrà inserito il numero
    k+=num_el_coll-1;

    for (i=0;i<num_el_coll;i++) {
        //Alloco memoria pari a quella che necessita una struttura di tipo lista_coll
        paux= (Lista_coll*)malloc(sizeof(Lista_coll));
        if (paux==NULL){
            printf("\nMemoria insufficiente per l'allocazione di un'altra struttura\n");
            exit(1);
        }
        printf("\nInserisci intero (posizione: %d) : ",k);
        scanf("%d",&el);
        fflush(stdin);
        paux->num_coll=el;
        //Il nuovo elemento punta alla testa (Se paux è il primo elemento della lista allora punta a NULL)
        paux->next=testa;
        //Sposto la testa
        testa=paux;
        k--;
    }
    //Modifico la testa della lista uguagliandola a paux (ultimo struttura creata)
    (*punt_crea)=paux;

    printf("\n\nNumero/i inserito/i con successo\n\n");
}
void Stampa_Lista_Coll(Lista_coll *punt_stampa){
    int i;
    printf("\n\n----------------------------------------------------------------------------------");
    printf("\n\t\t\t\tLISTA:\n\n");
    for (i=0;punt_stampa!=NULL;punt_stampa=punt_stampa->next,i++){
        printf("%d  ",punt_stampa->num_coll);
    }
    printf("\n\n----------------------------------------------------------------------------------");
}

void Ins_testa_coll(Lista_coll **punt_coda){
    Lista_coll *tmp;
    //Dichiaro un nuovo puntatore a struttura list_coll
    Lista_coll *new_node;
    //Alloco spazio sufficente per contenere una struttura di tipo lista_coll
    new_node=(Lista_coll*)malloc(sizeof(Lista_coll));
    //Controllo che l'allocazione sia terminata con successo
    if (new_node==NULL){
        printf("\nMemoria insufficiente per l'allocazione di un nuovo nodo\n");
        exit(1);
    }

    //Se ho creato il primo elemento in assoluto new_node punterà a NULL, altrimenti punterà alla testa della lista
    new_node->next=*punt_coda;
    //Sposto la testa della lista all'elemento appena creato
    (*punt_coda)=new_node;

    //Insermiento nuovo numero
    printf("\nNumero da inserire in coda: ");
    scanf("%d",&new_node->num_coll);
    fflush(stdin);
    printf("\nNumero inserito con successo\n\n");
}

void Elimina_dalla_coda_coll(Lista_coll **corr){
    Lista_coll *prec,*cur;
    if (*corr!=NULL){
        //Scorri la pila finchè il next è diverso da null.
        //prec prende il puntatore corrente e successivamente incremento quest'ultimo. NB: prec manterrà sempre il nodo precendete del corrente
        for(prec=NULL,cur=*corr;cur->next!=NULL;prec=cur,cur=cur->next){
        }

        //Elimino il nodo corrente con il next==NULL (fine della pila)
        free(cur);
        if (prec!=NULL){
            //Pongo il last dell'elemento precedente a NULL
            prec->next=NULL;
        } else {
            Iniz_Lista_coll(corr);
        }
        printf("\n\nElemento eliminato con successo\n\n");
    }
    else printf("\n\nNon e'\ stato eliminato alcun elemento perche\' la pila e\' vuota\n\n");
}
