#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (){

    long n=0;
    clock_t t1,t2;
    printf("donner le nombre de valuers  ");
    scanf("%ld",&n);
    long i=0;
    long tab[n];
    /* intialisation du tableau */
    for(i=0 ;i<n ;i++){ 


        tab[i]= rand() % n;

    }
    i=0;
    // for ( i = 0; i < n; i++)
    // {
        
    //     printf("%ld \n",tab[i]);
    // }

    
    i=0;
    long inter=0;
    t1 = clock();
    while(i<n-1){
        if(tab[i]>tab[i+1]){
            inter=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=inter;
            i=0;
        }
        else{
            i++;
        }

    }
    t2 = clock();
    // printf("le tableau résultat est \n");
    //   for ( i = 0; i < n; i++)
    // {
        
    //     printf("%ld \n",tab[i]);
    // }
    printf("Le temps d'execution est : %f\n", (float)(t2 -t1)/CLOCKS_PER_SEC);



    return  0;
}