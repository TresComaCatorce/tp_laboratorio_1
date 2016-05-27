#include "libTp3.h"

/** \brief Inizializa el array de peliculas con 'estado' en cero
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param largoArray (int) Largo del array.
 * \param (int) [0]=Inicializado correctamente /[-1]=Error al inicializar
 *
 */
int initMovies( sMovie *peliculas, int largoArray )
{
    int retorno = -1;

    if( peliculas != NULL && largoArray > 0 )
    {
        int i;

        for( i=0; i<largoArray ; i++ )
        {
            peliculas[i].estado = 0;
        }

        retorno = 0;

    }
    return retorno;
}



/** \brief Carga los datos desde el archivo binario de nombre "movies.dat" en caso que el archivo no exista lo crea.
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param length (int) Largo del array.
 * \return [0]=Carga Exitosa / [-1]=Error de argumentos / [-2]=No existia archivo, fue creado
 *
 */
int cargarDesdeArchivo( sMovie *peliculas, int length )
{
    int retorno = -1;

    if( peliculas != NULL && length > 0 )
    {
        FILE *pArchBin;
        int leyoArch = 0;

        pArchBin = fopen("movies.dat", "rb");

        if( pArchBin == NULL)
		{
			retorno = -2;
			pArchBin = fopen("movies.dat", "wb");
		}
		else
        {
            retorno = 0;
            leyoArch = 1;
        }

        if( pArchBin != NULL)
        {
            leyoArch = 1;
        }

        if( leyoArch == 1 )
        {
            fread( peliculas , sizeof(sMovie) , length , pArchBin );
            fclose( pArchBin );
        }
    }

	return retorno;

}



/** \brief Guarda los datos en el archivo binario "movies.dat".
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param length (int) Largo del array.
 * \return [0]=Guardado Exitoso / [-1]=Error de argumentos / [-2]=Error al guardar.
 *
 */
int guardarEnArchivo( sMovie *peliculas, int largoArray )
{
    int retorno = -1;

    if( peliculas != NULL && largoArray > 0 )
    {
        FILE *pArchBin;

        pArchBin = fopen("movies.dat","wb");

        if( pArchBin == NULL )
        {
            retorno = -2;
        }
        else
        {
            fwrite( peliculas , sizeof(sMovie) , largoArray , pArchBin );
            fclose( pArchBin );
            retorno = 0;
        }

    }

	return retorno;

}



/** \brief Agrega una película al array de peliculas.
 *
 * \param
 * \param
 *
 */
