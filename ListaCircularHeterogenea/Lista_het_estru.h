        #ifndef lista_het_estru_h
        #define lista_het_estru_h
        #define RET 0
        #define TRI 1
        #define CIR 2
        #define PI 3.1416

        struct retangulo
        {
            float b;
            float h;
        };
        typedef struct retangulo Retang;

        struct circulo
        {
            float r;
        };
        typedef struct circulo Circ;

        struct triangulo
        {
            float b;
            float h;
        };
        typedef struct triangulo Triang;

        typedef struct elemHet //elemento heterogeneo
        {
            int tipo;
            void *info; //ponteiro genérico
            struct elemHet *prox;
            float area;
        }ElemHet;


        //DEFINIÇÃO DAS FUNÇÕES
        ElemHet* cria(ElemHet* p);
        ElemHet* aloca (ElemHet* p, int tipo);
        //ElemHet* aloca_proximo(ElemHet* p); //Obsoleto
        void cria_ret (ElemHet * p,float a, float h);
        void cria_tri (ElemHet * p,float b, float h);
        void cria_cir (ElemHet * p,float r);
        void imprimir (ElemHet* p);
        void circular (ElemHet* p);
        float calc_area (ElemHet *p);
        float max_area(ElemHet *p);
        ElemHet* pesquisa_retang_tri(ElemHet * p, float a, float b);
        ElemHet* pesquisa_circ(ElemHet *p, float r);
        ElemHet* remove_elemento(ElemHet *p);
        ElemHet* remove_retang_tri(ElemHet *p, float b, float h);
        ElemHet* remove_circ(ElemHet *p, int raio);
        ElemHet* libera_lista(ElemHet *p);
        //Um dia adicionar igualdade de listas
        #endif // lista_het_estru_h
