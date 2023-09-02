#ifndef listade_h
#define listade_h

struct lstde
{
    int info;
    struct lstde* ant;
    struct lstde* prox;

};
typedef struct lstde Lstde;

Lstde* insere_elemento(Lstde* p);
void circular(Lstde* p);
void imprimir (Lstde* p);
Lstde* busca (Lstde* p);
Lstde* remover(Lstde* p);
#endif // listade_h


