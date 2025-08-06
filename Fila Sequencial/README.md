# Fila Sequencial Circular em C++

Este diretório contém uma implementação de fila sequencial circular em C++.

## Arquivos

- **Fila_Sequencial.h / Fila_Sequencial.cpp**: Definição e implementação da classe `FilaSeq`, que gerencia os elementos e operações da fila.
- **main.cpp**: Exemplo de uso da fila sequencial, com menu interativo para manipulação.
- **Makefile**: Facilita a compilação do projeto.

## Operações Disponíveis

- Verificar se a fila está vazia
- Verificar se a fila está cheia
- Obter o primeiro elemento da fila (front)
- Inserir elemento na fila (push)
- Remover elemento da fila (pop)

## Menu de Operações

O programa apresenta o seguinte menu para manipulação da fila:

```
1 - Verificar se a fila esta vazia
2 - Verificar se a fila esta cheia
3 - Obter o primeiro elemento da fila
4 - Inserir elemento na fila
5 - Remover elemento da fila
```

## Compilação

Para compilar manualmente:

```bash
g++ -std=c++17 main.cpp Fila_Sequencial.cpp -o fila_sequencial
```

Ou utilize o Makefile:

```bash
make
```

Para limpar os arquivos gerados:

```bash
make clean
```

## Observações

- O tamanho máximo da fila é definido pelo usuário na execução.
- As operações são circulares, ou seja, o índice retorna ao início quando chega ao final do vetor.
- Execute o programa e siga o menu para testar as operações da fila.
