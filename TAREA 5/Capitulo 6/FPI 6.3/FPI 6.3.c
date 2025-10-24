#include <stdio.h>

const int F = 9, C =2, P =5;
void lectura(int [][C][P], int,int,int);
void funcion1(int[][C][P],int,int,int);
void funcion2(int[][C][P],int,int,int);
void funcion3(int[][C][P],int,int,int);

void main(void)
{
    int UNI[F][C][P];
    lectura(UNI,F,C,P);
    funcion1(UNI,F,C,P);
    funcion2(UNI,F,C,P);
    funcion3(UNI,6,C,P);
}


void lectura(int A[][C][P], int FI,int CO, int PR)
{
    int K,I,J;
    for(K=0;I<FI;I++)
    for(I=0;I<FI;I++)
    for(J=0;J<CO;J++)
    {
        printf("Año: %d\tCarrera: %d\tSemestre: %d", K+1,I+1,J+1);
        scanf("%d", &A[I][J][K]);
    }
}
void funcion1(int A[][C][P], int FI, int CO, int PR)
{
    int K,I,J,MAY = 0, AO = -1, SUM;
    for(K=0;K<PR;K++)
    {
        SUM =0;
        for(I=0;I<FI;I++)
        for(J=0;J<CO;J++)
        SUM += A[I][J][K];
        if(SUM>MAY)
        {
            MAY=SUM;
            AO=K;
        }
    }
    printf("\n\nAño con mayor ingreso de alumnos: %d   Alumnos: %d", AO+1,MAY);
}

void funcion2(int A[][C][P], int FI, int CO, int PR)
{
    int I,J,MAY=0, CAR = -1, SUM;
    for(I=0;I<FI;I++)
    {
        SUM=0;
        for(J=0;J<CO;J++)
        SUM += A[I][J][PR-1];
        if(SUM>MAY)
        {
            MAY = SUM;
            CAR= I;
        }
    }
    printf("\n\nCarrera con mayor numero de alumnos: %d  Alumnos: %d", CAR+1, MAY);
}

void funcion3(int A[][C][P], int FI, int CO, int PR)
{
    int K,J,MAY = 0, AO = -1, SUM;
    for(J=0;J<CO;J++)
    {
    SUM += A[FI-1][J][K];
    if(SUM > MAY)
    {
        MAY = SUM;
        AO = K;
    }
    }
    printf("\n\nAño con mayor ingreso de alumnos: %d   AlumnosL %d", AO+1,MAY);
}