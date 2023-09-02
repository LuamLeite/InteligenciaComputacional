            #include "Lista_het_estru.h"
            #include <stdlib.h>
            #include <stdio.h>
            #define PI 3.1416
            ElemHet* cria(ElemHet* p)
            {
                return NULL;
            }
            ElemHet* aloca_insere (ElemHet* p, int tipo)
            {
                ElemHet* novo = (ElemHet*)malloc(sizeof(ElemHet));
                novo->prox = p;
                novo->tipo = tipo;
                return novo;
            }
            void cria_ret (ElemHet * p,float a, float h)
            {
                Retang* r;
                r = (Retang*)malloc(sizeof(Retang));
                r->b = a;
                r->h = h;
                p->info = r;
                p->area = calc_area(p);

            }

            void cria_tri (ElemHet * p,float b, float h)
            {
                Triang* t = (Triang*) malloc(sizeof(Triang));
                t->b = b;
                t->h = h;
                p->info = t;
                p->area = calc_area(p);
            }

            void cria_cir (ElemHet * p,float r)
            {
                Circ *c = (Circ*) malloc(sizeof(Circ));
                c->r = r;
                //printf("\n TESTE: RAIO: %2.f", r);
                p->info = c;
                 p->area = calc_area(p);
            }

            /*(ElemHet* aloca_proximo(ElemHet* p)
            {
             ElemHet* novo = (ElemHet*) malloc(sizeof(ElemHet));
             novo->prox = p->prox;
             return novo;
            }*/

            void imprimir (ElemHet* p)
            {
                float rarea;
                ElemHet *a;
                a = p;
                if(p == NULL)
                {
                    printf("\n Lista vazia");
                    return NULL;
                }
                for(a = p; a!=NULL; a=a->prox)
                {
                    switch(a->tipo)
                 {
             case 0:
                 printf("\n É um Retângulo");
                 Retang *r = (Retang*) a->info; //Cast de p->info para Retang
                 printf("\n Base: %2.f, Altura: %2.f", r->b, r->h);
                 //rarea = area(p);
                 printf("\n A area é: %2.f", a->area);
                 break;
             case 1:
                printf("\n É um Triângulo");
                 Triang *t = (Triang*) a->info; //Cast de p->info para Triang
                 printf("\n Base: %2.f, Altura: %2.f", t->b, t->h);
                 //rarea = area(p);
                 printf("\n A area é: %2.f", a->area);
                 break;
             case 2:
                printf("\n É um Circulo");
                 Circ *c = (Circ*) a->info; //Cast de p->info para Triang
                 printf("\n Raio: %2.f", c->r);
                 //rarea = area(p);
                 printf("\n A area é: %2.f", a->area);
                 break;
                 }
                }
                rarea = max_area(p);
                printf("\n A area máxima é: %2.f", rarea);

            }


            float calc_area (ElemHet *p)
            {
                float farea = 0;
                switch(p->tipo)
                 {
             case 0:;
                 Retang *r = (Retang*) p->info; //Cast de p->info para Retang
                 farea = (r->b * r->h)/2;
                 //printf("\n A area é: %f", farea);
                 break;
             case 1:;
                 Triang *t = (Triang*) p->info; //Cast de p->info para Triang
                 farea = (t->b * t->h)/2;
                 //printf("\n A area é: %f", farea);
                 break;
             case 2:;
                 Circ *c = (Circ*) p->info; //Cast de p->info para Triang
                 //printf("\TESTE, RAIO: %f", c->r);
                 farea = c->r * c->r * PI;
                 //printf("\n A area é: %f", farea);
                 break;
                 }
                 return farea;
            }
            float max_area(ElemHet *p)
            {
                float ar, amax = 0;
            for(p; p!=NULL; p=p->prox)
                {
                    ar = calc_area(p);
                    if(ar>amax)
                        amax = ar;
                }
                return amax;
            }

            ElemHet* pesquisa_retang_tri(ElemHet * p, float a, float b)
            {
                for(p; p!=NULL; p=p->prox)
                {
                switch(p->tipo)
                {
                 case 0:;
                 Retang *r = (Retang*) p->info; //Cast de p->info para Retang
                    if(r->b == a && r->h ==b)
                        return p;
                 break;
                 case 1:;
                 Triang *t = (Triang*) p->info; //Cast de p->info para Triang
                  if(t->b == a && t->h ==b)
                    return p;
                 break;

                 case 2:
                 break;
                 }
                }
                return NULL;
            }

            ElemHet* pesquisa_circ(ElemHet *p, float r)
            {
                 for(p; p!=NULL; p=p->prox)
                {
                Circ *c = (Circ*) p->info; //Cast de p->info para Circ
                 if(c->r == r)
                    return p;
                }
                    return NULL;
            }

        ElemHet* remove_retang_tri(ElemHet* p, float b, float h)
        {
            ElemHet* a;
            ElemHet* deletado;
            ElemHet* ant = NULL;
            for(a = p; a!=NULL; a=a->prox)
                {
                    //printf("\n Checkpoint 1");
                    switch(a->tipo)
                    {
                        case 0:;
                            //printf("\n Checkpoint 2");
                 Retang *r = (Retang*) a->info; //Cast de p->info para Retang
                if(r->b == b && r->h == h)
                    {
                        if(ant == NULL)
                        {
                            deletado = a;
                            a = a->prox;
                            //free(deletado->info);
                            //free(deletado);
                            printf("\n Elemento inicial deletado");
                            return a;
                            break;
                        }
                        ant->prox = a->prox;
                        deletado = a;
                        free(a->info);
                        free(a);
                        printf("\n Elemento deletado");
                        return p;
                        break;
                    }
                        case 1:;
                        Triang *t = (Retang*) a->info; //Cast de p->info para Triang
                        if(t->b == b && t->h == h)
                    {
                        if(ant == NULL)
                        {
                            deletado = a;
                            a = a->prox;
                            //free(deletado->info);
                            //free(deletado);
                            printf("\n Elemento inicial deletado");
                            return a;
                            break;
                        }
                        ant->prox = a->prox;
                        deletado = a;
                        free(a->info);
                        free(a);
                        printf("\n Elemento deletado");
                        return p;
                        break;
                    }
                        case 2:
                            break;
                    ant = a;
                 }
                 }
                 printf("\n Elemento não encontrado");
                 return a;
        }

        ElemHet* remove_circ(ElemHet* p,int raio)
        {
            ElemHet* a;
            ElemHet* deletado;
            ElemHet* ant = NULL;
            for(a = p; a!=NULL; a=a->prox)
                {
                 Circ *c = (Circ*) a->info; //Cast de p->info para Triang
                if(c->r == raio)
                    {
                        if(ant == NULL)
                        {
                            deletado = a;
                            a = a->prox;
                            //free(deletado->info);
                            //free(deletado);
                            printf("\n Elemento inicial deletado");
                            return a;
                            break;
                        }
                        ant->prox = a->prox;
                        deletado = a;
                        free(a->info);
                        free(a);
                        printf("\n Elemento deletado");
                        return p;
                    }
                    ant = a;
                 }
                 printf("\n Elemento não encontrado");
                 return a;

        }

        ElemHet* libera_lista(ElemHet *p)
        {
                ElemHet *a;
                ElemHet *temp = NULL;
                a = p;
                for(a = p; a!=NULL; a=a->prox)
                {
                   temp = a;
                   free(temp);
                   free(a->info);

                }
                free(temp);
                return NULL;
        }
