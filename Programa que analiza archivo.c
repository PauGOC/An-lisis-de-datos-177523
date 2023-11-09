#include <stdio.h>
#define COLUMNAS 3100
#define FILAS 50
#define TEXTO 1024*1024

int main() {
    FILE *archivo_csv = fopen("emails.csv", "r");
    if (!archivo_csv) {
        perror("Error al ejecutar el archivo");
        return 1;
    }

    char buffer[TEXTO];
    char *palabras[COLUMNAS];
    int conteo[COLUMNAS] = {0};
    int id = 415; //El ID es 177523

    if (fgets(buffer, sizeof(buffer), archivo_csv)) {
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna <= COLUMNAS) {
            palabras[columna] = strdup(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }
	int fila_actual;
	
    for ( fila_actual = 0; fila_actual <= id && fgets(buffer, sizeof(buffer), archivo_csv); fila_actual++) ;

    for ( fila_actual = 0; fila_actual < FILAS && fgets(buffer, sizeof(buffer), archivo_csv); fila_actual++) {
        char *token = strtok(buffer, ",");
        int columna = 0;
        while (token && columna < COLUMNAS) {
            conteo[columna] += atoi(token);
            token = strtok(NULL, ",");
            columna++;
        }
    }

    fclose(archivo_csv);
int i;
    FILE *salida = fopen("177523.txt", "w");
    if (!salida) {
        perror("Error al abrir el archivo de salida");
        for ( i = 0; i < COLUMNAS; i++) {
            free(palabras[i]);
        }
        return 1;
    }

    for ( i = 0; i < COLUMNAS && palabras[i] != NULL; i++) {
    	
        fprintf(salida, "%d) %s, %d\n", i+1, palabras[i], conteo[i]);
        free(palabras[i]);
    }

    fclose(salida);
    printf("El contenido desglosado se encuentra en la hoja de texto: 177523.txt\n");

    return 0;
}
