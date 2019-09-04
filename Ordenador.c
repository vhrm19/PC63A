#ifndef ORDENADOR_H_INCLUDED
#define ORDENADOR_H_INCLUDED

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
                *troca++;
            }
            *comparacao++;
        N--;
    }while(check == 1);
};

void heapSort(int *vetor, int N, int *comparacao, int *troca){
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

void maxHeap(int *vetor, int raiz, int N, int *comparacao, int *troca){
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

void InsertionSort(int *vetor, int N, int *comparacao, int *troca){
    int aux, j;
    for(int i=1; i<N; i++){
        aux = vetor[i];
        for(j=i-1; aux < vetor[j] && j >= 0; j--){
            vetor[j+1] = vetor[j];
            *troca++;
        }
        vetor[j+1] = aux;
        *comparacao++;
    }
};

void MergeSort(int *vetor, int inicio, int fim, int *comparacao, int *troca){
    int meio = floor((inicio+fim)/2);
    if(inicio < fim){
        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void merge(int *vetor, int inicio, int meio, int fim, int *comparacao, int *troca){
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

void quickSort(int *vetor, int inicio, int fim, int *comparacao, int *troca){
    int pivo;
    if(inicio < fim){
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}

int particiona(int *vetor, int inicio, int fim, int *comparacao, int *troca){
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
                *troca++;
            }
            *comparacao++;
        }
    };

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

#endif // ORDENADOR_H_INCLUDED
