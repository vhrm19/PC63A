#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
    int N = fgetc(dados) - '0';
    printf("Numeros ordenados: %i\n", N);
    int num;
    int comparacao = 0;
    int troca = 0;
    int *vetor = (int *) calloc(N, sizeof(int));
    for(int i=0; fscanf(dados, "%i\n", &num) != EOF; i++)
        vetor[i] = num;

    char *nome;
    switch(argv[1][0]){
        case 'q':
            ticks[2] = clock();
            quickSort(vetor, 0, N-1, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome = "_quicksort";
            break;
        case 'b':
            ticks[2] = clock();
            BubbleSort(vetor, N, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome = "_bubblesort";
            break;
        case 'i':
            ticks[2] = clock();
            InsertionSort(vetor, N, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome = "_insertionsort";
            break;
        case 's':
            ticks[2] = clock();
            SelectionSort(vetor, N, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome = "_selectionsort";
            break;
        case 'm':
            ticks[2] = clock();
            MergeSort(vetor, 0, N-1, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome = "_mergesort";
            break;
        case 'h':
            ticks[2] = clock();
            heapSort(vetor, N, &comparacao, &troca);
            ticks[3] = clock();
            printf("Tempo ordenacao %6.3fms\n", (double)(ticks[3] - ticks[2])*1000 / (CLOCKS_PER_SEC));
            nome = "_heapsort";
            break;
        default:
            printf("Opcao de ordenacao invalida!\n");
            break;
    }
    printf("Quantidade de comparacoes: %i\nQuantidade de trocas: %i\n", comparacao, troca);

    char *nome_saida;
    char *nome_extensao = strrchr(argv[2], '.');
    char vetor_temp[strlen(argv[2]) + strlen(nome)];
    if(nome_extensao == NULL){
        strncpy(vetor_temp, argv[2], strlen(argv[2]));
        vetor_temp[strlen(argv[2])] = '\0';
        strcat(vetor_temp, nome);
        printf("%s\n", vetor_temp);
        nome_saida = vetor_temp;
    } else {
    int index = strlen(argv[2]) - strlen(nome_extensao);        
    strncpy(vetor_temp, argv[2], index);
    vetor_temp[index] = '\0';
    strcat(vetor_temp, nome);
    strcat(vetor_temp, argv[2] + index);
    nome_saida = vetor_temp;
    }

    printf("%s\n", nome_saida);
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
