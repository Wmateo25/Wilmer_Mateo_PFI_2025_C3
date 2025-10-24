#include <stdio.h>


const int MAX=50;


void lectura(float [][MAX], int , int);
void intercambia(float [][MAX], int,int);
void imprime(float [][MAX],int,int);


void main(void)
{
    int F,C;
    float MAT[MAX][MAX];
    do 
    {
        printf("Ingrese el numero de filas: ");
        scanf("%d", &F);
    }
    while(F>MAX || F <1);
    do 
    {
        printf("Ingrese el numeron de columnas: ");
        scanf("%d", &C);
    }
    while(C>MAX || C < 1);

    lectura(MAT,F,C);
    intercambia(MAT,F,C);
    imprime(MAT,F,C);
}


void lectura(float A[][MAX], int F, int C)
{
    int I,J;
    for(I=0;I<F;I++)
    for(J=0;J<C;J++)
    {
        printf("Ingrese el elemento %d %d: ", I+1,J+1);
        scanf("%f", &A[I][J]);
    }
}


void intercambia(float A[][MAX], int F,int C)
{
    int I, J;
    float AUX;
    for(I=0;I<(C/2); I++)
    for(J=0;J<F;J++)
    {
        AUX= A[J][I];
        A[J][I]= A[J][C-I-1];
        A[J][C-I-1] = AUX;
    }
}

void imprime(float A[][MAX],int F, int C)
{
    int I,J;
    for(I=0;I<F;I++)
    for(J=0;J<C;J++)
    printf("\nElemento %d %d: %5.2f", I+1, J+1, A[I][J]);
}