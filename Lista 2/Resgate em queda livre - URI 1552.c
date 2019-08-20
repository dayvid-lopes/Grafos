#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// typedef struct typecoordenadas{
//     double x;
//     double y;
// }Ponto;

typedef struct typevertices Pessoas;

struct typevertices{
    double x;
    double y;
    Pessoas *origem;
};

typedef struct typearesta{
    double peso;
    Pessoas *vertice1;
    Pessoas *vertice2;
}Aresta;

// typedef struct typeheap Heap;

// struct typeheap{
//     Aresta *aresta;
//     int Nfilhos;
//     Heap *pai;
//     Heap *direita;
//     Heap *esquerda;
// };

// typedef struct typepilha Pilha;

// struct typepilha{
//     Heap *no;
//     Pilha *prox;
// };

#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)
// #define X coordenadas->x
// #define Y coordenadas->y
#define ARESTA raiz->aresta
#define PESO aresta->peso
#define DIREITA raiz->direita
#define ESQUERDA raiz->esquerda
#define NFILHOS raiz->Nfilhos
#define imprima(texto) fprintf(resultado, texto)
#define imprima1(texto, valor1) fprintf(resultado, texto, valor1)
#define imprima2(texto, valor1, valor2) fprintf(resultado, texto, valor1, valor2)
#define imprima3(texto, valor1, valor2, valor3) fprintf(resultado, texto, valor1, valor2, valor3)
#define filhoCompleto(valor) log2(1 - (valor / 2.0) * (1 - 2)) == (int)log2(1 - (valor / 2.0) * (1 - 2))? 1 : 0
#define ARESTAS(i, j) arestas[n * i + j]
#define REMOVE(raiz, aresta) raiz = removerRaiz(raiz, aresta)
#define distancia(ponto1, ponto2) sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto1->y - ponto2->y, 2))

FILE *resultado;

// double distancia(Pessoas *ponto1, Pessoas *ponto2){
//     return sqrt(pow(ponto1->x - ponto2->x, 2) + pow(ponto1->y - ponto2->y, 2));
// }

// Heap* insert(Heap *raiz, Aresta *nova_aresta){
//     if(raiz == NULL){
//         raiz = MALLOC(Heap, 1);
//         ESQUERDA = DIREITA = NULL;
//         ARESTA = nova_aresta;
//         return raiz;
//     }

//     if(ARESTA->peso > nova_aresta->peso){
//         Aresta *aux;
//         aux = nova_aresta;
//         nova_aresta = ARESTA;
//         ARESTA = aux;
//     }
//     Heap *filho;

//     if(NFILHOS < 2){
//         filho = MALLOC(Heap, 1);
//         filho->aresta = nova_aresta;
//         filho->direita = filho->esquerda = NULL;
//         filho->pai = raiz;
//         filho->Nfilhos = 0;
//         if(NFILHOS == 0){
//             ESQUERDA = filho;
//         }
//         else{
//             DIREITA = filho;
//         }
//     }
//     else{
//         if(ESQUERDA->Nfilhos == DIREITA->Nfilhos){
//             filho = insert(ESQUERDA, nova_aresta);
//         }
//         else{
//             if(filhoCompleto(ESQUERDA->Nfilhos)){
//                 filho = insert(DIREITA, nova_aresta);
//             }
//             else{
//                 filho = insert(ESQUERDA, nova_aresta);
//             }
//         }
//     }
//     NFILHOS++;
//     return filho;
// }

// void imprimirArvore(Heap *raiz){
//     if(raiz == NULL){
//         imprima("Arvore vazia");
//         return;
//     }
//     imprima1("%.2lf\t", ARESTA->peso);
//     if(ESQUERDA != NULL){
//         imprimirArvore(ESQUERDA);
//     }
//     if(DIREITA != NULL){
//         imprimirArvore(DIREITA);
//     }
//     else{
//         imprima("\n");
//     }
// }

// void decrementarPai(Heap *raiz, Heap *pai){
//     if(raiz != pai){
//         decrementarPai(raiz, pai->pai);
//     }
//     pai->Nfilhos--;
// }

// void peneirarValor(Heap *raiz){
//     if(NFILHOS < 2){
//         if(NFILHOS == 1){
//             if(ARESTA->peso > ESQUERDA->PESO){
//                 Aresta *aux;
//                 aux = ARESTA;
//                 ARESTA = ESQUERDA->aresta;
//                 ESQUERDA->aresta = aux;
//             }
//         }
//     }
//     else{
//         Aresta *aux;
//         if(ESQUERDA->PESO < DIREITA->PESO){
//             aux = ARESTA;
//             ARESTA = ESQUERDA->aresta;
//             ESQUERDA->aresta = aux;
//             peneirarValor(ESQUERDA);
//         }
//         else{
//             aux = ARESTA;
//             ARESTA = DIREITA->aresta;
//             DIREITA->aresta = aux;
//             peneirarValor(DIREITA);
//         }
//     }
// }

