#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main()
{
    printf("Hello listinhas e primeiro passo para as AV2S!!\n");
    int valor, i;
    Elemento* lista1;
    Elemento* busca;
    lista1 = lst_cria();
    for(i=0; i<=10; i++)
        {
    printf("\n Qual valor quer armazenar na lista? ");
    scanf("%d", &valor);
    lista1 = lst_insere(lista1, valor);
    // ^ Deve-se atualizar a variável que representa a lista a cada inserção.
        }
    lst_imprime(lista1);
    printf("\n Que elemento deseja buscar? ");
    scanf("%d", &valor);
    busca = lst_cria();
    busca = lst_busca(lista1, valor);
    lst_imprime(busca);


}
