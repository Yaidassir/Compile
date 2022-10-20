#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void TriBulle(long T[],int n){
    int m=n-1;
    int changement = 1;
        while(changement==1){
            changement=0;
            for(int i=0;i<m;i++){
                if(T[i]>T[i+1]){
                    int temp=0;
                    temp=T[i];
                    T[i]=T[i+1];
                    T[i+1]=temp;
                    changement=1;
                }
            }
            m=m-1;
        }
}

int main(int argc, char const *argv[])
{
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
    t1 = clock();
    TriBulle(tab,n);
    t2 = clock();
    // printf("Le resultat du tableau aprés la permutation \n");

    // for(i=0 ; i<n ; i++){
    //     printf("%ld \n",tab[i]);
    // }
    printf("Le temps d'execution est : %f\n", (float)(t2 -t1)/CLOCKS_PER_SEC);
    
}

  
