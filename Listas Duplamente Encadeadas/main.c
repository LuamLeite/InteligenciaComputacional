#include <stdio.h>
#include <stdlib.h>
#include "listade.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");
    int numero, i;
    Lstde* lst = NULL;
    Lstde* pesquisa = NULL;
    printf("Digite o número de vezes que quer repetir a inserção: ");
    scanf("%i", &numero);

    for(i=0; numero>i ; i++)
    {
        printf("\n Teste");
        lst = insere_elemento(lst);
    }
    imprimir(lst);

    pesquisa = busca(lst);
    lst = remover(lst);
    imprimir(lst);
    return 0;
}

