#include <stdio.h>

void lectura(int *, int);
void imprime(int *,int);
void elimina(int A[], int *T);


void main(void)
{
    int TAM, ARRE[100];
    do 
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    lectura(ARRE, TAM);
    elimina(ARRE, &TAM);
    imprime(ARRE, TAM);
    return 0;
}

void lectura(int A[], int T)
{
    printf("\n");
    int I;
    for(I=0;I<T;I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}


void imprime(int A[], int T)
{
    int I;
    for(I=0;I<T;I++)
    printf("\nA[%d]: %d", I, A[I]);
}

void elimina (int A[], int *T)
{
int I = 0, K, L;
while(I<(*T-1))
{
    K=I+1;
    while(K<= (*T-1))
    {
        if (A[I]==A[K])
        {
            for(L = K; L<(*T-1); L++)
            A[L]=A[L+1];
            *T= *T -1;
        }
        else
        K++;
    }
    I++;
}
}