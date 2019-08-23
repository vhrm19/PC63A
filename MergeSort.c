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

void exibeVetor(int *vetor, int N){
    for(int i=0; i<N; i++){
    printf("%i ", vetor[i]);
    }
    printf("\n");
}

void MergeSort(int *vetor, int inicio, int fim){
    int meio = floor((inicio+fim)/2);
    if(inicio < fim){
        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim){
    int *vetor_aux = (int *) calloc(fim-inicio+1, sizeof(int));
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    while(i <= meio && j <= fim){
        if(vetor[i] < vetor[j]){
            vetor_aux[k] = vetor[i];
            i++;
        }
        else{
            vetor_aux[k] = vetor[j];
            j++;
        }
        k++;
    }
    if(i > meio){
        while(j <= fim){
            vetor_aux[k] = vetor[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= meio){
            vetor_aux[k] = vetor[i];
            i++;
            k++;
        }
    }
    for(int l = inicio, k = 0; l <= fim; l++, k++){
        vetor[l] = vetor_aux[k];
    }
    free(vetor_aux);
    vetor_aux = NULL;
}

int main()
{
    int N = 10;
    int *vetor = alea(N);
    exibeVetor(vetor, N);
    MergeSort(vetor, 0, N-1);
    exibeVetor(vetor, N);
    return 0;
}
