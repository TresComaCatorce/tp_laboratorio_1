#include "libTp3.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void initMovies( sMovie *peliculas, int length )
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

void imprimirListaPeliculas( sMovie *peliculas, int length )
{
    if( peliculas != NULL && length > 0  )
    {
        int i;
        system(CLEAR_SCREEN);
        printf("Titulo\t\tPuntaje\tGenero\tDuracion\tDescripcion\n");
        for( i=0 ; i<length ; i++ )
        {
            if( peliculas[i].estado == 1 )
            {
                printf("%s\t\t%d\t%s\t%d\t%s\n", peliculas[i].titulo, peliculas[i].puntaje, peliculas[i].genero, peliculas[i].duracion, peliculas[i].descripcion );

            }
        }

        printf("\n");
        system("pause");
    }
}


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula( sMovie *pelicula, int largoArray )
{
    int i;
    for(i=0;i<largoArray;i++)
    {
        if(pelicula[i].estado == 0)
        {
            printf("Ingrese nombre de la pelicula: ");
            fflush(stdin);
            gets(pelicula[i].titulo);

            printf("Ingrese genero de la pelicula: ");
            fflush(stdin);
            gets(pelicula[i].genero);


            printf("Ingrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets(pelicula[i].descripcion);

            printf("Ingrese la duracion de la pelicula: ");
            fflush(stdin);
            scanf("%d", &pelicula[i].duracion);


            printf("Ingrese el puntaje de la pelicula: ");
            fflush(stdin);
            scanf("%d", &pelicula[i].puntaje);



            pelicula[i].estado=1;
            system("pause");
            system("cls");
            break;
        }
    }

    if(i==largoArray)
    {
        printf("\nNo hay espacio disponible para agregar una pelicula\n\n");
        system("pause");
        system("cls");
    }
}

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula( sMovie *pelicula, int largoArray)
{
    int retorno = 0;
    char titulo [51];
    int i;

    printf("Ingrese el titulo de la pelicula que desea eliminar: ");
    gets( titulo );

    for(i=0;i<largoArray;i++)
    {
        if(pelicula[i].estado == 1 && stricmp(titulo, pelicula[i].titulo)==0)
        {
            pelicula[i].estado = 0;

            retorno = 1;

            printf("Eliminacion exitosa!\n");
            system("pause");
            system("cls");

            break;
        }
    }
    if(i==largoArray)
    {
        printf("No existe la pelicula buscada.\n");
        system("pause");
        system("cls");
    }

    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void modificarPelicula (sMovie *pelicula, int largoArray)
{
    int retorno = 0;
    char titulo[51];
    int contadorErrores, i, opcion;

    printf("Ingrese el titullo de la pelicula que desea moficar: ");
    gets(titulo);

    for( i=0 ; i<largoArray ; i++ )
    {
        if(pelicula[i].estado == 1 && strcmp(titulo, pelicula[i].titulo)==0)
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
                        gets(pelicula[i].titulo);
                        break;
                    case 2:
                        printf("Ingrese genero de la pelicula: ");
                        fflush(stdin);
                        gets(pelicula[i].genero);
                        break;
                    case 3:
                        printf("Ingrese la descripcion de la pelicula: ");
                        fflush(stdin);
                        gets(pelicula[i].descripcion);
                        break;
                    case 4:
                        printf("Ingrese la duracion de la pelicula: ");
                        fflush(stdin);
                        scanf("%d", &pelicula[i].duracion);
                        break;

                    case 5:
                        printf("Ingrese el puntaje de la pelicula: ");
                        fflush(stdin);
                        scanf("%d", &pelicula[i].puntaje);

                    case 6:
                        return 0;
                }
            }while(opcion!=6);

            if(i==largoArray)
            {
                printf("No existe la pelicula buscada.\n");
                system("pause");
                system("cls");
            }
        }
    }
}


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 */
void generarPagina( sMovie *peliculas , int largoArray )
{
    int retorno = 0;
    int i;

    if( peliculas != NULL )
    {
        char head[500] = "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>";
        char foot[500] = "</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>";
        char body[8999] = "";
        char total[10000] = "";

        char fijo1[100] = "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='";
        char fijo2[40] = "' alt=''></a><h3><a href='#'>";
        char fijo3[40] = "</a></h3><ul><li>G�nero:";
        char fijo4[20] = "</li><li>Puntaje:";
        char fijo5[20] = "</li><li>Duraci�n:";
        char fijo6[20] = "</li></ul><p>";
        char fijo7[20] = "</p></article>";

        FILE *f;

		f=fopen("index.html","w");
		if(f != NULL)
		{

            strcat( total , head );

            for( i=0 ; i<largoArray ; i++ )
            {
                if( peliculas[i].estado == 1 )
                {
                    strcat( total , fijo1 );
                    strcat( total , "images/matrix.jpg" );
                    strcat( total , fijo2 );
                    strcat( total , peliculas[i].titulo );
                    strcat( total , fijo3 );
                    strcat( total , peliculas[i].genero );
                    strcat( total , fijo4 );
                    strcat( total , (char)peliculas[i].puntaje );
                    strcat( total , fijo5 );
                    strcat( total , (char)peliculas[i].duracion );
                    strcat( total , fijo6 );
                    strcat( total , peliculas[i].descripcion );
                    strcat( total , fijo7 );
                }
            }

            strcat( total , foot );
		}

        fclose(f);
    }

    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int buscarLibre(sMovie *peliculas)
{
	int index=-1;
	int i;
	for( i=0; i < LENGTH; i++)
	   if(peliculas[i].estado==0)
        {
		index=i;
		break;
	   }
	return index;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int guardarEnArchivo(sMovie *peliculas)
{

	FILE *f;

		f=fopen("movies.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(peliculas,sizeof(sMovie),LENGTH,f);

	fclose(f);

	return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cargarDesdeArchivo(sMovie *pelicula)
{
	int flag = 0;
	FILE *f;

	f = fopen("movies.dat", "rb");
	if(f==NULL)
	{
		f= fopen("movies.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
        fread(pelicula,sizeof(sMovie),LENGTH,f);
    }

	fclose(f);
	return 0;

}


void doExit(sMovie *peliculas)
{
    char guardar;
    system(CLEAR_SCREEN);
    printf("\nGuardar cambios S/N ?: ");
    guardar = tolower(getche());

    if( guardar == 's' )
    {
        if(guardarEnArchivo(peliculas))
        {
            printf("\nNo se pudo abrir el fichero.\n\n");
        }
        else
        {
            printf("\nSe guardo la informacion con exito.\n\n");
        }
    }
}