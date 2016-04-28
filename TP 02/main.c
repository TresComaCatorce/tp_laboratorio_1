#include <stdio.h>
#include <stdlib.h>
#include "libPersonas.h"

#include "../Bibliotecas/UtilesV2/UtilesV2.h"

int main()
{
    int returnedValue;
    returnedValue = runSystem();

    if(returnedValue == 0)
    {
        system("cls");
        printf("\n\nEjecuci""\xE0""n finalizada.\n\n");
        exit(0);
    }
    else
    {
        system("cls");
        printf("\n\nUsted ha superado la cantidad permitida de ingresos incorrectos.\n"
               "Ejecuci""\xE0""n finalizada.\n\n");
        exit(1);
    }

    /*short int error;

    printf("impresion\n\n");

    error = preguntarPorSiOPorNo("SI O NO?", "RTA MAL", 3);

    printf("RTA: %d", error);*/
}
