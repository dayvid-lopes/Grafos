#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)
#define distancia(ponto1, ponto2) sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto1->y - ponto2->y, 2))
#define imprima(texto) fprintf(resultado, texto)
#define imprima1(texto, valor1) fprintf(resultado, texto, valor1)
#define imprima2(texto, valor1, valor2) fprintf(resultado, texto, valor1, valor2)
#define imprima3(texto, valor1, valor2, valor3) fprintf(resultado, texto, valor1, valor2, valor3)
