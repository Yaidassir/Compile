#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int cle(double x, double i){

   return (int) (x/pow(10.0,i))%10;

}

void TriAux(int T[],int n,int i){
int m=n-1;
    int changement = 1;
        while(changement==1){
            changement=0;
            for(int j=0;j<m;j++){
                if(cle(T[j],i)>cle(T[j+1],i)){
                    int temp=0;
                    temp=T[j];
                    T[j]=T[j+1];
                    T[j+1]=temp;
                    changement=1;
                }
            }
            m=m-1;
        }
}

void TriBase(int T[],int n,int k){
    for(int j=0;j<k;j++){
        TriAux(T,n,j);
    }
}


int main(int argc, char const *argv[])
{
    int i;
    int n=0;
    int k;
    clock_t t1,t2;
    printf("donner le nombre de valeurs  ");
    scanf("%d",&n);
    int j=0;
    int tab[n];
    
    printf("Donnez l'entier k pour définir l'intervalle des valeur allant de 0 à (10**k)-1 :");
    scanf("%d",&k);
    /* intialisation du tableau */
    for(j=0 ;j<n ;j++){ 
        tab[j]= rand() % (int)pow(10.0,k);
    }
    /* affichage du tableau avant traitement */
    // j=0;
    // for ( j = 0; j < n; j++)
    // {
    //     printf("%d \n",tab[j]);
    // }
    t1 = clock();
    TriBase(tab,n,k);
    t2 = clock();
    /* affichage du tableau aprés traitement */
 
    // printf("Le resultat du tableau aprés la permutation \n");

    // for(i=0 ; i<n ; i++){
    //     printf("%d \n",tab[i]);
    // }
    printf("Le temps d'execution est : %f\n", (float)(t2 -t1)/CLOCKS_PER_SEC);

    
}