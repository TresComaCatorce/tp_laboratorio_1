#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/** \brief Pregunta al usuario si desea continuar.
 *
 * \return int 0(cero) si el usuario eligió NO continuar 1(uno) si el usuario eligió continuar
 *
 */
int preguntarDeseaContinuar()
{
    char respuesta; //Respuesta que ingresa el usuario
    int contador = 0;


    do{
        if(contador==0)
        {
            printf("Desea continuar? (s/n)");
        }
        else
        {
            printf("ERROR! Desea continuar? (s/n) ");
        }
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta=tolower(respuesta);
        contador++;
    }while( respuesta!='s' && respuesta!='n');

    switch(respuesta)
    {
        case 's':
            return 1;
            break;
        case 'n':
            return 0;
            break;
    }
    return 0;
}


/** \brief Valida si un número es entero, o con decimal.
 *
 * \param float numero a analizar.
 *
 * \return int 0(cero) si el número tiene decimales 1(uno) si el número es entero.
 *
 */
int esEntero(float numero)
{
    float auxiliar;
    auxiliar = numero - (int)numero;
    if(auxiliar==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
