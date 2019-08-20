#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct typevertices Pessoas;

struct typevertices{
    double x;
    double y;
    Pessoas *origem;
};

typedef struct typearesta{
    double peso;
    Pessoas *vertice1;
    Pessoas *vertice2;
}Aresta;

#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)
#define distancia(ponto1, ponto2) sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto1->y - ponto2->y, 2))

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

int main(){

    int c, i;

    scanf("%d", &c);

    while(c > 0){

        int n, NArestas;

        scanf("%d", &n);

        NArestas = (n*(n - 1)) / 2;

        Aresta *arestas[NArestas];

        Pessoas *vertice[n];

        for(i = 0; i < n; i++){
            vertice[i] = MALLOC(Pessoas, 1);
            vertice[i]->origem = vertice[i];
            scanf("%lf %lf", &vertice[i]->x, &vertice[i]->y);
        }
        
        double soma;
        soma = 0;
        int j, cont;
        cont = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i < j){
                    arestas[cont] = MALLOC(Aresta, 1);
                    arestas[cont]->peso = distancia(vertice[i], vertice[j]);

                    arestas[cont]->vertice1 = vertice[i];

                    arestas[cont]->vertice2 = vertice[j];

                    cont++;
                }
            }
        }
        
        qsort(arestas, NArestas, sizeof(Aresta*), comparadorPeso);
        
        i = 0;
        
        int cont1, cont2;

        while(i < NArestas){
            
            Pessoas *vertice1, *vertice2;

            vertice1 = arestas[i]->vertice1;
            vertice2 = arestas[i]->vertice2;

            cont1 = cont2 = 0;

            while(vertice1 != vertice1->origem){
                cont1++;
                vertice1 = vertice1->origem;
            }

            while(vertice2 != vertice2->origem){
                cont2++;
                vertice2 = vertice2->origem;
            }

            if(vertice1 != vertice2){
                if(cont1 < cont2){
                    vertice1->origem = vertice2;
                }
                else{
                    vertice2->origem = vertice1;
                }
                soma += arestas[i]->peso;
            }
            i++;
        }

        printf("%.2lf\n", soma / 100);

        c--;
    }
    return 0;
}