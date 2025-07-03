# Meta Tracker

Gerenciador de metas e submetas feito em C. Permite adicionar, editar, excluir, listar e marcar como concluídas metas com prioridade. Cada meta pode ter até 10 submetas.

## Funcionalidades
- CRUD de metas e submetas
- Persistência em arquivo (`data/metas.txt`)
- Interface por terminal (modo texto)
- Executável gerado via Makefile (Linux) ou `.exe` (Windows)

## Compilação

```bash
make
```

## Execução

```bash
make run
```

## Estrutura

- `src/`: código-fonte
- `data/`: arquivo com as metas
- `build/`: binários gerados

## Licença

MIT
