#include "Lista_Din.h"
#define RADD 4
//FUNZIONI LISTA DINAMICA
void Inizializz_Lista_Dinamica(Lista_dinamica **punt_iniz){
(*punt_iniz)->num_din=NULL;
(*punt_iniz)->last_din=-1;
(*punt_iniz)->size_din=NULL;
}
void Crea_lista_dinamica(Lista_dinamica **punt_crea,int num_el_din){
    (*punt_crea)->last_din=-1;
    //Alloco spazio pari al numero di elementi che vuole inserire l'utente
    if (num_el_din>10){
        (*punt_crea)->num_din=(tipoel*)malloc(20*sizeof(tipoel));
    }
    else{
        (*punt_crea)->num_din=(tipoel*)malloc(10*sizeof(tipoel));
    }
    //Controllo che l'allocazione sia terminata con successo
    if ((*punt_crea)->num_din==NULL){
        printf("Spazio insufficiente per l'allocazione di %d elementi\n",num_el_din);
    }
    else {
        if (num_el_din>10)
            (*punt_crea)->size_din=20;
        else
            (*punt_crea)->size_din=10;
    }
    Stampa_lista_dinamica(*punt_crea);
}

void Inserimento_lista_din(Lista_dinamica **punt_ins){
    int el,tempo;
    int n_el;
    printf("\nQuanti numeri vuoi inserire?: ");
    scanf("%d",&n_el);
    fflush(stdin);
    while (n_el<1){
        printf("\nNumero troppo piccolo, reinserire: ");
        scanf("%d",&n_el);
        fflush(stdin);
    }
    //Funzione che alloca la lista in memoria se l'utente non ha inserito alcun numero (last==-1)
    if ((*punt_ins)->last_din==-1){
        Crea_lista_dinamica(punt_ins,n_el);
    }
    if ((*punt_ins)->last_din+n_el>=(*punt_ins)->size_din){
        if (Raddoppio_din(punt_ins)!=true){
            printf("Spazio in memoria insufficiente per l'allocazione di altri %d numeri",n_el);
            exit(1);
        }
    }
    /*Ho scelto di usare come contatore l'intero last della lista dinamica e un intero "fine" che passerà il numero di elementi che si vuole inserire.
    La funzione è così riutilizzabile per l'inserimento quando il vettore num_din sarà reallocato.
    Perchè ho usato "fine" invece che size? Alla prima chiamata di questa funzione, "fine" è uguale a size, ma alla seconda (quando si vuole espandere il vettore)
    size raddoppia di dimensione e l'utente può non voler aggiungere tutta la seconda metà del vettore, ecco perchè ho bisogno di una variabile d'appoggio. . */
    (*punt_ins)->last_din++;
    tempo=(*punt_ins)->last_din+n_el;
    for (;(*punt_ins)->last_din<tempo;(*punt_ins)->last_din++){
        //Inserimento nuovo elemento
        printf("\nInserisci intero da inserire nella posizione %d: ",(*punt_ins)->last_din);
        scanf("%d",&el);
        fflush(stdin);
        (*punt_ins)->num_din[(*punt_ins)->last_din]=el;
    }
    (*punt_ins)->last_din--;
    printf("\n\nElemento/i inserito/i con successo\n\n");
}

bool Raddoppio_din(Lista_dinamica **punt_real){
    tipoel *punt_radd;
    punt_radd=realloc((*punt_real)->num_din,((*punt_real)->size_din*2*sizeof(tipoel)));
    //Se la reallocazione è terminata con successo: espandi size, il vettore num e return true. Return false altrimenti
    if (punt_radd!=NULL){
        (*punt_real)->size_din*=2;
        (*punt_real)->num_din=punt_radd;
        return true;
    }else return false;
}

void Ins_coda_din(Lista_dinamica **punt_coda){
    int el_ins_coda;
    // Inserimento elemento
    printf("\nElemento da inserire in coda: ");
    scanf("%d",&el_ins_coda);
    fflush(stdin);
    if ((*punt_coda)->last_din==-1){
        Crea_lista_dinamica(punt_coda,1);
    }
    //Controllo che non sia esaurito lo spazio nel vettore. Se si raddoppio le dimensioni
    if ((*punt_coda)->last_din+1>(*punt_coda)->size_din){
        if (Raddoppio_din(punt_coda)!=true){
            printf("Spazio in memoria insufficiente per l'allocazione di un altro numero");
            exit(1);
        }
    }

    //Inserisco l'elemento nel last incrementato
    (*punt_coda)->last_din++;
    (*punt_coda)->num_din[(*punt_coda)->last_din]=el_ins_coda;
    printf("\nElemento inserito con successo\n");
}

void Elimina_dalla_coda_din(Lista_dinamica **punt_elimina){
    // Prendo il vettore alla posizione last-1 (corrispondente all'ultimo elemento) e lo pongo a NULL
    (*punt_elimina)->num_din[(*punt_elimina)->last_din]=0;
    // Decremento il last
    (*punt_elimina)->last_din--;
    printf("\nElemento eliminato con successo\n");
}

void Stampa_lista_dinamica(Lista_dinamica *lista_dinamica){
    printf("\n\n----------------------------------------------------------------------------------");
    printf("\n\t\t\t\tLISTA:\n\n");
    printf("\tVettore: ");
    for (int i=0;i<=lista_dinamica->last_din;i++){
        printf("%d) %d\t",i,lista_dinamica->num_din[i]);
    }
    printf("\n\tLast: %d",lista_dinamica->last_din);
    printf("\n\tDimensione: %d\n",lista_dinamica->size_din);
    printf("\n\n----------------------------------------------------------------------------------");
}

