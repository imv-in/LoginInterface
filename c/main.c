#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>

#define COMPANY_NAME "imv"

//prototypes
int welcome(void);

int main(void){

    welcome();

    return 0;
}

int welcome(void){

    printf("Welcome to %s", COMPANY_NAME);
    getch();

    return 0;
}