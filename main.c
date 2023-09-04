#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

//-------------
// Estructura |
//-------------
typedef struct Libro{
    char titulo[51];
    char autor[51];
    char genero[51];
    char ISBN[21];
    char ubicacion[51];
    char estado[21];
    List* reservas;
} Libro;

//----------------------------------------------------------------
// Funciones de implementación (registrar,mostrar,reservar,etc.) |
//----------------------------------------------------------------

//Estas funciones son para evitar que se exceda el tamaño especificado de la cadena y para eliminar cualquier carácter de salto de línea residual en el búfer de entrada después de la lectura. 
void leerCadena51(char cadena[51]){
  scanf("%50[^\n]s",cadena);
  getchar();
}
void leerCadena21(char cadena[21]){
  scanf("%50[^\n]s",cadena);
  getchar();
}

//Esta función permite al usuario ingresar los detalles de un nuevo libro y lo agrega a una lista de libros. Además, establece el estado del libro como "Disponible" y crea una lista vacía de reservas para el libro recién agregado.
void registrarLibro(List* lista){
  getchar();
  char tituloAux[51];
  char autorAux[51];
  char generoAux[51];
  char ISBNAux[21];
  char ubicacionAux[51];

  printf("Ingrese el título del libro: ");
  leerCadena51(tituloAux);
  
  printf("Ingrese el autor del libro: ");
  leerCadena51(autorAux);

  printf("Ingrese el genero del libro: ");
  leerCadena51(generoAux);

  printf("Ingrese el ISBN del libro: ");
  leerCadena21(ISBNAux);

  printf("Ingrese la ubicación del libro: ");
  leerCadena51(ubicacionAux);

  Libro* aux = malloc(sizeof(Libro));
  strcpy(aux->titulo, tituloAux);
  strcpy(aux->autor, autorAux);
  strcpy(aux->genero, generoAux);
  strcpy(aux->ISBN, ISBNAux);
  strcpy(aux->ubicacion, ubicacionAux);
  strcpy(aux->estado, "Disponible");
  aux->reservas = createList();

  pushFront(lista, aux);
  printf("\nEl libro ha sido añadido correctamente!\n\n");
}

//Esta función permite al usuario buscar y visualizar los detalles de un libro específico en la biblioteca, incluyendo información como el título, autor, género, ISBN, ubicación, estado y quiénes lo tienen reservado si no está disponible o si esta prestado.
void mostrarDatosLibro(List* lista){
  getchar();
  char tituloAux[51];
  char autorAux[51];

  printf("Ingrese el título del libro: ");
  leerCadena21(tituloAux);

  printf("Ingrese el autor del libro: ");
  leerCadena21(autorAux);

  Libro* aux = firstList(lista);
  while(aux != NULL){

    if(strcmp(tituloAux, aux->titulo) == 0 && strcmp(autorAux, aux->autor) == 0){

      printf("\n------------------------------------------\n");
      printf("         Datos del libro '%s'\n",aux->titulo);
      printf("------------------------------------------\n\n");
      printf("Título: %s\n", aux->titulo);
      printf("Autor: %s\n", aux->autor); 
      printf("Genero: %s\n", aux->genero); 
      printf("ISBN: %s\n", aux->ISBN); 
      printf("Ubicación: %s\n", aux->ubicacion);

      if(strcmp(aux->estado,"Disponible")!= 0){
        printf("Estado: %s\n", aux->estado);
        char* aux2 = firstList(aux->reservas);
        printf("Reservado por:");

        while(aux2!=NULL){
          printf(" %s,",aux2);
          aux2 = nextList(aux->reservas);
        }
        printf("\n");
      }
      else{
        printf("Estado: Disponible\n");
      }
      
      printf("\n");
      return;
    }
    aux=nextList(lista);
  }
  printf("\nEl libro no está\n\n");
  
}

