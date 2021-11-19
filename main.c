//Nome: Rafael de Souza Coelho
//Matrícula: 202120111

#include <stdio.h>
#define pi 3.14159265359

//Converte o valor do ângulo recebido em radianos
double radianos(int anguloGraus)
{
    return (pi*anguloGraus)/180;
}

//Calcula a exponecial de um número, recebe a base e o expoente e retorna o valor calculado
double exponencial(double anguloRadianos, int indice)
{   
    double valorInicial = anguloRadianos;
    for (int d = 1; d < indice; d++) {
        anguloRadianos *= valorInicial;
    }
    if (indice != 1) {
        return anguloRadianos;
    }
    return 0;
}

//Calcula o fatorial do número recebido
int fatorial(int indice)
{   
    int fatorial = 1;
    for (int e = 1; e <= indice; e++) {
        fatorial *= e;
    }
    if (indice != 1) {
        return fatorial;
    }
}

//Calcula o seno do ângulo em graus, utilizando as três funções anteriores
double seno(int anguloGraus)
{   
    double valorAbs;
    double anguloRadianos = radianos(anguloGraus);
    for (int c = 0;; c++) {
        valorAbs = (exponencial(anguloRadianos, c*2 + 1)/fatorial(c*2 + 1));
        if (c % 2 == 0) {
            anguloRadianos += valorAbs;
        }
        else {
            anguloRadianos -= valorAbs;
        }
        if (c > 0 && valorAbs < 0.000001) {
            break;
        }
    }
    return anguloRadianos;
}

//Cria a tabela dos valores dos senos usando a função seno() passando todos os angulos de 0 a 89
int main()
{   
    double anguloGraus, anguloRadianos;
    for (int i = 18;i > 0; i--) {
        for (int cont = 18 - i; cont < 90; cont+= 18) {
            if (cont < 10) {
                printf("0%d %.6lf  ", cont, seno(cont));
            }
            else {
                printf("%d %.6lf  ", cont, seno(cont));  
            }
        }
        printf("\n");
    }
    return 0;
}
