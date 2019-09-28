#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_int= 543;
    float num_float = 9.4;
    double num_double= 2.6293;
    char let= 'Y';

    //addizione
    printf("\t\t Addizione \n\n");
    printf("int= %d, float= %g, (int + float)= %g\n\n -------------------------------------------------------------\n",num_int,num_float, num_int+num_float);
    //sottrazione
    printf("\t\t Sottrazione \n\n");
    printf("int= %d, double= %g,(int - double)= %g\n\n -------------------------------------------------------------\n",num_int, num_double, num_int-num_double);
    //moltiplicazione
    printf("\t\t Moltiplicazione \n\n");
    printf("double= %g, float= %g,(double x float)= %g\n\n -------------------------------------------------------------\n",num_double, num_float, num_double*num_float);
    //divisione
    printf("\t\t Divisione \n\n");
    printf("double= %g, int= %d,(double/int)= %g\n\n -------------------------------------------------------------\n", num_double, num_int, (num_double/num_int));
    //resto divisione
    printf("\t\t Resto divisione \n\n");
    printf("resto intero/intero= %d \n\n -------------------------------------------------------------\n", (num_int%num_int) );
    //assegnazione valore ad una variabile
    printf("\t\t Var=val \n\n");
    printf("intero=%d\n\n ---------------------------------------------------------------\n", num_int=500);

    // incremento e restituzione valore variabile
    printf("\t\t Incremento (++intero) \n\n");
    printf("intero= %d ", num_int);
    printf("++intero= %d\n\n", ++num_int);
    // restituzione valore ed incremento variabile
    printf("\t\t Incremento (intero++) \n\n");
    printf("intero= %d ", num_int);
    printf("intero++= %d ", num_int++);
    printf("intero (dopo++)= %d\n\n ----------------------------------------------------------------\n", num_int);


    // decremento e restituzione valore variabile
    printf("\t\t Decremento (--intero) \n\n");
    printf("intero= %d ", num_int);
    printf("--intero= %d\n\n", --num_int);
    // restituzione valore e decremento variabile
    printf("\t\t Decremento (intero++) \n\n");
    printf("intero= %d ", num_int);
    printf("intero--= %d ", num_int--);
    printf("intero (dopo--)= %d\n\n ---------------------------------------------------------------\n ", num_int);

    // +op, -op
    printf("\t\t +float, -float \n\n");
    printf("intero= %g, +float= %g\n\n", num_float, +num_float);
    printf("intero= %g, -float= %g\n\n ---------------------------------------------------------------\n", num_float, -num_float);

    // op= op[]op1
    printf("\t\t (op+=op1) \n\n");
    printf("double= %g, ", num_double);
    printf("char= %d, ", let);
    printf("double+=char= %g\n\n ---------------------------------------------------------------\n", num_double+=let);

    printf("\t\t (op-=op1) \n\n");
    printf("char= %d,", let);
    printf("float= %g, ", num_float);
    printf("float-=char= %g\n\n ---------------------------------------------------------------\n", num_float-=let);

    printf("\t\t (op*=op1) \n\n");
    printf("intero %d,", num_int);
    printf("float= %g, ", num_float);
    printf("float*=char= %g\n\n ---------------------------------------------------------------\n", num_float*=let);

    printf("\t\t (op/=op1) \n\n");
    printf("double= %f, ", num_double);
    printf("char= %d,", let);
    printf("double/=char= %g\n\n ---------------------------------------------------------------\n", num_double/=let);

    printf("\t\t (op%=op1) \n\n");
    printf("intero= %d, ", num_int);
    printf("intero%=intero=  %d\n\n ---------------------------------------------------------------\n", num_int%=num_int);


    return 0;
}
