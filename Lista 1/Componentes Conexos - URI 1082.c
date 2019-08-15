#include <string.h>
#include <stdio.h>

void carregarEntrada(int *arestas, int v, int e);
void adicionararestas(int *arestas, int vertice1, int vertice2, int v, int e);
void percorrerarestas(int *arestas, int vertices_conexos[], int v, int e, int i, int anterior);

int main(){
    int n, caso;

    caso = 1;

    scanf("%d", &n);

    while(caso <= n){
        printf("Case #%d:\n", caso);
        int v, e;
        
        scanf("%d %d", &v, &e);
        
        int arestas[v][e];
        
        int i, j;

        for(i = 0; i < v; i++){
            for(j = 0; j < e; j++){
                arestas[i][j] = -1;
            }
        }
        
        for(i = 0; i < e; i++){
            carregarEntrada(arestas, v, e);
        }

        int cont;
        cont = 0;

        for(i = 0; i < v; i++){

            if(arestas[i][0] == -1){ //Se o vertice nao tiver nenhuma aresta
                cont++;
                printf("%c,\n", i + 97);
            }
            else if(arestas[i][0] >= 0){ //Se o vertice tiver alguma aresta
                int vertices_conexos[v];
                for(j = 0; j < v; j++){
                    vertices_conexos[j] = 30;
                }
                percorrerarestas(arestas, vertices_conexos, v, e, i, i); //vai percorrer todos os vertices ligados ao vertice i
                j = 0;
                while(j < v){
                    if(vertices_conexos[j] != 30){
                        printf("%c,", vertices_conexos[j] + 97);
                    }
                    j++;
                }
                cont++;
                printf("\n");
            }
        }

        printf("%d connected components\n\n", cont);

        caso++;
    }
    printf("\n");
}

void carregarEntrada(int *arestas, int v, int e){
    int i;
    char letra1[2], letra2[2];
    scanf("%s %s", letra1, letra2);

    int vertice1, vertice2;

    vertice1 = letra1[0];
    vertice2 = letra2[0];

    adicionararestas(arestas, vertice1 - 97, vertice2 - 97, v, e);
}

void adicionararestas(int *arestas, int vertice1, int vertice2, int v, int e){
    int i, j;
    i = 0;
    while(arestas[e * vertice1 + i] >= 0){
        i++;
    }
    arestas[e * vertice1 + i] = vertice2;

    i = 0;
    while(arestas[e * vertice2 + i] >= 0){
        i++;
    }
    arestas[e * vertice2 + i] = vertice1;
}

void percorrerarestas(int *arestas, int vertices_conexos[], int v, int e, int i, int anterior){
    int j, k;

    k = 0;
    while(vertices_conexos[k] != i && k < v){
        k++;
    }
    if(k == v){
        j = v - 1;
        while(j > 0 && vertices_conexos[j - 1] > i){
            if(vertices_conexos[j - 1] != 30){
                vertices_conexos[j] = vertices_conexos[j - 1];
            }
            j--;
        }

        vertices_conexos[j] = i;
    }
    
    j = 0;

    while(j < e && arestas[e * i + j] != -1){ //vai visitar todos os vertices ligados ao vertice i
        if(arestas[e * i + j] != -2){ //se o vertice da relacao ainda nao tiver sido visitado
            int vertice = arestas[e * i + j];
            arestas[e * i + j] = -2;
            if(vertice != anterior){ //se o vertice visitado anteriormente nao for o mesmo que vai ser visitado agora
                percorrerarestas(arestas,vertices_conexos, v, e, vertice, i);
            }
        }
        j++;
    }
}