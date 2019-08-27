#include "cabeçalhos.h"

FILE *resultado;

typedef struct typeretorno{
    int ultimo_vertice;
    int maior_distancia;
}Retorno;

int n;
int adicionarAresta(int v, int w, int matriz[n][4], int indice){
    // if(matriz[v][indice] == -1){
    matriz[v][indice] = w;
    if(indice < 4){
        matriz[v][++indice] = -1;
    }
    return indice;
    // printf("adicionando aresta: (%d, %d)\n", v, w, matriz[v][]);
    // }
}

Retorno * calcularMaiorCaminho(int arestas[n][4], int marcacoes[], int atual){
    marcacoes[atual] = 1;
    // if(anterior == -1){
    //     marcacoes[0] = 1;
    // }
    // else{
    //     marcacoes[atual] = marcacoes[anterior] * (-1);
    // }

    int i, proximo, verificador;
    Retorno *recebido, *enviado;
    // int ultimo_vertice, vertice_maior_caminho;
    // vertice_maior_caminho = atual;
    verificador = 0;
    i = 0;
    enviado = MALLOC(Retorno, 1);
    enviado->maior_distancia = 0;
    enviado->ultimo_vertice = atual;
    
    while(i < 4 && arestas[atual][i] != -1){
        proximo = arestas[atual][i];
        if(marcacoes[proximo] == 0){
            recebido = calcularMaiorCaminho(arestas, marcacoes, proximo);
            recebido->maior_distancia++;
            if(enviado->maior_distancia < recebido->maior_distancia){
                enviado->maior_distancia = recebido->maior_distancia;
                enviado->ultimo_vertice = recebido->ultimo_vertice;
            }
            free(recebido);
        }
        i++;
    }
    return enviado;

    // else{
    //     if(marcacoes[anterior] == marcacoes[atual]){
    //         return 1;
    //     }
    //     else {
    //         return 0;
    //     }
    // }
}

int percorrerMaiorCaminho(int arestas[n][4], int marcacoes[], int atual){
    marcacoes[atual] = 1;
    // if(anterior == -1){
    //     marcacoes[0] = 1;
    // }
    // else{
    //     marcacoes[atual] = marcacoes[anterior] * (-1);
    // }

    int i, distancia, proximo, maior_distancia, verificador;
    int ultimo_vertice, vertice_maior_caminho;
    verificador = 0;
    i = 0;
    maior_distancia = 0;
    
    while(arestas[atual][i] != -1){
        proximo = arestas[atual][i];
        if(i < 4 && marcacoes[proximo] != -1){
            distancia = 1;
            distancia += percorrerMaiorCaminho(arestas, marcacoes, proximo);
            if(maior_distancia < distancia){
                maior_distancia = distancia;
            }
            verificador = 1;
        }
        i++;
    }
    return maior_distancia;

    // else{
    //     if(marcacoes[anterior] == marcacoes[atual]){
    //         return 1;
    //     }
    //     else {
    //         return 0;
    //     }
    // }
}

