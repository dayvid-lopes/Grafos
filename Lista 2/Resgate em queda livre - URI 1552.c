#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Coordenadas{
    int x;
    int y;
}Ponto;

#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)

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

        Ponto *pessoas[n];

        int i;

        for(i = 0; i < n; i++){
            pessoas[i] = MALLOC(Ponto, 1);
            scanf("%d %d", &pessoas[i]->x, &pessoas[i]->y);
        }
        fprintf(resultado, "%lf\n", distancia(pessoas[0], pessoas[1]));
        c--;
    }

    fclose(resultado);
    return 0;
}