#include "../Bibliotecas/UtilesV2/UtilesV2.h"
#include "personManager.h"
#include <stdio.h>
#include <stdlib.h>

#define NUMB_ATTEMPTS 3
#define QUANTITY 20

/** \brief Principal function of the program. Execute the menu and handle every case.
 *
 * \return [0]=User choose "Salir" / [1]=Exceeds the number of attempts.
 *
 */
short int runSystem(void)
{
    sPerson sPersons[QUANTITY];
    initPersonArray(sPersons, QUANTITY);

    initToTest(sPersons, QUANTITY);

    int answer;//Answer obtained from the user.



    do{
        answer = 5;//Response of the user.

        //Construction of the menu.
        answer = buildMenu(  "1) Agregar una persona\n"
                                "2) Borrar una persona\n"
                                "3) Imprimir lista ordenada por nombre\n"
                                "4) Imprimir gr""\xA0""fico de edades\n"
                                "5) Salir", 1, 5, NUMB_ATTEMPTS, "Error! La opci""\xE0""n ingresada no es v""\xA0""lida.");

        //The response is analyzed.
        switch(answer)
        {
            case 1:
                addPerson(sPersons, QUANTITY); //Add a 'sPerson' to 'sPersons'.
                break;

            case 2:
                deletePerson(sPersons, QUANTITY); //Delete person from the 'sPersons' by DNI number.
                break;

            case 3:
                printListSortedByName(sPersons, QUANTITY); //Print list of 'sPerson' contained in 'sPersons' sorted alphabetically.
                break;

            case 4:
                printAgesGraph(sPersons, QUANTITY); //Print a 2D graphic with ranges of ages.
                break;

            case 5:
                exitPersons(&answer); //Exit of the system.
                break;

            case -1:
                return 1;
                break;

            default:
                printf("System error 001\n");
                system("pause");
                break;
        }

    }while( answer != 5 );

    return 0;
}



