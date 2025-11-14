#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <complex.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 4

/* ---------- Utilidades de formato ---------- */

/* imprime un double sin ceros de más, con anchura mínima para columnas */
void print_double_col(double x, int width) 
{
    /* usamos %.10g para evitar ceros sobrantes y notación innecesaria */
    char buf[64];
    snprintf(buf, sizeof(buf), "%.10g", x);
    printf("%*s", width, buf);
}

/* imprime numero complejo con buen formato: a + bi, evitando + - confusos */
void print_complex_col(double complex z, int width)
 {
    double re = creal(z);
    double im = cimag(z);
    char buf[128];
    /* Formateamos cada parte con %.10g evitando ceros sobrantes */
    char bre[48], bim[48];
    snprintf(bre, sizeof(bre), "%.10g", re);
    snprintf(bim, sizeof(bim), "%.10g", fabs(im));
    if (fabs(im) < 1e-12) {
        /* prácticamente real */
        snprintf(buf, sizeof(buf), "%s", bre);
    } else if (fabs(re) < 1e-12) {
        /* prácticamente imaginario */
        if (im < 0) snprintf(buf, sizeof(buf), "-%si", bim);
        else snprintf(buf, sizeof(buf), "%si", bim);
    } else {
        /* ambos no nulos */
        if (im < 0) snprintf(buf, sizeof(buf), "%s - %si", bre, bim);
        else snprintf(buf, sizeof(buf), "%s + %si", bre, bim);
    }
    printf("%*s", width, buf);
}

/* lee un double con validación mínima */
double leer_double(const char *prompt) 
{
    double x;
    int rc;
    char line[128];
    while (1) {
        printf("%s", prompt);
        if (!fgets(line, sizeof(line), stdin)) exit(0);
        /* permitir coma como decimal si el usuario ingresa coma */
        for (char *p = line; *p; ++p) if (*p == ',') *p = '.';
        rc = sscanf(line, "%lf", &x);
        if (rc == 1) return x;
        printf("Entrada inválida. Intenta de nuevo.\n");
    }
}

/* ---------- Operaciones con double ---------- */

double add_double(double a, double b) { return a + b; }
double sub_double(double a, double b) { return a - b; }
double mul_double(double a, double b) { return a * b; }
double div_double(double a, double b) {
    if (fabs(b) < 1e-15) {
        fprintf(stderr, "Error: división por cero.\n");
        return NAN;
    }
    return a / b;
}

/* ---------- Prototipos (para organizar las 3 partes) ---------- */
/* Parte 2 contendrá operaciones con complejos y su menú */
void menu_complejos(void);

/* Parte 3 contendrá operaciones con matrices y su menú */
void menu_matrices(void);

/* menú para operaciones con double (normales) */
void menu_normales(void) {
    while (1) {
        printf("\n--- [Calculus C] -> Normales (double) ---\n");
        printf("1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n0) Volver\n");
        printf("Selecciona una opcion: ");
        int opt;
        if (scanf("%d%*c", &opt) != 1) { /* %*c para consumir newline */
            /* limpiar stdin */
            int c; while ((c = getchar()) != '\n' && c != EOF) ;
            printf("Opcion inválida.\n");
            continue;
        }
        if (opt == 0) break;
        double a = leer_double("Ingrese el primer numero: ");
        double b = leer_double("Ingrese el segundo numero: ");
        double res;
        switch (opt) {
            case 1: res = add_double(a,b); printf("\nResultado: "); print_double_col(res, 12); printf("\n"); break;
            case 2: res = sub_double(a,b); printf("\nResultado: "); print_double_col(res, 12); printf("\n"); break;
            case 3: res = mul_double(a,b); printf("\nResultado: "); print_double_col(res, 12); printf("\n"); break;
            case 4: res = div_double(a,b); if (!isnan(res)) { printf("\nResultado: "); print_double_col(res, 12); printf("\n"); } break;
            default: printf("Opcion no válida.\n");
        }
    }
}

/* ---------- Menú principal ---------- */
void menu_principal(void) {
    while (1) {
        printf("\n========================================\n");
        printf("         [Calculus C] - Calculadora     \n");
        printf("========================================\n");
        printf("Elija el tipo de numeros:\n");
        printf("1) Normales (double)\n2) Complejos\n3) Matrices (max 4x4)\n0) Salir\n");
        printf("Selecciona una opcion: ");
        int opt;
        if (scanf("%d%*c", &opt) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) ;
            printf("Entrada inválida.\n");
            continue;
        }
        if (opt == 0) {
            printf("Saliendo. Gracias por usar Calculus C.\n");
            break;
        }
        switch (opt) {
            case 1: menu_normales(); break;
            case 2: menu_complejos(); break; /* implementación en Parte 2 */
            case 3: menu_matrices(); break;  /* implementación en Parte 3 */
            default: printf("Opcion inválida.\n");
        }
    }
}

