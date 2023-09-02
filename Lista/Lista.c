#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

//LISTA DINAMICA ENCADEADA
Elemento* lst_cria(void)
{
    return NULL;
}

Elemento* lst_insere(Elemento* lst, int val)
{
    //No primeiro uso, o ponteiro vai entrar nulo e vai voltar então com DADO (info) que é um valor numerico, e ponteiro proximo, nulo.
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento)); //alocando espaço para o elemento.
    novo->info = val; //dentro desse elemento estamos transferindo o inteiro para o valor, deixando-o mais interno
    novo->prox = lst;
    return novo;
}

Elemento* lst_imprime(Elemento* lst)
{
Elemento *p;
for (p = lst; p!=NULL; p=p->prox)
    printf("info = %d \n", p->info);
}

int lst_vazia (Elemento* lst)
{
    return (lst == NULL);
    //Retorna 1 se vazia, ou 0 se não vazia
}

Elemento* lst_busca(Elemento* lst, int v)
{
    Elemento *p;
    for (p =lst; p!=NULL; p = p->prox)
    {
        if (p->info == v)
            return p;
    }
    return NULL;
    //Aparentemente, se já retornar o p, não vai retornar o null aqui embaixo
    //não precisa de if/else?
}

Elemento* lst_remove(Elemento* lst, int val)
{
    Elemento* rlst = lst;
    Elemento* p = lst;
    Elemento* ant = NULL;

    while(p != NULL && p->prox != val)
    {

        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        //Se não achou, retorna lista original
        return rlst;
    }

    if(ant == NULL)
    {
        //O primeiro é nulo, retira ele do inicio
        rlst = p->prox;
    }
    else
        {
            //Todos os outros casos, tira do meio/final da lista
            ant->prox = p->prox;
        }
    free(p); //Libera o p em questão
    return rlst;
}

Elemento * lst_libera (Elemento* lst)
{
    Elemento *p = lst, *t;
    while (p != NULL)
    {
        t = p->prox; //guarda a referência para o proximo elemento
        free(p); //libera memoria apontada por p
        p = t; //faz apontar para o próximo
    }
}
//ESTUDAR
Elemento * lst_insere_ordenado (Elemento *lst, int val)
{
    Elemento* novo;
    Elemento* ant = NULL;
    Elemento* p = lst;
    Elemento* rlst = lst;

    while(p != NULL && p->info < val)
    { //Enquanto p não for nulo e info for menor que val
      //No momento que achar um maior que val, deve-se colocar val antes dele e entre o antigo
     novo = (Elemento*) malloc(sizeof(Elemento));
     novo->info = val;
     //transferindo o valor para a informação do novo elemento.

     //encadeação do elemento
     if(ant == NULL)
     { //Será o primeiro elemento da lista nesse caso, basta colocar o prox como o o antigo
         novo->prox = lst;
         rlst = novo; //novo passaria a ser o primeiro elemento
     }
     else
     { //Em todos os outros casos
         novo->prox = ant->prox;
         //O proximo do novo é o próximo do anterior
         ant->prox = novo;
         //O proximo anterior é o novo
     }
        return rlst;
    }

    int lst_igual (Elemento* lst1, Elemento* lst2)
{
    Elemento* p1; //ponteiro para percorrer lst1
    Elemento* p2; //ponteiro para percorrer lst2
    for (p1=lst1, p2=lst2; p1 != NULL && p2 != NULL; p1 = p1->prox, p2 = p2->prox)
        {
            if (p1->info != p2->info)
            return 0;
            }
            return p1==p2;
}
 int lst_igual_recursivo (Elemento* lst1, Elemento* lst2)
 {
     if (lst1 == NULL && lst2 == NULL)
        return 1;
     if (lst1 == NULL || lst2 == NULL)
        return 0;
     else
        return (lst1->info == lst2-> info) && lst_igual(lst1->prox, lst2->prox);
     //Comparação da informação da primeira data de cada lista, e chamada de recursão da própria função para comparar o segundo nó de cada uma
 }





}
