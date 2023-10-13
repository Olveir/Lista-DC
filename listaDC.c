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

void cria_lista(lista* l, int tam){
    //lista* p = (lista*) malloc(sizeof(lista));
    l -> ini=NULL;
    l->fim=NULL;
    l->tam=0;
}

no* inicializa(void){
    return NULL;
}

no* criar(no* l, int num){
    no* p = (no*)malloc(sizeof(no));
    p->val = num;
    return p;
}

void libera(no* N){
    no* p= N;
    while (p != NULL) {
        no* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento*/
        free(p); /* libera a mem�ria apontada por p */
        p = t; /* faz p apontar para o pr�ximo */
    }
}

no* inserir_inicio(no* N, lista* l, int num, int tam){
    no* novoNo = criar(N, num);

    if(novoNo){
        novoNo->val = num;
        novoNo->prox = l->ini;
        novoNo->ant = l->fim;
        l->ini = novoNo;
        if(l->fim==NULL){
            l->fim = novoNo;
        } 
        l->fim->prox= l->ini;
        l->ini->ant= l->fim;
        l->tam++;
        return novoNo;
    } else {
        printf("Erro ao alocar memoria, tente novamente");
        libera(N);
        return N;
    }
}

no* inserir_fim(no* N, lista* l, int num, int tam){
    no* novoNo,* aux = criar(N, num);

    if (novoNo){
        novoNo->val=num;
        /*condicao para verificar se é o primeiro elemento a ser inserido*/
        if(l->ini==NULL){
            l->ini=novoNo;
            l->fim=novoNo;
            l->fim->prox=l->ini;
            l->ini->ant=l->fim;
        } else{
            /*aux = N;
            auxL = l;
            while (aux->prox&&auxL->fim)
            {
            aux = aux->prox;
            auxL= auxL->fim;
            }
            aux->prox= novoNo;
            novoNo->ant = aux;*/
            l->fim->prox = novoNo;
            l->ini->ant = l->fim;
            l->fim = novoNo;
            novoNo->prox = l->ini;
        }
        l->tam++;
        return novoNo;
    } else {
        printf("Erro ao alocar memoria, tente novamente");
        libera(N);
        return N;
    }
}

no* remover(no* N, lista* l, int num, int tam){
    no* p;
    p = N;
    /*if(N->prox == NULL){
        printf("lista vazia.");*/
     if(N == NULL){
        printf("lista vazia.");
        return N;
    }
    while (p!=NULL&&p->val!= num)
        {
            p= p->prox;
            if (p==NULL)
            {
                printf("O numero nao esta na lista.");
                return N;
            }
        }

    if(p->prox!=NULL){
        p->prox->ant = p->ant;
    }
    p->ant->prox =p ->prox;
    free(p);
    l->tam--;
    return N;
}

no* busca(no* N, int num){
    no* p;
    for (p=N; p!=NULL; p=p->prox)
    if (p->val == num){
        printf("Numero = %d\n", p->val);
        return p;
    }
    return NULL; /* nao achou o elemento */
}

void exibir(no* N, lista* l){
    no* p; /* variavel auxiliar para percorrer a lista */
    printf("Primeiro Numero = %p\n", l->ini);
    printf("Ultimo Numero = %p\n", l->fim);
    
    for (p = N; p != NULL; p = p->prox){
        printf("Numero = %d\n", p->val);
        printf("Numero anterior = %d\n, end: %p\n", p->ant->val, p->prox);
        printf("Numero proximo= %d\n, end: %p\n", p->prox->val, p->prox);
        //printf("endMemoria %d\n",p->prox );
        printf("-----------Fim----------\n");
    }
}

void printMenu(){
    printf("\n Menu de opcoes.\n");
    printf("1. Inserir um elemento no Inicio\n");
    printf("2. Inserir um elemento no Fim\n");
    printf("3. Remover um elemento\n");
    printf("4. Buscar um elemento\n");
    printf("5. Remover um elemento\n");
    printf("6. Encerrar o programa\n");
}

int main(){
    no* n;
    lista* l;
    int num, opcoes, tam;
    cria_lista(l, tam);
    n = inicializa();
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
            inserir_inicio(n, l, num, tam);
            break;
        case 2:
            printf("\nInsira um numero: \n");
            scanf("%d", &num);
            getchar();
            inserir_fim(n, l, num, tam);
            break;
        case 3:
            printf("\nInsira um numero: \n");
            scanf("%d", &num);
            getchar();
            remover(n, l, num, tam);
            break;
        case 4:
            printf("\nInsira um numero: \n");
            scanf("%d", &num);
            getchar();
            busca(n, num);
            break;
        case 5:
            exibir(n, l);
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