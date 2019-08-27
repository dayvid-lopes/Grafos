#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct typevertices Vertice;

struct typevertices{
    double x;
    double y;
    Vertice *origem;
};

typedef struct typearesta{
    double peso;
    Vertice *vertice1;
    Vertice *vertice2;
}Aresta;

#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)
#define distancia(ponto1, ponto2) sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto1->y - ponto2->y, 2))
#define imprima(texto) fprintf(resultado, texto)
#define imprima1(texto, valor1) fprintf(resultado, texto, valor1)
#define imprima2(texto, valor1, valor2) fprintf(resultado, texto, valor1, valor2)
#define imprima3(texto, valor1, valor2, valor3) fprintf(resultado, texto, valor1, valor2, valor3)

FILE *resultado;
int ultimo_vertice, vertice_ant;

void adicionarAresta(int n, int v, int w, int *matriz, int indice){
    if(matriz[n * v + indice] == -1){
        matriz[n * v + indice] = w;
        matriz[n * v + indice + 1] = -1;
    }
    else{
        adicionarAresta(n, v, w, matriz, indice + 1);
    }
}

int comparadorPeso(const void ** a, const void ** b) {
    double peso_a, peso_b;
    peso_a = ((Aresta*)*a)->peso;
    peso_b = ((Aresta*)*b)->peso;

    if (peso_a == peso_b)
        return 0;

    if (peso_a < peso_b)
        return -1;

    return 1;
}

int analisaRamos(int n, int *matriz, int *vertices, int vertice_atual){
    int i = 0, cont_ant = 0, cont = 0;
    printf("vertice atual: %d\n", vertice_atual);
    vertices[vertice_atual] = 1;
    while(matriz[n * vertice_atual + i] != -1){
        int w;
        w = matriz[n * vertice_atual + i];
        printf("proximo vertice: %d\t i: %d\tn * vertice_atual + i: %d\n", w, i, n * vertice_atual + i);
        if(vertices[w] == 0){
            cont = analisaRamos(n, matriz, vertices, w);
        }
        if(cont > cont_ant){
            vertice_ant = ultimo_vertice;
            // printf("vertice_ant: %d\t", vertice_ant);
            cont_ant = cont;
            // printf("cont_ant: %d\n", cont_ant);
        }
        i++;
    }
    if(cont_ant == 0){
        ultimo_vertice = vertice_atual;
    }
    return cont_ant + 1;
}

int main(){

    resultado = fopen("Lista 2/resultados/resultado 1621", "w");
    if(resultado == NULL){
        return 1;
    }

    int n, m, i, j;

    scanf("%d %d", &n, &m);

    // printf("%d %d\n", n, m);

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
                    imprima(".");
                }
                if(caracter == '#'){
                    vertice[i][j] = - 1;
                    imprima("#");
                }
                if(caracter == '\n'){
                    imprima("\n");
                }
                else{
                    imprima1("%d\t", vertice[i][j]);
                }
            }
            imprima("\n");
        }

        int matriz[NVertices * (NVertices * (NVertices - 1) / 2)], vertices[NVertices];

        for(i = 0; i < NVertices; i++){
            matriz[i * NVertices] = -1;
        }

        // for(i = 0; i < NVertices; i++){
        //     // vertices[i] = 0;
        //     j = 0;
        //     imprima1("%d\t|.\t", i);
        //     while(j < NVertices * (NVertices - 1) / 2 && matriz[NVertices * i + j] != -1){
        //         imprima1("%d\t", matriz[NVertices * i + j]);
        //         j++;
        //     }
        //     imprima("\n");
        // }

        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(vertice[i][j] > -1){
                    if(i > 0 && vertice[i - 1][j] > -1){
                        adicionarAresta(NVertices, vertice[i][j], vertice[i - 1][j], matriz, 0);
                    }
                    if(j > 0 && vertice[i][j - 1] > -1){
                        adicionarAresta(NVertices, vertice[i][j], vertice[i][j - 1], matriz, 0);
                    }
                    if((i < n - 1) && vertice[i + 1][j] > -1){
                        adicionarAresta(NVertices, vertice[i][j], vertice[i + 1][j], matriz, 0);
                    }
                    if((j < m - 1) && vertice[i][j + 1] > -1){
                        adicionarAresta(NVertices, vertice[i][j], vertice[i][j + 1], matriz, 0);
                    }
                }
            }
        }
        imprima("\n");
        // n = NVertices;
        for(i = 0; i < NVertices; i++){
            vertices[i] = 0;
            j = 0;
            imprima1("%d\t|\t", i);
            while(j < NVertices * (NVertices - 1) / 2 && matriz[NVertices * i + j] != -1){
                imprima1("%d\t", matriz[NVertices * i + j]);
                j++;
            }
            imprima("\n");
        }
        
        // printf("\n");
        // imprima("\n");
        // printf("primeira iteração %m\n");
        // imprima1("resultado inicial: %d\n", 
        analisaRamos(NVertices, matriz, vertices, 0);

        for(i = 0; i < NVertices; i++){
            vertices[i] = 0;
            // j = 0;
            // imprima1("%d\t|\t", i);
            // while(j < NVertices * (NVertices - 1) / 2 && matriz[NVertices * i + j] != -1){
            //     imprima1("%d\t", matriz[NVertices * i + j]);
            //     j++;
            // }
            // imprima("\n");
        }

        int res;
        printf("\nsegunda iteração %m\n");

        res = analisaRamos(NVertices, matriz, vertices, vertice_ant);
        printf("terceira iteração %m\n");

        imprima1("resultado: %d\n", res);
        printf("final %m\n\n");

        // scanf("%d", &n);

        // NArestas = (n*(n - 1)) / 2;

        // Aresta *arestas[NArestas];

        // Pessoas *vertice[n];

        // for(i = 0; i < n; i++){
        //     vertice[i] = MALLOC(Pessoas, 1);
        //     vertice[i]->origem = vertice[i];
        //     scanf("%lf %lf", &vertice[i]->x, &vertice[i]->y);
        // }
        
        // double soma;
        // soma = 0;
        // int j, cont;
        // cont = 0;
        // for(i = 0; i < n; i++){
        //     for(j = 0; j < n; j++){
        //         if(i < j){
        //             arestas[cont] = MALLOC(Aresta, 1);
        //             arestas[cont]->peso = distancia(vertice[i], vertice[j]);

        //             arestas[cont]->vertice1 = vertice[i];

        //             arestas[cont]->vertice2 = vertice[j];

        //             cont++;
        //         }
        //     }
        // }
        
        // qsort(arestas, NArestas, sizeof(Aresta*), comparadorPeso);
        
        // i = 0;
        
        // int cont1, cont2;

        // while(i < NArestas){
            
        //     Pessoas *vertice1, *vertice2;

        //     vertice1 = arestas[i]->vertice1;
        //     vertice2 = arestas[i]->vertice2;

        //     cont1 = cont2 = 0;

        //     while(vertice1 != vertice1->origem){
        //         cont1++;
        //         vertice1 = vertice1->origem;
        //     }

        //     while(vertice2 != vertice2->origem){
        //         cont2++;
        //         vertice2 = vertice2->origem;
        //     }

        //     if(vertice1 != vertice2){
        //         if(cont1 < cont2){
        //             vertice1->origem = vertice2;
        //         }
        //         else{
        //             vertice2->origem = vertice1;
        //         }
        //         soma += arestas[i]->peso;
        //     }
        //     i++;
        // }

        // printf("%.2lf\n", soma / 100);

        scanf("%d %d", &n, &m);
    }
    fclose(resultado);
    return 0;
}