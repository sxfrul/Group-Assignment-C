#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

// Hashmap or Dict
struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int numUsers = 0;

// COLOR --------------------------------------
void removeColor() {
    printf("\033[0m");
}

void pink() {
    printf("\033[0;95m");
}

void red() {
    printf("\033[0;31m");
}

void green() {
    printf("\033[0;32m");
}


// CUSTOMER-CENTERED ----------------------------------------------------
// Dummy function for customerpage
void customerPage(char username[]) {
    printf("Welcome, %s\n", username);
}

void signIn() {
    char username[MAX_USERNAME_LENGTH]; //Local
    char password[MAX_PASSWORD_LENGTH]; //Local
    
    pink();
    printf("\n\nCUSTOMER SIGN-IN PAGE\n");
    removeColor();

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            green();
            printf("\nLogin successful!\n");
            removeColor();

            customerPage(username);
            return;
        }
    }

    red();
    printf("\nLogin failed...\n");
    removeColor();
    return;
}

void signUp() {
    char password[20];
    char confirmPassword[20];

    if (numUsers >= MAX_USERS) {
        red();
        printf("Maximum number of users reached.\n");
        removeColor();
        return;
    }
    
    pink();
    printf("\nCUSTOMER SIGN-UP PAGE\n");
    removeColor();

    printf("Enter username: ");
    scanf("%s", users[numUsers].username);

    // Check if username already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, users[numUsers].username) == 0) {
            red();
            printf("Username already exists. Please choose another.\n");
            removeColor();
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", password);

    printf("Confirm password: ");
    scanf("%s", confirmPassword);

    if (strcmp(password, confirmPassword) == 0) {
        strcpy(users[numUsers].password, confirmPassword);
        numUsers++;

        green();
        printf("\nSignup successful!\n");
        removeColor();
        printf("Redirecting to sign-in page...");
        signIn();
    }
    else {
        red();
        printf("\nSignup unsuccessful...\n");
        removeColor();
        return;
    }
}

void customerLogin() {
    char choice;
    
    while (1) {
        pink();
        printf("\n>Selection Screen>Customer Login");
        removeColor();

        printf("\n\n[1] Sign-up");
        printf("\n[2] Sign-in");
        printf("\n[3] Back");
        
        printf("\n\nEnter choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                signUp();
                break;
            case '2':
                signIn();
                break;
            case '3':
                return;
            default:
                red();
                printf("Invalid choice. Try again...");
                removeColor();
        }
    }

    return;
}

// STAFF-CENTERED --------------------------------------------------------
// Dummy Function
void staffPage(char name[]) {
    printf("\nWelcome %s", name);
    // TERMINATE HERE! /CONTINUE
}

void staffSignIn() {
    char username[MAX_USERNAME_LENGTH]; // Username size
    char password[MAX_PASSWORD_LENGTH]; // Password size
    char choice;

    printf("\nEnter username: ");
    scanf("%19s", username); // Limit input length to prevent buffer overflow and include null terminator
    
    printf("Enter password: ");
    scanf("%19s", password); // Limit input length to prevent buffer overflow and include null terminator
    

    while (strcmp(username, "root") != 0 || strcmp(password, "admin") != 0) {
        red();
        printf("\nLogin failed. Incorrect username or password.");
        printf("\nWould you like to retry? [y/n]: ");
        removeColor();
        scanf(" %c", &choice);

        if (choice == 'y') {
            printf("\nEnter username: ");
            scanf("%19s", username); // Limit input length to prevent buffer overflow and include null terminator
    
            printf("Enter password: ");
            scanf("%19s", password); // Limit input length to prevent buffer overflow and include null terminator
        }
        else {
            return;
            break;
        }
    }
    green();
    printf("\nLogin succesful!\n");
    removeColor();
    staffPage(username);
}

void staffLogin() {
    char action;
    
    while (1) {
        pink();
        printf("\n>Selection Screen>Staff Login");
        removeColor();

        printf("\n\n[1] Sign-in");
        printf("\n[2] Back");

        printf("\n\nEnter choice: ");
        scanf(" %c", &action);

        switch (action) {
            case '1':
                staffSignIn();
                break;
            case '2':
                return;
                break;
            default:
                red();
                printf("\nInvalid input...");
                removeColor();
        }
    }
}

// SELECTION -------------------------------------------
void selectionScreen() {
    char action;
    
    while (1) {
        pink();
        printf("\n>Selection Screen");
        removeColor();

        printf("\n\n[1] Staff");
        printf("\n[2] Customer");
        printf("\n[3] Exit\n");
        
        do {
        printf("\nEnter choice: ");
        scanf(" %c", &action);
        if (action != '1' && action != '2' && action != '3')
        {
            red();
            printf("Invalid input.\n");
            removeColor();
        }
        } while (action != '1' && action != '2' && action != '3');
        
        if (action == '1') {
            staffLogin();
        }
        else if (action == '2') {
            customerLogin();
        }
        else if (action == '3') {
            pink();
            printf("\nThank you for using Astro Application. See you!");
            removeColor();
            return;
        }
    }
}

void welcomeMessage() {
    pink();
    printf("    _       _               _             _ _         _   _             \n");
    printf("   /_\\   __| |_ _ _ ___    /_\\  _ __ _ __| (_)__ __ _| |_(_)___ _ _  ___\n");
    printf("  / _ \\ (_-<  _| '_/ _ \\  / _ \\| '_ \\ '_ \\ | / _/ _` |  _| / _ \\ ' \\(_-<\n");
    printf(" /_/ \\_\\/__/\\__|_| \\___/ /_/ \\_\\ .__/ .__/_|_\\__\\__,_|\\__|_\\___/_||_/__/\n");
    printf("                               |_|  |_|                                 \n");
    removeColor();
}

int main()
{
    char start;

    welcomeMessage(); //subroutine to Welcome Message

    printf("Welcome to Astro Application");
    printf("\nPress enter to continue... ");
    scanf("%c", &start);
    
    selectionScreen();
    return 0;
}