//Esta función permite visualizar de manera organizada la lista de libros registrados en la biblioteca, mostrando el título y el autor de cada libro en una tabla. También maneja el caso en el que no haya libros registrados en absoluto.
void mostrarLibros(List* lista){
  Libro* aux = firstList(lista);
  if (aux == NULL) {
    printf("\nNo hay libros registrados!\n\n");
    return;
  }

  printf("\n------------------------------------------\n");
  printf("          Libros Registrados\n");
  printf("------------------------------------------\n");

  printf("%-22s %-22s\n", "Título", "Autor");
  printf("------------------------------------------\n\n");

  while (aux != NULL) {
      printf("%-22s%-22s\n", aux->titulo, aux->autor);
      aux = nextList(lista);
  }
  
  printf("\n");
}

//Esta función permite a un estudiante reservar un libro en la biblioteca, gestionando la lista de reservas y actualizando el estado del libro. También muestra mensajes apropiados en función de si el libro está disponible o no.
void reservarLibro(List* lista){
  getchar();
  char tituloAux[51];
  char autorAux[21];

  printf("\nIngrese el título del libro: ");
  leerCadena51(&tituloAux);

  printf("Ingrese el autor del libro: ");
  leerCadena51(autorAux);

  Libro* aux = firstList(lista);
  while(aux != NULL){

    if(strcmp(tituloAux, aux->titulo) == 0 && strcmp(autorAux, aux->autor) == 0){
      
      char estudiante[51];
      printf("Ingrese el nombre del estudiante: ");
      leerCadena51(estudiante);
      pushBack(aux->reservas, strdup(estudiante));
      strcpy(aux->estado,"Reservado");
      printf("\nEl libro fue reservado con exito a %s!\n\n",estudiante);
      return;
    }
    
    aux=nextList(lista);
  }
  printf("\nEl libro no está!\n");
}

//Esta función permite a un estudiante cancelar su reserva de un libro en la biblioteca, gestionando la lista de reservas y actualizando el estado del libro en función de si quedan reservas activas o no. Además, muestra mensajes apropiados en función de las condiciones.
void cancelarReservaLibro(List* lista){
    getchar();
    char tituloAux[51];
    char autorAux[51];
    char estudianteAux[51];
  
    printf("Ingrese el título del libro: ");
    leerCadena51(tituloAux);

    printf("Ingrese el autor del libro: ");
    leerCadena51(autorAux);

    printf("Ingrese el nombre del estudiante que desea cancelar la reserva: ");
    leerCadena51(estudianteAux);

    List* aux = lista;
    Libro* libro= firstList(aux);

    while(libro != NULL){
      if (strcmp(tituloAux, libro->titulo) == 0 && strcmp(autorAux, libro->autor) == 0){
        List* reservas = libro->reservas;
        char* reservaData = firstList(reservas);

        while(reservaData != NULL){

          if(strcmp(estudianteAux, reservaData) == 0){
            printf("\nReserva cancelada con éxito para %s.\n\n", estudianteAux);
            popCurrent(reservas);

            char* aux3= firstList(reservas);
            if(aux3==NULL){
              strcpy(libro->estado, "Disponible");
            }
            return;
          }
          reservaData = nextList(reservas); 
        }
        printf("\nEl estudiante no tiene una reserva para este libro.\n\n");
        return;
      }
    }
    libro = (Libro*)nextList(aux); 
    
    printf("\nEl libro no está en la biblioteca.\n\n");
}

//Esta función permite a un estudiante retirar un libro de la biblioteca, actualizando su estado y gestionando las reservas si es necesario, y muestra mensajes apropiados en función de las condiciones.
void retirarLibro(List* lista){
    getchar();
    char tituloAux[51];
    char autorAux[51];
    char estudianteAux[51];
  
    printf("Ingrese el título del libro: ");
    leerCadena51(tituloAux);

    printf("Ingrese el autor del libro: ");
    leerCadena51(autorAux);

    printf("Ingrese su nombre para retirar el libro: ");
    leerCadena51(estudianteAux);

    Libro* aux = firstList(lista);
    while(aux != NULL){
        if(strcmp(tituloAux, aux->titulo) == 0 && strcmp(autorAux, aux->autor) == 0){
            if(strcmp(aux->estado, "Disponible") == 0){
                strcpy(aux->estado, "Prestado");
                printf("\nLibro \"%s\" de \"%s\" ha sido retirado por %s.\n\n", aux->titulo, aux->autor, estudianteAux);
                return;
            }
            else{ 
              if(strcmp(aux->estado, "Reservado") == 0){
                List* reservas = aux->reservas;
                void* primerReservante = firstList(reservas);
              
                if(primerReservante != NULL && strcmp(estudianteAux, (char*)primerReservante) == 0){
                  popFront(reservas);
                  strcpy(aux->estado, "Prestado");
                  printf("\nLibro \"%s\" de \"%s\" ha sido retirado por %s.\n\n", aux->titulo, aux->autor, estudianteAux);
                  return;
                }
              }
            }
            printf("\nEl libro no puede ser retirado en este momento.\n\n");
            return;
        }
        aux = nextList(lista);
    }
    printf("\nEl libro no está en la biblioteca.\n\n");
}

