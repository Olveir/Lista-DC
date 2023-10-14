#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int val;
    struct No* prox;
    struct No* ant;
} no;

typedef struct Lista{
    int tam;
    struct No* ini;
    struct No* fim;
} lista;

lista* cria_lista(){
    lista *l = (lista *)malloc(sizeof(lista));
    l -> ini=NULL;
    l->fim=NULL;
    l->tam=0;
    return l;
}

no* criar(lista* l, int num){
    no* p = (no*)malloc(sizeof(no));
    p->val = num;
    return p;
}

no* libera(lista* l){
    no* p = l -> ini;
    while (p != NULL) {
        no* t = p->prox; /* guarda referencia para o proximo elemento*/
        free(p); /* libera a memoria apontada por p */
        p = t; /* faz p apontar para o proximo */
    }
    return p;
}

lista* inserir_inicio(lista* l, int num){
    no* novoNo = criar(l, num);
    /*condicao para verificar se a memoria foi alocada*/
    if(novoNo){
        /*condicao para verificar se e o primeiro elemento a se inserido*/
        if(l->ini==NULL){
            novoNo->val=num;
            l->ini = novoNo;
            l->fim = novoNo;
            novoNo->ant = novoNo;
            novoNo->prox = novoNo;
        } else {
            novoNo->val=num;
            novoNo->ant = l->fim;
            novoNo->prox = l->ini;
            l->fim->prox = novoNo;
            l->ini->ant = novoNo;
            l->ini = novoNo;
        }
        printf("Numero adicionado com sucesso.\n");
        l->tam++;
        return l;

    } else {
        /*condicao caso um erro ocorra erro na alocacao de memoria seguido com a funcao libera para liberar espaco na memoria*/
        printf("Erro ao alocar memoria, tente novamente");
        libera(l);
        return l;
    }
}

lista* inserir_fim(lista* l, int num){
    no* novoNo = criar(l, num);
    /*condicao para verificar se a memoria foi alocada*/
    if (novoNo){
        /*condicao para verificar se e o primeiro elemento a se inserido*/
        if(l->ini==NULL){
            novoNo->val=num;
            l->ini = novoNo;
            l->fim = novoNo;
            novoNo->ant = novoNo;
            novoNo->prox = novoNo;
        } else {
            novoNo->val=num;
            novoNo->ant = l->fim;
            novoNo->prox = l->ini;
            l->fim->prox = novoNo;
            l->ini->ant = novoNo;
            l->fim = novoNo;
        }
        printf("Numero adicionado com sucesso.\n");
        l->tam++;
        return l;

    } else {
        /*condicao caso um erro ocorra erro na alocacao de memoria seguido com a funcao libera para liberar espaco na memoria*/
        printf("Erro ao alocar memoria, tente novamente");
        libera(l);
        return l;
    }
}

lista* remover(lista* l){
    no* aux = l->ini;
    int remover = 0;

    if (l->ini==NULL)
    {
        printf("A lista esta vazia.");
        return l;
    }

    printf("\nInsira o numero que deseja remover: \n");
    scanf("%d", &remover);
    getchar();

    do
    {
        /*condicao para verificar se o numero foi encontrado*/
        if (aux->val == remover)
        {
            /*condicao para verificar se so ha um elemento*/
            if (aux->prox == aux)
            {
                l->ini = NULL;
                l->fim = NULL;

            }else{
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                    
                if (aux == l->ini)
                {
                    l->ini = aux->prox;
                }
                if (aux == l-> fim)
                {
                    l->fim = aux->ant;
                }
            }
            
            printf("O numero %d foi excluido com sucesso.", aux->val);
            free(aux);
            
            l->tam--;
            return l;
        }

        aux= aux->prox;

    } while (aux!=l->ini);

    printf("O numero %d nao foi encontrado.\n", remover);
    return l; /* nao achou o elemento */

}

void busca(lista* l){
    no* aux = l->ini;
    int buscar;
    int posicao = 1;
    int achou = 0;

    if (l->ini==NULL)
    {
        printf("\nA lista esta vazia.\n");
        return;
    }

    printf("\nInsira o numero que deseja encontrar: \n");
    scanf("%d", &buscar);
    getchar();

    do
    {
        /*condicao para verificar se o numero foi encontrado*/
        if (aux->val == buscar)
        {
            printf("Numero: %d\nPosicao: %d\n", aux->val, posicao);
            achou = 1;
            break;
        }

        aux= aux->prox;
        posicao++;

    } while (aux!=l->ini);

    if (!achou)
    {
        printf("O numero %d nao foi encontrado.\n", buscar);
    }

}

void exibir(lista* l){
    no* aux = l->ini;
    int posicao = 1;

    if (l->ini==NULL)
    {
        printf("\nA lista esta vazia.\n");
        return;
    }

    printf("\n|--------------------------|\n");
    printf("|--| ELEMENTOS DA LISTA |--|\n");
    printf("|--------------------------|\n");

    do
    {
        printf("Numero: %d, Posicao: %d\n", aux->val, posicao);
        aux= aux->prox;
        posicao++;

    } while (aux!=l->ini);
    
    printf("\n|--------------------------|\n");
    printf("Quantidade de elementos: %d.\n", l->tam);
    printf("|-----------fim------------|\n");
}

void printMenu(){
    printf("\nMenu de opcoes.\n");
    printf("1. Inserir um elemento no Inicio\n");
    printf("2. Inserir um elemento no Fim\n");
    printf("3. Remover um elemento\n");
    printf("4. Buscar um elemento\n");
    printf("5. Exibir elementos da lista\n");
    printf("6. Encerrar o programa\n");
}

int main(){
    
    lista* l = cria_lista();
    int num, opcoes;

    do//Do while para fazer o menu interativo
    {
        printMenu();
        scanf("%d", &opcoes);
        getchar();

        switch (opcoes)
        {
            case 1:
                printf("\nInsira um numero: \n");
                scanf("%d", &num);
                getchar();
                inserir_inicio(l, num);
                break;
            case 2:
                printf("\nInsira um numero: \n");
                scanf("%d", &num);
                getchar();
                inserir_fim(l, num);
                break;
            case 3:
                remover(l);
                break;
            case 4:
                busca(l);
                break;
            case 5:
                exibir(l);
                break;
            case 6:
                break;
            default:
                printf("Insira uma opcao valida!");
                break;
        }
    } while (opcoes!=6);

    return 0;
} 