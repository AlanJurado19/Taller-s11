#include <stdio.h>
#include "funciones.h"

int main()
{
    struct Libro biblioteca[MAX];
    int contador = 0;
    int opcion;

    do
    {
        printf("\n-menu de biblioteca\n");
        printf("1. registrar libro\n");
        printf("2. mostrar libros\n");
        printf("3. buscar libro\n");
        printf("4. actualizar estado de un libro\n");
        printf("5. eliminar libro\n");
        printf("6. salir\n");
        printf("seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch (opcion)
        {
        case 1:
            registrarLibro(biblioteca, &contador);
            break;

        case 2:
            if (contador == 0)
                printf("no hay libros registrados.\n");
            else
                mostrarLibros(biblioteca, contador);
            break;

        case 3:
            if (contador == 0)
                printf("no hay libros para buscar.\n");
            else
                buscarLibro(biblioteca, contador);
            break;

        case 4:
            if (contador == 0)
                printf("no hay libros para actualizar.\n");
            else
                actualizarEstado(biblioteca, contador);
            break;

        case 5:
            if (contador == 0)
                printf("mo hay libros para eliminar.\n");
            else
                eliminarLibro(biblioteca, &contador);
            break;

        case 6:
            printf("saliendo del programa...\n");
            break;

        default:
            printf("opcion invalida.\n");
        }

    } while (opcion != 6);

    return 0;
}