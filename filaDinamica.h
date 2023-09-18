#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED

struct aluno{
    int matricula;
    char nome[50];
    float media;
};

typedef struct fila Fila;

Fila* criar();
void destruir(Fila *);
int tamanho(Fila*);
int cheia(Fila *);
int vazia(Fila *);
int inserir(Fila *, struct aluno);
int remover(Fila *);
int acessar(Fila *, struct aluno *);
int imprimeFila(Fila *);

#endif // FILADINAMICA_H_INCLUDED
