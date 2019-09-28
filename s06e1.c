#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

//the function gives back a pointer
int *search(int *vettore,int dimensione,int elemento){
//variables declare
    int i;
    int *interm;
//i reserve a dynamic memory space where the occurrency indexes will be filled
    if (!(interm=(int*)malloc(dimensione*sizeof(int*)))){
    exit(1);
    }

    for (i=0;i<dimensione;i++){
        // if the occurrency is found fill interm array with the corresponding index
        if (*(vettore+i)==elemento){
        *(interm+i)=i;
        }
        else{
        *(interm+i)=-1;  //else, fill the index -i of the array  with -1
        }
    }
    return(interm);
}

int *search_ordered_array(int *vettore,int dimensione,int elemento){
//variables declare
    int i;
    int *interm_uno;
//i reserve a dynamic memory space where the occurrency indexes will be filled
    if (!(interm_uno=(int*)malloc(dimensione*sizeof(int*)))){
    exit(1);
    }
    i=0;
//the array is ordered, that means that the program must search until the i index of the array is <= the element we want to search
    while (elemento>=*(vettore+i)){
    if (*(vettore+i)==elemento){
        *(interm_uno+i)=i;
        }
        else{
        *(interm_uno+i)=-1;  //else, fill the index -i of the array  with -1
        }
    i++;
    }
    return(interm_uno);
}

int main()
{
    //PART1
    // variables declaration
    int v[MAX];
    int el_uno,i,k;
    int *ptr_vet_uno;

    //insert 10 (MAX) integers to start the array
    i=0;
    printf("Inerisci numeri interi per l'inizializzazione del vettore: ");
    while (i<MAX){
    scanf("%d",&v[i]);
        if (i+1==MAX){
        break;
        }
        else{
        printf("Hai inserito: %d, inserire un altro numero: ",v[i]);
        i++;
        }
    }
    //insert the number to search
    printf("\nInserisci elemento da cercare: ");
    scanf("%d",&el_uno);

    /*I create a function 'search' giving parameters the array v, its number of elements,
    and the integer the user is searching */
    ptr_vet_uno=search(v,MAX,el_uno); //torna v[0] o *v
    printf("Ho trovato: ");
    k=0;
    for (i=0;i<MAX;i++){
        if (ptr_vet_uno[i]!=-1){
        printf("%d ",ptr_vet_uno[i]);
        k++;
        }
    }
    // k==0 means no occurency found
    if (k==0){
    printf("%d (Nessuna corrispondenza)",*ptr_vet_uno);
    }
    else{
    printf("(indice/i del vettore creato)");
    }
    // I get free the dynamic memory (HEAP)
    free(ptr_vet_uno);

    //PART2
    //variables declaration
    int a[MAX]={0,2,5,5,8,9,11,18,19,27};
    int el_due;
    int *ptr_vet_due;

    //insert the number to search
    printf("\n\nInserisci elemento da cercare nel vettore già ordinato: ");
    scanf("%d",&el_due);

    //same as before
    ptr_vet_due=search_ordered_array(a,MAX,el_due);
    printf("Ho trovato: ");
    k=0;
    for (i=0;i<MAX;i++){
        if (ptr_vet_due[i]!=-1){
        printf("%d ",ptr_vet_due[i]);
        k++;
        }
    }
    // k==0 means no occurency found
    if (k==0){
    printf("%d (Nessuna corrispondenza)",*ptr_vet_due);
    }
    else{
    printf("(indice/i del vettore ordinato)");
    }
    // I get free the dynamic memory (HEAP)
    free(ptr_vet_due);

    return 0;
}
