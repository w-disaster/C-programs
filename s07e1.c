#include <stdio.h>
#include <stdlib.h>
//dichiaro una variabile globale
unsigned int x;
unsigned int fattoriale(unsigned int el){
    unsigned int i,temp,risultato;
    if (el==1){
    printf("1");
    /* Se il numero che hai inserito è <=1 allora ritorna 1 altrimenti se la funzione fattoriale
    ha moltiplicato el fino a el==1 ritorna 1 */
    return (1);
    }
    printf("%d*",el);
    //fattoriale richiama se stessa decrementando el finchè ==1
    risultato=(fattoriale(el-1)*el);


    if (el==x){
        //vedi printf()
        printf("\n\nFinche\' el>1 il return si blocca alla chiamata della funzione fattoriale passandogli el-1. Quando el==1 la funzione fattoriale tornera\' 1, e la chiamata della funzione precedente assumera\' valore (el-n)*1.\nLa funzione ricorsiva procedera\' così via a ritroso moltiplicandosi con tutti gli el decrementati fino a che si blocchera\' alla prima chiamata a funzione\ndove l'el originale(inserito precedentemente da tastiera) verra\' moltiplicato con tutte le moltiplicazioni precedenti.\n\n");
        i=2;
        temp=1;
        /*quando el ==1 la funzione procederà a ritroso delle sue chiamate perciò aumenterà el (++el)
        moltiplicandosi con quelli precedenti*/
        while (i<=el){
        printf("%d*%d= ",i,temp);
        temp=temp*i;
        printf("%d\n",temp);
        i++;
        }
    }

    return (risultato);
}

int main()
{
    //dichiarazione variabile
    unsigned int ris;
    printf("inserisci il numero di cui voi calcolarne il fattoriale (numero max per unsigned char: 16)\n");
    scanf("%d",&x);
    //controllo l'input (se sfora il range degli unsigned int o se <0)
    while (x>15||x<=0){
        printf("Numero troppo grande o <=0, reinserire: ");
        scanf("%d",&x);
        fflush(stdin);
    }
    printf("\nIl numero che hai inserito e\': %d\n",x);
    printf("Il fattoriale di %d corrisponde ai seguenti calcoli: ",x);
    //funzione fattoriale
    ris=fattoriale(x);
    //stampo il fattoriale
    printf("\nIl fattoriale di %d e\'= %d",x,ris);

    return 0;
}
