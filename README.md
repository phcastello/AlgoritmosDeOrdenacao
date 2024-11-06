# Algoritmos De Ordenacao

Este repositório contém implementações de algoritmos de ordenação em C++, focando em técnicas eficientes e variantes paralelas para grandes conjuntos de dados. Ele inclui três algoritmos principais: Merge Sort, Merge Sort Paralelo e Insertion Sort, Insertion Sort com Busca Binária, além de uma futura implementação de Selection Sort e uma otimização do mesmo algoritmo.

## Estrutura do Repositório

* **Algoritmos**:
  - `mergeSort.cpp`: Implementação sequencial do algoritmo de Merge Sort.
  - `mergeParalelo.cpp`: Implementação paralela do Merge Sort, utilizando múltiplas threads para melhorar o desempenho.
  - `insertionSort.cpp`: Implementação de Insertion Sort sem Busca Binária, uma versão menos otimizada do Insertion Sort.
  - `insertionSortBuscaBinaria.cpp`: Implementação de Insertion Sort com Busca Binária, uma versão otimizada do Insertion Sort padrão.
  - `selectionSort.cpp`: Planejado para inclusão futura.
  - `selectionSortOtimizado.cpp`: Planejado para inclusão futura.

* **Arquivos de Dados**:
  - `aleatorio100k.txt`: Lista desordenada de 100.000 números inteiros.
  - `contagem100k.txt`: Lista de 100.00 números inteiros em ordem decrescente (de 100k a 0), para testar o desempenho dos algoritmos.

* **Executáveis**:
  - `mergeSort.exe`: Executável do Merge Sort padrão.
  - `mergeParalelo.exe`: Executável do Merge Sort paralelizado.
  - `insertionSort.exe`: Executável do Insertion sort padrão.
  - `insertionSortBuscaBinaria.cpp`: Executavel do Insertion Sort
  - `selectionSort.exe`: Executável do Selection Sort padrão.
  - `selectionSortOtimizado.cpp`: Executável do Selection Sort otimizado.

## Algoritmos Implementados

### 1. Merge Sort
Implementação sequencial do algoritmo de Merge Sort, que divide a lista em metades até que cada metade tenha um único elemento e, em seguida, combina as partes em ordem crescente.

* **Arquivo**: `mergeSort.cpp`
* **Funcionamento**:
  1. Divide a lista ao meio recursivamente até que todas as sublistas tenham um único elemento.
  2. Mescla as sublistas em uma única lista ordenada.

### 2. Merge Sort Paralelo
Versão otimizada do Merge Sort que utiliza múltiplas threads para acelerar a ordenação. Até três níveis de profundidade, a divisão do vetor é feita em threads separadas.

* **Arquivo**: `mergeParalelo.cpp`
* **Funcionamento**:
  1. Divide o vetor recursivamente usando threads até o nível de profundidade 3.
  2. Mescla os subvetores em uma thread principal para garantir que os dados fiquem em ordem.     

### 3. Insertion Sort Padrão

Implementação do Insertion Sort tradicional, onde cada elemento é inserido na posição correta através de comparações lineares no subarray ordenado.

- **Arquivo**: `insertion.cpp`
- **Funcionamento**:
  1. Para cada elemento no array, encontra a posição correta no subarray já ordenado.
  2. Desloca os elementos à direita para abrir espaço e insere o elemento na posição correta.


### 4. Insertion Sort com Busca Binária
Insertion Sort que realiza a busca da posição de inserção usando Busca Binária, o que reduz o número de comparações ao longo da ordenação.

* **Arquivo**: `insertionSort.cpp`
* **Funcionamento**:
  1. Para cada elemento, busca a posição correta no subarray ordenado.
  2. Insere o elemento e desloca os demais à direita.



### 5. Selection Sort (Planejado)
Algoritmo de ordenação Selection Sort tradicional, que seleciona o menor elemento e o coloca na posição correta.

* **Arquivo**: `selectionSort.cpp` (planejado)

### 6. Selection Sort Otimizado (Planejado)

Uma versão otimizada do Selection Sort tradicional.

- **Arquivo**: `selectionSortOtimizado.cpp` (planejado)

## Como Utilizar

1. **Compilar os Códigos**: Utilize o comando abaixo para compilar cada arquivo separadamente.
   ```bash
   g++ nomeDoArquivo.cpp -o nomeDoArquivo.exe

2. **Executar os arquvos ".exe"**: Dê um clique duplo em qualquer arquvio .exe ou o execute por linha de comando
   ```bash
   ./nomeDoArquivo.exe
   ```
    por padrão, todos os executaveis usarão a lista **contagem100k.txt**.
     
