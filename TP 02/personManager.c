#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "personManager.h"
#include "../Bibliotecas/UtilesV2/UtilesV2.h"

#define INPUT_ATTEMPTS 3
#define SLEEP_TIME 1400

/** \brief Function used to init 'sPersons' array with fake data. Only to test.
 *
 * \param arrayToInit (sPerson[]) Array to initializice.
 * \param length (int) length of array to initializice.
 * \return (void)
 *
 */
void initToTest(sPerson* sPersons, int length)
{
    char names[][51] = {"Till", "Richard", "Paul", "Oliver", "Christoph", "Christian"};
    char lastNames[][51] = {"Lindemann", "Kruzpe", "Landers", "Riedel", "Schneider", "Lorenz"};
    int ages[] = {48, 46, 44, 41, 49, 51};
    char dnis[][10] = {"44555888", "21548718", "91736482", "71635249", "84269157", "76495813"};

    int i;

    for( i=0 ; (i<6 && i<length) ; i++ )
    {
        strcpy(sPersons[i].name, names[i]);
        strcpy(sPersons[i].lastname, lastNames[i]);
        sPersons[i].age = ages[i];
        strcpy(sPersons[i].dni, dnis[i]);
        sPersons[i].state = 1;
    }
}


/** \brief Initializes 'state' equal to 0 of 'sPerson' array.
 *
 * \param arrayToInit (sPerson[]) Array to initializice.
 * \param length (int) length of array to initializice.
 * \return (short int) [0]=Succes init / [-1]=Failed to initialize(WIP).
 *
 */
short int initPersonArray(sPerson* arrayToInit, int length)
{
    int i;

    for( i=0 ; i<length ; i++ )
    {
        arrayToInit[i].state = 0;
    }

    return 0;
}


/** \brief Search the first empty place in a 'sPerson' array.
 *
 * \param sPersons (sPerson[]) Array where to search.
 * \param length (int) Length of the array 'sPersons'
 * \return (int) Nº of empty index /[-1]=No free place.
 *
 */
int hasEmptyPlace(sPerson* sPersons, int length)
{
    int i=0;
    for( i=0; i<length ; i++ )
    {
        if( sPersons[i].state == 0 )
        {
            return i;
        }
    }
    return -1;
}


/** \brief Request data to user, and add a 'sPerson' to array.
 *
 * \param sPersons (sPerson[]) Array to add the person.
 * \param length (int) Length of 'sPersons'.
 * \param attempts (short int) Quantity of failed attempts.
 * \return (short int) [0]=Succesfully added / [-1]=No place to add.
 *
 */
short int addPerson(sPerson* sPersons, int length)
{
    sPerson auxPerson;  //Auxiliar variable type 'sPerson'.
    auxPerson.state = 0;//Initialize state of auxiliar in 0.

    int index;
    short int error;

    index = hasEmptyPlace(sPersons, length); //Obtain empty index in the array.

    if( index == -1 )
    {
        system("cls");
        printf("Error! No hay lugar para cargar el empleado.\n\n");
        system("pause");
        return -1;
    }
    else
    {
        error = requestPersonToUser(sPersons, length, &auxPerson, index);
        if( error == -1)
        {
            return -1;
        }
        else
        {
            sPersons[index] = auxPerson;
            return 0;
        }
    }
    return -1;
}



/** \brief Request to user the entry of person (name, last name, age and DNI).
 *
 * \param (sPerson*) Person where the data is saved.
 * \return (short int) [0]=Succesfull. / [-1]=Failed.
 *
 */
short int requestPersonToUser(sPerson* sPersons, int length, sPerson* auxPerson, int index)
{
    int returnValue = -1;
    short int answer = -1;
    char name[51], lastName[51], dni[10];
    int age;
    short int error;

    system("cls"); //Request the 'name'
    error = getStringConIntentos(name, 51, "Carga de persona\nIngrese Nombre: ", "Error! El nombre debe tener 50 caracteres como m""\xA0""ximo.", INPUT_ATTEMPTS);

    if( error == 0 )
    {
        normalizarString(name, 51, 3); //Normalize the 'name'

        system("cls"); //Request the 'lastName'
        error = getStringConIntentos(lastName, 51, "Carga de persona\nIngrese Apellido: ", "Error! El apellido debe tener 50 caracteres como m""\xA0""ximo.", INPUT_ATTEMPTS);

        if( error == 0 )
        {
            normalizarString(lastName, 51, 3);//Normalize the 'lastName'

            system("cls"); //Request the 'age'
            error = getInt(&age, "Carga de persona\nIngrese edad: ", 1, 1, 0, 150, "Error! Ingrese una edad v""\xA0""lida.", INPUT_ATTEMPTS);

            if( error == 0 )
            {
                system("cls"); //Request the 'dni' number.
                error = askForDNI( sPersons, length, dni, INPUT_ATTEMPTS );

                if( error == 0 )
                {
                    int contadorRtas = 0;
                    do
                    {
                        system("cls");
                        printf("Los datos cargados son los siguientes:\n"
                               "Nombre: \t%s \n"
                               "Apellido: \t%s \n"
                               "Edad: \t\t%d \n"
                               "N""\xA7"" DNI: \t%s \n\n", name, lastName, age, dni);

                        answer = preguntarPorSiOPorNo("Desea confirmar la carga? (S/N) ", "Respuesta inv""\xA0""lida.", 1);
                        if( answer == 0 || answer == 1)
                        {
                            system("cls");
                            contadorRtas = (INPUT_ATTEMPTS+1);
                        }
                        contadorRtas++;
                    }while( contadorRtas < INPUT_ATTEMPTS );

                }
            }
        }
    }

    if( answer == 1 )
    {
        strcpy( auxPerson[index].name , name);
        strcpy( auxPerson[index].lastname , lastName);
        auxPerson[index].age = age;
        strcpy( auxPerson[index].dni , dni);
        auxPerson[index].state = 1;
        returnValue = 0;
    }
    else
    {
        system("cls");
        printf("Se cancel""\xE0"" la carga.\n\n");
        system("pause");
    }

    return returnValue;
}