void agregarPelicula( sMovie *peliculas, int largoArray )
{
    if( peliculas != NULL && largoArray > 0 )
    {
        int error;
        int indexLibre;
        sMovie auxPelicula;

        indexLibre = buscarLibre( peliculas, largoArray );

        if( indexLibre >= 0 )
        {
            error = solicitarIngresoPelicula( &auxPelicula, 3 );

            if( error == 0 )
            {
                peliculas[indexLibre] = auxPelicula;
                system(CLEAR_SCREEN);
                printf("\nPel""\xA1""cula cargada correctamente.\n\n");
                system("pause");
            }

        }
        else if( indexLibre == -2 )
        {
            system(CLEAR_SCREEN);
            printf("\nNo hay lugar para cargar pel""\xA1""cula\n\n");
            system("pause");
        }
        else if( indexLibre == -1 )
        {
            system(CLEAR_SCREEN);
            printf("\nError al cargar la pel""\xA1""cula\n\n");
            system("pause");
        }
    }
}

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void borrarPelicula( sMovie *peliculas, int largoArray )
{
    if( peliculas != NULL && largoArray > 0 )
    {
        int error;
        char tituloABuscar[20];
        int indexABorrar;

        system(CLEAR_SCREEN);

        error = getStringConIntentos( tituloABuscar, 20, "Ingrese el titulo de la pel""\xA1""cula que desea eliminar: ", "Error! Titulo inva""\xA0""lido", 3 );

        if( error == 0 )
        {
            indexABorrar = buscaIndexPeliculaPorTitulo( peliculas, largoArray, tituloABuscar );
            if( indexABorrar >= 0 )
            {
                peliculas[indexABorrar].estado = 0;

                system(CLEAR_SCREEN);
                printf("\nPel""\xA1""cula eliminada correctamente.\n\n");
                system("pause");
            }
            else if( indexABorrar == -2 )
            {
                system(CLEAR_SCREEN);
                printf("\nNo existe una pel""\xA1""cula con ese titulo.\n\n");
                system("pause");
            }
            else if( indexABorrar == -1 )
            {
                system(CLEAR_SCREEN);
                printf("\nError al eliminar la pel""\xA1""cula.\n\n");
                system("pause");
            }
        }
    }
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void modificarPelicula (sMovie *peliculas, int largoArray)
{
    /*char titulo[51];
    int contadorErrores, i, opcion;

    printf("Ingrese el titullo de la pelicula que desea moficar: ");
    gets(titulo);

    for( i=0 ; i<largoArray ; i++ )
    {
        if(peliculas[i].estado == 1 && strcmp(titulo, peliculas[i].titulo)==0)
        {
            printf("Elija una opcion:\n1- Modificar titulo\n2- Modificar genero\n3- Modificar descripcion\n4- Modificar duracion\n5- Modificar puntaje\n6- Salir");
            scanf("%d", &opcion);

        while(opcion<1 || opcion>5)
            {
                printf("Error, reingrese opcion: \n");
                scanf("%d", &opcion);
                contadorErrores++;

                if(contadorErrores>=3)
                {
                    printf("Demasidos intentos, el programa se cerrara.");
                }
                break;
            }

            do
            {
                switch(opcion)
                {
                    case 1:
                        printf("Ingrese titulo de la pelicula : ");
                        fflush(stdin);
                        gets(peliculas[i].titulo);
                        break;
                    case 2:
                        printf("Ingrese genero de la pelicula: ");
                        fflush(stdin);
                        gets(peliculas[i].genero);
                        break;
                    case 3:
                        printf("Ingrese la descripcion de la pelicula: ");
                        fflush(stdin);
                        gets(peliculas[i].descripcion);
                        break;
                    case 4:
                        printf("Ingrese la duracion de la pelicula: ");
                        fflush(stdin);
                        scanf("%d", &peliculas[i].duracion);
                        break;

                    case 5:
                        printf("Ingrese el puntaje de la pelicula: ");
                        fflush(stdin);
                        scanf("%d", &peliculas[i].puntaje);

                    case 6:
                        break;
                }
            }while(opcion!=6);

            if(i==largoArray)
            {
                printf("No existe la pelicula buscada.\n");
                system("pause");
                system("cls");
            }
        }
    }*/
}



/** \brief Genera el archivo "index.html" dentro de la carpeta "WebPage" con un listado de las peliculas cargadas.
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param largoArray (int) Largo del array.
 *
 */
void generarPagina( sMovie *peliculas , int largoArray )
{
    int i;

    if( peliculas != NULL )
    {
        char head[375] = "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>";
        char foot[225] = "</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>";
        char body[9390] = "";
        char total[10000] = "";

        char fijo1[100] = "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
        char fijo2[40] = "' alt=''></a><h3><a href='#'>";
        char fijo3[35] = "</a></h3><ul><li>G&eacutenero: ";
        char fijo4[20] = "</li><li>Puntaje: ";
        char fijo5[30] = "</li><li>Duraci&oacuten: ";
        char fijo6[20] = "</li></ul><p>";
        char fijo7[20] = "</p></article>";
        char aux[50];

        FILE *pArchHTML;

		pArchHTML = fopen( "WebPage/index.html", "w" );
		if( pArchHTML != NULL )
		{
            strcat( total , head );

            for( i=0 ; i<largoArray ; i++ )
            {
                if( peliculas[i].estado == 1 )
                {
                    strcat( body , fijo1 );
                    strcat( body , peliculas[i].linkImagen );
                    strcat( body , fijo2 );
                    strcat( body , peliculas[i].titulo );
                    strcat( body , fijo3 );
                    strcat( body , peliculas[i].genero );
                    strcat( body , fijo4 );

                    sprintf( aux , "%d", peliculas[i].puntaje );
                    strcat( body , aux );

                    strcat( body , fijo5 );

                    sprintf( aux , "%d" , peliculas[i].duracion );
                    strcat( body , aux );

                    strcat( body , fijo6 );
                    strcat( body , peliculas[i].descripcion );
                    strcat( body , fijo7 );

                    strcat( total, body);

                    strcpy( body, "");
                }
            }

            strcat( total , foot );

            fprintf( pArchHTML, "%s", total );
		}

        fclose(pArchHTML);

        system(CLEAR_SCREEN);
        printf("\nP""\xA0""gina web generada correctamente.\n\n");
        system("pause");

    }
    else
    {
        system(CLEAR_SCREEN);
        printf("\nNo se pudo generar la p""\xA0""gina web.\n\n");
        system("pause");
    }
}



/** \brief Funcion para la salida del programa, pregunta si se quieren guardar los cambios realizados o no.
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param largoArray (int) Largo del array.
 *
 */
void doExit( sMovie *peliculas, int largoArray )
{
    short int respuesta;
    int error;

    system(CLEAR_SCREEN);

    respuesta = preguntarPorSiOPorNo( "\nDesea guardar los cambios realizados? (S/N) ", "\nError en la respuesta", 3 );

    system(CLEAR_SCREEN);

    if( respuesta == 1 )
    {
        error = guardarEnArchivo( peliculas, largoArray );
        if( error == 0 )
        {
            printf("\nSe guardo la informacion con exito.\n\n");
        }
        else
        {
            printf("\nNo se pudo guardar en el fichero.\n\n");
        }
    }
    else
    {
        printf("\nNo se guardaron los cambios.\n\n");
    }
}



/** \brief Solicita el ingreso de una pelicula al usuario (Titulo, genero, duracion, puntaje, descripcion y URL de la imagen) y la carga en la variable del tipo 'sMovie' de la que se recibe un puntero como parámetro.
 *
 * \param peliculaAux (*sMovie) Puntero a la variable auxiliar del tipo 'sMovie' donde se van a almacenar los datos guardados.
 * \param intentos (int) Cantidad de intentos permitidos.
 * \return [0]=Ingreso correcto/[-1]=Error en el ingreso.
 *
 */
int solicitarIngresoPelicula( sMovie *peliculaAux, int intentos )
{
    int retorno = -1;

    if( peliculaAux != NULL && intentos > 0 )
    {
        int error;

        system(CLEAR_SCREEN); //Solicito el ingreso del titulo de la película
        error = getStringConIntentos( peliculaAux->titulo, 20, "Ingrese el t""\xA1""tulo de la pel""\xA1""cula: ", "\nError! T""\xA1""tulo inv""\xA0""lido.", intentos );
        if( error == 0 )
        {
            system(CLEAR_SCREEN);//Solicito el ingreso del genero de la película
            error = getStringConIntentos( peliculaAux->genero, 20, "Ingrese el g""\x82""nero de la  pel""\xA1""cula: ", "\nError! G""\x82""nero inv""\xA0""lido.", intentos );
            if( error == 0 )
            {
                system(CLEAR_SCREEN);//Solicito el ingreso de la duracion de la película
                error = getInt ( &peliculaAux->duracion, "Ingrese la duraci""\xA2""n de la  pel""\xA1""cula: ", 1, 1, 1, 1000, "\nError! Duraci""\xA2""n inv""\xA0""lida.", intentos );
                if( error == 0 )
                {
                    system(CLEAR_SCREEN);//Solicito el ingreso de la descripción de la película
                    error = getStringConIntentos( peliculaAux->descripcion, 50,"Ingrese la descripci""\xA2""nn de la pel""\xA1""cula: ", "\nError! Descripci""\xA2""n inv""\xA0""lida.", intentos );
                    if( error == 0 )
                    {
                        system(CLEAR_SCREEN);//Solicito el ingreso del puntaje  de la película
                        error = getInt ( &peliculaAux->puntaje, "Ingrese el puntaje de la  pel""\xA1""cula: ", 1, 1, 0, 10, "\nError! Puntaje inv""\xA0""lido.", intentos );
                        if( error == 0)
                        {
                            system(CLEAR_SCREEN);//Solicito el ingreso de la URL de la imagen de la película.
                            error = getStringConIntentos( peliculaAux->linkImagen, 150, "Ingrese la URL de la imagen de la pel""\xA1""cula (Google imagenes): ", "\nError! URL inv""\xA0""lida.", intentos );
                            if( error == 0 )
                            {
                                peliculaAux->estado = 1;
                                retorno = 0;
                            }
                        }
                    }
                }
            }

        }
    }

    return retorno;
}



/** \brief Busca un lugar libre en el array de peliculas y devuelve su indice.
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param largoArray (int) Largo del array.
 * \return (int) [Indice libre]=Si hay un lugar libre devuelve el subindice del array libre/[-1]=Error de argumentos/[-2]=No hay lugar libre
 *
 */
int buscarLibre( sMovie *peliculas, int largoArray )
{
	int retorno = -1;
	int hayLugar = 0;
	int i;

	if( peliculas != NULL && largoArray > 0 )
    {
        for( i=0; i < largoArray; i++)
        {
            if( peliculas[i].estado == 0 )
            {
                retorno = i;
                hayLugar = 1;
                break;
            }
        }

        if( !hayLugar )
        {
            retorno = -2;
        }

    }

	return retorno;
}



/** \brief Busca el subindice de una pelicula dentro del array por el titulo.
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param largoArray (int) Largo del array.
 * \param tituloABuscar (*char) Titulo de la pelicula buscada.
 * \return (int) [Indice de la pelicula]=Si se encontró la pelicula/[-1]=Error de argumentos/[-2]=No se encontró la pelicula.
 *
 */
int buscaIndexPeliculaPorTitulo( sMovie *peliculas, int largoArray, char *tituloABuscar )
{
    int retorno = -1;
    if( peliculas != NULL && largoArray > 0 && tituloABuscar != NULL && tituloABuscar[0]!='\0' )
    {
        int i;
        int encontroPelicula = 0;

        for( i=0 ; i<largoArray ; i++ )
        {
            if( peliculas[i].estado == 1 && (stricmp(tituloABuscar, peliculas[i].titulo) == 0) )
            {
                encontroPelicula = 1;
                retorno = i;
            }
        }

        if( encontroPelicula == 0 )
        {
            retorno = -2;
        }

    }
    return retorno;
}



/** \brief Inicializa el array de peliculas con datos falsos, utilizado para test.
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param length (int) Largo del array.
 *
 */
void chargeWithFakeData( sMovie *peliculas, int length )
{
    if( peliculas != NULL && length > 0 )
    {
        int i;
        char titulos[3][20] = {"Matrix", "A serbian film", "A clockwork orange"};
        char generos[3][20] = {"Accion", "Horror", "Drama"};
        int duraciones[3] = {120, 111, 215};
        char descripciones[3][50] = {"Matrix description.", "A serbian film description.", "A clockwork orange description."};
        int puntajes[3] = {8, 10, 9};
        char linkImagenes[3][150] = {"https://upload.wikimedia.org/wikipedia/en/c/c1/The_Matrix_Poster.jpg", "http://images.moviepostershop.com/a-serbian-film-movie-poster-2010-1020669469.jpg", "https://c1.staticflickr.com/7/6013/6015447285_dbbe78d881_b.jpg"};

        for( i=0; i<3 ; i++ )
        {
            strcpy( peliculas[i].titulo, titulos[i] );
            strcpy( peliculas[i].genero, generos[i] );
            strcpy( peliculas[i].descripcion, descripciones[i] );
            strcpy( peliculas[i].linkImagen, linkImagenes[i] );
            peliculas[i].duracion = duraciones[i];
            peliculas[i].puntaje = puntajes[i];
            peliculas[i].estado = 1;
        }

    }
}



/** \brief Imprime un listado con las peliculas cargadas, utilizado para test.
 *
 * \param peliculas (*sMovie) Array de peliculas.
 * \param length (int) Largo del array.
 *
 */
void imprimirListaPeliculas( sMovie *peliculas, int length )
{
    if( peliculas != NULL && length > 0  )
    {
        int i;
        system(CLEAR_SCREEN);
        printf("Titulo\tPuntaje\tGenero\tDuracion\tDescripcion\n");
        for( i=0 ; i<length ; i++ )
        {
            if( peliculas[i].estado == 1 )
            {
                printf("%s\t%d\t%s\t%d\t%s\n", peliculas[i].titulo, peliculas[i].puntaje, peliculas[i].genero, peliculas[i].duracion, peliculas[i].descripcion );

            }
        }

        printf("\n");
        system("pause");
    }
}
