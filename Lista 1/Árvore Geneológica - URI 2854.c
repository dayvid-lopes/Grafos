#include <string.h>
#include <stdio.h>

int carregarDados(char nomes[][25], int *relacoes, int m, int n, int pos_final_nome);
int buscarNome(char nomes[][25], char nome[25], int pos_final_nome);
void adicionarRelacoes(int *relacoes, int vertice1, int vertice2, int m, int n);
void percorrerRelacoes(int *relacoes, int m, int n, int i, int anterior);

int main(){
    
    // int m, n;
    
    // scanf("%d %d", &m, &n);
    
    // char nomes[m][25];
    // int relacoes[m][n];
    
    // int i, j;

    // for(i = 0; i < m; i++){
    //     for(j = 0; j < n; j++){
    //         relacoes[i][j] = -1;
    //     }
    // }

    // int pos_final_nome;
    // pos_final_nome = 0;
    // // strcpy(nomes[0], "teste");

    // for(i = 0; i < n; i++){
    //     pos_final_nome = carregarDados(nomes, relacoes, m, n, pos_final_nome);
    // }

    // int cont;
    // cont = 0;

    // for(i = 0; i < m; i++){

    //     if(relacoes[i][0] == -1){ //Se o vertice nao tiver nenhuma aresta
    //         cont++;
    //     }
    //     else if(relacoes[i][0] >= 0){ //Se o vertice tiver alguma aresta
    //         percorrerRelacoes(relacoes, m, n, i, i); //vai percorrer todos os vertices ligados ao vertice i
    //         cont++;
    //     }
    // }
    for(int i = 0; i < 8; i++){
        int num;
        scanf("%d", &num);
        // num = letra;
        // num = 100;
        // letra = num - 32511;
        printf("%d\n", num / 2);
        // printf("%d\n", cont);
    }
}

int carregarDados(char nomes[][25], int *relacoes, int m, int n, int pos_final_nome){
    int i;
    char nome1[25], relacao[25], nome2[25];
    scanf("%s %s %s", nome1, relacao, nome2);

    int pos_nome1, pos_nome2;

    pos_nome1 = buscarNome(nomes, nome1, pos_final_nome);
    if(pos_final_nome == pos_nome1){
        pos_final_nome++;
    }
    pos_nome2 = buscarNome(nomes, nome2, pos_final_nome);
    if(pos_final_nome == pos_nome2){
        pos_final_nome++;
    }

    adicionarRelacoes(relacoes, pos_nome1, pos_nome2, m, n);
    
    return pos_final_nome;
}

int buscarNome(char nomes[][25], char nome[25], int pos_final_nome){
    int i;
    i = 0;
    while(i < pos_final_nome && strcmp(nomes[i], nome) != 0){
        i++;
    }

    if(strcmp(nomes[i], nome) != 0){
        strcpy(nomes[i], nome);
    }

    return i;
}

void adicionarRelacoes(int *relacoes, int vertice1, int vertice2, int m, int n){
    int i, j;

    i = 0;
    while(relacoes[n * vertice1 + i] >= 0){
        i++;
    }
    relacoes[n * vertice1 + i] = vertice2;

    i = 0;
    while(relacoes[n * vertice2 + i] >= 0){
        i++;
    }
    relacoes[n * vertice2 + i] = vertice1;
}

void percorrerRelacoes(int *relacoes, int m, int n, int i, int anterior){
    int j = 0;
    while(j < n && relacoes[n * i + j] != -1){ //vai visitar todos os vertices ligados ao vertice i
        if(relacoes[n * i + j] != -2){ //se o vertice da relacao ainda nao tiver sido visitado
            int vertice = relacoes[n * i + j];
            relacoes[n * i + j] = -2;
            if(vertice != anterior){ //se o vertice visitado anteriormente nao for o mesmo que vai ser visitado agora
                percorrerRelacoes(relacoes, m, n, vertice, i);
            }
        }
        j++;
    }
}