/** \brief Print a list of 'sPerson' contained in 'sPersons' sorted alphabetically.
 *
 * \param sPersons (sPerson[]) Array to sort and print.
 * \param length (int) Length of 'sPersons'.
 * \return
 *
 */
void printListSortedByName(sPerson* sPersons, int length)
{
    int i;

    if( sPersons != NULL && length > 0)
    {
        int flagHasAEnabledPerson = 0;

        //Check if has a enabled people in array.
        for( i=0 ; i<length ; i++ )
        {
            if( sPersons[i].state == 1 )
            {
                flagHasAEnabledPerson = 1;
                break;
            }
        }

        system("cls");

        //If has a enabled person, print the list.
        if( flagHasAEnabledPerson == 1 )
        {
            sortPersonArrayByName(sPersons, length);
            printf("Apellido y nombre\tEdad\tN""\xA7"" DNI\n\n");

            for( i=0 ; i<length ; i++ )
            {
                if( sPersons[i].state == 1 )
                {
                    printf("%s, %s\t\t%d\t%s\n", sPersons[i].lastname, sPersons[i].name, sPersons[i].age, sPersons[i].dni);
                }
            }
        }
        //If not has a enabled person...
        else
        {
            printf("No hay personas cargadas en el sistema.\n");
        }
    }
    printf("\n");
    system("pause");
}


/** \brief Sort array of 'sPerson' by 'name'.
 *
 * \param sPersons (sPerson[]) Array to sort.
 * \param length (int) Length of 'sPersons'.
 * \return (short int) [0]=Sucess sorted / [-1]=Failed to sort.
 *
 */
short int sortPersonArrayByName(sPerson* sPersons, int length)
{
    int i, j;
    int countSort=0; //Counter of sorted items, used to return.
    sPerson auxPerson;

    //Sort the array
    for( i=0 ; i<(length-1) ; i++ )
    {
        for( j=i+1 ; j<length ; j++ )
        {
            if( sPersons[i].state == 1 )
            {
                if( strcmp(sPersons[i].lastname,sPersons[j].lastname) > 0 )
                {
                    auxPerson = sPersons[i];
                    sPersons[i] = sPersons[j];
                    sPersons[j] = auxPerson;
                    countSort++;
                }
            }
        }
    }

    if(countSort==0)
    {
        return -1; //If don't exist person with state=1 in the array.
    }
    else
    {
        return 0; //Succesfully sorted.
    }
}


/** \brief Delete a person from 'sPerson' array. Change the 'state' to [0].
 *
 * \params Persons (sPerson*) Array of 'sPerson'.
 * \param length (int) Length of 'sPersons'.
 *
 */
void deletePerson(sPerson* sPersons, int length)
{
    char dniToDelete[10];
    int indexToDelete;

    system("cls");
    getString(dniToDelete, 10, "Eliminar persona\nIngrese N""\xA7"" DNI de la persona que desea eliminar: ", "Buscando...");

    indexToDelete = searchPersonByDni(sPersons, length, dniToDelete);

    if( indexToDelete == -1 )
    {
        system("cls");
        printf("ERROR! No existe una persona con ese N""\xA7"" de DNI.\n");
        system("pause");
    }
    else
    {
        sPersons[indexToDelete].state = 0;
        system("cls");
        printf("La siguiente persona fue eliminada exitosamente:\n"
       "Nombre: \t%s \n"
       "Apellido: \t%s \n"
       "Edad: \t\t%d \n"
       "N""\xA7"" DNI: \t%s \n\n", sPersons[indexToDelete].name, sPersons[indexToDelete].lastname, sPersons[indexToDelete].age, sPersons[indexToDelete].dni);
       system("pause");
    }
}

