#ifndef LISTA_HETE
#define LISTA_HETE

typedef struct retangulo Retangulo;
struct retangulo {
    float b;
    float h;
};

typedef struct triangulo Triangulo;
struct triangulo {
    float b;
    float h;
};

typedef struct circulo Circulo;
struct circulo {
    float r;
};

typedef enum tipo Tipo;
enum tipo {
    RET,
    TRI,
    CIRC
};

typedef struct no No;
struct no {
    Tipo tipo;
    void *elem;
    No *prox;
};

typedef struct lista ListaHete;
struct lista {
    ListaHete *ini, fim;
};

#endif
