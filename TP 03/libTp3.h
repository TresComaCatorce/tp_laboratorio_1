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

//Prototipos

int initMovies( sMovie *peliculas, int largoArray );


int cargarDesdeArchivo( sMovie *peliculas, int length );
int guardarEnArchivo( sMovie *peliculas, int largoArray );


int agregarPelicula( sMovie *pelicula, int largoArray );

int borrarPelicula( sMovie *movie, int largoArray );

void modificarPelicula ( sMovie *pelicula, int largoArray );

int generarPagina(sMovie *peliculas, int largoArray);

int buscarLibre( sMovie *peliculas, int largoArray );

void doExit( sMovie *peliculas, int largoArray );


//Prototipos para TEST

void chargeWithFakeData( sMovie *peliculas, int length );
void imprimirListaPeliculas( sMovie *peliculas, int length );

#endif // FUNCIONES_H_INCLUDED
