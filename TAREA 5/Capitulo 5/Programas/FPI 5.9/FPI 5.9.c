#include <stdio.h>


const int MAX = 100;

void lectura(int [], int);
int busca(int *, int, int);


void main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do 
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while(TAM>MAX || TAM<1);
    lectura(VEC,TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = busca (VEC, TAM, ELE);
    if(RES)
    printf("\nEl lemento se encuentra en la posicion %d", RES);
    else
    printf("\nEl elemento no se encuentra en el arreglo");
}

void lectura(int A[], int T)
{
    int I;
    for(I=0; I<T;I++)
    {
        printf("Ingrese el elemnto %d:", I+1);
        scanf("%d", &A[I]);
    }
}

int busca (int A[], int T, int K)
{
    int I = 0, BAN = 0, RES;
    while(I<T && !!BAN)
    if (A[I] == K)
    BAN++;
    else
    I++;
    if(BAN)
    RES =  I+1;
    else
    RES = BAN;
    return(RES);
}
