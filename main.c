#include <stdio.h>
#include "pilhaDinamica.h"

int main() {
    Pilha *pilha = criar();
    int opcao;

    while (1) {
        printf("\nMenu de Op��es:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Acessar topo\n");
        printf("4. Verificar vazia\n");
        printf("5. Imprimir pilha\n");
        printf("6. Tamanho da pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                struct aluno novoAluno;
                printf("Digite o nome: ");
                scanf(" %49[^\n]", novoAluno.nome);
                printf("Digite a matr�cula: ");
                scanf("%d", &novoAluno.matricula);
                inserir(pilha, novoAluno);
                printf("Aluno inserido com sucesso!\n");
                break;
            }
            case 2: {
                if (remover(pilha)) {
                    printf("Aluno removido com sucesso!\n");
                } else {
                    printf("Erro ao remover aluno. Pilha vazia?\n");
                }
                break;
            }
            case 3: {
                struct aluno alunoDoTopo;
                if (acessar(pilha, &alunoDoTopo)) {
                    printf("Aluno do topo:\n");
                    printf("Nome: %s\nMatr�cula: %d\n", alunoDoTopo.nome, alunoDoTopo.matricula);
                } else {
                    printf("Erro ao acessar aluno do topo. Pilha vazia?\n");
                }
                break;
            }
            case 4: {
                if (vazia(pilha)) {
                    printf("A pilha est� vazia.\n");
                } else {
                    printf("A pilha n�o est� vazia.\n");
                }
                break;
            }
            case 5: {
                imprimePilha(pilha);
                break;
            }
            case 6: {
                printf("Tamanho da pilha: %d\n", tamanho(pilha));
                break;
            }
            case 0:
                destruir(pilha);
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    }

    return 0;
}
