#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *alea(int N){
    int *vetor = (int *) malloc(N*sizeof(int));
    srand(time(NULL));
    for(int i=0; i<N; i++)
        vetor[i] = rand()%N;
    return vetor;
}

void exibeVetor(int *vetor, int N){
    for(int i=0; i<N; i++){
    printf("%i ", vetor[i]);
    }
    printf("\n");
};

void InsertionSort(int *vetor, int N){
    int aux, j;
    for(int i=1; i<N; i++){
        aux = vetor[i];
        for(j=i-1; aux < vetor[j] && j >= 0; j--){
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = aux;
    }
};

int main()
{
    int N = 10;
    int *vetor = alea(N);
    exibeVetor(vetor, N);
    InsertionSort(vetor, N);
    exibeVetor(vetor, N);
    return 0;
}
