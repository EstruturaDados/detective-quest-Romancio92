
//inclusão de bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char valor[50];
    struct No* esquerda;
    struct No* direita;

} No;

//inicialização da função main.
int main ()
{


    return 0;
}

//definição de funções.
//definição de função para criar nó.
No* criarNo (const char* valor)
{
    No* novo =  (No*) malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(novo->valor, valor);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

//criar função de inserir nó.
No* inserir(No* raiz, const char*valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }
    if (strcmp(valor, raiz->valor) < 0);
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else
    {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}