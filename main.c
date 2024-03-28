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

// Dummy function for customerpage
void customerPage(char username[]) {
    printf("Welcome, %s\n", username);
}

void signIn() {
    char username[MAX_USERNAME_LENGTH]; //Local
    char password[MAX_PASSWORD_LENGTH]; //Local
    
    printf("\n\nCUSTOMER SIGN-IN PAGE\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("\nLogin successful!\n");
            customerPage(username);
        }
    }
}

void signUp() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    
    printf("\nCUSTOMER SIGN-UP PAGE\n");
    printf("Enter username: ");
    scanf("%s", users[numUsers].username);

    // Check if username already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, users[numUsers].username) == 0) {
            printf("Username already exists. Please choose another.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", users[numUsers].password);
    numUsers++;

    printf("\nSignup successful!");
    printf("\nRedirecting to sign-in page...");
    signIn();
}

void customerLogin() {
    int choice;
    
    printf("\n>Selection Screen>Customer Login");
    printf("\n\n[1] Sign-up");
    printf("\n[2] Sign-in");
    
    printf("\n\nEnter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            signUp();
            break;
        case 2:
            signIn();
            break;
        default:
            printf("Invalid choice. Try again...");
    }

    return;
}

// Dummy Function
void staffPage(char name[]) {
    printf("\nWelcome %s", name);
}

void staffLogin() {
    char username[20]; // Username size
    char password[20]; // Password size
    
    printf("\n>Selection Screen>Staff Login");
    
    while (1) {
        printf("\n\nEnter username: ");
        scanf("%19s", username); // Limit input length to prevent buffer overflow and include null terminator
        
        printf("Enter password: ");
        scanf("%19s", password); // Limit input length to prevent buffer overflow and include null terminator
        
        if (strcmp(username, "root") == 0 && strcmp(password, "admin") == 0) {
            printf("\nSuccessfully logged in. [root]");
            staffPage(username);
            break;
        } else {
            printf("\nLogin failed. Incorrect username or password.");
        }
    }
}

void selectionScreen() {
    int action;
    
    printf("\n>Selection Screen");
    printf("\n\n[1] Staff");
    printf("\n[2] Customer\n");
    
    do {
    printf("\nEnter action according to number: ");
    scanf("%d", &action);
    } while (action != 1 && action != 2);
    
    if (action == 1) {
        staffLogin();
    }
    else if (action == 2) {
        customerLogin();
    }
}

int main()
{
    char start;
    
    printf("Welcome to Astro Application");
    printf("\nPress enter to continue... ");
    scanf("%c", &start);
    
    selectionScreen();

    return 0;
}
