/**
 * @file Ordenador.h
 * @author Victor Hugo Rodrigues Machado
 * @date 04 Sep 2019
 * @brief Implementacao dos métodos de ordenacao
 * Implementa os metodos de ordenacao vistos na disciplina
 * pesquisa e classificacao de dados.
 */ 

#ifndef ORDENADOR_H_INCLUDED
#define ORDENADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Ordena o vetor usando BubbleSort
 *
 * \param vetor vetor a ser ordenado
 * \param N tamanho do vetor
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Ordena o vetor usando o método Bubble Sort
 * Esse algorimo tem um comportamento assintótico O (N²)
 */

void BubbleSort(int *vetor, int N, int *comparacao, int *troca){
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
                (*troca)++;
            }
            (*comparacao)++;;
        N--;
    }while(check == 1);
};

/**
 * \brief Ordena o vetor usando HeapSort
 *
 * \param vetor vetor a ser ordenado
 * \param N tamanho do vetor
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Ordena o vetor usando o método Heap Sort
 * Esse algorimo tem um comportamento assintótico O (N*log(N))
 */

void heapSort(int *vetor, int N, int *comparacao, int *troca){
    int aux;
    for(int i = (N-1)/2; i >= 0; i--)
        maxHeap(vetor, i, N-1, comparacao, troca);

    for(int i = N-1; i >= 1; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        maxHeap(vetor, 0, i - 1, comparacao, troca);
        (*troca)++;
    }
}

/**
 * \brief Funcao auxiliar para ordenar o vetor como um heap maximo
 *
 * \param vetor vetor a ser ordenado
 * \param raiz indice do elemento pai
 * \param N tamanho do vetor
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Organiza o vetor como um heap maximo para que possa ser realizado um Heap Sort
 */

void maxHeap(int *vetor, int raiz, int N, int *comparacao, int *troca){
    int aux = vetor[raiz];
    int esquerda = raiz*2 + 1;
    while(esquerda <= N){
        (*comparacao)++;;
        if(esquerda == N);
        else if(vetor[esquerda+1] > vetor[esquerda]){
            esquerda++;
        }
        if(aux < vetor[esquerda]){
            vetor[raiz] = vetor[esquerda];
            raiz = esquerda;
            esquerda = raiz*2 + 1;
        }
        else esquerda = N + 1;
    }
    (*troca)++;
    vetor[raiz] = aux;
}

/**
 * \brief Ordena o vetor usando InsertionSort
 *
 * \param vetor vetor a ser ordenado
 * \param N tamanho do vetor
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Ordena o vetor usando o método Insertion Sort
 * Esse algorimo tem um comportamento assintótico O (N²)
 */

void InsertionSort(int *vetor, int N, int *comparacao, int *troca){
    int aux, j;
    for(int i=1; i<N; i++){
        aux = vetor[i];
        for(j=i-1; aux < vetor[j] && j >= 0; j--){
            vetor[j+1] = vetor[j];
            (*troca)++;
        }
        vetor[j+1] = aux;
        (*comparacao)++;;
    }
};

/**
 * \brief Ordena o vetor usando MergeSort
 *
 * \param vetor vetor a ser ordenado
 * \param inicio posicao a qual o vetor utilizado comeca
 * \param fim posicao a qual o vetor utilizado acaba
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Ordena o vetor usando o método Merge Sort
 * Esse algorimo tem um comportamento assintótico O (N*log(N))
 */

void MergeSort(int *vetor, int inicio, int fim, int *comparacao, int *troca){
    int meio = floor((inicio+fim)/2);
    if(inicio < fim){
        MergeSort(vetor, inicio, meio, comparacao, troca);
        MergeSort(vetor, meio+1, fim, comparacao, troca);
        merge(vetor, inicio, meio, fim, comparacao, troca);
    }
}