// Heap* removerRaiz(Heap *raiz, Heap *ultimoElemento){
//     if(NFILHOS == 0){
//         free(ARESTA);
//         free(raiz);
//         return NULL;
//     }
    
//     free(ARESTA);
//     ARESTA = ultimoElemento->aresta;
//     Heap *pai;
//     pai = ultimoElemento->pai;
//     if(pai->Nfilhos == 2){
//         pai->direita = NULL;
//     }
//     else{
//         pai->esquerda = NULL;
//     }
//     decrementarPai(raiz, pai);
//     free(ultimoElemento);

//     peneirarValor(raiz);

//     // if(ESQUERDA->aresta->peso < DIREITA->aresta->peso){

//     // }
//     return raiz;
// }

int comparadorPeso(const void ** a, const void ** b) {
    double peso_a, peso_b;
    peso_a = ((Aresta*)*a)->peso;
    peso_b = ((Aresta*)*b)->peso;

    if (peso_a == peso_b)
        return 0;

    if (peso_a < peso_b)
        return -1;

    return 1;
}

// void imprimirVetor(Aresta *arestas[], int n){
//     if(n > 0){
//         imprimirVetor(arestas, n - 1);
//         n--;
//         imprima1("%.2lf\t", arestas[n]->peso);
//     }
// }

