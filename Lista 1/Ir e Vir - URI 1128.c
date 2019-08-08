#include <stdio.h>
#include <stdlib.h>


int num, compNo;

typedef struct typepilha pilha;

struct typepilha{
    int valor;
    pilha *prox;
};

pilha *topo_pilha;

void adicionarAresta(int n, int v, int w, int *matriz, int indice){
    if(matriz[n * v + indice] == -1){
        matriz[n * v + indice] = w;
        matriz[n * v + indice + 1] = -1;
    }
    else{
        adicionarAresta(n, v, w, matriz, indice + 1);
    }
}

void primeiraBusca(int n, int *matriz, int vertices_alcancados[], int vertice_atual){
    int i;
    i = 0;
    
    vertices_alcancados[vertice_atual] = 1;

    while(i < n && matriz[n * vertice_atual + i] != -1){
        if(vertices_alcancados[matriz[n * vertice_atual + i]] == 0){
            primeiraBusca(n, matriz, vertices_alcancados, matriz[n * vertice_atual + i]);
        }
        i++;
    }
}

void buscaProfundidade(int n, int *matriz, int PE[], int high[], int comp[], int vertice_atual){
    int i, verificador;
    i = 0;
    verificador = 0;
    PE[vertice_atual] = num;
    num++;

    pilha *item;
    item = (pilha *) malloc(sizeof(pilha));
    item->valor = vertice_atual;
    item->prox = topo_pilha;
    topo_pilha = item;

    high[vertice_atual] = PE[vertice_atual];

        // if(vertice_atual == -1){
        //     i = 1;
        //     vertice_atual = 0;
        // }

        // if(vertices_confirmados[vertice_atual] && !i){
        //     return 1;
        // }
    
    int proximo_vertice;

    while(i < n && matriz[n * vertice_atual + i] != -1){
        proximo_vertice = matriz[n * vertice_atual + i];
        if(PE[proximo_vertice] == 0){

            buscaProfundidade(n, matriz, PE, high, comp, proximo_vertice);
            
            if(high[vertice_atual] > high[proximo_vertice]){
                high[vertice_atual] = high[proximo_vertice];
            }

                // // printf("vai sair do vertice %d para percorrer o ramo %d do vertice %d\t%m\n", vertice_atual, i, matriz[n * vertice_atual + i]);
                // if(percorrerRamo(n, m, matriz, vertices_confirmados, matriz[n * vertice_atual + i], vertices_alcancados) == 1){
                //     printf("resultado verdadeiro\n");
                //     for(i = 0; i < n; i++){
                //         vertices_confirmados[i] = vertices_alcancados[i];
                //     }
                // }
                // else{
                //     return 0;
                // }
        }
        else{
            if(PE[proximo_vertice] < PE[vertice_atual] && comp[proximo_vertice] == 0){
                if(high[vertice_atual] > PE[proximo_vertice]){
                    high[vertice_atual] = PE[proximo_vertice];
                }
            }
        }

        // if(high[vertice_atual] == PE[vertice_atual]){

        // }
            // buscaProfundidade(n, m, matriz, vertices_confirmados, matriz[n * vertice_atual + i], vertices_alcancados);
            // if(vertices_confirmados[vertice_atual] == 1){
            // }
            // if(vertices_alcancados[matriz[n * vertice_atual + i]] == 0){

            // }
            // if(vertices_confirmados[matriz[n * vertice_atual + i]] == 1){
            //     int j;
            //     for(j = 0; j < n; j++){
            //         if(vertices_alcancados[j] == 1){
            //             vertices_confirmados[j] = 1;
            //             vertices_alcancados[j] = 0;
            //         }
            //     }

            //             if(verificador > 0){
            //                 return buscaProfundidade(n, m, matriz, vertices_confirmados, vertice_atual, vertices_alcancados);
            //             }
            // }
            // else{
            //     if(vertices_alcancados[matriz[n * vertice_atual + i]] == 0){
            //         vertices_alcancados[matriz[n * vertice_atual + i]] = 1;
            //         // printf("vertice: %d\taresta: %d\tproximo: %d\t%m\n", vertice_atual, i, matriz[n * vertice_atual + i]);
            //         verificador = buscaProfundidade(n, m, matriz, vertices_confirmados, matriz[n * vertice_atual + i], vertices_alcancados);
            //         if(verificador < 0){
            //             return verificador;
            //         }
            //     }
            //     else{
            //         if(vertices_alcancados[matriz[n * vertice_atual + i]] == 1){
            //             verificador = 1;
            //         }
            //         else{
            //             return -1;
            //         }
            //     }
            // }
        i++;
    }
    if(high[vertice_atual] == PE[vertice_atual]){
        // printf("vertice atual: %d\t high e PE: %d\n", vertice_atual, high[vertice_atual]);
        compNo++;
        int vertice_desempilhado;
        vertice_desempilhado = -1;
        if(topo_pilha != NULL){
            do{
                
                item = topo_pilha;
                vertice_desempilhado = item->valor;
                topo_pilha = topo_pilha->prox;
                free(item);
                comp[vertice_desempilhado] = compNo;
                
                // printf("vertice atual: %d\tvertice desempilhado: %d\t\tcompNo: %d\t%m\n", vertice_atual, vertice_desempilhado, compNo);
            } while(vertice_atual != vertice_desempilhado);
        }
    }
    // return 1;
        // if(verificador == 0 && vertices_confirmados[vertice_atual] == 0){
        //     vertices_alcancados[vertice_atual] = -1;
        //     return 0;
        // }
        // vertices_alcancados[vertice_atual] = 0;
        // return verificador;
}