//Esta función permite a un estudiante devolver un libro prestado o reservado, actualizando su estado a "Disponible" si estaba en uno de esos estados y mostrando mensajes apropiados en función de las condiciones.
void devolverLibro(List* lista){
    getchar();
    char tituloAux[51];
    char autorAux[51];

    printf("\nIngrese el título del libro: ");
    leerCadena51(tituloAux);

    printf("Ingrese el autor del libro: ");
    leerCadena51(autorAux);

    Libro* aux = firstList(lista);
    while(aux != NULL){
        if(strcmp(tituloAux, aux->titulo) == 0 && strcmp(autorAux, aux->autor) == 0){
            if(strcmp(aux->estado, "Reservado" ) == 0 || strcmp(aux->estado, "Prestado")== 0){
                strcpy(aux->estado, "Disponible");
                printf("\nLibro \"%s\" de \"%s\" ha sido devuelto.\n\n", aux->titulo, aux->autor);
            } else {
                printf("\nEl libro \"%s\" de \"%s\" ya está disponible.\n\n", aux->titulo, aux->autor);
            }
            return;
        }
        aux = nextList(lista);
    }
    printf("\nEl libro no está en la biblioteca.\n\n");
}

//Esta función muestra de manera detallada los libros prestados en la biblioteca, incluyendo sus títulos, autores y los nombres de solo los estudiantes que los tienen prestados. También maneja el caso en el que no haya libros prestados, mostrando un mensaje apropiado en ese caso.
void mostrarLibrosPrestados(List* lista){
    Libro* aux = firstList(lista);
    int prestados = 0;

    printf("\n------------------------------------------\n");
    printf("        Libros Prestados\n");
    printf("------------------------------------------\n");

    while (aux != NULL) {
        if (strcmp(aux->estado, "Prestado") == 0) {
            printf("Título: %s, Autor: %s, Estudiante: ", aux->titulo, aux->autor);
          
            List* reservas = aux->reservas;
            void* reservaData = firstList(reservas);

            while (reservaData != NULL) {
                printf("%s", (char*)reservaData);
                reservaData = nextList(reservas);
                if (reservaData != NULL) {
                  printf(", ");
                }
            }

            printf("\n");

            prestados++;
        }

        aux = nextList(lista);
    }

    if (prestados == 0) {
        printf("\nNo hay libros prestados en este momento.\n");
    }

    printf("\n");
}

//Esta función escanea una línea de texto CSV y extrae el campo deseado según el índice k, tomando en cuenta las comas como separadores de campo y manejando adecuadamente los casos de comas iniciales y finales.
const char* get_csv_field(char* tmp, int k){
  
  int i = 0, j = 0;
  char* ret = (char*)malloc(100 * sizeof(char));

  // Saltar las comas iniciales (si las hay)
  while(tmp[i] == ','){
    i++;
  }

  while(tmp[i] != '\0') {
    if(tmp[i] == ','){
      if(k == j){
        ret[j] = '\0';  // Agregar terminador nulo
        return ret;
      }
    j++;
    i++;
    } 
    else{
      ret[j++] = tmp[i++];
    }
  }

  if (k == j) {
    ret[j] = '\0';  // Agregar terminador nulo
    return ret;
  }

  return NULL;
}

