#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)

typedef struct typeretorno{
    int ultimo_vertice;
    int maior_distancia;
}Retorno;

int n;

Retorno * calcularMaiorCaminho(int arestas[n][4], int marcacoes[], int atual){
    marcacoes[atual] = 1;

    int i, proximo, verificador;
    Retorno *recebido, *enviado;
    verificador = 0;
    i = 0;
    enviado = MALLOC(Retorno, 1);
    enviado->maior_distancia = 0;
    enviado->ultimo_vertice = atual;
    
    while(i < 4 && arestas[atual][i] != -1){
        proximo = arestas[atual][i];
        if(marcacoes[proximo] == 0){
            recebido = calcularMaiorCaminho(arestas, marcacoes, proximo);
            recebido->maior_distancia++;
            if(enviado->maior_distancia < recebido->maior_distancia){
                enviado->maior_distancia = recebido->maior_distancia;
                enviado->ultimo_vertice = recebido->ultimo_vertice;
            }
            free(recebido);
        }
        i++;
    }
    return enviado;
}

int main(){

    int m, i, j;

    scanf("%d %d", &n, &m);

    while(n != 0 || m != 0){

        getchar();
        int NArestas = 4, NVertices = 0;

        int vertice[n][m];

        for(i = 0; i < n; i++){
            char caracter;
            for(j = 0; j <= m; j++){
                scanf("%c", &caracter);
                if(caracter == '.'){
                    vertice[i][j] = NVertices;
                    NVertices++;
                }
                if(caracter == '#'){
                    vertice[i][j] = - 1;
                }
            }
        }

        int matriz[NVertices][4], vertices[NVertices];

        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(vertice[i][j] > -1){
                    int indice = 0;
                    if(i > 0 && vertice[i - 1][j] > -1){
                        matriz[vertice[i][j]][indice] = vertice[i - 1][j];
                        matriz[vertice[i][j]][++indice] = -1;
                    }
                    if(j > 0 && vertice[i][j - 1] > -1){
                        matriz[vertice[i][j]][indice] = vertice[i][j - 1];
                        matriz[vertice[i][j]][++indice] = -1;
                    }
                    if((i < n - 1) && vertice[i + 1][j] > -1){
                        matriz[vertice[i][j]][indice] = vertice[i + 1][j];
                        matriz[vertice[i][j]][++indice] = -1;
                    }
                    if((j < m - 1) && vertice[i][j + 1] > -1){
                        matriz[vertice[i][j]][indice] = vertice[i][j + 1];
                        if(indice < 4){
                            matriz[vertice[i][j]][++indice] = -1;
                        }
                    }
                }
            }
        }
        
        for(i = 0; i < NVertices; i++){
            vertices[i] = 0;
        }
        
        Retorno *retorno;
        
        retorno = calcularMaiorCaminho(matriz, vertices, 0);

        for(i = 0; i < NVertices; i++){
            vertices[i] = 0;
        }
        
        retorno = calcularMaiorCaminho(matriz, vertices, retorno->ultimo_vertice);

        printf("%d\n", retorno->maior_distancia);
        
        scanf("%d %d", &n, &m);
    }
    return 0;
}
