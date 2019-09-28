#include <stdio.h>
#include <stdlib.h>
#define NUM 5
int main()
{
    //dichiarazione variabili
    int i,k, *pi,v[NUM]={10,20,30,40,50}, *pv;
    char c, *pc;
    float f, *pf;
    double d, *pd;
    int method;

    //inizializzo i vettori
    pi=&i;
    pv=&v;
    pc=&c;
    pf=&f;
    pd=&d;
    //inserimento valori delle variabili
    printf("Inserisci intero: ");
    scanf("%d",&*pi);
    printf("Inserisci char: ");
    scanf("%s",&*pc);
    printf("Inserisci float: ");
    scanf("%f",&*pf);
    printf("Inserisci double: ");
    scanf("%f",&*pd);

    printf("Inserire 0 se vuoi stampare le variabili con il metodo indiretto (tramite i puntatori) o 1 se vuoi stamparlo con il metodo diretto (accesso diretto alla variabile)\n");
    scanf("%d",&method);
    fflush(stdin);


    if (method==0){
    //stampo accedendo indirettamente alla varibile
    printf("\n");
    /*stampo i valori delle variabili:
    variabile int */
    printf("Intero: %d\n",*pi);
    //vettore
    printf("Vettore: ");
    while (pv<=&v[NUM-1]){
    printf("%d, ",*pv);
    pv+=1;
    }
    printf("\n");
    //variabile char,float,double
    printf("Char: %c\n",*pc);
    printf("Float: %g\n",*pf);
    printf("Double: %g\n",*pd);

    /* stampo indirettamente gli indirizzi delle variabili:
    variabile int */
    printf("Indirizzo variabile intera: %p\n",pi);
    //vettore
    printf("Indirizzo elementi vettore: ");
    while (pv<=(NUM-1)){
    printf("%p",pv);
    }
    printf("\n");
    //variabile char, float,double
    printf("Indirizzo variabile char: %p\n",pc);
    printf("Indirizzo variabile float: %p\n",pf);
    printf("Indirizzo variabile double: %p\n",pd);
    }
    else if (method==1) {
    printf("\n");
    /*stampo accedendo direttamente alla variabile
    variabile int */
    printf("Intero: %d\n",i);
    //vettore
    k=0;
    printf("Vettore: ");
    while (k<=(NUM-1)){
    printf("%d, ",v[k]);
    k+=1;
    }
    printf("\n");
    //variabile char, float, double
    printf("Char: %c\n",c);
    printf("Float: %g\n",f);
    printf("Double: %g\n",d);
    /*stampo con metodo diretto l'indirizzo le variabili:
    variabile int */
    printf("Indirizzo variabile intera: %p\n",&i);
    //vettore
    printf("Indirizzo elementi vettore (0-4): ");
    k=0;
    while (k<=(NUM-1)){
    printf("%p ",&v[k]);
    k++;
    }
    printf("\n");
    //variabile char, float, double
    printf("Indirizzo variabile char: %p\n",&c);
    printf("Indirizzo variabile float: %p\n",&f);
    printf("Indirizzo variabile double: %p\n",&d);
    }
    //se hai inserito un carattere non supportato, allora esci dall'esecuzione
    else{
    printf("Formato di inserimento metodo non supportato\n");
    exit(1);
    }
    return 0;
    }
