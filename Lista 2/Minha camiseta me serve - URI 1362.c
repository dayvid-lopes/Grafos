#include"cabeçalhos.h"
FILE *saida;
int n, m;

typedef struct Voluntario{
    int numero;
    int tam1;
    int tam2;
}Voluntario;

int *pa;
int *visited;

void newMatching(int *match, int t) { 
    int x;
    do{
        x = pa[t];
        match[t] = x;
        match[x] = t;
        t = pa[x]; 
    }while (t != x);
}

int acharCaminhoDeAumento(int matriz[m][n], int v, int *match){ 
    int i;
    for (i = m; i < m + n; i++){
            //     if(v == 2)
            // printf("matriz[%d][%d] = %d\n", v, i - m, matriz[v][i - m]);
        if(matriz[v][i - m] == 1){
            if (visited[i] == 0){
                visited[i] = 1;

            //     if(v == 2)
            // printf("i = %d\t v = %d\n", i, v);
            if (match[i] == -1 || acharCaminhoDeAumento(matriz, match[i], match) == 1){
                match[v] = i;
                match[i] = v;
                return 1;
            }
            }
        }
	}
	return 0;
}

int UGRAPHbipMatch(int matriz[m][n], int *match){
    int i, j;
    visited = MALLOC(int, (m + n));
    for (i = 0; i < m + n; i++){
        match[i] = -1;
        visited[i] = 0;
    }
    int size = 0;
    for(i = 0; i < m; i++){
        if(match[i] == -1){
            // printf("match[%d] = %d\n", i, match[i]);
            size += acharCaminhoDeAumento(matriz, i, match);
            // printf("match[%d] = %d\n", i, match[i]);
            for(j = 0; j < m + n; j++){
                visited[j] = 0;
            }
        }
    }
    free(visited);
    // printf("\n");
    // while (augmentMatch(matriz, color, match)){
    //     size++;
    // }
    return size;
}

int main(){
    saida = fopen("Lista 2/resultados/resultado 1362", "w");
    int c;
    scanf("%d", &c);
    while (c > 0){
        int i, j;
        char tam1[4], tam2[4];
        scanf("%d %d", &n, &m);
        int matriz[m][n];
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                matriz[i][j] = 0;
            }
        }
        for(i = 0; i < m; i++){
            scanf("%s %s", tam1, tam2);
            int tam;
            if(strcmp(tam1, "XXL") == 0){
                tam = 0;
            }
            else{
                if(strcmp(tam1, "XL") == 0){
                    tam = 1;
                }
                else{
                    if(strcmp(tam1, "L") == 0){
                        tam = 2;
                    }
                    else{
                        if(strcmp(tam1, "M") == 0){
                            tam = 3;
                        }
                        else{
                            if(strcmp(tam1, "S") == 0){
                                tam = 4;
                            }
                            else{
                                if(strcmp(tam1, "XS") == 0){
                                    tam = 5;
                                }
                            }
                        }
                    }
                }
            }
            for(j = 0; j < n / 6; j++){
                matriz[i][tam * n/6 + j] = 1;
            }
            if(strcmp(tam2, "XXL") == 0){
                tam = 0;
            }
            else{
                if(strcmp(tam2, "XL") == 0){
                    tam = 1;
                }
                else{
                    if(strcmp(tam2, "L") == 0){
                        tam = 2;
                    }
                    else{
                        if(strcmp(tam2, "M") == 0){
                            tam = 3;
                        }
                        else{
                            if(strcmp(tam2, "S") == 0){
                                tam = 4;
                            }
                            else{
                                if(strcmp(tam2, "XS") == 0){
                                    tam = 5;
                                }
                            }
                        }
                    }
                }
            }
            // tam = i;
            for(j = 0; j < n / 6; j++){
                matriz[i][tam * n/6 + j] = 1;
                // imprima2("j = %d\ttam * 6 + j = %d\n", j, tam * (n/6) + j);
            }
            
            // imprima2("tam1: %s\ttam2: %s\n", tam1, tam2);
        // imprima("\n");
        }
        // imprima1("matriz[2][")
        int color[n + m], match[n + m];
        // UGRAPHbipMatch(matriz, match);
        for(i = 0; i < m + n; i++){
            // for(j = 0; j < n; j++){
                // imprima1("%d\t", match[i]);
            // }
        // imprima("\n");
        }
        imprima1("%s\n", UGRAPHbipMatch(matriz, match) == m?"YES":"NO");
        // imprima("\n");
        c--;
    }
    
    free(saida);
    return 0;
}