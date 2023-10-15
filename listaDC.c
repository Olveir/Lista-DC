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

/*funcao para criar a lista circular*/
lista* cria_lista(){
    lista *l = (lista *)malloc(sizeof(lista));//alocacao dinamica
    l -> ini=NULL;
    l->fim=NULL;
    l->tam=0;
    return l;//retorna a lista vazia
}

/*funcao para criar o no duplamente encadeado*/
no* criar(lista* l, int num){
    no* p = (no*)malloc(sizeof(no));//alocacao dinamica
    p->val = num;
    return p;//retorna o no alocado
}

/*funcao para liberar qualquer memoria alocada dinamicamente, permitindo o gerenciamento da memoria.*/
no* libera(lista* l){
    no* p = l -> ini;/* ponteiro para percorrer a lista*/
    while (p != NULL) {
        no* t = p->prox; /* guarda referencia para o proximo elemento*/
        free(p); /* libera a memoria apontada por p */
        p = t; /* faz p apontar para o proximo */
    }
    return p;
}

/*funcao para inserir um elemento no inicio da lista*/
lista* inserir_inicio(lista* l, int num){
    
    /*cria novo no*/
    no* novoNo = criar(l, num);

    /*condicao para verificar se a memoria foi alocada*/
    if(novoNo){
        /*condicao para verificar se e o primeiro elemento a se inserido*/
        if(l->ini==NULL){
            l->ini = novoNo;
            l->fim = novoNo;
            novoNo->ant = novoNo;
            novoNo->prox = novoNo;
        
        /*insere elemento no inicio*/
        } else {
            novoNo->ant = l->fim;
            novoNo->prox = l->ini;
            l->fim->prox = novoNo;
            l->ini->ant = novoNo;
            l->ini = novoNo;
        }
        printf("Numero adicionado com sucesso.\n");
        l->tam++;//incremento na variavel de tamanho da lista
        return l;//retorna a lista com o novo no inserido

    } else {
        /*condicao caso um erro ocorra erro na alocacao de memoria seguido com a funcao libera para liberar memoria alocada dinamicamente*/
        printf("Erro ao alocar memoria, tente novamente");
        libera(l);//libera qualquer memoria alocada dinamicamente
        return l;//retorna a lista apos liberacao
    }
}

/*funcao para inserir um elemento no fim da lista*/
lista* inserir_fim(lista* l, int num){
    
    /*cria novo no*/
    no* novoNo = criar(l, num);

    /*condicao para verificar se a memoria foi alocada*/
    if (novoNo){
        /*condicao para verificar se e o primeiro elemento a se inserido*/
        if(l->ini==NULL){
            l->ini = novoNo;
            l->fim = novoNo;
            novoNo->ant = novoNo;
            novoNo->prox = novoNo;

        /*insere elemento no fim*/
        } else {
            novoNo->ant = l->fim;
            novoNo->prox = l->ini;
            l->fim->prox = novoNo;
            l->ini->ant = novoNo;
            l->fim = novoNo;
        }
        printf("Numero adicionado com sucesso.\n");
        l->tam++;//incremento na variavel de tamanho da lista
        return l;//retorna a lista com o novo no inserido

    } else {
        /*condicao caso um erro ocorra erro na alocacao de memoria seguido com a funcao libera para liberar memoria alocada dinamicamente*/
        printf("Erro ao alocar memoria, tente novamente");
        libera(l);//libera qualquer memoria alocada dinamicamente
        return l;//retorna a lista apos liberacao
    }
}

