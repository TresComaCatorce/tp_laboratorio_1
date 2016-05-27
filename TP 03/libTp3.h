#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define SLEEP_TIME 1200
#define CLEAR_SCREEN "cls"
#define LENGTH 10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "estructuras.h"
#include "../Bibliotecas/UtilesV2/UtilesV2.h"

/******- Prototipos -*******/

//Funciones de inicializacion
int initMovies( sMovie *peliculas, int largoArray );

//Funciones para cargar/guardar el archivo binario
int cargarDesdeArchivo( sMovie *peliculas, int length );
int guardarEnArchivo( sMovie *peliculas, int largoArray );


//Funciones del menú
void agregarPelicula( sMovie *peliculas, int largoArray );

void borrarPelicula( sMovie *peliculas, int largoArray );

void modificarPelicula ( sMovie *peliculas, int largoArray );

void generarPagina(sMovie *peliculas, int largoArray);

void doExit( sMovie *peliculas, int largoArray );


//Funciones internas
int solicitarIngresoPelicula( sMovie *peliculaAux, int intentos );
int buscarLibre( sMovie *peliculas, int largoArray );
int buscaIndexPeliculaPorTitulo( sMovie *peliculas, int largoArray, char *tituloABuscar );


//Prototipos para TEST
void chargeWithFakeData( sMovie *peliculas, int length );
void imprimirListaPeliculas( sMovie *peliculas, int length );

#endif // FUNCIONES_H_INCLUDED
