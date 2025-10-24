#include <stdio.h>

const int TAM = 50;


void lectura (int*, int);
void frecuencia (int[], int, int[], int);
void impresion(int *, int);
void mayor(int *, int);

void main (void)
{
    int CAL[TAM], FRE[6] = {0};
    lectura(CAL, TAM);
    frecuencia(CAL, TAM ,FRE, 6);
    printf("\nFrecuencia de calificaciones\n");
    impresion (FRE,6);
    mayor(FRE,6);
}

void lectura(int VEC[], int T)
{
    int I;
    for(I=0; I<T; I++)
    {
        printf("Ingrese la calificacion -0:5- delm alumno %d: ", I+1);
        scanf("%d", &VEC[I]);
    }
}

void impresion(int VEC[], int T)
{
    int I;
    for (I=0; I<T; I++)
    printf("\nVEC[%d]: %d", I, VEC[I]);
}

void frecuencia (int A[], int P, int B[], int T)
{
int I;
int MVAL = 0, MFRE = 0;

for(I=0;I<P;I++)
{
    if(MVAL<A[I])
    {
        MFRE=I;
        MVAL = A[I];
    }
}
printf("\n\nMayor frecuencia de calificiaciones: %d\tValor: %d", MFRE, MVAL);
}