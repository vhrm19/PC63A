#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenador.h"

int main(int argc, char **argv){
    clock_t ticks[4];
    ticks[0] = clock();
    FILE *dados = fopen("dados.txt", "r+");
    char *nome_saida;
    int N = fgetc(dados) - '0';
    printf("Numeros ordenados: %i\n", N);
    char test = 'm';
    int num;
    double tempo_total, tempo_ordenacao;
    int *vetor = (int *) malloc(N * sizeof(int));
    for(int i=0; fscanf(dados, "%i\n", &num) != EOF; i++){
        vetor[i] = num;
    };
    switch(test){
        case 'q':
            ticks[2] = clock();
            quickSort(vetor, 0, N-1);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_quicksort.txt";
            break;
        case 'b':
            ticks[2] = clock();
            BubbleSort(vetor, N);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_bubblesort.txt";
            break;
        case 'i':
            ticks[2] = clock();
            InsertionSort(vetor, N);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_insertionsort.txt";
            break;
        case 's':
            ticks[2] = clock();
            SelectionSort(vetor, N);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_selectionsort.txt";
            break;
        case 'm':
            ticks[2] = clock();
            MergeSort(vetor, 0, N-1);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_mergesort.txt";
            break;
        case 'h':
            ticks[2] = clock();
            heapSort(vetor, N);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_heapsort.txt";
            break;
        default:
            printf("Opcao de ordenacao invalida!\n");
            break;
    }
    FILE *saida = fopen(nome_saida, "w");
    for(int i=0; i < N; i++)
        fprintf(saida, "%i\n", vetor[i]);
    fclose(dados);
    fclose(saida);
    printf("Arquivo %s gerado com sucesso!\n", nome_saida);
    ticks[1] = clock();
    printf("Tempo total %6.3lfms\n", (double)(ticks[1] - ticks[0])*1000 / (CLOCKS_PER_SEC));
    return 0;
}
