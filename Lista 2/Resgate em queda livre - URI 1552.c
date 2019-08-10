#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct typecoordenadas{
    int x;
    int y;
}Ponto;

typedef struct typevertices
{
    int status;
    int numero;
}Pessoas;

typedef struct typearesta{
    double peso;
    int status;
    Pessoas *vertice1;
    Pessoas *vertice2;
}Aresta;

typedef struct typeheap Heap;

struct heap{
    Aresta *vertice;
    Heap *direita;
    Heap *esquerda;
};

#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)
#define X coordenadas->x
#define Y coordenadas->y
#define imprima(texto) fprintf(resultado, texto)
#define imprima1(texto, valor1) fprintf(resultado, texto, valor1)
#define imprima2(texto, valor1, valor2) fprintf(resultado, texto, valor1, valor2)

double distancia(Ponto *ponto1, Ponto *ponto2){
    return sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto1->y - ponto2->y, 2));
}

int main (){
    FILE *resultado;
    resultado = fopen("Lista 2/resultados/resultado 1552", "w");
    if(resultado == NULL){
        return 1;
    }
    int c;

    scanf("%d", &c);

    while(c > 0){

        int n;

        scanf("%d", &n);

        // Pessoas *pessoas[n];
        Ponto *coordenadas[n];

        Aresta *arestas[n][n];

        int i;

        for(i = 0; i < n; i++){
            coordenadas[i] = MALLOC(Ponto, 1);
            scanf("%d %d", &coordenadas[i]->x, &coordenadas[i]->y);
        }
        
        double matriz[n*n];
        int j;
        
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                Pessoas *vertice;
                
                arestas[i][j] = MALLOC(Aresta, 1);
                arestas[i][j]->peso = distancia(coordenadas[i], coordenadas[j]);

                vertice = MALLOC(Pessoas, 1);
                vertice->numero = i;
                arestas[i][j]->vertice1 = vertice;
                
                vertice = MALLOC(Pessoas, 1);
                vertice->numero = j;
                arestas[i][j]->vertice2 = vertice;

                imprima1("%.2lf\t", arestas[i][j]->peso);
            }
            imprima("\n");
        }

        imprima("\n");

        imprima1("teste de define com numero %d\n\n", 5);

        c--;
    }

    fclose(resultado);
    return 0;
}