//Esta función permite importar datos de un archivo CSV, dividiendo las líneas en campos y creando objetos Libro con estos datos, que luego se almacenan en una lista enlazada.
void importarLibrosDesdeCSV(List* lista) {
  FILE* archImportar;
  char nombreArchivo[100];
  printf("Ingrese el nombre del archivo en formato .csv: ");
  scanf("%s", nombreArchivo);

  archImportar = fopen(nombreArchivo, "r");

  if(!archImportar){
    printf("Error: no se pudo abrir el archivo\n");
    return;
  }
  
  printf("\nSe han importado los datos al archivo %s\n\n", nombreArchivo);

  char linea[1024];

  // Leer la cabecera (encabezado) del archivo CSV
  fgets(linea, 1024, archImportar);

  while(fgets(linea, 1024, archImportar) != NULL){
    Libro* libroN = (Libro*)malloc(sizeof(Libro));
    libroN->reservas = createList();
    char* token;
    int i = 0;

    // Dividir la línea en tokens separados por comas
    token = strtok(linea, ",");
    
    while(token != NULL){
      switch (i){
        case 0:
          strcpy(libroN->titulo, token);
          break;
        case 1:
          strcpy(libroN->autor, token);
          break;
        case 2:
          strcpy(libroN->genero, token);
          break;
        case 3:
          strcpy(libroN->ISBN, token);
          break;
        case 4:
          strcpy(libroN->ubicacion, token);
          break;
        case 5:
          strcpy(libroN->estado, token);
          break;
        case 6:
          // Dividir el último campo (reservas) en tokens separados por comas
          token = strtok(token, "\n");
          char* reservas = strtok(token, ",");
          while(reservas != NULL){
            pushBack(libroN->reservas, strdup(reservas));
            reservas = strtok(NULL, ",");
          }
          break;
        default:
          break;
      }

      token = strtok(NULL, ",");
      i++;
    }
    pushFront(lista, libroN);
  }

  fclose(archImportar);
}

//Esta función toma la lista de libros y la exporta como un archivo CSV estructurado con campos separados por comas y en cabezados de columna.
void exportarLibrosACSV(List* lista, const char* archivo) {
  FILE* archivoCSV = fopen(archivo, "w");
  if(archivoCSV == NULL){
    printf("No se pudo abrir el archivo CSV para exportar.\n");
    return;
  }

  fprintf(archivoCSV, "Título,Autor,Genero,ISBN,Ubicación,Estado\n");

  Libro* libro = firstList(lista);

  while(libro != NULL){
    fprintf(archivoCSV, "\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\"\n",libro->titulo, libro->autor, libro->genero, libro->ISBN, libro->ubicacion, libro->estado);
    libro = nextList(lista);
  }

  fclose(archivoCSV);
  printf("\nLos libros han sido exportados a %s con éxito.\n\n", archivo);
}

//--------------------
// Función Principal |
//--------------------
int main(){
  List* lista = createList();
  int opcion = -1; 

  while(opcion!=0){
      printf("------------------------------------------\n");
      printf("           Menú de libreria\n");
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
      scanf("%d",&opcion);
      
      switch(opcion){
          case 1:
            // Registrar libro
            registrarLibro(lista);
            break;
          case 2:
            // Mostrar datos de libro
            mostrarDatosLibro(lista);
            break;
        case 3:
            // Mostrar todos los libros
            mostrarLibros(lista);
            break;
        case 4:
            // Reservar libro
            reservarLibro(lista);
            break;
        case 5:
            // Cancelar reserva de libro
            cancelarReservaLibro(lista);
            break;
        case 6:
            // Retirar libro
            retirarLibro(lista);
            break;
        case 7:
            // Devolver libro
            devolverLibro(lista);
            break;
        case 8:
            // Mostrar libros prestados
            mostrarLibrosPrestados(lista);
            break;
        case 9:
            // Importar libros desde un archivo CSV
            importarLibrosDesdeCSV(lista);
            break;
        case 10:
            // Exportar libros a un archivo CSV
            exportarLibrosACSV(lista, "biblioteca_exportada.csv");
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
  free(lista);
  return 0;
}