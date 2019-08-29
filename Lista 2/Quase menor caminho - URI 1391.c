#include "cabeçalhos.h"
int n;
FILE *saida;

int main(){
    saida = fopen("resultados/resultado 1391", "w");
    int m;
    scanf("%d %d", &n, &m);
    while(n != 0 && m != 0){
        int s, d, u, v, p, i, j;
        int matriz[n][n], distancias[n];
        scanf("%d %d", &s, &d);
        for(i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &p);
            matriz[u][v] = p;
            distancias[n] = -1;
        }
        
        scanf("%d %d", &n, &m);
    }
    free(saida);
    return 0;
}