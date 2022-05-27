//global includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//global vars
#define COMPANY_NAME "imv"
#define DATABASE_NAME "userDatabase.csv"

//OS specific includes and defines
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

//typedefs
typedef struct {
    char username[20];
    char password[20];
} user;

//prototypes
int welcome(void);
char losi(void);
int login(user *templ);
int signup(user *temps);
int credInput(user *tempc);

//main
int main(void){
    welcome();
    //declare a character variable called choice
    char choice;
    user temp;
    menu: 
    choice = losi();
    if (choice == 'l') login(&temp);
    else if (choice == 's') signup(&temp);
    else if (choice == 'q') exit(0);
    else{
        printf("Invalid choice");
        sleep(3);
        goto menu;
    }
    //test
    printf("User: %s\n", temp.username);
    printf("Password: %s\n", temp.password);
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

//login
int login(user *templ){
    CLEAR;
    printf("Login\n");
    credInput(templ);
    return 0;
}

//signup
int signup(user *temps){
    CLEAR;
    printf("Signup\n");
    credInput(temps);
    return 0;
}

int credInput(user *tempc){
    printf("Username: ");
    scanf("%s", &tempc->username);
    printf("Password: ");
    scanf("%s", &tempc->password);
    return 0;
}