int verificarHigh(int n, int high[]){
    n--;
    if(n == 0){
        if(high[n] == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    if(high[n] == 1){
        return 1 + verificarHigh(n, high);
    }
    
    return 0 + verificarHigh(n, high);

    //     if(vertices_confirmados[vertice_atual] == 0){
    //         if(vertices_alcancados[vertice_atual] == 0){
    //             vertices_alcancados[vertice_atual] = 0;
    //             int i;
    //             i = 0;
    //             while(i < n && matriz[n * vertice_atual + i] != -1){
    //                 vertices_alcancados[vertice_atual] = 1;
    //                 vertices_alcancados[vertice_atual] = percorrerRamo(n, m, matriz, vertices_confirmados, matriz[n * vertice_atual + i], vertices_alcancados);
    //                 if(vertices_alcancados[vertice_atual] == 1){
    //                     return 1;
    //                 }
    //                 i++;
    //             }
    //         }
    //         return 0;
    //     }
    //     return 1;
    // }

    // int verificarConexidade(int n, int vertices_confirmados[]){
    //     int i;
    //     for(i = 0; i < n; i++){
    //         if(vertices_confirmados[i] == 0){
    //             printf("vertice %d não confirmado\n", i);
    //             return 0;
    //         }
    //     }
    // return 1;
}

int main(){
    int m, n;

    scanf("%d %d", &n, &m);

    while(m != 0 && n != 0){
        // printf("n: %d\tm: %d\t%m\n", n, m);

        int v, w, p, i, matriz[n][n], high[n], PE[n], comp[n];
        
        for(i = 0; i < n; i++){
            matriz[i][0] = -1;
            PE[i] = 0;
            comp[i] = 0;
        }

        compNo = 0;

        num = 1;
        topo_pilha = NULL;

        for(i = 0; i < m; i++){
            scanf("%d %d %d", &v, &w, &p);
            v--;
            w--;
            adicionarAresta(n, v, w, matriz, 0);
            // printf("linha: %d = %m\n", i);
            if(p == 2){
                adicionarAresta(n, w, v, matriz, 0);
            }
        }

        // for(i = 0; i < n; i++){
        //     int j;
        //     j = 0;
        //     while(j < m && matriz[i][j] != -1){
        //         printf("%d\t", matriz[i][j]);
        //         j++;
        //     }
        //     printf("\n");
        // }
        
        // printf("\n");

        buscaProfundidade(n, matriz, PE, high, comp, n/2);

        num--;

        // printf("n = %d\t num = %d\tresultado: ", n, num);

        if(compNo == 1 && num == n){
            printf("1\n");
        }
        else{
            printf("0\n");
        }

            // primeiraBusca(n, matriz, vertices_alcancados, 0);
            // printf("saiu da primeira busca\t\m\n");

            // if(verificarConexidade(n, vertices_alcancados)){
            //     for(i = 0; i < n; i++){
            //         vertices_alcancados[i] = 0;
            //     }
            //     vertices_confirmados[0] = 1;
            //     printf("vai entrar na segunda busca\t\m\n");
            //     printf("%d\n", buscaProfundidade(n, m, matriz, vertices_confirmados, 0, vertices_alcancados));
            // }

            // int erro, verificador;

            // for(i = 0; i < n; i++){
            //     if(vertices_alcancados[i]){
            //         vertices_alcancados[i] = 0;
            //     }
            //     else{
            //         erro = 1;
            //     }
            // }

            // if(!erro){
            // vertices_alcancados[0] = 1;
            // verificador = buscaProfundidade(n, m, matriz, vertices_confirmados, 0, vertices_alcancados);
            // }
            // if(verificador < 0){
            //     printf("0\n");
            // }
            // else{
            //     printf("%d\n", verificarConexidade(n, vertices_alcancados));
            // }

            // if(verificador > 0){
            //     printf("0\n");
            // }
            // else{
            //     printf("1\n");
            // }

        scanf("%d %d", &n, &m);
    }
}