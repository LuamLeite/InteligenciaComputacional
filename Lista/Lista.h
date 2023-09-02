#ifndef Lista_h
#define Lista_h

//LISTA DINAMICA ENCADEADA
//A raz�o de n�o ser typedef aqui, � porque inst�ncia uma dentro da outra

struct elemento
{
    int info;
    struct elemento *prox;
};

//Apelido para instancia��o n�o conflituosa de elemento
typedef struct elemento Elemento;

Elemento* lst_cria(void);//Necess�rio para deixar o ponteiro vazio, sem lixo, e mostrar quando a lista est� vazia p�s adi��o de outros componentes.
Elemento* lst_insere(Elemento* lst, int val); //malloca o elemento e transfere os valores
Elemento* lst_imprime(Elemento* lst); //Imprime todos os inteiros at� achar null
int lst_vazia (Elemento* lst); //Teste de lista vazia, retorna 1 se vazia, 0 se n�o vazia.
Elemento* lst_busca(Elemento* lst, int val); //Retorna o n�(ponteiro) que o elemento procurado est� caso ache correspond�ncia, do contr�rio, retorna NULL.
Elemento* lst_remove(Elemento* lst, int v); //Remove elementos
Elemento * lst_libera (Elemento* lst);
Elemento * lst_insere_ordenado (Elemento *lst, int val);
int lst_igual_recursivo (Elemento* lst1, Elemento* lst2);
#endif // Lista_h

