#include <stdio.h>

int percorrerVertices(int *arestas, int marcacoes[], int n, int atual, int anterior);

int main() {
    int n;
    
    scanf("%d", &n);

    while(n != 0){

        int i, j, arestas[n][n], id, marcacoes[n];
        
        char enter;

        for(i = 0; i < n; i++){
            scanf("%d", &id);
            j = 0;
            do{
                scanf("%d%c", &arestas[i][j], &enter);
                arestas[i][j]--;
                j++;
            }while(enter != '\n');

            arestas[i][j] = -1;

            marcacoes[i] = 0;
        }

        if(percorrerVertices(arestas, marcacoes, n, 0, -1) > 0){
            printf("NAO\n");
        }
        else{
            printf("SIM\n");
        }

        scanf("%d", &n);
    }
    return 0;
}

int percorrerVertices(int *arestas, int marcacoes[], int n, int atual, int anterior){
    if(marcacoes[atual] == 0){
        if(anterior == -1){
            marcacoes[0] = 1;
        }
        else{
            marcacoes[atual] = marcacoes[anterior] * (-1);
        }

        int i, verificador;
        i = 0;
        verificador = 0;
        
        while(arestas[n * atual + i] != -1){
            verificador += percorrerVertices(arestas, marcacoes, n, arestas[n * atual + i], atual);
            i++;
            if(verificador > 0){
                return verificador;
            }
        }
        return verificador;
    }

    else{
        if(marcacoes[anterior] == marcacoes[atual]){
            return 1;
        }
        else {
            return 0;
        }
    }
}