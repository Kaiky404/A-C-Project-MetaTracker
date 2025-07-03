#include "metas.h"
#include <stdio.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void adicionarMeta(Meta *metas, int *qtd) {
    if (*qtd >= MAX_METAS) {
        printf("Limite de metas atingido!\n");
        return;
    }

    Meta nova;
    nova.concluida = 0;
    nova.qtdSubmetas = 0;

    printf("Digite o título da meta: ");
    fgets(nova.titulo, sizeof(nova.titulo), stdin);
    nova.titulo[strcspn(nova.titulo, "\n")] = '\0'; // remove \n

    printf("Digite a descrição da meta: ");
    fgets(nova.descricao, sizeof(nova.descricao), stdin);
    nova.descricao[strcspn(nova.descricao, "\n")] = '\0';

    char resposta;
    printf("Deseja adicionar submetas? (s/n): ");
    scanf(" %c", &resposta);
    limparBuffer();

    if (resposta == 's' || resposta == 'S') {
        for (int i = 0; i < MAX_SUBMETAS; i++) {
            printf("Submeta %d (ou deixe vazio pra parar): ", i + 1);
            fgets(nova.submetas[i], sizeof(nova.submetas[i]), stdin);
            nova.submetas[i][strcspn(nova.submetas[i], "\n")] = '\0';

            if (strlen(nova.submetas[i]) == 0) break;

            nova.qtdSubmetas++;
        }
    }

    metas[*qtd] = nova;
    (*qtd)++;

    printf("\nMeta adicionada com sucesso!\n");
}

void listarMetas(Meta *metas, int qtd) {
    if (qtd == 0) {
        printf("\nNenhuma meta cadastrada ainda.\n");
        return;
    }

    printf("\n====== LISTA DE METAS ======\n");

    for (int i = 0; i < qtd; i++) {
        printf("\nMeta %d:\n", i + 1);
        printf("Título     : %s\n", metas[i].titulo);
        printf("Descrição : %s\n", metas[i].descricao);
        printf("Status     : %s\n", metas[i].concluida ? "Concluída" : "Pendente");

        if (metas[i].qtdSubmetas > 0) {
            printf("Submetas:\n");
            for (int j = 0; j < metas[i].qtdSubmetas; j++) {
                printf("  [%d] %s\n", j + 1, metas[i].submetas[j]);
            }
        }
    }

    printf("\n============================\n");
}


void editarMeta(Meta *metas, int qtd) {
    if (qtd == 0) {
        printf("\nNenhuma meta cadastrada para editar.\n");
        return;
    }

    listarMetas(metas, qtd);
    int indice;
    printf("\nDigite o número da meta que deseja editar: ");
    scanf("%d", &indice);
    limparBuffer();

    if (indice < 1 || indice > qtd) {
        printf("Meta inválida.\n");
        return;
    }

    Meta *m = &metas[indice - 1];

    printf("Editar título atual [%s]: ", m->titulo);
    fgets(m->titulo, sizeof(m->titulo), stdin);
    m->titulo[strcspn(m->titulo, "\n")] = '\0';

    printf("Editar descrição atual [%s]: ", m->descricao);
    fgets(m->descricao, sizeof(m->descricao), stdin);
    m->descricao[strcspn(m->descricao, "\n")] = '\0';

    char opcao;
    printf("Meta está concluída? (s/n): ");
    scanf("%c", &opcao);
    limparBuffer();
    m->concluida = (opcao == 's' || opcao == 'S') ? 1 : 0;

    printf("Deseja editar as submetas? (s/n): ");
    scanf("%c", &opcao);
    limparBuffer();

    if (opcao == 's' || opcao == 'S') {
        m->qtdSubmetas = 0;
        for (int i = 0; i < MAX_SUBMETAS; i++) {
            printf("Nova submeta %d (ou deixe vazio para parar): ", i + 1);
            fgets(m->submetas[i], sizeof(m->submetas[i]), stdin);
            m->submetas[i][strcspn(m->submetas[i], "\n")] = '\0';

            if (strlen(m->submetas[i]) == 0)
                break;

            m->qtdSubmetas++;
        }
    }

    printf("Meta atualizada com sucesso!\n");
}


