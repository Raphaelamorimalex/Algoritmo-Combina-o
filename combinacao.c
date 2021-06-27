#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** criamatriz(int tamanho){
    int i,j;
    int **matriz = (int**) malloc(tamanho*sizeof(int*));
    srand(time(NULL));
    for(i = 0; i < tamanho; i++){
        matriz[i] = (int*) malloc(tamanho*sizeof(int));
        for(j = 0; j < tamanho; j++){
            matriz[i][j] = rand()%2;
        }
    }

    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho; j++){
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
    return matriz;
}

int Existe(int valores[], int tam, int valor){
    for(int i = 0; i < tam; i++){
        if(valores[i] == valor){
            return 0;
        }
    }
    return 1;
}

void GeraAleatorio(int numero[], int qnt , int limite){
    srand((unsigned)time(NULL));
    int aux,check;
    limite++;
    for(int i = 0 ; i < qnt; i++){
        aux = rand() % limite;
        while(check == 0){
            check = Existe(numero,qnt,aux);
            aux = rand() % limite;
            getchar();
        }
        numero[i] = aux;
        printf("Valor do conjunto gerado = %d \n", numero[i]);
    }
}


int main(){
    int ** mat;
    int tamanho, r;
    printf("Digite o tamanho da matriz\n");
    scanf("%d", &tamanho);
    printf("Digite o valor do conjunto de teste\n");
    scanf("%d",&r);
    int conjun[r]; // Vetor para armazenar os valores do conjunto de teste
    GeraAleatorio(conjun,r,tamanho); // Função para geração de números aleatorios para o conjunto de teste
    mat = criamatriz(tamanho); // Criação da matriz no terminal, sendo essa uma matriz quadrada

    for(int i = 0; i < r-1; i++){
        if(mat[conjun[i]][conjun[i+1]] == 1){
            printf("As pessoas nas posições %d e %d  se conhecem \n", conjun[i], conjun[i+1]);
        }else{
            printf("As pessoas nas posições %d e %d não se conhecem \n", conjun[i],conjun[i+1]);
        }
    }
    


    return 0;
}