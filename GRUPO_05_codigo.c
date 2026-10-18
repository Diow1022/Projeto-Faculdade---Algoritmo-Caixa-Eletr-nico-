/*
 * ATIVIDADE 2 - SISTEMA DE CAIXA ELETRONICO (ATM)
 * Componente: Algoritmos e Pensamento Computacional (APC)
 * Arquivo: GRUPO_05_codigo.c
 * Integrantes Grupo 5: 
 *   Christian Badolato Santos/RGM: 47224011,
 *   Davi Barros Correia/RGM: 47204885,
 *   Guilherme Pereira Ferreira da Silva/RGM: 47228903,
 *   Jonatas do Nascimento Lima/RGM: 46929720,
 *   Matheus Pedrosa dos Reis/RGM: 46784721,
 *   Pablo Orlando Bizari Di Sisto/RGM: 46695737,
 *   Vithor Hugo Moreno de Carvalho/RGM: 46761926.
 * 
 * Descricao:
 *   Simula um caixa eletronico. Le o valor do saque, valida e calcula a
 *   menor quantidade de cedulas (100, 50, 20, 10, 5 e 2) e moedas de 1, exibindo
 *   apenas as notas cuja quantidade seja maior que zero.
 */

#include <stdio.h>   // biblioteca de entrada e saida (printf, scanf)

