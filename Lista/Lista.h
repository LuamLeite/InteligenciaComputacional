#ifndef Lista_h
#define Lista_h

//LISTA DINAMICA ENCADEADA
//A razão de não ser typedef aqui, é porque instância uma dentro da outra

struct elemento
{
    int info;
    struct elemento *prox;
};

//Apelido para instanciação não conflituosa de elemento
typedef struct elemento Elemento;

Elemento* lst_cria(void);//Necessário para deixar o ponteiro vazio, sem lixo, e mostrar quando a lista está vazia pós adição de outros componentes.
Elemento* lst_insere(Elemento* lst, int val); //malloca o elemento e transfere os valores
Elemento* lst_imprime(Elemento* lst); //Imprime todos os inteiros até achar null
int lst_vazia (Elemento* lst); //Teste de lista vazia, retorna 1 se vazia, 0 se não vazia.
Elemento* lst_busca(Elemento* lst, int val); //Retorna o nó(ponteiro) que o elemento procurado está caso ache correspondência, do contrário, retorna NULL.
Elemento* lst_remove(Elemento* lst, int v); //Remove elementos
Elemento * lst_libera (Elemento* lst);
Elemento * lst_insere_ordenado (Elemento *lst, int val);
int lst_igual_recursivo (Elemento* lst1, Elemento* lst2);
#endif // Lista_h