/**
 * \brief Funcao auxiliar para a funcao MergeSort
 *
 * \param vetor vetor a ser ordenado
 * \param inicio posicao a qual o vetor utilizado comeca
 * \param fim posicao a qual o vetor utilizado acaba
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Utiliza um vetor auxiliar para poder armazenar os
 * dados a serem organizados por intercalacao
 */

void merge(int *vetor, int inicio, int meio, int fim, int *comparacao, int *troca){
    int *vetor_aux = (int *) calloc(fim-inicio+1, sizeof(int));
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    while(i <= meio && j <= fim){
        if(vetor[i] < vetor[j]){
            vetor_aux[k] = vetor[i];
            i++;
            (*comparacao)++;
        }
        else{
            vetor_aux[k] = vetor[j];
            j++;
            (*comparacao)++;;
        }
        k++;
    }
    if(i > meio){
        while(j <= fim){
            vetor_aux[k] = vetor[j];
            j++;
            k++;
            (*comparacao)++;;
        }
    }
    else{
        while(i <= meio){
            vetor_aux[k] = vetor[i];
            i++;
            k++;
            (*comparacao)++;;
        }
    }
    for(int l = inicio, k = 0; l <= fim; l++, k++){
        vetor[l] = vetor_aux[k];
        (*troca)++;
    }
    free(vetor_aux);
    vetor_aux = NULL;
}

/**
 * \brief Ordena o vetor usando QuickSort
 *
 * \param vetor vetor a ser ordenado
 * \param inicio posicao a qual o vetor utilizado comeca
 * \param fim posicao a qual o vetor utilizado acaba
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Ordena o vetor usando o método Quick Sort
 * Esse algorimo tem um comportamento assintótico O (N*log(N))
 */

void quickSort(int *vetor, int inicio, int fim, int *comparacao, int *troca){
    int pivo;
    if(inicio < fim){
        pivo = particiona(vetor, inicio, fim, comparacao, troca);
        quickSort(vetor, inicio, pivo-1, comparacao, troca);
        quickSort(vetor, pivo+1, fim, comparacao, troca);
    }
}

/**
 * \brief Funcao auxiliar para a funcao quickSort
 *
 * \param vetor vetor a ser ordenado
 * \param inicio posicao a qual o vetor utilizado comeca
 * \param fim posicao a qual o vetor utilizado acaba
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Organiza os dados a partir de um pivo pre definido
 */

int particiona(int *vetor, int inicio, int fim, int *comparacao, int *troca){
    int pivo = vetor[inicio];
    int esq = inicio;
    int dir = fim;
    int aux;
    while(dir >= esq){
        while(vetor[esq] <= pivo){
            esq++;
            (*comparacao)++;;
        }
        while(vetor[dir] > pivo){
            dir--;
            (*comparacao)++;;
        }
        if(dir >= esq){
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
            (*troca)++;
        }
    }

    aux = vetor[dir];
    vetor[dir] = pivo;
    vetor[inicio] = aux;
    (*troca)++;
    return dir;
}

/**
 * \brief Ordena o vetor usando SelectionSort
 *
 * \param vetor vetor a ser ordenado
 * \param N tamanho do vetor
 * \param comparacao contador de comparacoes feitas pelo algoritmo
 * \param troca contador de trocas feitas pelo algoritmo
 *
 * Ordena o vetor usando o método Selection Sort
 * Esse algorimo tem um comportamento assintótico O (N²)
 */

void SelectionSort(int *vetor, int N, int *comparacao, int *troca){
        int aux;
        int pos = 0;

        for(int j=0; j<N; j++){
            pos = j;
            for(int i=j+1; i<N; i++)
                if(vetor[i] < vetor[pos])
                    pos = i;

            if(j != pos){
                aux = vetor[j];
                vetor[j] = vetor[pos];
                vetor[pos] = aux;
                (*troca)++;
            }
            (*comparacao)++;;
        }
    };

#endif // ORDENADOR_H_INCLUDED
