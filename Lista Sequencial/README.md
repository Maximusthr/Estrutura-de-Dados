# Lista Sequencial em C++

Este projeto implementa uma lista sequencial (vetorial) em C++.

## Arquivos

- **Lista_Sequencial.cpp / Lista_Sequencial.h**: Implementação da estrutura e métodos da lista sequencial.
- **main.cpp**: Exemplo de uso e menu interativo para manipulação da lista.

## Estrutura do Código

As principais operações disponíveis são:
- **Criação e Inicialização**: Instanciação da lista com tamanho máximo definido.
- **Inserção**: Adiciona elementos em posições específicas.
- **Remoção**: Remove elementos da lista.
- **Busca**: Procura elementos ou retorna o índice de um elemento.
- **Exibição**: Mostra todos os elementos da lista.

## Menu de Operações

O programa apresenta o seguinte menu para manipulação da lista:

```
1 - Lista Vazia
2 - Lista Cheia
3 - Tamanho da Lista
4 - Indice de um elemento na lista (Insira o elemento)
5 - Elemento da lista (Insira o indice)
6 - Atualizando elemento da lista (Insira elemento, indice)
7 - Inserindo elemento na lista dado a posicao (Insira elemento, indice)
8 - Removendo elemento da lista (insira o indice)
```

## Compilação Manual

Compile com o comando abaixo:

```bash
g++ -std=c++17 main.cpp Lista_Sequencial.cpp -o lista
```

## Compilação com Makefile

Para compilar usando o Makefile, execute no terminal:

```bash
make
```

Para remover os arquivos gerados pela compilação:

```bash
make clean
```

## Casos de testes

Foram adicionados uma pasta contendo alguns casos de testes e seus respectivos resultados para validação.
