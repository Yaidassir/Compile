#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


  
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}


void heapify(int arr[], int n, int i) {                                                           
    int max = i;                                                                              
    int leftChild = 2 * i + 1;                                                                
    int rightChild = 2 * i + 2;                                                               
  
    if (leftChild < n && arr[leftChild] > arr[max])                                           
      max = leftChild;                                                                        
  
    if (rightChild < n && arr[rightChild] > arr[max])                                         
      max = rightChild;                                                                       
      

  
    if (max != i) {
      swap(&arr[i], &arr[max]);
      heapify(arr, n, max);
    }
  }
 

  void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
  }
  

  
  int main(int argc, char const *argv[]) {           
    int val;
    int n;
    clock_t t1,t2;
    

    int i;
    int k;
    printf("donner le nombre de valuers  ");
    scanf("%d",&n);
    int j=0;
    int arr[n];
    
    /* intialisation du tableau */
    for(j=0 ;j<n ;j++){ 
        arr[j]= rand() % n;
    }
    /* affichage du tableau avant traitement */
    // j=0;
    // for ( j = 0; j < n; j++)
    // {
    //     printf("%d \n",arr[j]);
    // }
	
  //  printf("Original array:\n");                                                 
  //   display(arr, n);                                                                                                                           
    t1 = clock();
    heapSort(arr, n);      
    t2 = clock();

  
    // printf("Sorted array:\n");                                                   
    // display(arr, n);


  printf("Le temps d'execution est : %f\n", (float)(t2 -t1)/CLOCKS_PER_SEC);
  return 0;                                                          
  }