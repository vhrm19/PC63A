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

void quickSort(int *vetor, int inicio, int fim){
    int pivo;
    if(inicio < fim){
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}

int particiona(int *vetor, int inicio, int fim){
    int pivo = vetor[inicio];
    int esq = inicio;
    int dir = fim;
    int aux;
    while(dir >= esq){
        while(vetor[esq] <= pivo)
            esq++;
        while(vetor[dir] > pivo)
            dir--;
        if(dir >= esq){
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }

    aux = vetor[dir];
    vetor[dir] = pivo;
    vetor[inicio] = aux;
    return dir;
}

int main()
{
    int N = 10;
    int *vetor = alea(N);
    exibeVetor(vetor, 0, N);
    quickSort(vetor, 0, N-1);
    exibeVetor(vetor, 0, N);
    return 0;
}
