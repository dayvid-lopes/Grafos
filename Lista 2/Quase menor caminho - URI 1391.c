#include "cabeçalhos.h"
int n;
FILE *saida;

int Dijkstra(int matriz[n][n], int distancias[n], int s, int d, int v){
    int i, peso, menor_peso = -1, vertice;
    for(i = 0; i < n; i++){
        peso = matriz[v][i];
        if(peso > 0){
            if((distancias[i] > distancias[v] + peso) || distancias[i] == -1){
                distancias[i] = distancias[v] + peso;
                if(menor_peso > distancias[i]){
                    menor_peso = distancias[i];
                    vertice = i;
                }
            }
        }
    }
    return vertice;
}

int main(){
    saida = fopen("resultados/resultado 1391", "w");
    int m;
    scanf("%d %d", &n, &m);
    while(n != 0 && m != 0){
        int s, d, u, v, p, i, j;
        int matriz[n][n], distancias[n], q[n];
        scanf("%d %d", &s, &d);
        for(i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &p);
            matriz[u][v] = p;
            distancias[n] = -1;
            q[i] = 0;
        }
        distancias[s] = 0;
        for(i = 0; i < n; i++){
            
            Dijkstra(matriz, distancias, s, d, s);
        }
        scanf("%d %d", &n, &m);
    }
    free(saida);
    return 0;
}