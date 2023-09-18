#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

int main() {
    Fila *fila = criar();
    if (fila == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    int opcao;
    struct aluno aluno;

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Inserir aluno na fila\n");
        printf("2. Remover aluno da fila\n");
        printf("3. Acessar primeiro aluno na fila\n");
        printf("4. Imprimir a fila\n");
        printf("5. Tamanho da fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &aluno.matricula);
                printf("Digite o nome do aluno: ");
                scanf("%s", &aluno.nome);
                printf("Digite a media do aluno: ");
                scanf("%f", &aluno.media);
                inserir(fila, aluno);
                printf("Aluno inserido na fila.\n");
                break;

            case 2:
                if (remover(fila)) {
                    printf("Aluno removido da fila.\n");
                } else {
                    printf("Fila vazia. Nenhum aluno para remover.\n");
                }
                break;

            case 3:
                if (acessar(fila, &aluno)) {
                    printf("Primeiro aluno na fila:\n");
                    printf("Matricula: %d\nNome: %s\n", aluno.matricula, aluno.nome);
                } else {
                    printf("Fila vazia. Nenhum aluno para acessar.\n");
                }
                break;

            case 4:
                if (imprimeFila(fila)) {
                    printf("Fila impressa.\n");
                } else {
                    printf("Fila vazia. Nada para imprimir.\n");
                }
                break;

            case 5:
                printf("Tamanho da fila: %d\n", tamanho(fila));
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    destruir(fila);

    return 0;
}


