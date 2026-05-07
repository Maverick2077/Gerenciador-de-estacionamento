/*

------------------------------------------------
Danilo Do Nascimento Esteves
Matricula: 2021073521
Curso: Bacharelado interdisciplinar em Ciência e Tecnologia
Disciplina: Laboratorio de Programação - C
-------------------------------------------------
Prova 1 - Estacionamento Rotativo
Data: 01/05/2026

Compilador: GCC
Linguagem: C17
Descrição:
Desenvolver um programa em C para calcular o valor a ser pago por um veículo que utilizou um estacionamento rotativo. 
O programa deve solicitar a placa do veículo, o tipo (moto, carro ou caminhonete) e o tempo de permanência em horas. 
O valor a ser pago é calculado com base no tipo do veículo e no tempo de permanência, aplicando regras de desconto e multa conforme necessário. 
O programa deve exibir um comprovante detalhado do pagamento.    

*/


#include <stdio.h>
#include <string.h>

int main() {
    char placa[10];
    int tipo;
    float horas, valor_hora, valor_base, valor_final, ajuste = 0;
    char nome_tipo[20];

    // Entrada
    printf("--- SISTEMA DE ESTACIONAMENTO ROTATIVO ---\n");
    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);

    printf("Selecione o tipo de veiculo:\n");
    printf("1 - Moto\n2 - Carro\n3 - Caminhonete\nOpcao: ");
    scanf("%d", &tipo);

    printf("Digite o tempo de permanencia (em horas): ");
    scanf("%f", &horas);

    // Processamento - Definindo valor por tipo
    switch(tipo) {
        case 1:
            valor_hora = 3.00;
            strcpy(nome_tipo, "Moto");
            break;
        case 2:
            valor_hora = 5.00;
            strcpy(nome_tipo, "Carro");
            break;
        case 3:
            valor_hora = 8.00;
            strcpy(nome_tipo, "Caminhonete");
            break;
        default:
            printf("Tipo invalido!\n");
            return 1; // Encerra o programa com erro
    }

    // Cálculo do valor base (Garante o mínimo de 1 hora)
    if (horas < 1.0) {
        valor_base = 1.0 * valor_hora;
    } else {
        valor_base = horas * valor_hora;
    }

    // Aplicação de Regras de Desconto e Multa
    if (horas > 10.0) {
        ajuste = 20.00; // Multa fixa
        valor_final = valor_base + ajuste;
    } else if (horas > 5.0) {
        ajuste = valor_base * 0.10; // 10% de desconto
        valor_final = valor_base - ajuste;
        ajuste = -ajuste; // Negativo para indicar desconto na saída
    } else {
        valor_final = valor_base;
    }

    // Saída
    printf("\n======================================\n");
    printf("        COMPROVANTE DE PAGAMENTO       \n");
    printf("======================================\n");
    printf("Placa: %s\n", placa);
    printf("Veiculo: %s\n", nome_tipo);
    printf("Permanencia: %.2f horas\n", horas);
    printf("Valor Base: R$ %.2f\n", valor_base);

    if (ajuste < 0) {
        printf("Desconto (10%%): R$ %.2f\n", -ajuste);
    } else if (ajuste > 0) {
        printf("Multa Adicional: R$ %.2f\n", ajuste);
    } else {
        printf("Descontos/Multas: R$ 0.00\n");
    }

    printf("--------------------------------------\n");
    printf("VALOR TOTAL: R$ %.2f\n", valor_final);
    printf("======================================\n");

    return 0;
}


