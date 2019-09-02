#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)
// #define distancia(ponto1, ponto2) sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto1->y - ponto2->y, 2))
#define imprima(texto) fprintf(saida, texto)
#define imprima1(texto, valor1) fprintf(saida, texto, valor1)
#define imprima2(texto, valor1, valor2) fprintf(saida, texto, valor1, valor2)
#define imprima3(texto, valor1, valor2, valor3) fprintf(saida, texto, valor1, valor2, valor3)