/** \brief Search a index with a specific 'dni'.
 *
 * \param sPersons (sPerson[]) Array searched.
 * \param length (int) Length of 'sPersons'.
 * \param dniToSearch (char[]) Number of 'dni' searched.
 * \return (int) Index of a person with the 'dni' / [-1]=If the person don't exist.
 *
 */
int searchPersonByDni(sPerson* sPersons, int length, char dniToSearch[])
{
    int returnValue = -1;
    int i;

    for( i=0 ; i<length ; i++ )
    {
        if( sPersons[i].state == 1 && (strcmp(sPersons[i].dni, dniToSearch) == 0) )
        {
            returnValue = i;
        }
    }
    return returnValue;
}


/** \brief Print a 2D graphic with ranges of ages.
 *
 * \param sPersons (sPerson[]) Array used to generate the graphic.
 * \param length (int) Length of 'sPersons'.
 *
 */
void printAgesGraph(sPerson sPersons[], int length)
{
    int i, j;
    int countMinor18 = 0;
    int count19to35 = 0;
    int countMajor35 = 0;
    int countTotal = 0;

    if( sPersons != NULL && length >0 )
    {

        //Counter of ranges and total
        for( i=0 ; i<length ; i++ )
        {
            if( sPersons[i].state == 1 )
            {
                countTotal++;

                if( sPersons[i].age <= 18 )
                {
                    countMinor18++;
                }
                if( sPersons[i].age > 18 && sPersons[i].age <= 35)
                {
                    count19to35++;
                }
                if( sPersons[i].age > 35 )
                {
                    countMajor35++;
                }
            }
        }

        system("cls");

        //If array is not empty.
        if( countTotal > 0 )
        {
            //Create a matriz to print.
            char graph[3][countTotal];

            //Init matriz in a empty char.
            for( i=0 ; i<3 ; i++ )
            {
                for( j=0 ; j<countTotal ; j++ )
                {
                    graph[i][j] = '\x20';
                }
            }

            for( j=0 ; j<countTotal ; j++ )
            {
                if( countMinor18 > j )
                {
                    graph[0][j] = '*';
                }
                if( count19to35 > j)
                {
                    graph[1][j] = '*';
                }
                if( countMajor35 > j)
                {
                    graph[2][j] = '*';
                }
            }

            printf("Menor de 18\tEntre 19 y 35\tMayor de 35\n");
            for( j=0 ; j<countTotal ; j++ )
            {
                for( i=0 ; i<3 ; i++ )
                {
                    printf("%c\t\t", graph[i][j]);
                }
                printf("\n");
            }
            printf("\n\n");


        }
        else
        {
            printf("No hay personas cargadas en el sistema.\n\n");
        }

        system("pause");
    }
}


/** \brief Used to exit from the system.
 *
 * \param answer (int*) Answer to assign a value.
 *
 */
void exitPersons(int* answer)
{
    short int respuesta;
    system("cls");

    respuesta = preguntarPorSiOPorNo( "Esta seguro que desea salir? (S/N) ", "ERROR! Respuesta inv""\xA0""lida", 1 );
    if( respuesta == 1 )
    {
        *answer = 5;
    }
    else
    {
        *answer = 1;
    }
}


/** \brief Request to user, a 'dni' number and validate if that 'dni' number was entered.
 *
 * \param sPersons (sPerson[]) Array searched.
 * \param length (int) Length of 'sPersons'.
 * \param dni (int*) Pointer where assign the value, if was correct.
 * \param attempts (int) Quantity of attempts.
 * \return (short int) [0]=Succes entry / [-1]=Fail.
 *
 */
short int askForDNI(sPerson* sPersons, int length, char* dni, int attempts)
{
    short int returnValue = -1;
    int countAttempts = 0;
    short int error;
    int indexOfPerson;
    char auxDni[10];

    do
    {
        system("cls");
        error = getStringConIntentos(auxDni, 10, "Carga de persona\nIngrese N""\xA7"" DNI: ", "Error! El DNI debe tener 9 caracteres como m""\xA0""ximo.", INPUT_ATTEMPTS);

        if( error == 0 )
        {
            //If has a person with that DNI number in array.
            indexOfPerson = searchPersonByDni(sPersons, length, auxDni);
            if( indexOfPerson == -1 )
            {
                strcpy( dni , auxDni );
                returnValue = 0;
                break;
            }
            else if( indexOfPerson >= 0 )
            {
                system("cls");
                printf("Ya existe una persona con ese N""\xA7"" de DNI.\n");
                Sleep(SLEEP_TIME);
            }
        }
        else if( error == -1 )
        {
            break;
        }

        countAttempts++;

    }while( countAttempts < attempts );

    return returnValue;
}
