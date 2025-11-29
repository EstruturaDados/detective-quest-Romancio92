#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala
{
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

Sala *criarSala(char *nomecomodo); 
void liberar(Sala *raiz);
void posOrdem(Sala *raiz);

int main()
{
    int opcao;

    Sala *raiz = criarSala("Hall de Entrada");
    raiz->esquerda = criarSala("Sala de Estar");
    raiz->direita = criarSala("Biblioteca");
    raiz->esquerda->esquerda = criarSala("Quarto");
    raiz->esquerda->direita = criarSala("Cozinha");
    raiz->direita->esquerda = criarSala("Porão");
    raiz->direita->direita = criarSala("Varanda");

    printf("Detetive encontra-se na entrada da mansão: %s", raiz);
    do
    {
        printf("\n#### MENU DE PERCURSO ####\n");        
        printf("1. Esquerda.\n");
        printf("2. Direita.\n");
        printf("0. liberar e sair.\n");
        printf("\nEscolha uma das opções: \n");
        scanf("%i", &opcao);

        switch (opcao)
        {
            case 1:
                printf("Detetive entrou no cômodo: %s", raiz->esquerda);

                
                do
                {
                    printf("\n#### MENU DE PERCURSO 2 ####\n");        
                    printf("11. Esquerda.\n");
                    printf("12. Direita.\n");
                    printf("0. liberar e sair.\n");
                    printf("\nEscolha uma das opções: \n");
                    scanf("%i", &opcao);

                    switch (opcao)
                    {

                        case 11:
                            printf("Detetive entrou no cômodo: %s", raiz->esquerda->esquerda);
                            break;

                        case 12:
                            printf("Detetive entrou no cômodo: %s", raiz->esquerda->direita);
                            break;       
                        case 0:
                            posOrdem(raiz);
                            printf("\n");            
                            liberar(raiz);
                            printf("saindo do sistema...");
                            break;
                            
                        default:
                            printf("Opção inválida! Tente novamente.");
                            break;

                        
                    } 
                } while (opcao != 0);

                break;

            case 2:
                printf("Detetive entrou no cômodo: %s", raiz->direita);

                do
                {
                    printf("\n#### MENU DE PERCURSO 2 ####\n");        
                    printf("21. Esquerda.\n");
                    printf("22. Direita.\n");
                    printf("0. liberar e sair.\n");
                    printf("\nEscolha uma das opções: \n");
                    scanf("%i", &opcao);

                    switch (opcao)
                    {

                        case 21:
                            printf("Detetive entrou no cômodo: %s", raiz->direita->esquerda);
                            break;

                        case 22:
                            printf("Detetive entrou no cômodo: %s", raiz->direita->direita);
                            break;    
                            
                        case 0:
                            posOrdem(raiz);
                            printf("\n");            
                            liberar(raiz);
                            printf("saindo do sistema...");
                            break;

                        default:
                            printf("Opção inválida! Tente novamente.");
                            break;              

                        
                    } 
                } while (opcao != 0);

                
                break;

            case 0:
                printf("Pós-ordem: ");
                posOrdem(raiz);
                printf("\n");            
                liberar(raiz);
                printf("saindo do sistema...");
                break;      
                
            default:
                printf("Opção inválida! Tente novamente.");
                break;
            }
    } while (opcao != 0);
    
    return 0;
}

//função para criar nós como cômodos.
Sala *criarSala(char *nomecomodo) 
{
    Sala *novo = (Sala*) malloc(sizeof(Sala));
    strcpy(novo->nome, nomecomodo);
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

/*Sala explorarSala()
{

}*/


void liberar(Sala *raiz) 
{
    if (raiz != NULL) 
    {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

void posOrdem(Sala *raiz) 
{
    if (raiz != NULL) 
    {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s - ", raiz->nome);
    }
}
