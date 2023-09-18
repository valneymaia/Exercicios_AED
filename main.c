#include <stdio.h>
#include <stdlib.h>
#include "listaDinamicaSimplesmenteEncadeada.h"

int main() {
    Lista *ldse = criar();
    if (ldse == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    int opcao;
    struct aluno aluno;
    int matricula, posicao;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Inserir aluno no inicio\n");
        printf("2. Inserir aluno no fim\n");
        printf("3. Inserir aluno ordenado por matricula\n");
        printf("4. Remover aluno do inicio\n");
        printf("5. Remover aluno do fim\n");
        printf("6. Remover aluno por matricula\n");
        printf("7. Acessar aluno por posicao\n");
        printf("8. Acessar aluno por matricula\n");
        printf("9. Imprimir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &aluno.matricula);
                printf("Digite o nome do aluno: ");
                scanf("%s", aluno.nome);
                inserirInicio(ldse, aluno);
                break;
            case 2:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &aluno.matricula);
                printf("Digite o nome do aluno: ");
                scanf("%s", aluno.nome);
                inserirFim(ldse, aluno);
                break;
            case 3:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &aluno.matricula);
                printf("Digite o nome do aluno: ");
                scanf("%s", aluno.nome);
                inserirOrdenado(ldse, aluno);
                break;
            case 4:
                removerInicio(ldse);
                break;
            case 5:
                removerFim(ldse);
                break;
            case 6:
                printf("Digite a matricula do aluno a ser removido: ");
                scanf("%d", &matricula);
                removerValor(ldse, matricula);
                break;
            case 7:
                printf("Digite a posicao do aluno a ser acessado: ");
                scanf("%d", &posicao);
                if (acessarIndice(ldse, posicao, &aluno))
                    printf("Aluno na posicao %d:\nMatricula: %d\nNome: %s\n", posicao, aluno.matricula, aluno.nome);
                else
                    printf("Posição invalida.\n");
                break;
            case 8:
                printf("Digite a matrícula do aluno a ser acessado: ");
                scanf("%d", &matricula);
                if (acessarValor(ldse, matricula, &aluno))
                    printf("Aluno encontrado:\nMatrícula: %d\nNome: %s\n", aluno.matricula, aluno.nome);
                else
                    printf("Aluno não encontrado.\n");
                break;
            case 9:
                imprimeLista(ldse);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    destruir(ldse);
    free(ldse);

    return 0;
}
