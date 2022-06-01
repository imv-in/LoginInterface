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
int loginBack(user *templ);
int signupBack(user *temps);

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
    int auth = loginBack(templ);
    if (auth == 1){
        sleep(2);
        login(templ);
    }
    return 0;
}

//signup
int signup(user *temps){
    CLEAR;
    printf("Signup\n");
    credInput(temps);
    int auth = signupBack(temps);
    if (auth == 1){ 
        sleep(2); 
        signup(temps);
    }
    return 0;
}

//credInput
int credInput(user *tempc){
    printf("Username: ");
    scanf("%s", &tempc->username);
    printf("Password: ");
    scanf("%s", &tempc->password);
    return 0;
}

int loginBack(user *templ){

    //open database
    FILE *fp;
    fp = fopen(DATABASE_NAME, "r");
    
    //check if file exists
    if (fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    //variables
    char entry[21];
    char *token;

    //check if any entry matches the username and password
    while (fgets(entry, 21, fp) != NULL){
        token = strtok(entry, ",");
        if (strcmp(token, templ->username) == 0){
            token = strtok(NULL, ",");
            if (strcmp(token, templ->password) == 0){
                printf("Login successful\n");
                fclose(fp);
                return 0;
            }
            else{
                printf("Incorrect password\n");
                fclose(fp);
                return 1;
            }
        }
        else{
            printf("Incorrect username\n");
            fclose(fp);
            return 1;
        }
    }
}

int signupBack(user *temps){
    //open database
    FILE *fp;
    fp = fopen(DATABASE_NAME, "a");
    
    //check if file exists
    if (fp == NULL){
        printf("Error opening file");
        exit(1);
    }

    //check if the username exist
    char entry[21];
    char *token;
    while (fgets(entry, 21, fp) != NULL){
        token = strtok(entry, ",");
        if (strcmp(token, temps->username) == 0){
            printf("Username already exists\n");
            fclose(fp);
            return 1;
        }
    }

    //write to file
    fprintf(fp, "%s,%s\n", temps->username, temps->password);
    printf("Signup successful\n");
    fclose(fp);
    return 0;
}