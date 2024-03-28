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