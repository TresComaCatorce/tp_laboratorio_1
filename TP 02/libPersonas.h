#ifndef __STRUCT
#define __STRUCT
//Structs
typedef struct {

    char name[51];
    char lastname[51];
    int age;
    short int state; //[0]=Deleted-Data deprecated //[1]=With valid data
    char dni[10];

}sPerson;
#endif

//Function prototypes
short int runSystem(void);
