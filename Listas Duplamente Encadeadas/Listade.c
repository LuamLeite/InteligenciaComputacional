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
        //SE A LISTA N�O ESTA VAZIA, AI SIM, O ponteiro anterior do antigo PRIMEIRO ELEMENTO DA LISTA, aponta o novo atualizado
    }
    //Novo � onde a lista vai come�ar, o elemento mais recente.
    //Ent�o o prox ser� o elemento que veio antes.
    //Novo n�o tem anterior na primeira inser��o, o anterior vem antes.
    //O elemento mais recente nunca ter� anterior
    //Mas, ter� na segunda
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
    printf("\n Elemento n�o encontrado.");
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
            if(aux->ant == NULL) //� o primeiro elemento
            {
                deletar = aux;
                aux = aux->prox;
                printf("\n Elemento inicial deletado.");
                free(deletar);
                return aux;
            }
            if(aux->prox == NULL) //� o ultimo elemento
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
    printf("\n Elemento n�o encontrado para ser deletado.");
}
