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
int login(void);
int signup(void);

//main
int main(void){

    welcome();

    //declare a character variable called choice
    char choice;
    
    menu: 
    choice = losi();
    if (choice == 'l') login();
    else if (choice == 's') signup();
    else if (choice == 'q') exit(0);
    else
        printf("Invalid choice");
        sleep(3);
        goto menu;
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
    
    printf("(L)ogin\n(S)ignup\n(Q)uit\n");
    char choicel = getch();
    choicel = tolower(choicel);
    
    return choicel;
}

int login(void){

    CLEAR;
    printf("Login\n");
    printf("Username: ");
    char username[20];
    scanf("%s", username);
    printf("Password: ");
    char password[20];
    scanf("%s", password);
    return 0;
}

int signup(void){

    CLEAR;
    printf("Signup\n");
    printf("Username: ");
    char username[20];
    scanf("%s", username);
    printf("Password: ");
    char password[20];
    scanf("%s", password);
    return 0;
}