\# Sistema de Monitoramento de Estações Meteorológicas



Projeto de um sistema para coletar, armazenar, processar e analisar leituras de estações meteorológicas, além de detectar leituras anômalas que possam indicar falhas em sensores ou eventos climáticos relevantes.



\## Compilação



```bash

gcc main.c -o estacoes -lm

```

> A flag `-lm` é obrigatória para vincular a biblioteca matemática (`math.h`), usada pelas funções `sqrt`, `pow` e `fabsf`.



\## Execução



```bash

\# Linux/Mac

./estacoes



\# Windows

estacoes.exe

```



\## Funcionamento geral



Ao iniciar o programa exibe um menu numérico, onde o usuário deve selecionar a opção desejada com base nos números indicados, o programa solicita as informações da estação, permitindo cadastrá-las, editá-las, removê-las e salvá-las em CSV.



\## Descrição das funções



\### `float mediaComRecursiva(float \*leituras, int n)`

Calcula a média de um vetor de leituras de forma recursiva.

\- \*\*Entrada:\*\* vetor de floats `leituras` e quantidade de elementos `n`.

\- \*\*Saída:\*\* retorna a média como `float`.



\### `void calcularVariancia(Estacao \*e)`

Calcula a variância das leituras de uma estação e armazena o resultado em `e->variancia`.

\- \*\*Entrada:\*\* ponteiro para uma struct `Estacao` com média já calculada.

\- \*\*Saída:\*\* nenhuma (atualiza o campo `variancia` da struct).



\### `void calcularDesvioP(Estacao \*e)`

Calcula o desvio padrão a partir da variância já calculada e armazena em `e->desvioPadrao`.

\- \*\*Entrada:\*\* ponteiro para uma struct `Estacao` com variância já calculada.

\- \*\*Saída:\*\* nenhuma (atualiza o campo `desvioPadrao` da struct).



\### `void adicionarEstacao(Estacao \*e)`

Cadastra uma nova estação meteorológica, solicitando todos os dados ao usuário e calculando automaticamente as estatísticas.

\- \*\*Entrada:\*\* ponteiro para uma struct `Estacao` vazia.

\- \*\*Saída:\*\* nenhuma (preenche os campos da struct com os dados fornecidos).



\### `void listarEstacoes(Estacao \*estacoes, int total)`

Percorre o vetor de estações e exibe todos os dados de cada uma na tela.

\- \*\*Entrada:\*\* vetor de estações e quantidade total de estações cadastradas.

\- \*\*Saída:\*\* nenhuma (imprime os dados na tela).



\### `void editarEstacoes(Estacao \*estacoes, int total)`

Busca uma estação pelo ID e permite alterar nome, operador, sensor e data.

\- \*\*Entrada:\*\* vetor de estações e quantidade total.

\- \*\*Saída:\*\* nenhuma (atualiza os campos da estação encontrada).



\### `void excluirEstacao(Estacao \*estacoes, int \*total)`

Busca uma estação pelo ID e a remove do vetor, substituindo-a pela última estação cadastrada.

\- \*\*Entrada:\*\* vetor de estações e ponteiro para o total.

\- \*\*Saída:\*\* nenhuma (remove a estação e decrementa o total).



\### `void buscarPorOperador(Estacao \*estacoes, int total)`

Lista todas as estações associadas a um determinado operador.

\- \*\*Entrada:\*\* vetor de estações, total e nome do operador digitado pelo usuário.

\- \*\*Saída:\*\* nenhuma (imprime os dados das estações encontradas).



\### `void detectarAnomalias(Estacao \*estacoes, int total)`

Lista as leituras de uma estação que se afastam da média em mais de dois desvios padrão.

\- \*\*Entrada:\*\* vetor de estações e total.

\- \*\*Saída:\*\* nenhuma (imprime as leituras anômalas encontradas).



\### `void salvarnoCSV(Estacao \*estacoes, int total)`

Grava todas as estações em um arquivo `estacoes.csv` no formato CSV.

\- \*\*Entrada:\*\* vetor de estações e total.

\- \*\*Saída:\*\* nenhuma (cria ou sobrescreve o arquivo `estacoes.csv`).



\### `void carregarCSV(Estacao \*estacoes, int \*total)`

Lê o arquivo `estacoes.csv` e restaura as estações pna memória.

\- \*\*Entrada:\*\* vetor de estações e ponteiro para o total.

\- \*\*Saída:\*\* nenhuma (preenche o vetor com os dados do arquivo).



\## Opções do menu



| Opção | Funcionalidade |

|-------|----------------|

| 1 | Adicionar estação  |

| 2 | Editar estação     |

| 3 | Excluir estação    |

| 4 | Listar estações    |

| 5 | Buscar por operador|

| 6 | Detectar anomalias |

| 7 | Salvar CSV         |

| 8 | Carregar CSV       |

| 0 | Sair               |



\## Entradas e saídas



\- \*\*Entradas:\*\* dados digitados pelo usuário via teclado — id (`int`), strings (`char\[]`), datas (`int`), leituras (`float`).

\- \*\*Saídas:\*\* dados exibidos na tela e persistidos em arquivo CSV.



\## Tratamento de erros



\- \*\*ID inválido:\*\* valores fora do intervalo \[0, 9999] são rejeitados.

\- \*\*Data inválida:\*\* dia, mês e ano são validados individualmente, incluindo anos bissextos.

\- \*\*Quantidade de leituras inválida:\*\* valores fora do intervalo \[1, 9998] são rejeitados.

\- \*\*Erro de memória:\*\* falha no `malloc` é tratada com mensagem de erro.

\- \*\*Arquivo não encontrado:\*\* falha ao abrir o CSV é tratada com mensagem de erro.

\- \*\*Estação não encontrada:\*\* buscas por ID ou operador inexistentes exibem mensagem adequada.



\## Exemplo de uso



```

||1. Adicionar estacao  ||

||2. Editar estacao     ||

||3. Excluir estacao    ||

||4. Listar estacoes    ||

||5. Buscar por Operador||

||6. Detectar anomalias ||

||7. Salvar CSV         ||

||8. Carregar CSV       ||

||0. Sair               ||

1

ID (0-9999): 1

Nome da estacao: EstacaoNorte

Operador: Talita

Sensor: temperatura

Ano (1900-2100): 2025

Mes (1-12): 10

Dia: 12

Quantidade de leituras: 3

Leitura 1: 20.5

Leitura 2: 22.0

Leitura 3: 21.5

```

