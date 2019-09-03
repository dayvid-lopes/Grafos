#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC(t,n) (t*) malloc(sizeof(t)*n)

int n, m;
int *visited;

int acharCaminhoDeAumento(int matriz[m][n], int v, int *match){ 
    int i;
    for (i = m; i < m + n; i++){
        if(matriz[v][i - m] == 1){
            if (visited[i] == 0){
                visited[i] = 1;
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
            size += acharCaminhoDeAumento(matriz, i, match);
            for(j = 0; j < m + n; j++){
                visited[j] = 0;
            }
        }
    }
    free(visited);
    return size;
}

int main(){
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
            for(j = 0; j < n / 6; j++){
                matriz[i][tam * n/6 + j] = 1;
            }
        }
        int match[n + m];
        printf("%s\n", UGRAPHbipMatch(matriz, match) == m?"YES":"NO");
        c--;
    }
    return 0;
}