#ifndef METAS_H
#define METAS_H

#define MAX_METAS 100
#define MAX_SUBMETAS 10

#define MAX_TITULO 100
#define MAX_DESC 256
#define MAX_SUBMETA 100


#define MAX_SUBMETAS 10

typedef struct {
    char titulo[100];
    char descricao[256];
    int concluida;
    char submetas[MAX_SUBMETAS][100];
    int qtdSubmetas;
} Meta;

// Declarações das funções (a serem implementadas em metas.c)
void adicionarMeta(Meta *metas, int *qtd);
void listarMetas(Meta *metas, int qtd);
void editarMeta(Meta *metas, int qtd);
void excluirMeta(Meta *metas, int *qtd);
void concluirMeta(Meta *metas, int qtd);
void salvarMetas(Meta *metas, int qtd);
void carregarMetas(Meta *metas, int *qtd);

#endif
