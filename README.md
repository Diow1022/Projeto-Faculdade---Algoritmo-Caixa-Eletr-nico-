# Sistema de Caixa Eletrônico (ATM) em Linguagem C

## Sobre o Projeto

Este projeto consiste no desenvolvimento de um **simulador de caixa eletrônico (ATM)** utilizando a linguagem de programação C.

O sistema permite realizar simulações de saques bancários, verificando a validade do valor solicitado, o saldo disponível e calculando a distribuição de cédulas e moedas necessárias para completar a operação.

O projeto foi desenvolvido como parte da disciplina **Algoritmos e Pensamento Computacional (APC)**, com o objetivo de aplicar conceitos fundamentais de programação, estruturas condicionais, operações matemáticas e validação de dados.

## Objetivos

- Desenvolver um sistema de simulação de saques bancários.
- Aplicar conceitos de lógica de programação em linguagem C.
- Implementar validações para operações financeiras simuladas.
- Calcular a distribuição de cédulas e moedas.
- Utilizar operadores de divisão inteira e módulo.
- Realizar testes para verificar a confiabilidade do algoritmo.
- Tratar entradas inválidas e operações que excedam o saldo disponível.

## Tecnologias Utilizadas

| Tecnologia | Aplicação |
|---|---|
| Linguagem C | Desenvolvimento do algoritmo |
| GCC | Compilação do código-fonte |
| Terminal | Entrada e saída de informações |
| Operadores aritméticos | Cálculo de cédulas e moedas |
| Estruturas condicionais | Validação e controle das operações |

## Funcionamento do Sistema

O programa simula um caixa eletrônico com saldo inicial fixo de **R$ 1.000,00**.

O usuário informa o valor que deseja sacar e o sistema verifica se a operação pode ser realizada.

### Regras de Validação

O sistema verifica:

1. Se a entrada contém um número inteiro válido.
2. Se o valor solicitado é maior que zero.
3. Se o valor não ultrapassa o saldo disponível.
4. Se o valor pode ser representado pelas cédulas e moedas disponíveis.

Após a validação, o programa calcula a distribuição do valor solicitado, utilizando as seguintes denominações:

| Tipo | Valor |
|---|---|
| Cédula | R$ 100 |
| Cédula | R$ 50 |
| Cédula | R$ 20 |
| Cédula | R$ 10 |
| Cédula | R$ 5 |
| Cédula | R$ 2 |
| Moeda | R$ 1 |

O algoritmo utiliza divisões inteiras e operações de módulo para calcular as quantidades necessárias.

Somente as cédulas e moedas com quantidade superior a zero são apresentadas ao usuário.

## Lógica do Algoritmo

A distribuição das cédulas é realizada de maneira sequencial, começando pelas maiores denominações.

Para cada denominação, o programa:

1. Divide o valor restante pela denominação atual.
2. Armazena a quantidade obtida.
3. Calcula o restante utilizando o operador módulo (`%`).
4. Repete o processo com a próxima denominação.
5. Exibe apenas as quantidades diferentes de zero.

Essa abordagem permite distribuir o valor solicitado utilizando a menor quantidade de cédulas e moedas para as denominações adotadas.

### Exemplo de Execução

**Entrada:**

```text
Digite o valor do saque: 123
```

**Saída:**

```text
Notas entregues:
1 nota(s) de 100
1 nota(s) de 20
1 nota(s) de 2
1 moeda(s) de 1
```

**Resultado:**

```text
100 + 20 + 2 + 1 = 123
```

A operação foi concluída utilizando quatro unidades monetárias.

## Testes e Validação

Foram realizados testes funcionais para verificar o comportamento do sistema diante de diferentes entradas.

### Testes Principais

| Entrada | Cenário | Resultado | Status |
|---|---|---|---|
| R$ 50 | Saque válido | 1 nota de R$ 50 | Aprovado |
| R$ 95 | Saque válido | 1 nota de R$ 50, 2 de R$ 20 e 1 de R$ 5 | Aprovado |
| R$ 123 | Saque válido | 1 nota de R$ 100, 1 de R$ 20, 1 de R$ 2 e 1 moeda de R$ 1 | Aprovado |
| R$ 1.005 | Saldo insuficiente | Operação recusada | Aprovado |

### Testes Complementares

Além dos cenários principais, foram realizados testes adicionais para avaliar a validação das entradas.

| Entrada | Cenário | Resultado |
|---|---|---|
| 285 | Saque válido | Distribuição correta das cédulas |
| 0 | Valor inválido | Operação recusada |
| -5 | Valor negativo | Operação recusada |
| abc | Entrada não numérica | Operação recusada |

Todos os cenários apresentaram os resultados esperados.

## Tratamento de Erros

O programa possui verificações para impedir operações inválidas.

**Saldo insuficiente:**

```text
Digite o valor do saque: 1005
