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
    printf("Digite o n�mero de vezes que quer repetir a inser��o: ");
    scanf("%i", &numero);

    for(i=0; numero>i ; i++)
    {
        //printf("\n Teste");
        lst = insere_elemento(lst);
    }
    circular(lst);
    imprimir(lst);

    pesquisa = busca(lst);
    lst = remover(lst);
    imprimir(lst);
    imprimir_inverso(lst);
    //printf("\n %i %i %i %i %i %i", lst->ant->info, lst->ant->ant->info, lst->ant->ant->ant->info, lst->ant->ant->ant->ant->info, lst->ant->ant->ant->ant->ant->info, lst->ant->ant->ant->ant->ant->ant->info);
    return 0;
}