int main(){
    resultado = fopen("Lista 2/resultados/resultado 1552", "w");
    if(resultado == NULL){
        return 1;
    }
    int c;

    scanf("%d", &c);

    while(c > 0){

        int n,NArestas;

        scanf("%d", &n);

        NArestas = (n*(n - 1)) / 2;
        // Pessoas *pessoas[n];
        // Ponto *coordenadas[n];

        Aresta *arestas[NArestas];

        Pessoas *vertice[n];

        int i;

        for(i = 0; i < n; i++){
            vertice[i] = MALLOC(Pessoas, 1);
            vertice[i]->origem = vertice[i];
            scanf("%lf %lf", &vertice[i]->x, &vertice[i]->y);
        }
        
        double soma;
        soma = 0;
        int j, cont;
        cont = 0;
        // Heap *raiz;
        // raiz = NULL;
        // Pilha *topo;
        for(i = 0; i < n; i++){
            // vertice1 = MALLOC(Pessoas, 1);
            for(j = 0; j < n; j++){
                // Pessoas *vertice2;
                if(i < j){
                    arestas[cont] = MALLOC(Aresta, 1);
                    arestas[cont]->peso = distancia(vertice[i], vertice[j]);
                    // imprima1("peso: %lf", arestas[i][j]->peso);

                    arestas[cont]->vertice1 = vertice[i];
                    
                    // vertice2 = MALLOC(Pessoas, 1);
                    arestas[cont]->vertice2 = vertice[j];

                    // if(i == 0 && j == 1){
                    //     raiz = MALLOC(Heap, 1);
                    //     ARESTA = arestas[i][j];
                    //     DIREITA = ESQUERDA = raiz->pai = NULL;
                    //     NFILHOS = 0;
                    //     topo = MALLOC(Pilha, 1);
                    //     topo->no = raiz;
                    //     topo->prox = NULL;
                    // }
                    // else{
                    // Pilha *aux;
                    // aux = MALLOC(Pilha, 1);
                    // aux->no = insert(raiz, arestas[i][j]);
                    // aux->prox = topo;
                    // topo = aux;
                    // if(raiz == NULL){
                    //     raiz = topo->no;
                    // }
                    // }

                    // arestas[i][j]->status = 0;

                    // imprima1("%.2lf\t", arestas[i][j]->peso);
                    cont++;
                }
                // else{
                //     arestas[j][i] = arestas[i][j];
                //     // if(i == j){
                //     //     arestas[i][j]->status = 1;
                //     // }
                //     // imprima("\t");
                // }
            }
            // imprima("\n");
        }
        // imprima("antes da ordenação: ");
        // imprimirVetor(arestas, NArestas);
        qsort(arestas, NArestas, sizeof(Aresta*), comparadorPeso);
        // imprima("\ndepois da ordenação: ");
        // imprimirVetor(arestas, NArestas);
        // imprima("\n\n");
        i = 0;
        
        int cont1, cont2;

        while(i < NArestas){
            
            Pessoas *vertice1, *vertice2;

            vertice1 = arestas[i]->vertice1;
            vertice2 = arestas[i]->vertice2;

            cont1 = cont2 = 0;

            // raiz1 = vertice1;

            while(vertice1 != vertice1->origem){
                // vertice1->origem = raiz1;
                vertice1 = vertice1->origem;
                cont1++;
                // contV1++;
                // imprima1("raiz1 em i = %d\n", i);
            }

            // raiz2 = vertice2;
            while(vertice2 != vertice2->origem){
                // vertice2->origem = raiz2;
                cont2++;
                // contV2++;
                vertice2 = vertice2->origem;
            }

            if(vertice1 != vertice2){
                if(cont1 < cont2){
                    vertice1->origem = vertice2;
                }
                else{
                    vertice2->origem = vertice1;
                }
                // for(j = 0; j < n; j++){
                //     if(vertice[j]->floresta == floresta){
                //         vertice[j]->floresta = vertice2->floresta;
                //     }
                // }
                // imprima1("i = %d\n", i);
                soma += arestas[i]->peso;
            }
            i++;
        }
        // imprima3("cont total = %5d | cont1 = %5d | cont2 = %5d\n", cont1 + cont2, cont1, cont2);
        // Pilha *aux;
        // aux = MALLOC(Pilha, 1);
        // aux->no = insert(raiz, arestas[0][1]);
        // aux->prox = topo;
        // topo = aux;
        // if(raiz == NULL){
        //     raiz = topo->no;
        // }

        // arestas[0][1]->status = -1;

        // for(i = 0; i < n; i++){
        //     for(j = 0; j < n; j++){
        //         if(i < j){
        //             if(arestas[i][j]->status == 0){
        //                 aux = MALLOC(Pilha, 1);
        //                 aux->no = insert(raiz, arestas[i][j]);
        //                 aux->prox = topo;
        //                 topo = aux;
        //                 if(raiz == NULL){
        //                     raiz = topo->no;
        //                 }
        //             }
        //         }
        //     }
        //     aux = topo;
        //     topo = aux->prox;
        //     // imprima1("Removendo: %.2lf\n", ARESTA->peso);
        //     REMOVE(raiz, aux->no);
        //     free(aux);
        //     if(topo == NULL){
        //         raiz = NULL;
        //     }
        // }

        // while(topo != NULL){
        //     // imprima1("%.2lf\t", topo->no->aresta->peso);
        //     if(ARESTA->vertice1->status == 0 || ARESTA->vertice2->status == 0 || ARESTA->vertice1->floresta != ARESTA->vertice2->floresta){
        //         soma += raiz->PESO;
        //         int florestaAtual;
        //         florestaAtual = ARESTA->vertice1->floresta;
        //         for(i = 0; i < n; i++){
        //             if(vertice[i]->floresta == florestaAtual){
        //                 vertice[i]->floresta = ARESTA->vertice2->floresta;
        //             }
        //         }
        //         // imprima("vertice 1:\n");
        //         // imprima2("numero: %d\tstatus: %d\n", ARESTA->vertice1->numero, ARESTA->vertice1->status);
        //         // imprima("vertice 2:\n");
        //         // imprima2("numero: %d\tstatus: %d\n", ARESTA->vertice2->numero, ARESTA->vertice2->status);
        //         if(topo == NULL){
        //             raiz = NULL;
        //         }
        //     }
        //     ARESTA->vertice1->status = ARESTA->vertice2->status = 1;
        //     aux = topo;
        //     topo = aux->prox;
        //     // imprima1("Removendo: %.2lf\n", ARESTA->peso);
        //     REMOVE(raiz, aux->no);
        //     if(topo == NULL){
        //         raiz = NULL;
        //     }
        //     free(aux);
        //     // imprima("\n");
        //     // imprima("\n");
        //     // imprimirArvore(raiz);
        //     // imprima("\n");
        // }

        // imprima1("%.3lf\n", soma / 100);

        printf("%.2lf\n", soma / 100);

        // if(c == 2){
        //     imprima1("teste de casting: %lf\n\n", sqrt(5));
        //     imprima1("teste de casting: %lf\n\n", sqrt(7));
        //     imprima1("teste de casting: %lf\n\n", log2(8));
        // }
        // else {
        //     double valor;

        //     int Nfilhos = 6;
        //     valor = filhoCompleto(Nfilhos);
        //     imprima1("teste de casting: %lf\n\n", valor);
        //     if(valor == 0){
        //         imprima("inteiro\n");
        //     }
        //     else
        //     {
        //         imprima("não inteiro\n");
        //     }

        //     valor = log2(7) - (int)log2(7);
        //     imprima1("teste de casting: %lf\n\n", valor);
        //     if(valor == 0){
        //         imprima("inteiro\n");
        //     }
        //     else
        //     {
        //         imprima("não inteiro\n");
        //     }

        //     valor = log2(8) - (int)log2(8);
        //     imprima1("teste de casting: %lf\n\n", valor);
        //     if(valor == 0){
        //         imprima("inteiro\n");
        //     }
        //     else
        //     {
        //         imprima("não inteiro\n");
        //     }
            
            
        // }


        c--;
    }

    fclose(resultado);
    return 0;
}