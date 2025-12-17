#include <stdio.h>
#include <string.h>

#define MAX 100

struct Libro
{
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    int estado;
};

void registrarLibro(struct Libro biblioteca[], int *contador);
void mostrarLibros(struct Libro biblioteca[], int contador);
void buscarLibro(struct Libro biblioteca[], int contador);
void actualizarEstado(struct Libro biblioteca[], int contador);
void eliminarLibro(struct Libro biblioteca[], int *contador);