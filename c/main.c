#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define COMPANY_NAME "imv"

#ifdef _WIN32
#define CLEAR system("cls")
#define getch _getch
#include <conio.h>
#endif

#ifdef linux
#define CLEAR system("clear")
#include <termios.h>
#define getch getchar
#endif
//prototypes
int welcome(void);
char losi(void);

//main
int main(void){

    welcome();

    return 0;
}

//welcome
int welcome(void){

    printf("Welcome to %s", COMPANY_NAME);
    getch();

    return 0;
}

//losi
char losi(void){

    CLEAR;
    return '\0';
}