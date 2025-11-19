
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

            No* criarNo (const char* valor);
            No* inserir(No* raiz, const char*valor);
            void preOrdem (No *raiz);
            void emOrdem (No *raiz);
            void posOrdem (No *raiz);
            void liberar(No *raiz);

            //inicialização da função main.
            int main ()
            {
                No *raiz = NULL;

                    raiz = inserir(raiz, "Hall de Entrada");
                        raiz = inserir(raiz, "Sala de Estar");
                            raiz = inserir(raiz, "Biblioteca");
                                raiz = inserir(raiz, "Quarto");

                                    printf("Pre-ordem: ");
                                        preOrdem(raiz);
                                            printf("\n");

                                                printf("Em ordem: ");
                                                    emOrdem(raiz);
                                                        printf("\n");

                                                            printf("Pos ordem: ");
                                                                posOrdem(raiz);
                                                                    printf("\n");

                                                                        liberar(raiz);

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

                                                                                                                                                    if (strcmp(valor, raiz->valor) < 0)
                                                                                                                                                        {
                                                                                                                                                                raiz->esquerda = inserir(raiz->esquerda, valor);
                                                                                                                                                                    }
                                                                                                                                                                        else
                                                                                                                                                                            {
                                                                                                                                                                                    raiz->direita = inserir(raiz->direita, valor);
                                                                                                                                                                                        }
                                                                                                                                                                                            return raiz;
                                                                                                                                                                                            }

                                                                                                                                                                                            void preOrdem (No *raiz)
                                                                                                                                                                                            {
                                                                                                                                                                                                if (raiz != NULL)
                                                                                                                                                                                                    {
                                                                                                                                                                                                            printf("%s", raiz->valor);
                                                                                                                                                                                                                    preOrdem(raiz->esquerda);
                                                                                                                                                                                                                            preOrdem(raiz->direita);
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                void emOrdem (No *raiz)
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                    if (raiz != NULL)
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                emOrdem(raiz->esquerda);
                                                                                                                                                                                                                                                        printf("%s", raiz->valor);
                                                                                                                                                                                                                                                                preOrdem(raiz->direita);
                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                    void posOrdem (No *raiz)
                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                        if (raiz != NULL)
                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                    emOrdem(raiz->esquerda);
                                                                                                                                                                                                                                                                                            preOrdem(raiz->direita);
                                                                                                                                                                                                                                                                                                    printf("%s", raiz->valor);
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                        void liberar(No *raiz)
                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                            if (raiz != NULL)
                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                        liberar(raiz->esquerda);
                                                                                                                                                                                                                                                                                                                                liberar(raiz->direita);
                                                                                                                                                                                                                                                                                                                                        free(raiz);
                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                            }