int main() {

    /* ---------------------------------------------------------
     * PASSO 1: DECLARACAO DE VARIAVEIS
     * Todas sao do tipo int, pois lidamos com valores inteiros.
     * --------------------------------------------------------- */
    int saldo = 1000;   // saldo disponivel na conta (valor fixo para os testes)
    int menorMoeda = 1; // menor moeda disponivel no caixa
    int saque;          // valor que o usuario deseja sacar
    int resto;          // valor que ainda falta distribuir em notas

    // contadores: quantidade de cada tipo de cedula/moeda
    int n100, n50, n20, n10, n5, n2, m1;

    /* ---------------------------------------------------------
     * PASSO 2: LEITURA DO VALOR DO SAQUE
     * --------------------------------------------------------- */
    printf("Digite o valor do saque: ");

    // scanf devolve quantos valores leu com sucesso; se nao for 1,
    // o usuario digitou algo que nao e um numero inteiro (ex.: letras)
    if (scanf("%d", &saque) != 1) {
        printf("Erro: entrada invalida. Digite apenas numeros inteiros.\n");
        return 1;   // encerra o programa sinalizando erro
    }

    /* ---------------------------------------------------------
     * PASSO 3: VALIDACAO DOS DADOS
     * 3.1 O valor precisa ser maior que zero
     * 3.2 O valor precisa ser multiplo da menor cedula/moeda (saque % menorMoeda)
     *     Como existem cedula de 2 e moeda de 1, a menor e 1 e todo valor
     *     inteiro positivo e multiplo dela, ou seja, pode ser pago.
     * 3.3 O valor precisa ser menor ou igual ao saldo disponivel
     * --------------------------------------------------------- */
    if (saque <= 0) {

        // zero ou negativo nao e um saque possivel
        printf("Erro: valor invalido. Digite um valor maior que zero.\n");

    } else if (saque % menorMoeda != 0) {

        // valor que nao pode ser pago exatamente com as cedulas e moedas disponiveis
        printf("Erro: o valor deve ser multiplo de %d.\n", menorMoeda);

    } else if (saque > saldo) {

        // valor maior que o saldo disponivel
        printf("Erro: saldo insuficiente. Saldo disponivel: R$ %d\n", saldo);

    } else {

        /* -----------------------------------------------------
         * PASSO 4: CALCULO ENCADEADO DAS NOTAS
         *
         * Objetivo: entregar o MENOR numero de notas possivel. Por isso
         * comecamos pela nota maior (100) e seguimos ate a moeda de 1.
         *
         * Para cada nota usamos sempre o mesmo par de linhas:
         *   quantidade = resto / nota   -> DIVISAO INTEIRA: quantas notas
         *                                  cabem no valor que falta pagar
         *   resto = resto % nota        -> MODULO: o que sobrou depois de
         *                                  tirar essas notas
         *
         * O "resto" de uma nota vira o valor da proxima nota. E por isso
         * que o calculo e chamado de "encadeado".
         *
         * Exemplo com saque = 285:
         *   285 / 100 = 2 notas   e   285 % 100 = 85  (sobraram 85)
         *    85 /  50 = 1 nota    e    85 %  50 = 35  (sobraram 35)
         *    35 /  20 = 1 nota    e    35 %  20 = 15  (sobraram 15)
         *    15 /  10 = 1 nota    e    15 %  10 =  5  (sobraram 5)
         *     5 /   5 = 1 nota    e     5 %   5 =  0  (nada sobrou)
         * ----------------------------------------------------- */
        resto = saque;            // comeca com o valor total a ser pago

        // Notas de 100
        n100 = resto / 100;       // quantas notas de 100 cabem em "resto"
        resto = resto % 100;      // o que sobrou para as notas menores

        // Notas de 50
        n50 = resto / 50;         // quantas notas de 50 cabem no que sobrou
        resto = resto % 50;       // atualiza o que ainda falta pagar

        // Notas de 20
        n20 = resto / 20;
        resto = resto % 20;

        // Notas de 10
        n10 = resto / 10;
        resto = resto % 10;

        // Notas de 5
        n5 = resto / 5;
        resto = resto % 5;

        // Notas de 2
        n2 = resto / 2;
        resto = resto % 2;

        // Moedas de 1: tudo o que sobrou e pago com moedas de 1
        m1 = resto / 1;
        resto = resto % 1;        // resultado sempre 0: nao falta pagar nada

        /* -----------------------------------------------------
         * PASSO 5: EXIBICAO DO RESULTADO
         *
         * Mostra na tela somente as notas que foram realmente entregues,
         * ou seja, com quantidade maior que zero (como em um recibo).
         *
         * Cada nota tem o seu proprio "if" independente (nao usamos
         * "else if"), pois TODAS as notas precisam ser verificadas.
         *
         * Como ler o comando printf("%d nota(s) de 100\n", n100):
         *   %d                 -> lugar onde entra o numero da variavel
         *   n100               -> variavel cujo valor sera mostrado no %d
         *   " nota(s) de 100"  -> texto exibido logo depois do numero
         *   \n                 -> pula para a linha de baixo
         *
         * Exemplo com saque = 95 (n50 = 1, n20 = 2, n5 = 1; o resto e 0):
         *   1 nota(s) de 50
         *   2 nota(s) de 20
         *   1 nota(s) de 5
         * ----------------------------------------------------- */
        printf("Notas entregues:\n");

        // So mostra se existir pelo menos 1 nota de 100
        if (n100 > 0) {
            printf("%d nota(s) de 100\n", n100);
        }
        // So mostra se existir pelo menos 1 nota de 50
        if (n50 > 0) {
            printf("%d nota(s) de 50\n", n50);
        }
        // So mostra se existir pelo menos 1 nota de 20
        if (n20 > 0) {
            printf("%d nota(s) de 20\n", n20);
        }
        // So mostra se existir pelo menos 1 nota de 10
        if (n10 > 0) {
            printf("%d nota(s) de 10\n", n10);
        }
        // So mostra se existir pelo menos 1 nota de 5
        if (n5 > 0) {
            printf("%d nota(s) de 5\n", n5);
        }
        // So mostra se existir pelo menos 1 nota de 2
        if (n2 > 0) {
            printf("%d nota(s) de 2\n", n2);
        }
        // So mostra se existir pelo menos 1 moeda de 1
        if (m1 > 0) {
            printf("%d moeda(s) de 1\n", m1);
        }
    }

    return 0;   // fim do programa sem erros
}
