#include <stdio.h>
#include <math.h>


const int MAX = 100;

void lectura(int *, int);
float media(int *, int);
float varianza(int *, int, float);
float desviacion(float);
void frecuencia(int *, int, int *);
int moda(int *, int);



void main (void)
{
    int TAM, MOD, ALU[MAX], FRE[11] = {0};
    float MED, VAR, DES; 
    do 
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    }
    while(TAM >MAX || MAX < 1);
    lectura(ALU, TAM);
    MED = media(ALU, TAM);
    VAR = varianza(ALU, TAM, MED);
    DES = desviacion(VAR);
    frecuencia(ALU, TAM, FRE);
    MOD = moda(FRE, 11);
    printf("\nmedia:  %.2f", MED);
    printf("\nvarianza:  %.2f", VAR);
    printf("\ndesviacion:  %.2f", DES);
    printf("\nmoda:  %d", MOD);
}

void lectura(int A[], int T)
{
    int I;
    for(I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
    }
}


float media(int A[], int T)
{
    int I;
    float SUM= 0.0;
    for(I=0; I< T;I++)
    SUM += A[I];
    return(SUM/T);
}


float varianza(int A[], int T, float M)
{
    int I;
    float SUM = 0.0;
    for(I=0; I < T; I++)
    SUM += pow ((A[I] - M), 2);
    return(SUM / T);
}

float desviacion(float V)
{
    return(sqrt(V));
}

void frecuencia(int A[], int P, int B[])
{
    int I;
    for(I=0; I<P; I++)
    B[A[I]]++;
}

int moda(int A[], int T)
{
    int I, MOD = 0, VAL = A[0];
    for(I =1; I<T;I++)
    if(MOD < A[I])
    {
    MOD =I;
    VAL = A[I];
    }
    return(MOD);
}
