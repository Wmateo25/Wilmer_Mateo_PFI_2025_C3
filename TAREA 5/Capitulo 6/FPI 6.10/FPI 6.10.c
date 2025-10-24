#include <stdio.h>


const int MAX=50;

void cuadrado(int[][MAX], int);
void imprime(int [][MAX], int);

void main(void)
{
    int CMA[MAX][MAX], TAM;
    do 
    {
        printf("Ingrese el tamaño impar de la matriz: ");
        scanf("%d",&TAM);
    }
    while((TAM> MAX || TAM <1) && (TAM % 2));
    cuadrado(CMA,TAM);
    imprime(CMA,TAM);
}


void cuadrado(int A[][MAX], int N)
{
    int I, FIL =0, COL =N / 2, NUM = N * N;
    while(I<=NUM)
    {
        A[FIL][COL]=I;
        if (I%N != 0)
        {
            FIL = (FIL =1 + N) % N;
            COL = (COL + 1) % N;
        }
        else
        FIL ++;
        I++;
    }
}

void imprime(int A[][MAX], int N)
{
    int I,J;
    for(I=0; I<N;I++)
    for(J=0;J<N;J++)
    printf("\nelemento %d %d: %d", I+1, J+1, A[I][J]);
}