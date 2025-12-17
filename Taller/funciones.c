#include <stdio.h>
#include <math.h>
#include "funciones.h"
#include <string.h>

void registrarLibro(struct Libro biblioteca[], int *contador)
{
    if (*contador >= 10)
    {
        printf("no se pueden registrar mas de 10 libros.\n");
        return;
    }

    struct Libro nuevoLibro;
    int id_repetido = 0;

    printf("ingrese id del libro: ");
    if (scanf("%d", &nuevoLibro.id) != 1)
    {
        printf("error: debe ingresar un numero.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    getchar(); // limpiar buffer

    // validar id unico
    for (int i = 0; i < *contador; i++)
    {
        if (biblioteca[i].id == nuevoLibro.id)
        {
            id_repetido = 1;
            break;
        }
    }

    if (id_repetido)
    {
        printf("error: ese id ya existe.\n");
        return;
    }

    printf("ingrese titulo del libro: ");
    fgets(nuevoLibro.titulo, 100, stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = 0;
    printf("ingrese autor del libro: ");
    fgets(nuevoLibro.autor, 50, stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = 0;
    printf("ingrese anio de publicacion: ");

    if (scanf("%d", &nuevoLibro.anio) != 1)
    {
        printf("error: debe ingresar un numero.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    getchar(); // limpiar buffer

    nuevoLibro.estado = 1;
    biblioteca[*contador] = nuevoLibro;
    (*contador)++;
    printf("libro registrado exitosamente.\n");
}

void mostrarLibros(struct Libro biblioteca[], int contador)
{
    printf("id\ttitulo\t\tautor\t\tanio\testado\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d\t%s\t%s\t%d\t%s\n",
               biblioteca[i].id,
               biblioteca[i].titulo,
               biblioteca[i].autor,
               biblioteca[i].anio,
               biblioteca[i].estado == 1 ? "disponible" : "prestado");
    }
}

void buscarLibro(struct Libro biblioteca[], int contador)
{
    int opcion;
    printf("buscar por: 1. ID  2. titulo\n");
    scanf("%d", &opcion);
    getchar();

    if (opcion == 1)
    {
        int idBuscado;
        printf("ingrese ID del libro a buscar: ");
        scanf("%d", &idBuscado);

        for (int i = 0; i < contador; i++)
        {
            if (biblioteca[i].id == idBuscado)
            {
                printf("libro encontrado: %d, %s, %s, %d, %s\n",
                       biblioteca[i].id,
                       biblioteca[i].titulo,
                       biblioteca[i].autor,
                       biblioteca[i].anio,
                       biblioteca[i].estado == 1 ? "disponible" : "prestado");
                return;
            }
        }

        printf("libro con ID %d no encontrado.\n", idBuscado);
    }
    else if (opcion == 2)
    {
        char tituloBuscado[100];
        printf("ingrese titulo del libro a buscar: ");
        fgets(tituloBuscado, 100, stdin);
        tituloBuscado[strcspn(tituloBuscado, "\n")] = 0;

        for (int i = 0; i < contador; i++)
        {
            if (strcmp(biblioteca[i].titulo, tituloBuscado) == 0)
            {
                printf("libro encontrado: %d, %s, %s, %d, %s\n",
                       biblioteca[i].id,
                       biblioteca[i].titulo,
                       biblioteca[i].autor,
                       biblioteca[i].anio,
                       biblioteca[i].estado == 1 ? "disponible" : "prestado");
                return;
            }
        }
        printf("libro con titulo '%s' no encontrado.\n", tituloBuscado);
    }
}

void actualizarEstado(struct Libro biblioteca[], int contador)
{
    int idBuscado;
    printf("ingrese ID del libro para actualizar estado: ");
    scanf("%d", &idBuscado);

    for (int i = 0; i < contador; i++)
    {
        if (biblioteca[i].id == idBuscado)
        {
            biblioteca[i].estado = !biblioteca[i].estado;
            printf("estado del libro con ID %d actualizado a %s.\n",
                   idBuscado,
                   biblioteca[i].estado == 1 ? "disponible" : "prestado");
            return;
        }
    }
    printf("libro con ID %d no encontrado.\n", idBuscado);
}

void eliminarLibro(struct Libro biblioteca[], int *contador)
{
    int idBuscado;
    printf("ingrese ID del libro a eliminar: ");
    scanf("%d", &idBuscado);
    for (int i = 0; i < *contador; i++)
    {
        if (biblioteca[i].id == idBuscado)
        {
            if (biblioteca[i].estado ==0)       
            {
                printf("No se puede eliminar el libro con ID %d porque esta prestado.\n", idBuscado);
                return;
            }
            
            for (int j = i; j < *contador - 1; j++)
            {
                biblioteca[j] = biblioteca[j + 1];
            }
            (*contador)--;
            printf("libro con ID %d eliminado exitosamente.\n", idBuscado);
            return;
        }
    }
    printf("libro con ID %d no encontrado.\n", idBuscado);
}