#include <ctype.h>

/* funciones básicas con complex.h */
double complex add_complex(double complex a, double complex b) { return a + b; }
double complex sub_complex(double complex a, double complex b) { return a - b; }
double complex mul_complex(double complex a, double complex b) { return a * b; }
double complex div_complex(double complex a, double complex b) {
    if (cabs(b) < 1e-15) {
        fprintf(stderr, "Error: división por cero (complejo).\n");
        return NAN + NAN*I;
    }
    return a / b;
}

/* lee numero complejo en dos formas: "re im" o "a+bi" (sencillo) - implementamos lectura por dos doubles */
double complex leer_complex(const char *prompt)
 {
    printf("%s\n", prompt);
    double re = leer_double("  Parte real: ");
    double im = leer_double("  Parte imaginaria: ");
    return re + im * I;
}

/* menú para complejos */
void menu_complejos(void) 
{
    while (1) {
        printf("\n--- [Calculus C] -> Complejos ---\n");
        printf("1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n0) Volver\n");
        printf("Selecciona una opcion: ");
        int opt;
        if (scanf("%d%*c", &opt) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) ;
            printf("Opcion inválida.\n");
            continue;
        }
        if (opt == 0) break;
        double complex a = leer_complex("Ingrese el primer numero complejo:");
        double complex b = leer_complex("Ingrese el segundo numero complejo:");
        double complex r;
        switch (opt) {
            case 1: r = add_complex(a,b); printf("\nResultado: "); print_complex_col(r, 24); printf("\n"); break;
            case 2: r = sub_complex(a,b); printf("\nResultado: "); print_complex_col(r, 24); printf("\n"); break;
            case 3: r = mul_complex(a,b); printf("\nResultado: "); print_complex_col(r, 24); printf("\n"); break;
            case 4: r = div_complex(a,b); if (!isnan(creal(r)) || !isnan(cimag(r))) { printf("\nResultado: "); print_complex_col(r, 24); printf("\n"); } break;
            default: printf("Opcion no válida.\n");
        }
    }
}

typedef struct {
    int rows, cols;
    double a[MAX_N][MAX_N];
} Matrix;

/* imprimir matriz con columnas alineadas */
void print_matrix(const Matrix *m)
 {
    int w = 12; /* anchura columna */
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->cols; ++j) {
            print_double_col(m->a[i][j], w);
        }
        printf("\n");
    }
}

/* leer dimensiones con validación */
void leer_dimensiones(int *r, int *c)
 {
    while (1) {
        int rr = (int)leer_double("  Filas (1-4): ");
        int cc = (int)leer_double("  Columnas (1-4): ");
        if (rr>=1 && rr<=MAX_N && cc>=1 && cc<=MAX_N) { *r=rr; *c=cc; break; }
        printf("Dimensiones inválidas. Deben estar entre 1 y %d.\n", MAX_N);
    }
}

/* leer matriz */
Matrix leer_matrix(const char *titulo)
 {
    Matrix m;
    printf("%s\n", titulo);
    leer_dimensiones(&m.rows, &m.cols);
    for (int i=0;i<m.rows;++i) {
        for (int j=0;j<m.cols;++j) {
            char prompt[64];
            snprintf(prompt, sizeof(prompt), "  elemento [%d,%d]: ", i+1, j+1);
            m.a[i][j] = leer_double(prompt);
        }
    }
    return m;
}

/* suma/resta (dimensiones iguales) */
bool same_dim(const Matrix *A, const Matrix *B)
 {
    return A->rows==B->rows && A->cols==B->cols;
}

Matrix add_matrix(const Matrix *A, const Matrix *B) 
{
    Matrix R = *A;
    for (int i=0;i<A->rows;++i) for (int j=0;j<A->cols;++j) R.a[i][j] = A->a[i][j] + B->a[i][j];
    return R;
}
Matrix sub_matrix(const Matrix *A, const Matrix *B)
 {
    Matrix R = *A;
    for (int i=0;i<A->rows;++i) for (int j=0;j<A->cols;++j) R.a[i][j] = A->a[i][j] - B->a[i][j];
    return R;
}

/* multiplicación A(rows x k) * B(k x cols) */
bool can_mul(const Matrix *A, const Matrix *B)
 {
    return A->cols == B->rows;
}
Matrix mul_matrix(const Matrix *A, const Matrix *B) 
{
    Matrix R;
    R.rows = A->rows; R.cols = B->cols;
    for (int i=0;i<R.rows;++i) for (int j=0;j<R.cols;++j) R.a[i][j]=0.0;
    for (int i=0;i<A->rows;++i) {
        for (int j=0;j<B->cols;++j) {
            double s=0;
            for (int k=0;k<A->cols;++k) s += A->a[i][k] * B->a[k][j];
            R.a[i][j] = s;
        }
    }
    return R;
}

