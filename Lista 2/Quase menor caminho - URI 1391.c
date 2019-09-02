#include "cabeçalhos.h"
int n, *menor_distancia, *prox, *q;
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
    if(menor_distancia[vb] == -1){
        return -1;
    }
    if(menor_distancia[va] == -1){
        return 1;
    }
    if(va == -1){
        return 1;
    }
    if(vb == -1){
        return -1;
    }
    if (menor_distancia[va] == menor_distancia[vb])
        return 0;

    if (menor_distancia[va] < menor_distancia[vb])
        return -1;

    return 1;
}

void atualizarPesos(int matriz[n][n], int distancias[n][n], int v){
    int i, peso;
    for(i = 0; i < n; i++){
        peso = matriz[v][i];
        if(peso > 0){
            // if(peso + menor_distancia[v] == menor_distancia[i] && distancias[i][0] != -1){
            //     int j = 0;
            //     while(j < n && (distancias[i][j] != -1 || distancias[i][j] != v)){
            //         j++;
            //     }
            //     if(j < n && distancias[i][j] != v){
            //         distancias[i][j] = v;
            //         distancias[i][j + 1] = -1;
            //     }
            // }
            // else{
                if(menor_distancia[i] == -1){
                    menor_distancia[i] = peso + menor_distancia[v];
                    distancias[i][0] = v;
                    distancias[i][1] = -1;
                }
                else{
                    if(peso + menor_distancia[v] < menor_distancia[i]){
                        menor_distancia[i] = peso + menor_distancia[v];
                        distancias[i][0] = v;
                        distancias[i][1] = -1;
                    }
                    if((peso + menor_distancia[v] == menor_distancia[i])){
                        int j;
                        j = 0;
                        while(j < n && distancias[i][j] != -1 && distancias[i][j] != v){
                            j++;
                        }
                        if(j < n && distancias[i][j] == -1){
                            distancias[i][j] = v;
                            distancias[i][j+1] = -1;
                        }
                    }
                }
            // }
        }
    }
}

void Dijkstra(int matriz[n][n], int distancias[n][n], int v, int ant){
    int i, peso;
        // for(i = 0; i < n; i++){
        //     // j = 0;
        //     // imprima1("%d | ", i);
        //     // while(j < n){
        //         imprima1("%d\t", menor_distancia[i]);
        //     //     j++;
        //     // }
        // }
            // imprima1("V: %d\n", v);
        for(i = 0; i < n; i++){
            // j = 0;
            // imprima1("%d | ", i);
            // while(j < n){
                // imprima2("%d->%d\t", menor_distancia[i], distancias[i][0]);
            //     j++;
            // }
        }
    atualizarPesos(matriz, distancias, v);
        // imprima1("proximo: %d\n", v);
        // for(i = 0; i < n; i++){
        //     // j = 0;
        //     // imprima1("%d | ", i);
        //     // while(j < n){
        //         imprima1("%d\t", menor_distancia[i]);
        //     //     j++;
        //     // }
        // }
        //     imprima("\n");
        //     imprima("\n");
    qsort(prox, n, sizeof(int), comparadorPeso);
            // imprima("\nDepois de ordenar: ");
            // for(i = 0; i < n; i++){
            // // j = 0;
            // // imprima1("%d | ", i);
            // // while(j < n){
            //     imprima2("%d->%d\t", menor_distancia[i], distancias[i][0]);
            // //     j++;
            // // }
            // }
        
            // imprima("\n");
    if(prox[0] != -1){
        int proximo;
        proximo = prox[0];
        prox[0] = -1;
        // distancias[proximo][0] = v;
        // distancias[proximo][1] = -1;
        Dijkstra(matriz, distancias, proximo, v);
    }
}

void removerMenoresCaminhos(int matriz[n][n], int distancias[n][n], int v){
    int i;
    i = 0;
    printf("v: %d %m\n", v);
    while(distancias[v][i] != -1){
        if(distancias[v][i] < n && distancias[v][i] >= 0)
        matriz[distancias[v][i]][v] = 0;
        int proximo;
        proximo = distancias[v][i];
        distancias[v][i] = -1;
        removerMenoresCaminhos(matriz, distancias, proximo);
        i++;
    }
    // while(i > 0){
    //     i--;
    // }
}

int main(){
    saida = fopen("Lista 2/resultados/resultado 1391", "w");
    int m;
    scanf("%d %d", &n, &m);
    while(n != 0 && m != 0){
        int s, d, u, v, p, i, j;
        int matriz[n][n], distancia[n], proximo[n], distancias[n][n];
        menor_distancia = distancia;
        prox = proximo;
        scanf("%d %d", &s, &d);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                matriz[i][j] = 0;
            }
            menor_distancia[i] = -1;
            prox[i] = i;
            distancias[i][0] = -1;
        }

        for(i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &p);
            matriz[u][v] = p;
        }

        menor_distancia[s] = 0;
        // int menor_caminho[n], indice;
        // indice = 0;
        prox[s] = -1;
        distancias[s][0] = s;
        distancias[s][1] = -1;
        Dijkstra(matriz, distancias, s, s);
        // while(i < n && q[prox] == 0){
        //     if(q)
        //     menor_caminho[indice++] = prox;
        //     q[prox] = 1;
        //     Dijkstra(matriz, menor_distancia, q, d, prox);
        //     i++;
        // }

        // imprima1("antes: %d\n", menor_distancia[d]);
        // for(i = 0; i < n; i++){
        //     for(j = 0; j < n; j++){
        //         imprima1("%d\t", distancias[i][j]);
        //     }
        //     imprima("\n");
        // }
        removerMenoresCaminhos(matriz, distancias, d);
        for(i = 0; i < n; i++){
            // j = 0;
            // imprima1("%d | ", i);
            // while(j < n){
                // imprima1("%d\t", distancias[i]);
            //     j++;
            // }
        }
            // imprima("\n");
        // while(i < n && distancias[i] != -1){
        //     matriz[i - 1][i] = 0;
        // }

        // i = 0;

        for(i = 0; i < n; i++){
            menor_distancia[i] = -1;
            prox[i] = i;
            distancias[i][0] = -1;
        }

        menor_distancia[s] = 0;
        // // indice = 0;
        // // i = 0;
        prox[s] = -1;
        distancias[s][0] = s;
        distancias[s][1] = -1;
        Dijkstra(matriz, distancias, s, s);
        // while(i < n && prox != -1){
        //     q[prox] = 1;
        //     Dijkstra(matriz, menor_distancia, q, d, prox);
        //     i++;
        // }

        // for(i = 0; i < n; i++){
        //     imprima2("i: %d\tdistancia: %d\n", i, menor_distancia[i]);
        // }
        imprima1("%d\n", menor_distancia[d]);

        // for(i = 0; i < n; i++){
        //     for(j = 0; j < n; j++){
        //         imprima1("%d\t", matriz[i][j]);
        //     }
        //     imprima("\n");
        // }

        // qsort(menor_distancia, n, sizeof(int), comparadorPeso);
        
        // for(i = 0; i < n; i++){
        //     imprima2("i: %d\tdistancia: %d\n", i, menor_distancia[i]);
        // }
        // imprima("\n");

        scanf("%d %d", &n, &m);
    }
    free(saida);
    return 0;
}