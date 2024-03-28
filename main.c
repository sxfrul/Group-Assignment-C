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

void mainPage() {
    printf("Welcome!\n");
}

void signup() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

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

    printf("Signup successful!\n");
}

void login() {
    char username[MAX_USERNAME_LENGTH]; //Local
    char password[MAX_PASSWORD_LENGTH]; //Local
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            mainPage();
        }
    }

    printf("Invalid username or password.\n");
}

void customerLogin() {
    int choice;
    do {
        printf("\n[1] Signup\n[2] Login\n[3] Back\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                signup();
                printf("test2");
                break;
            case 2:
                login();
                printf("test");
                break;
            case 3:
                return;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return;
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
            // staffPage();
            // break;
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
