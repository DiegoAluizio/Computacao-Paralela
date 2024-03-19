# Read me do Laboratório

## Lab 02b - Pthreads
Read me para a entrega do laboratório de pthreads. Realizado por Diego Oliveira Aluizio.

## Como Compilar:
Escrever o comando de compilação do C no terminal linux + nome do arquivo, que gerará um arquivo de saída:
Exemplo: gcc Multi1Pthreads.c

## Como executar:
./nome do arquivo de saída:
exemplo: ./a.out

# 1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução

O código serial está na pasta <preencher>
O código paralelo da entrega da semana passada está na pasta <preencher>

## Tempos de execução em serial:

place holder prints

## Grafico:

place holder

## Tempos de execução em paralelo

place holder

place holder gráfico

# 2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.

?????????????

# 3. Como você acha que poderia melhorar o seu algoritmo para obter maior benefício com o paralelismo? Para provar seu ponto, refaça a solução com essa abordagem e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.

A otimização da segunda versão do código foi feita através da diminuição do número de threads. Para isso, foi utilizado o comando sysconf(_SC_NPROCESSORS_ONLN) da biblioteca unistd que retorna quantas cpus estão disponíveis para o uso. Com essa informação em mãos, o programa divide as as linhas e cria exatamente esse número de threads.

O código desta versão está na pasta CodigoAtualizado deste repositório

## Prints tempo de execução:

Place holder prints

## Gráfico:

place holder gráfico

# Dados da CPU:

Processador da VM: Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz

place holder print do terminal com os dados da cpu
