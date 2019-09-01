#include "cabeçalhos.h"
int n, *distancias;
FILE *saida;

// typedef struct Heap{
//     int vertice;
//     int Nfilhos;
//     struct Heap *pai;
//     struct Heap *direita;
//     struct Heap *esquerda;
// };

int comparadorPeso(const void * a, const void * b) {
    int va, vb;
    va = *(int*)a;
    vb = *(int*)b;
    if(distancias[va] == -1){
        return 1;
    }
    if(distancias[vb] == -1){
        return -1;
    }
    if (distancias[va] == distancias[vb])
        return 0;

    if (distancias[va] < distancias[vb])
        return -1;

    return 1;
}

void atualizarPesos(int matriz[n][n], int menores_distancias[n][n], int v){
    int i, peso, menor_peso = -1, prox;
    for(i = 0; i < n; i++){
        peso = matriz[v][i];
        if(peso > 0){
            if(peso + distancias[v] == distancias[i] && menores_distancias[i][0] != -1){
                int j = 0;
                while(j < n && (menores_distancias[i][j] != -1 || menores_distancias[i][j] != v)){
                    j++;
                }
                if(j < n && menores_distancias[i][j] != v){
                    menores_distancias[i][j] = v;
                    menores_distancias[i][j + 1] = -1;
                }
            }
            else{
                if(peso + distancias[v] < distancias[i] || distancias[i] == -1){
                    distancias[i] = peso + distancias[v];
                }
            }
        }
    }
}

void Dijkstra(int matriz[n][n], int menores_distancias[n][n], int prox[n], int v, int ant){
    int i, peso, menor_peso = -1, vertice = -1;
    menores_distancias[v][0] = ant;
    menores_distancias[v][1] = -1;
    atualizarPesos(matriz, menores_distancias, v);
    qsort(prox, n, sizeof(int), comparadorPeso);
    if(prox[0] != -1){
        int proximo;
        proximo = prox[0];
        prox[0] = -1;
        Dijkstra(matriz, menores_distancias, prox, proximo, v);
    }
}

void removerMenoresCaminhos(int matriz[n][n], int menores_caminhos[n][n], int v){
    int i;
    i = 0;
    while(menores_caminhos[v][i] != -1){
        matriz[menores_caminhos[v][i]][v] = 0;
        removerMenoresCaminhos(matriz, menores_caminhos, menores_caminhos[v][i]);
        i++;
    }
}

int main(){
    saida = fopen("Lista 2/resultados/resultado 1391", "w");
    int m;
    scanf("%d %d", &n, &m);
    while(n != 0 && m != 0){
        int s, d, u, v, p, i, j;
        int matriz[n][n], distancia[n], prox[n], menores_caminhos[n][n];
        distancias = distancia;
        scanf("%d %d", &s, &d);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                matriz[i][j] = 0;
            }
            distancias[i] = -1;
            prox[i] = i;
            menores_caminhos[i][0] = -1;
        }

        for(i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &p);
            matriz[u][v] = p;
        }

        distancias[s] = 0;
        // int menor_caminho[n], indice;
        // indice = 0;
        prox[s] = -1;
        Dijkstra(matriz, menores_caminhos, prox, s, s);
        // while(i < n && q[prox] == 0){
        //     if(q)
        //     menor_caminho[indice++] = prox;
        //     q[prox] = 1;
        //     Dijkstra(matriz, distancias, q, d, prox);
        //     i++;
        // }

        // removerMenoresCaminhos(matriz, menores_caminhos, d);
        for(i = 0; i < n; i++){
            j = 0;
            imprima1("%d | ", i);
            while(j < n){
                imprima1("%d\t", menores_caminhos[i][j]);
                j++;
            }
            imprima("\n");
        }
        // while(i < n && menores_caminhos[i] != -1){
        //     matriz[i - 1][i] = 0;
        // }

        // i = 0;

        for(i = 0; i < n; i++){
            // distancias[i] = -1;
            prox[i] = i;
            menores_caminhos[i][0] = -1;
        }

        distancias[s] = 0;
        // indice = 0;
        // i = 0;
        prox[s] = -1;
        // Dijkstra(matriz, menores_caminhos, prox, s, s);
        // while(i < n && prox != -1){
        //     q[prox] = 1;
        //     Dijkstra(matriz, distancias, q, d, prox);
        //     i++;
        // }

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