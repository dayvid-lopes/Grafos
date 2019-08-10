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

struct typeheap{
    Aresta *aresta;
    int Nfilhos;
    Heap *direita;
    Heap *esquerda;
};

#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)
#define X coordenadas->x
#define Y coordenadas->y
#define ARESTA raiz->aresta
#define DIREITA raiz->direita
#define ESQUERDA raiz->esquerda
#define NFILHOS raiz->Nfilhos
#define imprima(texto) fprintf(resultado, texto)
#define imprima1(texto, valor1) fprintf(resultado, texto, valor1)
#define imprima2(texto, valor1, valor2) fprintf(resultado, texto, valor1, valor2)
#define filhoCompleto(valor) log2(1 - (valor / 2.0) * (1 - 2)) == (int)log2(1 - (valor / 2.0) * (1 - 2))? 1 : 0

double distancia(Ponto *ponto1, Ponto *ponto2){
    return sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto1->y - ponto2->y, 2));
}

void insert(Heap *raiz, Aresta * nova_aresta){
    
    if(ARESTA->peso > nova_aresta->peso){
        Aresta *aux;
        aux = nova_aresta;
        nova_aresta = ARESTA;
        ARESTA = aux;
    }

    if(NFILHOS < 2){
        Heap *filho;
        filho = MALLOC(Heap, 1);
        filho->aresta = nova_aresta;
        filho->direita = NULL;
        filho->esquerda = NULL;
        filho->Nfilhos = 0;
        if(NFILHOS == 0){
            ESQUERDA = filho;
        }
        else{
            DIREITA = filho;
        }
    }
    else{
        if(ESQUERDA->Nfilhos == DIREITA->Nfilhos){
            insert(ESQUERDA, nova_aresta);
        }
        else{
            if(filhoCompleto(ESQUERDA->Nfilhos)){
                insert(DIREITA, nova_aresta);
            }
            else{
                insert(ESQUERDA, nova_aresta);
            }
        }
    }
    NFILHOS++;
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

                // imprima1("%.2lf\t", arestas[i][j]->peso);
            }
            // imprima("\n");
        }

        imprima("\n");

        // if(c == 2){
        //     imprima1("teste de casting: %lf\n\n", sqrt(5));
        //     imprima1("teste de casting: %lf\n\n", sqrt(7));
        //     imprima1("teste de casting: %lf\n\n", log2(8));
        // }
        // else {
            // double valor;

            // int Nfilhos = 6;
            // valor = filhoCompleto(Nfilhos);
            // imprima1("teste de casting: %lf\n\n", valor);
        //     if(valor == 0){
        //         imprima("inteiro\n");
        //     }
        //     else
        //     {
        //         imprima("não inteiro\n");
        //     }

        //     valor = log2(7) - (int)log2(7);
        //     imprima1("teste de casting: %lf\n\n", valor);
        //     if(valor == 0){
        //         imprima("inteiro\n");
        //     }
        //     else
        //     {
        //         imprima("não inteiro\n");
        //     }

        //     valor = log2(8) - (int)log2(8);
        //     imprima1("teste de casting: %lf\n\n", valor);
        //     if(valor == 0){
        //         imprima("inteiro\n");
        //     }
        //     else
        //     {
        //         imprima("não inteiro\n");
        //     }
            
            
        // }


        c--;
    }

    fclose(resultado);
    return 0;
}