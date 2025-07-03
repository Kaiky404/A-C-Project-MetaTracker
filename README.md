# 🎯 Meta Tracker

Meta Tracker é um projeto em C desenvolvido para ajudar no gerenciamento de metas pessoais, com suporte para submetas, marcação de conclusão, edição e persistência dos dados em arquivo.

> ⚙️ Projeto feito inteiramente em C, com foco em prática de lógica, modularização, uso de structs e manipulação de arquivos.

---

## ✨ Funcionalidades

- Adicionar meta (com título, descrição e submetas)
- Listar metas
- Editar metas
- Excluir metas
- Marcar como concluída
- Salvar em arquivo (`data/metas.txt`)
- Carregar metas do arquivo
- Interface via terminal

---

## 📁 Estrutura do projeto

```bash
meta-tracker/
├── data/
│   └── metas.txt          # Arquivo salvo das metas
├── src/
│   ├── main.c             # Função principal
│   ├── menu.c/.h          # Lida com o menu e a navegação
│   ├── metas.c/.h         # Todas as funções de manipulação das metas
│   └── utils.c/.h         # Funções utilitárias (ex: limpar buffer)
├── build/                 # Pasta onde o executável é gerado
├── Makefile               # Compilação do projeto
└── README.md              # Este arquivo
