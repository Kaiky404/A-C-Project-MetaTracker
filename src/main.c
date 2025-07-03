#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "metas.h"

#define MAX_METAS 100

int main() {
    Meta metas[MAX_METAS];
    int qtdMetas = 0;
    int opcao;

    while (1) {
        mostrarMenu();
        scanf("%d", &opcao);
        getchar(); // limpar buffer do Enter

        switch (opcao) {
            case 1:
                adicionarMeta(metas, &qtdMetas);
                break;
            case 2:
                listarMetas(metas, qtdMetas);
                break;
            case 3:
                editarMeta(metas, qtdMetas);
                break;
            case 4:
                excluirMeta(metas, &qtdMetas);
                break;
            case 5:
                concluirMeta(metas, qtdMetas);
                break;
            case 6:
                salvarMetas(metas, qtdMetas);
                break;
            case 7:
                carregarMetas(metas, &qtdMetas);
                break;
            case 8:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }

        printf("\nPressione Enter para continuar...");
        getchar();
    }

    return 0;
}