void excluirMeta(Meta *metas, int *qtd) {
    if (*qtd == 0) {
        printf("\nNenhuma meta para excluir.\n");
        return;
    }

    listarMetas(metas, *qtd);

    int indice;
    printf("\nDigite o número da meta que deseja excluir: ");
    scanf("%d", &indice);
    limparBuffer();

    if (indice < 1 || indice > *qtd) {
        printf("Meta inválida.\n");
        return;
    }

    // Move as metas seguintes uma posição pra trás
    for (int i = indice - 1; i < *qtd - 1; i++) {
        metas[i] = metas[i + 1];
    }

    (*qtd)--;

    printf("Meta excluída com sucesso!\n");
}


void concluirMeta(Meta *metas, int qtd) {
    if (qtd == 0) {
        printf("\nNenhuma meta para concluir.\n");
        return;
    }

    listarMetas(metas, qtd);

    int indice;
    printf("\nDigite o número da meta que deseja marcar como concluída: ");
    scanf("%d", &indice);
    limparBuffer();

    if (indice < 1 || indice > qtd) {
        printf("Meta inválida.\n");
        return;
    }

    Meta *m = &metas[indice - 1];
    if (m->concluida) {
        printf("Essa meta já está marcada como concluída. Deseja marcar como não concluída? (s/n): ");
        char opcao;
        scanf("%c", &opcao);
        limparBuffer();
        if (opcao == 's' || opcao == 'S') {
            m->concluida = 0;
            printf("Meta marcada como não concluída.\n");
        } else {
            printf("Nada alterado.\n");
        }
    } else {
        m->concluida = 1;
        printf("Meta marcada como concluída!\n");
    }
}


void salvarMetas(Meta *metas, int qtd) {
    FILE *arquivo = fopen("data/metas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }

    fprintf(arquivo, "%d\n", qtd); // salva a quantidade

    for (int i = 0; i < qtd; i++) {
        fprintf(arquivo, "%s\n", metas[i].titulo);
        fprintf(arquivo, "%s\n", metas[i].descricao);
        fprintf(arquivo, "%d\n", metas[i].concluida);
        fprintf(arquivo, "%d\n", metas[i].qtdSubmetas);

        for (int j = 0; j < metas[i].qtdSubmetas; j++) {
            fprintf(arquivo, "%s\n", metas[i].submetas[j]);
        }
    }

    fclose(arquivo);
    printf("Metas salvas com sucesso!\n");
}


void carregarMetas(Meta *metas, int *qtd) {
    FILE *arquivo = fopen("data/metas.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum arquivo de metas encontrado.\n");
        return;
    }

    int quantidade;
    fscanf(arquivo, "%d\n", &quantidade);

    if (quantidade > MAX_METAS) {
        printf("Número de metas no arquivo excede o máximo permitido.\n");
        fclose(arquivo);
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fgets(metas[i].titulo, MAX_TITULO, arquivo);
        metas[i].titulo[strcspn(metas[i].titulo, "\n")] = '\0';

        fgets(metas[i].descricao, MAX_DESC, arquivo);
        metas[i].descricao[strcspn(metas[i].descricao, "\n")] = '\0';

        fscanf(arquivo, "%d\n", &metas[i].concluida);
        fscanf(arquivo, "%d\n", &metas[i].qtdSubmetas);

        if (metas[i].qtdSubmetas > MAX_SUBMETAS) {
            printf("Meta %d tem mais submetas do que o permitido. Ignorando submetas extras.\n", i+1);
            metas[i].qtdSubmetas = MAX_SUBMETAS;
        }

        for (int j = 0; j < metas[i].qtdSubmetas; j++) {
            fgets(metas[i].submetas[j], MAX_SUBMETA, arquivo);
            metas[i].submetas[j][strcspn(metas[i].submetas[j], "\n")] = '\0';
        }
    }

    *qtd = quantidade;

    fclose(arquivo);
    printf("Metas carregadas com sucesso!\n");
}


