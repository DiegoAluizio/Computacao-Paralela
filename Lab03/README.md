# Read me do Laboratório

## Lab 02b - Pthreads
Read me para a entrega do laboratório de pthreads. Realizado por Diego Oliveira Aluizio.

## Como Compilar:
Escrever o comando de compilação do C no terminal linux + nome do arquivo, que gerará um arquivo de saída:

Exemplo: gcc Multi1Pthreads.c

## Como executar:
./nome do arquivo de saída:

Exemplo: ./a.out

# 1. Qual o tempo de execução serial e paralelo para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico contendo todos os tempos de execução

O código serial está na pasta CodigoSerial deste repositório.
O código paralelo da entrega da semana passada está na pasta CodigoLegado deste repositório.

## Prints dos tempos de execução disponíveis nas pastas PrintsSerial e PrintsVMOriginal deste repositório

## Gráfico Serial:

<img src="https://github.com/DiegoAluizio/Computacao-Paralela/blob/main/Lab03/Graficos/GraficoSerial.png" alt="Gráfico Serial">

## Gráfico Paralelo:

<img src="https://github.com/DiegoAluizio/Computacao-Paralela/blob/main/Lab03/Graficos/GraficoVMOriginal.png" alt="Gráfico Paralelo">

# 2. Qual o speedup para 1, 2, 4, 6 e 8 processadores? Desenhe um gráfico mostrando os diferentes valores de speedup.

Não houve speedup. A performance do programa piorou com a implementação de threads.
Houve uma perda de: 0.016 , 0.021 , 0.014 e 0.026 segundos para 1, 2, 4, 6 e 8 processadores, respectivamente.

## Gráfico:

<img src="https://github.com/DiegoAluizio/Computacao-Paralela/blob/main/Lab03/Graficos/GraficoSpeedupSerialParalelo.png" alt="Gráfico Speedup 1">

# 3. Como você acha que poderia melhorar o seu algoritmo para obter maior benefício com o paralelismo? Para provar seu ponto, refaça a solução com essa abordagem e construa um novo gráfico de speedup para 1, 2, 4, 6 e 8 processadores.

A otimização da segunda versão do código foi feita através da diminuição do número de threads. Para isso, foi utilizado o comando sysconf(_SC_NPROCESSORS_ONLN) da biblioteca unistd que retorna quantas cpus estão disponíveis para o uso. Com essa informação em mãos, o programa divide as as linhas e cria exatamente esse número de threads. Com isso, obtivemos um ganho de 0.011 , 0.028 , 0.022 , 0.038 e 0.040 segundos para 1, 2, 4, 6 e 8 processadores, respectivamente.

O código desta versão está na pasta CodigoAtualizado deste repositório.

Comando descoberto através deste fórum: https://www.linuxquestions.org/questions/programming-9/how-to-get-the-number-of-cores-using-c-874749/#:~:text=C%20is%20pretty.-,Code%3A,all%20kinds%20of%20configuration%20stuff.

## Prints tempo de execução disponíveis na pasta PrintsVMAtualizado deste repositório

## Gráfico Tempos de Execução:

<img src="https://github.com/DiegoAluizio/Computacao-Paralela/blob/main/Lab03/Graficos/GraficoVMnovo.png" alt="Gráfico Novo">

## Gráfico Speedup:

<img src="https://github.com/DiegoAluizio/Computacao-Paralela/blob/main/Lab03/Graficos/GraficoSpeedupNovoCodigo.png" alt="Gráfico Speedup 2">

# Dados da CPU:

Processador da VM: Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz

<img src="https://github.com/DiegoAluizio/Computacao-Paralela/blob/main/Lab03/DadosDaCPU.png" alt="Dados da CPU">

## Nota:
Nesse repositório há uma pasta chamada "PrintsVostro". Nela, estão os tempos de execução da máquina disponível no prédio 31, coletados no dia do laboratório. Como não pude testar os outros códigos nela, nem mudar o número de linhas da matriz para uma comparação justa nela, optei por apenas deixar os prints no repositório para provar os testes de aula.
