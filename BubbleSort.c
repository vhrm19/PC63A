#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *vetor, int N){
    int aux;
    int check;
    do{
        check = 0;
        for(int i=0; i<N-1; i++)
            if(vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                check = 1;
            }
        N--;
    }while(check == 1);
};

void exibeVetor(int *vetor, int N){
    for(int i=0; i<N; i++){
    printf("%i ", vetor[i]);
    }
    printf("\n");
};

int main()
{
    int N = 10;
    int vetor[10] = {67, 23, 87, 12, 54, 98, 34, 23, 67, 21};
    exibeVetor(vetor, N);
    BubbleSort(vetor, N);
    exibeVetor(vetor, N);
    return 0;
}
