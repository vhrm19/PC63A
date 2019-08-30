#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int *alea(int N){
    int *vetor = (int *) malloc(N*sizeof(int));
    srand(time(NULL));
    for(int i=0; i<N; i++)
        vetor[i] = rand()%N;
    return vetor;
}

void exibeVetor(int *vetor, int inicio, int fim){
    for(int i=inicio; i<fim; i++){
    printf("%i ", vetor[i]);
    }
    printf("\n");
}

void heapSort(int *vetor, int N){
    int aux;
    for(int i = (N-1)/2; i >= 0; i--)
        maxHeap(vetor, i, N-1);

    for(int i = N-1; i >= 1; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        maxHeap(vetor, 0, i - 1);
    }
}

void maxHeap(int *vetor, int raiz, int N){
    int aux = vetor[raiz];
    int esquerda = raiz*2 + 1;
    while(esquerda <= N){
        if(esquerda == N);
        else if(vetor[esquerda+1] > vetor[esquerda])
            esquerda++;
        if(aux < vetor[esquerda]){
            vetor[raiz] = vetor[esquerda];
            raiz = esquerda;
            esquerda = raiz*2 + 1;
        }
        else esquerda = N + 1;
    }
    vetor[raiz] = aux;
}

int main()
{
    int N = 10;
    int *vetor = alea(N);
    exibeVetor(vetor, 0, N);
    heapSort(vetor, N);
    exibeVetor(vetor, 0, N);
    return 0;
}
