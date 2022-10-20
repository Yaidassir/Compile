#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void tri_rapide (int *tab, int size) {
    int borne, Current, pv, tmp;
    if (size < 2) return;
    // On prend comme pv l element le plus a droite
    pv = tab[size - 1];
    borne  = Current = 0;
    while (Current<size) {
        if (tab[Current] <= pv) {
            if (borne != Current) {
                tmp=tab[Current];
                tab[Current]=tab[borne];
                tab[borne]=tmp;              
            }
            borne ++;
        }
        Current ++;
    }
    tri_rapide(tab, borne - 1);
    tri_rapide(tab + borne - 1, size - borne + 1);
}

int main (){

    int  n=0;
    clock_t t1,t2;
    printf("donner le nombre de valeurs  ");
    scanf("%d",&n);
    int i=0;
    int tab[n];
    /* intialisation du tab */
    for(i=0 ;i<n ;i++){ 


        tab[i]= rand() % n;

    }
    i=0;
    // for ( i = 0; i < n; i++)
    // {
        
    //     printf("%d \n",tab[i]);
    // }
    t1 = clock();
    tri_rapide(tab,n);
    t2 = clock();

    //   printf("le tab résultat est \n");
    //   for ( i = 0; i < n; i++)
    // {
        
    //     printf("%d \n",tab[i]);
    // }
    printf("Le temps d'execution est : %f\n", (float)(t2 -t1)/CLOCKS_PER_SEC);


}