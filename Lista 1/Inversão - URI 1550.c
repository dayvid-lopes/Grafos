#include <stdio.h>
#include <stdlib.h>

int analisarGrafo(int b);
int inverter(int a);
int potencia(int a, int b);
int valor(int numero[]);
void adicionarValor(int valor, int nivel);

typedef struct typefila fila;

struct typefila{
	int valor;
    int nivel;
	fila *prox;
};

fila *inicio, *fim;

int posicao, algarismos, valores_alcancados[20000];

int main(){
    int t;

    posicao = 0;

    scanf("%d", &t);

    while(t > 0){
        int a, b;

        inicio = NULL;

        scanf("%d %d", &a, &b);
        
        int i;
        
        for(i = 1; i < 5; i++){
            if(potencia(10, i - 1) <= b){
                algarismos = i;
            }
        }

        if(a == b){
            printf("0\n");
        }
        else{
            adicionarValor(a, 0);
            printf("%d\n", analisarGrafo(b));
        }
        
        t--;
    }
    return 0;
}

int analisarGrafo(int b){
    do{
        fila *item;
        item = inicio;
        
        if(valores_alcancados[item->valor + 1]){
            adicionarValor(item->valor + 1, item->nivel + 1);
        }
        
        inicio = item->prox;

        if(fim->valor == b){
            free(item);
            return fim->nivel;
        }

        int inverso;
        inverso = inverter(item->valor);

        if(valores_alcancados[inverso]){
            adicionarValor(inverso, item->nivel + 1);
        }
        if(fim->valor == b){
            free(item);
            return fim->nivel;
        }
        
        free(item);
    }while(inicio->nivel != fim->nivel);
    return analisarGrafo(b);
}

void separaFatores(int partes[], int valor){
    int i;
    for(i = 1; i <= algarismos; i++){
        partes[i - 1] = valor / potencia(10, algarismos - i);
        valor -= partes[i - 1] * potencia(10, algarismos - i);
    }
}

int inverter(int a){
    int i, ver, cont, original[algarismos], inverso[algarismos];

    separaFatores(original, a);

    ver = 0;
    cont = 0;
    for(i = 0; i < algarismos; i++){
        if(original[i] != 0){
            ver = 1;
        }
        else{
            if(ver == 0){
                inverso[cont] = 0;
                cont++;
            }
        }
        if(ver){
            inverso[algarismos - i + cont - 1] = original[i];
        }
    }

    return valor(inverso);
}

int potencia(int a, int b){
    if(b == 0){
        return 1;
    }

    return potencia(a, b - 1) * a;
}

int valor(int numero[]){
    if(algarismos == 0){
        algarismos = posicao;
        posicao = 0;
        return 0;
    }
    posicao++;
    algarismos--;
    return numero[algarismos] * potencia(10, posicao - 1) + valor(numero);
}

void adicionarValor(int valor, int nivel){
    fila *item;
    item = (fila *) malloc(sizeof(fila));
    item->valor = valor;
    item->nivel = nivel;
    item->prox = NULL;
    
    int i;

    if(nivel == 0){
        inicio = item;
        fim = item;
        for(i = 0; i < 20000; i++){
            valores_alcancados[i] = 1;
        }
    }
    else{
        fim->prox = item;
        fim = item;
    }

    valores_alcancados[valor] = 0;
}