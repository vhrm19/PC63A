#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *nome;
    char *cidade;
    char *curso;
}Aluno;


int main(){
    int num_cadastros = 3;
    char buffer[100];
    Aluno cadastro[num_cadastros];
    FILE *saida;
    saida = fopen("alunos.txt", "w");
    for(size_t i = 0; i < num_cadastros; i++){   
        printf("Digite o nome do aluno: ");
        scanf("%[^\n]s", buffer);
        cadastro[i].nome = (char *) malloc(strlen(buffer)*sizeof(char));
        strcpy(cadastro[i].nome, buffer);
        __fpurge(stdin);

        printf("Digite a cidade do aluno: ");
        scanf("%[^\n]s", buffer);
        cadastro[i].cidade = (char *) malloc(strlen(buffer)*sizeof(char));
        strcpy(cadastro[i].cidade, buffer);
        __fpurge(stdin);

        printf("Digite a curso do aluno: ");
        scanf("%[^\n]s", buffer);
        cadastro[i].curso = (char *) malloc(strlen(buffer)*sizeof(char));
        strcpy(cadastro[i].curso, buffer);
        __fpurge(stdin);

        fprintf(saida, "%-50.50s", cadastro[i].nome);
        fprintf(saida, "%-50.50s", cadastro[i].cidade);
        fprintf(saida, "%-50.50s|", cadastro[i].curso);
    }
    fflush(saida);
    fclose(saida);

    FILE *arq = fopen("alunos.txt", "r");
    Aluno recebe[num_cadastros];
    for(size_t i = 0; i < num_cadastros; i++){   
        fscanf(arq, "%50s", buffer);
        recebe[i].nome = (char *) malloc(strlen(buffer)+1);
        strcpy(recebe[i].nome, buffer);

        fscanf(arq, "%50s", buffer);
        recebe[i].cidade = (char *) malloc(strlen(buffer)+1);
        strcpy(recebe[i].cidade, buffer);

        fscanf(arq, "%50s", buffer);
        printf("%i\n", strcspn(buffer, "|"));
        // buffer[strcspn(buffer, '|')] = "\0";
        recebe[i].curso = (char *) malloc(strlen(buffer)+1);
        strcpy(recebe[i].curso, buffer);

        //printf("Nome[%i]: %s Cidade: %s Curso: %s\n", i, recebe[i].nome, recebe[i].cidade, recebe[i].curso);
    }
    return 0;
}
