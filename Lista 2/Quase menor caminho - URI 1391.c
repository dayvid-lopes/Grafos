#include <stdio.h>
#include <stdlib.h>

int n, *menor_distancia, *prox;

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
        }
    }
}

void Dijkstra(int matriz[n][n], int distancias[n][n], int v, int ant){
    int i;
    atualizarPesos(matriz, distancias, v);
    qsort(prox, n, sizeof(int), comparadorPeso);
    if(prox[0] != -1){
        int proximo;
        proximo = prox[0];
        prox[0] = -1;
        Dijkstra(matriz, distancias, proximo, v);
    }
}

void removerMenoresCaminhos(int matriz[n][n], int distancias[n][n], int v){
    int i;
    i = 0;
    while(distancias[v][i] != -1){
        if(distancias[v][i] < n && distancias[v][i] >= 0)
        matriz[distancias[v][i]][v] = 0;
        int proximo;
        proximo = distancias[v][i];
        distancias[v][i] = -1;
        removerMenoresCaminhos(matriz, distancias, proximo);
        i++;
    }
}

int main(){
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
        prox[s] = -1;
        distancias[s][0] = s;
        distancias[s][1] = -1;
        Dijkstra(matriz, distancias, s, s);

        removerMenoresCaminhos(matriz, distancias, d);

        for(i = 0; i < n; i++){
            menor_distancia[i] = -1;
            prox[i] = i;
            distancias[i][0] = -1;
        }

        menor_distancia[s] = 0;
        prox[s] = -1;
        distancias[s][0] = s;
        distancias[s][1] = -1;
        Dijkstra(matriz, distancias, s, s);
        printf("%d\n", menor_distancia[d]);
        scanf("%d %d", &n, &m);
    }
    return 0;
}