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

    void SelectionSort(int *vetor, int N){
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
            }
        }
    };

    int main()
    {
        int N = 10;
        int *vetor = alea(N);
        exibeVetor(vetor, N);
        SelectionSort(vetor, N);
        exibeVetor(vetor, N);
        return 0;
    }
