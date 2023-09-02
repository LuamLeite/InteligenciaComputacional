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

void circular(Lstde* p)
{
    Lstde* aux = NULL;
    for(p; p!=aux; p= p->prox)
    {
        if(aux == NULL)
        {
            aux = p;
        }
        if(p->prox == NULL)
        {
            p->prox = aux;
            aux->ant = p;
        }
    }
    //printf("\n Teste fim");
}
void imprimir (Lstde* p)
{
    Lstde* pri = NULL;
    for (p; p!=pri; p = p->prox)
    {
        if(pri == NULL)
        {
            pri = p;
        }
        printf("\n %i", p->info);
    }
}

void imprimir_inverso (Lstde* p)
{
    Lstde* pri = NULL;
    printf("\n Impressão Inversa");
    p = p->ant; //IMPORTANTE, TEM QUE COMEÇAR A IMPRIMIR NO ULTIMO, LOOP TEM QUE COMEÇAR AQUI.
    for (p; p!=pri; p = p->ant)
    {
        if(pri == NULL)
        {
            pri = p;
        }

         printf("\n %i", p->info);
    }
}

Lstde* busca (Lstde* p)
{
    int valor;
    Lstde* aux;
    Lstde* pri = NULL;
    printf("\n Digite o valor que deseja buscar: ");
    scanf("%i", &valor);
    for (aux = p; aux!=pri; aux= aux->prox)
    {
        if(pri == NULL)
        {
            pri = aux;
        }
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
    Lstde* pri = NULL;
    Lstde* aux; //retornar ponteiro atualizado
    Lstde* deletar = NULL; //dar free
    printf("\n Digite o valor do elemento que deseja remover: ");
    scanf("%i", &valor);

    for (aux = p; aux!=pri; aux= aux->prox)
    {
        if(pri == NULL)
        {
            pri = aux;
        }
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
return p;
}
