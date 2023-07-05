#include <stdio.h>
#include <stdlib.h>

typedef struct no_fila
{
    char nucleotideo;
    struct no_fila *prox;
} NoFila;

typedef struct
{
    NoFila *inicio;
    NoFila *fim;
} Fila;

typedef struct no_pilha
{
    char nucleotideo;
    struct no_pilha *prox;
} NoPilha;

typedef struct
{
    NoPilha *topo;
} Pilha;

void inicializarFila(Fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

void inicializarPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}

void inserirFila(Fila *fila, char nucleotideo)
{
    NoFila *novoNo = (NoFila *)malloc(sizeof(NoFila));
    novoNo->nucleotideo = nucleotideo;
    novoNo->prox = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else
    {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

char excluirFila(Fila *fila)
{
    if (fila->inicio == NULL)
    {
        printf("A fila esta vazia.\n");
        return '\0';
    }

    NoFila *noRemovido = fila->inicio;
    char nucleotideo = noRemovido->nucleotideo;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(noRemovido);
    return nucleotideo;
}

void imprimirFila(Fila *fila)
{
    NoFila *atual = fila->inicio;

    printf("Fila: ");
    while (atual != NULL)
    {
        printf("%c", atual->nucleotideo);
        atual = atual->prox;
    }
    printf("\n");
}

void inserirPilha(Pilha *pilha, char nucleotideo)
{
    NoPilha *novoNo = (NoPilha *)malloc(sizeof(NoPilha));
    novoNo->nucleotideo = nucleotideo;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

void imprimirPilha(Pilha *pilha)
{
    NoPilha *atual = pilha->topo;

    printf("Pilha: ");
    while (atual != NULL)
    {
        printf("%c", atual->nucleotideo);
        atual = atual->prox;
    }
    printf("\n");
}

int main()
{
    Fila fila;
    Pilha pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int opcao;
    char nucleotideo;

    do
    {
        printf("\nMenu:\n");
        printf("1. Inserir na fila\n");
        printf("2. Excluir da fila\n");
        printf("3. Imprimir fila\n");
        printf("4. Inserir na pilha\n");
        printf("5. Imprimir pilha\n");
        printf("0. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o nucleotideo a ser inserido na fila: ");
            scanf(" %c", &nucleotideo);
            inserirFila(&fila, nucleotideo);
            if (nucleotideo == 'A')
            {
                inserirPilha(&pilha, 'T');
            }
            else if (nucleotideo == 'C')
            {
                inserirPilha(&pilha, 'G');
            }
            else if (nucleotideo == 'T')
            {
                inserirPilha(&pilha, 'A');
            }
            else if (nucleotideo == 'G')
            {
                inserirPilha(&pilha, 'C');
            }
            break;
        case 2:
            nucleotideo = excluirFila(&fila);
            if (nucleotideo != '\0')
            {
                printf("Nucleotideo removido da fila: %c\n", nucleotideo);
            }
            break;
        case 3:
            imprimirFila(&fila);
            break;
        case 4:
            printf("Digite o nucleotideo a ser inserido na pilha: ");
            scanf(" %c", &nucleotideo);
            inserirPilha(&pilha, nucleotideo);
            if (nucleotideo == 'A')
            {
                inserirFila(&fila, 'T');
            }
            else if (nucleotideo == 'C')
            {
                inserirFila(&fila, 'G');
            }
            else if (nucleotideo == 'T')
            {
                inserirFila(&fila, 'A');
            }
            else if (nucleotideo == 'G')
            {
                inserirFila(&fila, 'C');
            }
            break;
        case 5:
            imprimirPilha(&pilha);
            break;
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}