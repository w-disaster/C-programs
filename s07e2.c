#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
    //Variables declare
    int max, *prime, dim;
    int i,k,j;
    int flag;
    dim=5;
    //Insert the range on which you want to calculate the prime numbers
    printf("Insert the max number on which you want to calculate the prime numbers: ");
    scanf("%d",&max);
    fflush(stdin);
    printf("\n");
    //I allocate a memory of space of 50 integers into the array prime
    prime=(int*)malloc(dim*sizeof(int));
    //If prime is null there isn't enough memory space, then exit the program execution
    if (prime==NULL){
        printf("There isn't enough memory space");
        exit(1);
    }


    printf("The prime numbers between 0 and %d are: \n\n",max);
    i=1;
    j=0;
    while (i<=max){
    //flag=1 means that i is not set as a prime number
        flag=1;

        for (k=2;k<=i/2;k++){
        //If there's rest between the division of i and k, i is not a prime number
            if (i%k==0){
                flag=0;
                break;
            }
        }
        //If flag==1 there's rest then i is a prime number
        if (flag==1){
            //If j==50 the array finished the space then i reallocate a memory space equal to an integer to expand the array
            if (j>=dim){
                dim=dim*2;
                prime=(int*)realloc(prime,dim*sizeof(int));
                //Same as the beginning of the program
                if (prime==NULL){
                    printf("\nThere isn't enough memory space");
                    exit(1);
                }
            }
            prime[j]=i;
            printf("%d ",prime[j]);
            //After 25 prime numbers printed go to the next line
            if (j%25==0&&i!=1){
                printf("\n");
            }
            j++;
        }
    i++;
    }
    printf("\n");
    //Free the dynamic memory (array)
    free (prime);
    return 0;
}


