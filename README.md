# Projeto de Digrafo

## Descrição

Este projeto implementa um digrafo utilizando a linguagem C++. O programa lê um número de vértices e arestas e constrói o digrafo. Em seguida, utiliza o algoritmo de Kosaraju para encontrar componentes fortemente conectadas (CFCs) e cria um grafo condensado, exibindo as conexões entre as CFCs.

## Estrutura dos Arquivos

- `main.cpp`: Contém a função principal que executa o programa.
- `Digrafo.h`: Declarações das classes e funções utilizadas no projeto.
- `Digrafo.cpp`: Implementações das classes e funções declaradas em `Digrafo.h`.
- `Aresta.h`: Declaração da classe `Aresta`, representando uma aresta do grafo.

## Pré-requisitos

Para compilar e executar o projeto, você precisará de:

- Um compilador C++ (ex: `g++` ou `clang++`)

## Instruções de Compilação

### Windows

1. Abra o terminal ou prompt de comando.
2. Navegue até o diretório onde os arquivos estão localizados.
3. Compile o projeto utilizando o seguinte comando:

```bash
g++ *.cpp -o main
./main
```
