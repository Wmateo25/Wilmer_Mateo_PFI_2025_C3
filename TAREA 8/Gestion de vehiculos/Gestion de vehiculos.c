    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define ARCHIVO "vehiculos.dat"
    #define MAX_MARCA 50
    #define MAX_MODELO 50

    typedef struct {
        char marca[MAX_MARCA];
        float precio;
        char modelo[MAX_MODELO];
        int anio;
    } Vehiculo;

    void mostrarMenu();
    void listarVehiculos();
    void agregarVehiculo();
    void limpiarBuffer();
    void pausar();

    int main() {
        int opcion;
        
        do {
            mostrarMenu();
            printf("Seleccione una opcion: ");
            scanf("%d", &opcion);
            limpiarBuffer();
            
            switch(opcion) {
                case 1:
                    listarVehiculos();
                    break;
                case 2:
                    agregarVehiculo();
                    break;
                case 3:
                    printf("\nGracias por usar el sistema!\n");
                    break;
                default:
                    printf("\nOpcion invalida. Intente de nuevo.\n");
                    pausar();
            }
        } while(opcion != 3);
        
        return 0;
    }

    void mostrarMenu() {
        system("cls");
        printf("\n");
        printf("========================================\n");
        printf("  SISTEMA DE GESTION DE VEHICULOS     \n");
        printf("========================================\n");
        printf("\n");
        printf("  1. Lista de vehiculos\n");
        printf("  2. Agregar vehiculo\n");
        printf("  3. Salir\n");
        printf("\n");
        printf("========================================\n");
    }

    void listarVehiculos() {
        FILE *archivo;
        Vehiculo vehiculo;
        int contador = 0;
        
        archivo = fopen(ARCHIVO, "rb");
        
        system("cls");
        printf("\n");
        printf("========================================\n");
        printf("       LISTA DE VEHICULOS              \n");
        printf("========================================\n");
        printf("\n");
        
        if(archivo == NULL) {
            printf("No hay vehiculos registrados aun.\n");
            pausar();
            return;
        }
        
        while(fread(&vehiculo, sizeof(Vehiculo), 1, archivo)) {
            contador++;
            printf("----------------------------------------\n");
            printf("Vehiculo #%d\n", contador);
            printf("----------------------------------------\n");
            printf("  Marca:  %s\n", vehiculo.marca);
            printf("  Modelo: %s\n", vehiculo.modelo);
            printf("  Anio:   %d\n", vehiculo.anio);
            printf("  Precio: $%.2f\n", vehiculo.precio);
            printf("\n");
        }
        
        if(contador == 0) {
            printf("No hay vehiculos registrados.\n");
        } else {
            printf("========================================\n");
            printf("Total de vehiculos: %d\n", contador);
        }
        
        fclose(archivo);
        pausar();
    }

    void agregarVehiculo() {
        FILE *archivo;
        Vehiculo vehiculo;
        
        system("cls");
        printf("\n");
        printf("========================================\n");
        printf("       AGREGAR NUEVO VEHICULO          \n");
        printf("========================================\n");
        printf("\n");
        
        printf("Marca: ");
        fgets(vehiculo.marca, MAX_MARCA, stdin);
        vehiculo.marca[strcspn(vehiculo.marca, "\n")] = 0;
        
        printf("Modelo: ");
        fgets(vehiculo.modelo, MAX_MODELO, stdin);
        vehiculo.modelo[strcspn(vehiculo.modelo, "\n")] = 0;
        
        printf("Anio: ");
        scanf("%d", &vehiculo.anio);
        
        printf("Precio: $");
        scanf("%f", &vehiculo.precio);
        limpiarBuffer();
        
        archivo = fopen(ARCHIVO, "ab");
        
        if(archivo == NULL) {
            printf("\nError al abrir el archivo.\n");
            pausar();
            return;
        }
        
        fwrite(&vehiculo, sizeof(Vehiculo), 1, archivo);
        fclose(archivo);
        
        printf("\n");
        printf("========================================\n");
        printf("Vehiculo agregado exitosamente!\n");
        printf("========================================\n");
        pausar();
    }

    void limpiarBuffer() {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    void pausar() {
        printf("\nPresione ENTER para continuar...");
        getchar();
    }