/*funcao para remover um elemento da lista*/
lista* remover(lista* l){
    no* aux = l->ini;//ponteiro para percorrer a lista
    int remover = 0;//variavel para receber o input do usuario e fazer a busca

    /*condicao para verificar se a lista esta vazia*/
    if (l->ini==NULL)
    {
        printf("A lista esta vazia.");
        return l;
    }

    printf("\nInsira o numero que deseja remover: \n");
    scanf("%d", &remover);
    getchar();

    /*laco do while para percorrer todos elementos da lista*/
    do
    {
        /*condicao para verificar se o numero foi encontrado*/
        if (aux->val == remover)
        {
            /*condicao para verificar se so ha um elemento*/
            if (aux->prox == aux)
            {
                /*remove o elemento e a lista fica vazia*/
                l->ini = NULL;
                l->fim = NULL;

            }else{
                aux->ant->prox = aux->prox;//o ponteiro proximo do elemento anterior ao auxiliar vai receber o proximo elemento em relacao ao auxiliar
                aux->prox->ant = aux->ant;//o ponteiro anterior do proximo elemento em relacao ao auxiliar vai receber o elemento anteiror em relacao ao auxiliar

                /*remove do inicio*/    
                if (aux == l->ini)
                {
                    l->ini = aux->prox;
                }
                /*remove do fim*/
                if (aux == l-> fim)
                {
                    l->fim = aux->ant;
                }
            }
            
            printf("O numero %d foi excluido com sucesso.", aux->val);
            free(aux);/*libera o no da memoria*/
            
            l->tam--;/*decremento na variavel de tamanho da lista*/
            return l;/*retorna a lista com o valor ja excluido*/
        }

        aux= aux->prox;//recebe o proximo elemento

    } while (aux!=l->ini);

    printf("O numero %d nao foi encontrado.\n", remover);
    return l; /* nao achou o elemento */

}

void busca(lista* l){
    no* aux = l->ini;//ponteiro para percorrer a lista
    int buscar;//variavel para receber o input do usuario e fazer a busca
    int posicao = 1;//variavel para contar a posicao de cada elemento, comecando a partir do primeiro elemento
    int achou = 0;//flag para verificar se o elemento foi ou nao encontrado

    /*condicao para verificar se a lista esta vazia*/
    if (l->ini==NULL)
    {
        printf("\nA lista esta vazia.\n");
        return;
    }

    printf("\nInsira o numero que deseja encontrar: \n");
    scanf("%d", &buscar);
    getchar();

    /*laco do while para percorrer todos elementos da lista*/
    do
    {
        /*condicao para verificar se o numero foi encontrado*/
        if (aux->val == buscar)
        {
            printf("Numero: %d\nPosicao: %d\n", aux->val, posicao);
            achou = 1;//flag é setada
            break;
        }

        aux= aux->prox;//recebe o proximo elemento
        posicao++;//incremento da variavel posicao, a cada passagem do laco do while, a variavel e incrementada

    } while (aux!=l->ini);

    /*condicao para verificar se a flag foi setada, se achou continuar = 0, significa que o elemento inserido nao foi encontrado*/
    if (!achou)
    {
        printf("O numero %d nao foi encontrado.\n", buscar);
    }

}

void exibir(lista* l){
    no* aux = l->ini;//ponteiro para percorrer a lista
    int posicao = 1;//variavel para contar a posicao de cada elemento, comecando a partir do primeiro elemento

    /*condicao para verificar se a lista esta vazia*/
    if (l->ini==NULL)
    {
        printf("\nA lista esta vazia.\n");
        return;
    }

    printf("\n|--------------------------|\n");
    printf("|--| ELEMENTOS DA LISTA |--|\n");
    printf("|--------------------------|\n");

    /*laco do while para percorrer todos elementos da lista*/
    do
    {
        printf("Numero: %d, Posicao: %d\n", aux->val, posicao);
        aux= aux->prox;//recebe o proximo elemento
        posicao++;//incremento da variavel posicao, a cada passagem do laco do while, a variavel e incrementada

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
    
    lista* l = cria_lista();//inicializacao da lista

    /*variaveis para receber o input do usuario. 'num' para receber o valor que o usuario deseja inserir e 'opcoes' para receber qual funcionalidade do codigo o usuario deseja realizar*/
    int num, opcoes;

    do//Do while para fazer o menu interativo
    {
        printMenu();
        scanf("%d", &opcoes);
        getchar();

        switch (opcoes)
        {
            case 1://inserir no inicio
                printf("\nInsira um numero: \n");
                scanf("%d", &num);
                getchar();
                inserir_inicio(l, num);
                break;
            case 2://inserir no fim
                printf("\nInsira um numero: \n");
                scanf("%d", &num);
                getchar();
                inserir_fim(l, num);
                break;
            case 3://remocao de um elemento
                remover(l);
                break;
            case 4://busca de um elemento
                busca(l);
                break;
            case 5://impressao de todos elementos da lista
                exibir(l);
                break;
            case 6://sair do programa
                break;
            default://caso o usuario insira uma opcao invalida
                printf("Insira uma opcao valida!");
                break;
        }
    } while (opcoes!=6);

    return 0;
} 