/* Inversa mediante eliminación Gauss-Jordan para matrices cuadradas hasta 4x4 */
bool inverse_matrix(const Matrix *A, Matrix *inv) 
{
    if (A->rows != A->cols) return false;
    int n = A->rows;
    double aug[MAX_N][2*MAX_N];
    /* construir matriz aumentada [A|I] */
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) aug[i][j] = A->a[i][j];
        for (int j=0;j<n;++j) aug[i][n+j] = (i==j)?1.0:0.0;
    }
    /* Gauss-Jordan */
    for (int col=0; col<n; ++col) {
        /* buscar pivote */
        int piv = col;
        for (int r=col; r<n; ++r) {
            if (fabs(aug[r][col]) > fabs(aug[piv][col])) piv = r;
        }
        if (fabs(aug[piv][col]) < 1e-12) return false; /* singular */
        /* intercambiar filas si es necesario */
        if (piv != col) {
            for (int j=0;j<2*n;++j) {
                double tmp = aug[col][j]; aug[col][j] = aug[piv][j]; aug[piv][j] = tmp;
            }
        }
        /* normalizar fila pivot */
        double pivval = aug[col][col];
        for (int j=0;j<2*n;++j) aug[col][j] /= pivval;
        /* eliminar otras filas */
        for (int r=0;r<n;++r) if (r!=col) {
            double factor = aug[r][col];
            for (int j=0;j<2*n;++j) aug[r][j] -= factor * aug[col][j];
        }
    }
    /* copiar inversa */
    inv->rows = inv->cols = n;
    for (int i=0;i<n;++i) for (int j=0;j<n;++j) inv->a[i][j] = aug[i][n+j];
    return true;
}

/* división de matrices: A * inv(B) cuando es posible (B cuadrada e invertible y dimensiones compatibles) */
bool can_div_matrix(const Matrix *A, const Matrix *B) {
    /* A (m x k), B (k x k) cuadrada e inv(B) tiene k x k => A * inv(B) es (m x k) */
    return (B->rows == B->cols) && (A->cols == B->rows);
}
Matrix div_matrix(const Matrix *A, const Matrix *B, bool *ok) {
    Matrix R;
    *ok = false;
    if (!can_div_matrix(A,B)) return R;
    Matrix Binv;
    if (!inverse_matrix(B, &Binv)) return R;
    R = mul_matrix(A, &Binv);
    *ok = true;
    return R;
}

/* Menú matrices.*/
void menu_matrices(void)
 {
    while (1) {
        printf("\n--- [Calculus C] -> Matrices (max 4x4) ---\n");
        printf("1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir (A * inv(B))\n0) Volver\n");
        printf("Selecciona una opcion: ");
        int opt;
        if (scanf("%d%*c", &opt) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) ;
            printf("Opcion inválida.\n");
            continue;
        }
        if (opt == 0) break;
        Matrix A = leer_matrix("Matriz A:");
        Matrix B = leer_matrix("Matriz B:");
        Matrix R;
        bool ok = true;
        switch (opt) {
            case 1:
                if (!same_dim(&A,&B)) { printf("Error: dimensiones deben ser iguales para sumar.\n"); break; }
                R = add_matrix(&A,&B);
                printf("\nResultado A + B:\n"); print_matrix(&R); break;
            case 2:
                if (!same_dim(&A,&B)) { printf("Error: dimensiones deben ser iguales para restar.\n"); break; }
                R = sub_matrix(&A,&B);
                printf("\nResultado A - B:\n"); print_matrix(&R); break;
            case 3:
                if (!can_mul(&A,&B)) { printf("Error: dimensiones no compatibles para multiplicar (A.cols must equal B.rows).\n"); break; }
                R = mul_matrix(&A,&B);
                printf("\nResultado A * B:\n"); print_matrix(&R); break;
            case 4:
                R = div_matrix(&A,&B,&ok);
                if (!ok) { printf("Error: no se pudo dividir. B debe ser cuadrada e invertible y A.cols debe igualar B.rows.\n"); break; }
                printf("\nResultado A * inv(B):\n"); print_matrix(&R); break;
            default:
                printf("Opcion no válida.\n");
        }
    }
}

/* ---------- main ---------- */
int main(void) {
    /* Bienvenida inicial con nombre visible */
    printf("========================================\n");
    printf("             [Calculus C]\n");
    printf("     Calculadora avanzada en lenguaje C\n");
    printf("========================================\n");
    menu_principal();
    return 0;
}
