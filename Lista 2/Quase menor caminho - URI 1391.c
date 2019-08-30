#include "cabeçalhos.h"
int n;
FILE *saida;

int comparadorPeso(const void * a, const void * b) {
    if (*(int*)a == *(int*)b)
        return 0;

    if (*(int*)a < *(int*)b)
        return -1;

    return 1;
}

int Dijkstra(int matriz[n][n], int distancias[n], int q[n], int d, int v){
    int i, peso, menor_peso = -1, vertice;
    for(i = 0; i < n; i++){
        peso = matriz[v][i];
        if(peso > 0){
            if((distancias[i] > distancias[v] + peso) || distancias[i] == -1){
                distancias[i] = distancias[v] + peso;
                if(menor_peso == -1 || menor_peso > distancias[i]){
                    menor_peso = distancias[i];
                    if(q[i] == 0){
                        vertice = i;
                    }
                }
            }
        }
    }
    return vertice;
}

int main(){
    saida = fopen("Lista 2/resultados/resultado 1391", "w");
    int m;
    scanf("%d %d", &n, &m);
    while(n != 0 && m != 0){
        int s, d, u, v, p, i, j;
        int matriz[n][n], distancias[n], q[n];
        scanf("%d %d", &s, &d);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                matriz[i][j] = 0;
            }
        }

        for(i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &p);
            matriz[u][v] = p;
            distancias[i] = -1;
            q[i] = 0;
        }

        distancias[s] = 0;
        int prox, menor_caminho[n], indice;
        indice = 0;
        i = 0;
        prox = s;
        while(i < n && q[prox] == 0){
            menor_caminho[indice++] = prox;
            q[prox] = 1;
            prox = Dijkstra(matriz, distancias, q, d, prox);
            i++;
        }


        for(i = 1; i < indice; i++){
            matriz[i - 1][i] = 0;
        }

        for(i = 0; i < m; i++){
            distancias[i] = -1;
            q[i] = 0;
        }

        distancias[s] = 0;
        indice = 0;
        i = 0;
        prox = s;
        while(i < n){
            q[prox] = 1;
            prox = Dijkstra(matriz, distancias, q, d, prox);
            i++;
        }

        // for(i = 0; i < n; i++){
        //     imprima2("i: %d\tdistancia: %d\n", i, distancias[i]);
        // }
        imprima1("%d\n", distancias[d]);

        // qsort(distancias, n, sizeof(int), comparadorPeso);
        
        // for(i = 0; i < n; i++){
        //     imprima2("i: %d\tdistancia: %d\n", i, distancias[i]);
        // }
        // imprima("\n");

        scanf("%d %d", &n, &m);
    }
    free(saida);
    return 0;
}