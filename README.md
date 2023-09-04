Biblioteca

  Descripción

    Esta aplicación facilita la administración de la biblioteca de su universidad. Con esta herramienta, puede realizar diversas operaciones, como agregar, eliminar, reservar, prestar y devolver libros. El programa gestiona los detalles de cada libro, incluyendo su título, autor, género, ISBN, ubicación y estado (disponible, prestado, reservado). Además, los usuarios tienen la capacidad de realizar reservas y cancelarlas según sea necesario. Toda esta funcionalidad se implementa mediante el uso de una estructura de datos tipo lista (TDA lista) para una gestión eficiente y organizada. Además,  en las reservas, el funcionamiento interno que utiliza la lógica, es de una estructura de un TDA pila.

  Cómo compilar y ejecutar

  1. Clonar el repositorio:
    
      ```
      git clone <https://github.com/username/Tarea 1 Al/Be1.git>
    
      ```
    
  2. Navegar al directorio del proyecto:
    
      ```
      cd Tarea 1 Al/Be1
      
      ```
    
  3. Compilar el código:
    
      ```
      gcc main.c Tarea 1 Al/Be1.c -o gestor
    
      ```
    
  4. Ejecutar la aplicación:
    
      ```
      ./gestor
    
      ```
    

  Funcionalidades
      Funcionando correctamente:

        - Agregar libros.
        - Ver detalles de un libro en especifico.
        - Ver todos los libros.
        - Reservar libros.
        - Eliminar reservas.
        - Mostrar libros prestados (Detalles).
        - Importar libros a archivo cvs(Detalles).
        - Exportar libros a archivo cvs(Detalles).

      Problemas conocidos:

        - Tenemos dos problemas al momento de mostrar la lista de reservas:
            1) Al momento exportar o importar no se muestran los estudiantes que reservaron los libros

            2) Al momento de mostrar los datos del libro, no se muestran correctamente los alumnos

      A mejorar:

        - De momento sabemos que el principal problema que tenemos es el de mostrar las recervas, pero el codigo a pesar de no mostarlas maneja a la perfeccion todo.

        -Organización de tiempo al momento de programar

  Contribuciones 

    Alvaro Del Pino:

      - Desarrolló las funciones Cancelar reserva de libro, Retirar libro, Devolver libro y Mostrar libros prestados.
      - **Auto-evaluación**: 3 (Aporte excelente).


    Benjamin Rodríguez:

      - Diseño del menu de usuario.
      - Desarrolló las funciones de Registrar libro, Mostrar datos, Mostrar todos los libros, Importar libros desde un archivo CSV y Exportar libros a un archivo CSV.
      - Documentación y comentarios en el código.
      - Diseño y redacción del README.
      - **Auto-evaluación**: 3 (Aporte excelente).