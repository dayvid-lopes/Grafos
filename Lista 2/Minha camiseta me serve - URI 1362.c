#include"cabeçalhos.h"
FILE *saida;

typedef struct Voluntario{
    int numero;
    int tam1;
    int tam2;
}Voluntario;

int main(){
    saida = fopen("Lista 2/resultados/resultado 1362", "w");
    int c;
    scanf("%d", &c);
    while (c > 0){
        int m, n, i, j;
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
                imprima2("j = %d\ttam * 6 + j = %d\n", j, tam * (n/6) + j);
            }
            
            // imprima2("tam1: %s\ttam2: %s\n", tam1, tam2);
        imprima("\n");
        }
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                imprima1("%d\t", matriz[i][j]);
            }
        imprima("\n");
        }
        imprima("\n");
        c--;
    }
    
    free(saida);
    return 0;
}