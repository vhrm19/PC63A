#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ordenador.h"

int main(int argc, char **argv){
    if(argc != 3){
        printf("Número errado de parametros!\n");
        return 1;
    }
    clock_t ticks[4];
    ticks[0] = clock();
    FILE *dados = fopen(argv[2], "r+");
    if(dados == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 0;
    }
    char *nome_saida;
    int N = fgetc(dados) - '0';
    printf("Numeros ordenados: %i\n", N);
    char test = argv[1][0];
    int num;
    int comparacao = 0;
    int troca = 0;
    int *vetor = (int *) calloc(N, sizeof(int));
    for(int i=0; fscanf(dados, "%i\n", &num) != EOF; i++){
        vetor[i] = num;
    };
    switch(test){
        case 'q':
            ticks[2] = clock();
            quickSort(vetor, 0, N-1, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_quicksort.txt";
            break;
        case 'b':
            ticks[2] = clock();
            BubbleSort(vetor, N, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_bubblesort.txt";
            break;
        case 'i':
            ticks[2] = clock();
            InsertionSort(vetor, N, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_insertionsort.txt";
            break;
        case 's':
            ticks[2] = clock();
            SelectionSort(vetor, N, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_selectionsort.txt";
            break;
        case 'm':
            ticks[2] = clock();
            MergeSort(vetor, 0, N-1, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_mergesort.txt";
            break;
        case 'h':
            ticks[2] = clock();
            heapSort(vetor, N, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome_saida = "dados_heapsort.txt";
            break;
        default:
            printf("Opcao de ordenacao invalida!\n");
            break;
    }
    printf("Quantidade de comparacoes: %i\nQuantidade de trocas: %i\n", comparacao, troca);
    FILE *saida = fopen(nome_saida, "w");
    if(saida == NULL){
        printf("Erro ao abrir o arquivo de saida!\n");
        return 0;
    }
    for(int i=0; i < N; i++)
        fprintf(saida, "%i\n", vetor[i]);
        
    if(fclose(dados) == EOF){
        printf("Erro ao fechar arquivo de dados!");
        return 0;
    }
    if(fclose(saida) == EOF){
        printf("Erro ao fechar arquivo de saida!");
        return 0;
    }
    printf("Arquivo %s gerado com sucesso!\n", nome_saida);
    ticks[1] = clock();
    printf("Tempo total %6.3lfms\n", (double)(ticks[1] - ticks[0])*1000 / (CLOCKS_PER_SEC));
    return 0;
}
