#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Estructuras
typedef struct Estudiante{
    char nombre[51];
    char codigo[21];
    struct Estudiante* siguiente;
} Estudiante;

typedef struct Libro{
    char titulo[51];
    char autor[51];
    char genero[51];
    char ISBN[21];
    char ubicacion[51];
    char estado[21];
    Estudiante* reservas;
    struct Libro* siguiente;
} Libro;

// Funciones de implementacion (registrar,mostrar,reservar,etc.)

int main(){
  Libro* biblioteca = NULL;
  int opcion = -1; 

  while(opcion!=0){
      printf("------------------------------------------");
      printf("\n           Menú de libreria\n");
      printf("------------------------------------------\n\n");
      printf("1. Registrar libro\n");
      printf("2. Mostrar datos de libro\n");
      printf("3. Mostrar todos los libros\n");
      printf("4. Reservar libro\n");
      printf("5. Cancelar reserva de libro\n");
      printf("6. Retirar libro\n");
      printf("7. Devolver libro\n");
      printf("8. Mostrar libros prestados\n");
      printf("9. Importar libros desde un archivo CSV\n");
      printf("10. Exportar libros a un archivo CSV\n");
      printf("0. Salir\n\n");
      printf("Selecciona una opción: ");
      scanf("%i", &opcion);
      
      switch(opcion){
          case 1:
            // Registrar libro
            // registrarLibro(&biblioteca, ...);
            break;
          case 2:
            // Mostrar datos de libro
            // mostrarDatosLibro(biblioteca);
            break;
        case 3:
            // Mostrar todos los libros
            // mostrarLibros(biblioteca);
            break;
        case 4:
            // Reservar libro
            // reservarLibro(biblioteca);
            break;
        case 5:
            // Cancelar reserva de libro
            // cancelarReservaLibro(biblioteca);
            break;
        case 6:
            // Retirar libro
            // retirarLibro(biblioteca);
            break;
        case 7:
            // Devolver libro
            // devolverLibro(biblioteca);
            break;
        case 8:
            // Mostrar libros prestados
            // mostrarLibrosPrestados(biblioteca);
            break;
        case 9:
            // Importar libros desde un archivo CSV
            // importarLibrosDesdeCSV(&biblioteca);
            break;
        case 10:
            // Exportar libros a un archivo CSV
            // exportarLibrosACSV(biblioteca);
            break;
        case 0:
            printf("\n¡Hasta luego!\n");
            break;
        default:
            printf("\nOpción inválida. Por favor, selecciona una opción válida.\n");
            break;
      }
    }

  // Liberar memoria de la biblioteca y las reservas
  // liberarBiblioteca(biblioteca);

  return 0;
}