int main(){

    resultado = fopen("Lista 2/resultados/resultado 1621", "w");
    if(resultado == NULL){
        return 1;
    }

    int m, i, j;

    scanf("%d %d", &n, &m);

    // printf("%d %d\n", n, m);

    while(n != 0 || m != 0){

        getchar();
        int NArestas = 4, NVertices = 0;

        int vertice[n][m];

        for(i = 0; i < n; i++){
            char caracter;
            for(j = 0; j <= m; j++){
                scanf("%c", &caracter);
                if(caracter == '.'){
                    vertice[i][j] = NVertices;
                    NVertices++;
                    // imprima(".");
                }
                if(caracter == '#'){
                    vertice[i][j] = - 1;
                    // imprima("#");
                }
                if(caracter == '\n'){
                    // imprima("\n");
                }
                else{
                    // imprima1("%d\t", vertice[i][j]);
                }
            }
            // imprima("\n");
        }

        int matriz[NVertices][4], vertices[NVertices];

        // for(i = 0; i < NVertices; i++){
        //     matriz[i][0] = -1;
        // }

        // for(i = 0; i < NVertices; i++){
        //     // vertices[i] = 0;
        //     j = 0;
            // imprima1("%d\t|.\t", i);
        //     while(j < NVertices * (NVertices - 1) / 2 && matriz[NVertices * i + j] != -1){
                // imprima1("%d\t", matriz[NVertices * i + j]);
        //         j++;
        //     }
            // imprima("\n");
        // }

        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(vertice[i][j] > -1){
                    int indice = 0;
                    if(i > 0 && vertice[i - 1][j] > -1){
                        matriz[vertice[i][j]][indice] = vertice[i - 1][j];
                        matriz[vertice[i][j]][++indice] = -1;
                    }
                    if(j > 0 && vertice[i][j - 1] > -1){
                        matriz[vertice[i][j]][indice] = vertice[i][j - 1];
                        matriz[vertice[i][j]][++indice] = -1;
                    }
                    if((i < n - 1) && vertice[i + 1][j] > -1){
                        matriz[vertice[i][j]][indice] = vertice[i + 1][j];
                        matriz[vertice[i][j]][++indice] = -1;
                    }
                    if((j < m - 1) && vertice[i][j + 1] > -1){
                        matriz[vertice[i][j]][indice] = vertice[i][j + 1];
                        if(indice < 4){
                            matriz[vertice[i][j]][++indice] = -1;
                        }
                    }
                }
            }
        }

        // imprima("\n");
        // n = NVertices;
        for(i = 0; i < NVertices; i++){
            vertices[i] = 0;
            j = 0;
            // imprima1("%d\t|\t", i);
            while(j < 4 && matriz[i][j] != -1){
                // imprima1("%d\t", matriz[i][j]);
                if(j > 0){
                    // printf("j = %d\n", j);
                }
                j++;
            }
            // imprima("\n");
        }
        
        // printf("\n");
        // imprima("\n");
        // printf("primeira iteração %m\n");
        // imprima1("resultado inicial: %d\n", 
        Retorno *retorno;
        
        retorno = calcularMaiorCaminho(matriz, vertices, 0);

        for(i = 0; i < NVertices; i++){
            vertices[i] = 0;
            // j = 0;
            // imprima1("%d\t|\t", i);
            // while(j < NVertices * (NVertices - 1) / 2 && matriz[NVertices * i + j] != -1){
                // imprima1("%d\t", matriz[NVertices * i + j]);
            //     j++;
            // }
            // imprima("\n");
        }
        // imprima1("primeiro resultado: %d\n", retorno->maior_distancia);
        int res;
        res = retorno->maior_distancia;
        retorno = calcularMaiorCaminho(matriz, vertices, retorno->ultimo_vertice);
        // if(res > retorno->maior_distancia){
        //     imprima("Warning!!!");
        // }
        // printf("\nsegunda iteração %m\n");

        // res = analisaRamos(NVertices, matriz, vertices, vertice_ant);
        // printf("terceira iteração %m\n");

        imprima1("%d\n", retorno->maior_distancia);
        // printf("final %m\n\n");

        // scanf("%d", &n);

        // NArestas = (n*(n - 1)) / 2;

        // Aresta *arestas[NArestas];

        // Pessoas *vertice[n];

        // for(i = 0; i < n; i++){
        //     vertice[i] = MALLOC(Pessoas, 1);
        //     vertice[i]->origem = vertice[i];
        //     scanf("%lf %lf", &vertice[i]->x, &vertice[i]->y);
        // }
        
        // double soma;
        // soma = 0;
        // int j, cont;
        // cont = 0;
        // for(i = 0; i < n; i++){
        //     for(j = 0; j < n; j++){
        //         if(i < j){
        //             arestas[cont] = MALLOC(Aresta, 1);
        //             arestas[cont]->peso = distancia(vertice[i], vertice[j]);

        //             arestas[cont]->vertice1 = vertice[i];

        //             arestas[cont]->vertice2 = vertice[j];

        //             cont++;
        //         }
        //     }
        // }
        
        // qsort(arestas, NArestas, sizeof(Aresta*), comparadorPeso);
        
        // i = 0;
        
        // int cont1, cont2;

        // while(i < NArestas){
            
        //     Pessoas *vertice1, *vertice2;

        //     vertice1 = arestas[i]->vertice1;
        //     vertice2 = arestas[i]->vertice2;

        //     cont1 = cont2 = 0;

        //     while(vertice1 != vertice1->origem){
        //         cont1++;
        //         vertice1 = vertice1->origem;
        //     }

        //     while(vertice2 != vertice2->origem){
        //         cont2++;
        //         vertice2 = vertice2->origem;
        //     }

        //     if(vertice1 != vertice2){
        //         if(cont1 < cont2){
        //             vertice1->origem = vertice2;
        //         }
        //         else{
        //             vertice2->origem = vertice1;
        //         }
        //         soma += arestas[i]->peso;
        //     }
        //     i++;
        // }

        // printf("%.2lf\n", soma / 100);

        scanf("%d %d", &n, &m);
    }
    fclose(resultado);
    return 0;
}

// #include <stdio.h>

// int percorrerVertices(int *arestas, int marcacoes[], int n, int atual, int anterior);

// int main() {
//     int n;
    
//     scanf("%d", &n);

//     while(n != 0){

//         int i, j, arestas[n][n], id, marcacoes[n];
        
//         char enter;

//         for(i = 0; i < n; i++){
//             scanf("%d", &id);
//             j = 0;
//             do{
//                 scanf("%d%c", &arestas[i][j], &enter);
//                 arestas[i][j]--;
//                 j++;
//             }while(enter != '\n');

//             arestas[i][j] = -1;

//             marcacoes[i] = 0;
//         }

//         if(percorrerVertices(arestas, marcacoes, n, 0, -1) > 0){
//             printf("NAO\n");
//         }
//         else{
//             printf("SIM\n");
//         }

//         scanf("%d", &n);
//     }
//     return 0;
// }

// int percorrerVertices(int *arestas, int marcacoes[], int n, int atual, int anterior){
//     if(marcacoes[atual] == 0){
//         if(anterior == -1){
//             marcacoes[0] = 1;
//         }
//         else{
//             marcacoes[atual] = marcacoes[anterior] * (-1);
//         }

//         int i, verificador;
//         i = 0;
//         verificador = 0;
        
//         while(arestas[n * atual + i] != -1){
//             verificador += percorrerVertices(arestas, marcacoes, n, arestas[n * atual + i], atual);
//             i++;
//             if(verificador > 0){
//                 return verificador;
//             }
//         }
//         return verificador;
//     }

//     else{
//         if(marcacoes[anterior] == marcacoes[atual]){
//             return 1;
//         }
//         else {
//             return 0;
//         }
//     }
// }