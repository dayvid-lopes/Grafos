#include"cabeçalhos.h"
FILE *saida;

int main(){
    saida = fopen("Lista 2/resultados/resultado 1362", "w");
    imprima("teste");
    free(saida);
    return 0;
}