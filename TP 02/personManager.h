#include "libPersonas.h"

//Function prototypes
void initToTest(sPerson * sPersons, int length);


short int initPersonArray(sPerson arrayToInit[], int length);
int hasEmptyPlace(sPerson* sPersons, int length);
short int addPerson(sPerson* sPersons, int length);
short int requestPersonToUser(sPerson* sPersons, int length, sPerson* auxPerson, int index);

void printListSortedByName(sPerson sPersons[], int length);
short int sortPersonArrayByName(sPerson sPersons[], int length);

void deletePerson(sPerson sPersons[], int length);
int searchPersonByDni(sPerson sPersons[], int length, char dniToSearch[]);

void printAgesGraph(sPerson sPersons[], int length);

void exitPersons(int* answer);

short int askForDNI(sPerson* sPersons, int length, char* dni, int attempts);
int existPersonByDNI(sPerson* sPersons, int length, char* dni);
