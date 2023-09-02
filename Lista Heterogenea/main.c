    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>
    #include "Lista_het_estru.h"
    int main()
    {
    setlocale(LC_ALL, "");
    int i, tipo;
    float base, altura, raio;
    ElemHet* Lsthet = cria(Lsthet);
    ElemHet* inicio;
    ElemHet* pesquisa = NULL;
    ElemHet* listatemp = NULL;
      //alocando ponteiro da listaHeterogenea

      for(i=0; i<5; i++)
      {
     do
     {
     printf("\n Digite o n�mero correspondente ao tipo que deseja:");
     printf("\n Ret�ngulo = 0");
     printf("\n Tri�ngulo = 1");
     printf("\n Circulo = 2 \n");
     scanf("%i", &tipo);
    // if(tipo<0 && tipo<3);
     //printf("\n N�mero inv�lido, tente novamente. \n");
     }
     while(tipo>0 && tipo>3 || tipo<0 && tipo<3); //Wow, got me confused
        Lsthet = aloca_insere(Lsthet, tipo);
        inicio = Lsthet;
        printf("\n Tipo: %i", Lsthet->tipo);
     //Dependendo da escolha
     switch(tipo)
     {
     case 0:
        printf("\n Digite o valor da base do ret�ngulo: ");
        scanf("%f", &base);
        printf("\n Digite o valor da altura do ret�ngulo: ");
        scanf("%f", &altura);
        cria_ret(Lsthet, base, altura);
        break;
     case 1:
        printf("\n Digite o valor da base do tri�ngulo: ");
        scanf("%f", &base);
        printf("\n Digite o valor da altura do tri�ngulo: ");
        scanf("%f", &altura);
        cria_tri(Lsthet, base, altura);
        break;
     case 2:
        printf("\n Digite o valor do raio do c�rculo: ");
        scanf("%f", &raio);
        cria_cir(Lsthet, raio);
        break;
     }
     }
     imprimir(Lsthet);
     inicio = Lsthet;
     do
     {
         getch();
    printf("\n PESQUISA ELEMENTO");
    printf("\n Digite o n�mero correspondente ao tipo que deseja pesquisar:");
     printf("\n Ret�ngulo = 0");
     printf("\n Tri�ngulo = 1");
     printf("\n Circulo = 2 \n");
     scanf("%i", &tipo);
    }
     while(tipo>0 && tipo>3 || tipo<0 && tipo<3);
     switch(tipo)
     {
     case 0:
        printf("\n Digite o valor da base do ret�ngulo que quer pesquisar: ");
        scanf("%f", &base);
        printf("\n Digite o valor da altura do ret�ngulo: ");
        scanf("%f", &altura);
        pesquisa = pesquisa_retang_tri(Lsthet, base, altura);
        if(pesquisa!=NULL)
        {
        printf("\n Elemento encontrado!");
        }
        else
        {
            printf("\n Elemento n�o encontrado");
        }

        break;
     case 1:
        printf("\n Digite o valor da base do tri�ngulo que quer pesquisar: ");
        scanf("%f", &base);
        printf("\n Digite o valor da altura do tri�ngulo: ");
        scanf("%f", &altura);
        pesquisa = pesquisa_retang_tri(Lsthet, base, altura);
        if(pesquisa!=NULL)
        {
        printf("\n Elemento encontrado!");
        }
        else
        {
            printf("\n Elemento n�o encontrado");
        }
        break;
     case 2:
        printf("\n Digite o valor do raio do c�rculo que quer pesquisar: ");
        scanf("%f", &raio);
         pesquisa = pesquisa_circ(Lsthet, raio);
         if(pesquisa!=NULL)
        {
        printf("\n Elemento encontrado!");
        }
        else
        {
            printf("\n Elemento n�o encontrado");
        }
        break;
     }

    getch();
    imprimir(inicio);
     do
     {
    printf("\n DELETA ELEMENTO");
    printf("\n Digite o n�mero correspondente ao tipo que deseja deletar:");
     printf("\n Ret�ngulo = 0");
     printf("\n Tri�ngulo = 1");
     printf("\n Circulo = 2 \n");
     scanf("%i", &tipo);
    }
     while(tipo>0 && tipo>3 || tipo<0 && tipo<3);
     switch(tipo)
     {
     case 0:
        printf("\n Digite o valor da base do ret�ngulo que quer deletar: ");
        scanf("%f", &base);
        printf("\n Digite o valor da altura do ret�ngulo: ");
        scanf("%f", &altura);
        Lsthet = remove_retang_tri(Lsthet, base, altura);
        break;
     case 1:
        printf("\n Digite o valor da base do tri�ngulo que quer deletar: ");
        scanf("%f", &base);
        printf("\n Digite o valor da altura do tri�ngulo: ");
        scanf("%f", &altura);
        Lsthet = remove_retang_tri(Lsthet, base, altura);
        break;
     case 2:
        printf("\n Digite o valor do raio do c�rculo que quer deletar: ");
        scanf("%f", &raio);
         Lsthet = remove_circ(Lsthet, raio);
        break;
     }
     imprimir(Lsthet);
     Lsthet = libera_lista(Lsthet);
     imprimir(Lsthet);
    }
