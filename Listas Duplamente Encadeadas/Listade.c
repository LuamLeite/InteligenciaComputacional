#include "Listade.h"
#include <stdlib.h>
#include <stdio.h>

Lstde* insere_elemento(Lstde* p)
{
    int valor;
    Lstde* novo = (Lstde*) malloc(sizeof(Lstde));
    novo->ant = NULL;
    novo->prox = p;

    printf("\n Insira o valor que deseja colocar na lista: ");
    scanf("%i", &valor);
    novo->info = valor;


    if(p!=NULL)
    {
        p->ant = novo;
        //SE A LISTA NÃO ESTA VAZIA, AI SIM, O ponteiro anterior do antigo PRIMEIRO ELEMENTO DA LISTA, aponta o novo atualizado
    }
    //Novo é onde a lista vai começar, o elemento mais recente.
    //Então o prox será o elemento que veio antes.
    //Novo não tem anterior na primeira inserção, o anterior vem antes.
    //O elemento mais recente nunca terá anterior
    //Mas, terá na segunda
    return novo;
}

void imprimir (Lstde* p)
{
    for (p; p!=NULL; p = p->prox)
    {
        printf("\n %i", p->info);
    }
}

Lstde* busca (Lstde* p)
{
    int valor;
    Lstde* aux;
    printf("\n Digite o valor que deseja buscar: ");
    scanf("%i", &valor);
    for (aux = p; aux!=NULL; aux= aux->prox)
    {
        if(aux->info == valor)
        {
            printf("\n Elemento encontrado!");
            return aux;
        }
    }
    printf("\n Elemento não encontrado.");
}

Lstde* remover(Lstde* p)
{
    int valor;
    Lstde* aux; //retornar ponteiro atualizado
    Lstde* deletar = NULL; //dar free
    printf("\n Digite o valor do elemento que deseja remover: ");
    scanf("%i", &valor);

    for (aux = p; aux!=NULL; aux= aux->prox)
    {
        if(aux->info == valor)
        {
            if(aux->ant == NULL) //É o primeiro elemento
            {
                deletar = aux;
                aux = aux->prox;
                printf("\n Elemento inicial deletado.");
                free(deletar);
                return aux;
            }
            if(aux->prox == NULL) //É o ultimo elemento
            {
                deletar = aux;
                aux->ant->prox = NULL;
                free(aux);
                printf("\n Elemento final deletado.");
                return p;
            }
            //elemento do meio
            printf("\n Elemento deletado!");
            deletar = p;
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(deletar);
            return p;
        }
    }
    printf("\n Elemento não encontrado para ser deletado.");
}
