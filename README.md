# Comparação de Algoritmos de Ordenação em C

## Descrição e objetivo
Programa em C que implementa três algoritmos de ordenação (Bubble Sort, Selection Sort e Insertion Sort) e compara o desempenho de cada um, contando o número de **comparações**, **trocas** e o **tempo de execução** em vetores de 100, 1.000 e 5.000 elementos. O programa também demonstra a **busca binária** em um vetor ordenado.

O projeto foi feito como estudo dos conteúdos de Algoritmos e Estruturas de Dados I (AED I), do curso de Ciência da Computação da PUC Minas, com o objetivo de praticar a linguagem C (vetores, funções, alocação dinâmica) e entender na prática a diferença de custo entre algoritmos de ordenação e a vantagem da busca binária.

## Tecnologias utilizadas
- Linguagem: C (padrão C99 ou superior)
- Compilador: GCC
- Bibliotecas padrão: `stdio.h`, `stdlib.h`, `time.h`

## Como executar
1. Clone o repositório:
   ```
   git clone https://github.com/SEU-USUARIO/NOME-DO-REPOSITORIO.git
   ```
2. Entre na pasta do projeto:
   ```
   cd NOME-DO-REPOSITORIO
   ```
3. Compile e execute:
   ```
   gcc main.c -o programa
   ./programa
   ```
   No Windows, execute com `programa.exe`.

## Exemplo de saída
Para cada tamanho de vetor, o programa imprime uma linha por algoritmo com comparações, trocas e tempo. Ao final, mostra a busca binária em um vetor de 20 elementos.

## Autor
Marcus Felipe Miranda Rocha — Ciência da Computação, PUC Minas
