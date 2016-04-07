#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../Bibliotecas/Operaciones/Operaciones.h"
#include "../Bibliotecas/Utiles/Utiles.h"

int buildMenu(float numeroA, float numeroB);
float ingresaOperando(char identificadorOperando);
void muestraResultado(float resultado);

int main()
{
    //Declaracion de variables
    float numeroA=0.0, numeroB=0.0, resultado=0.0; //Numeros ingresados por el usuario y resultado de la operación
    int respuesta=0; //Opcion del menu seleccionada por el usuario

    do{
        respuesta=buildMenu(numeroA, numeroB);
        switch(respuesta)
        {
            case 1:
                numeroA=ingresaOperando('A');
                system("cls");
                break;

            case 2:
                numeroB=ingresaOperando('B');
                system("cls");
                break;

            case 3:
                resultado=suma(numeroA, numeroB);
                printf("\nEl resultado de la suma A+B es: %.2f \n\n", resultado);
                system("pause");
                system("cls");
                break;

            case 4:
                resultado=resta(numeroA, numeroB);
                printf("\nEl resultado de la resta A-B es: %.2f \n\n", resultado);
                system("pause");
                system("cls");
                break;

            case 5:
                if(numeroB != 0)
                {
                    resultado=cociente(numeroA, numeroB);
                    printf("\nEl resultado del cociente A/B es: %.2f \n\n", resultado);
                }
                else
                {
                    printf("\nERROR! El operando 'B' no puede ser igual a 0. \n\n")
                }
                system("pause");
                system("cls");
                break;

            case 6:
                resultado=producto(numeroA, numeroB);
                printf("\nEl resultado del producto A*B es: %.2f \n\n", resultado);
                system("pause");
                system("cls");
                break;

            case 7:
                if(esEntero(numeroA))
                {
                    resultado=factorial((int)numeroA);
                    printf("\nEl resultado del factorial de A es: %.0f \n\n", resultado);

                }
                else
                {
                    printf("\nERROR! El operando 'A' no es entero mayor o igual a 1.\n\n");
                }

                system("pause");
                system("cls");
                break;

            case 8:
                resultado=suma(numeroA, numeroB);
                printf("\nEl resultado de la suma A+B es: %.2f \n", resultado);

                resultado=resta(numeroA, numeroB);
                printf("El resultado de la resta A-B es: %.2f \n", resultado);

                resultado=cociente(numeroA, numeroB);
                printf("El resultado del cociente A/B es: %.2f \n", resultado);

                resultado=producto(numeroA, numeroB);
                printf("El resultado del producto A*B es: %.2f \n", resultado);

                resultado=factorial((int)numeroA);
                printf("El resultado del factorial de A es: %.0f \n\n", resultado);

                system("pause");
                system("cls");

                break;

            case 9:
                break;

            default:
                printf("ERROR! Ingrese una opcion valida.");
                Sleep(2000);
                system("cls");
                break;
        }
    }while(respuesta!=9);


    return 0;
}

int buildMenu(float numeroA, float numeroB)
{
        int respuesta=0;
        printf("------------------------------------\n");
        printf("\t T.P. N""\xa7""1 Calculadora \n");
        printf("\tLaboratorio I - UTN FRA \n");
        printf("\t   Ferrero Cristian\n");
        printf("------------------------------------\n");
        printf("1. Ingresar primer operando (A=%.2f) \n", numeroA);
        printf("2. Ingresar segundo operando (B=%.2f) \n", numeroB);
        printf("3. Calcular la suma (A+B) \n");
        printf("4. Calcular la resta (A-B) \n");
        printf("5. Calcular el cociente (A/B) \n");
        printf("6. Calcular la multiplicaci""\xe0""n (A*B) \n");
        printf("7. Calcular el factorial (A!) \n");
        printf("8. Calcular todas las operaciones \n");
        printf("9. Salir \n \n");
        printf("Ingrese la opci""\xa2""n deseada (1-9): ");
        fflush(stdin);
        scanf("%d", &respuesta);

        return respuesta;
}

float ingresaOperando(char identificadorOperando)
{
    float operando=0.0;
    printf("\nIngrese el operando %c: ", identificadorOperando);
    fflush(stdin);
    scanf("%f", &operando);
    return operando;
}
