#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_FIRSTNAME_LENGTH 20
#define MAX_LASTNAME_LENGTH 20

// SERVICE DATABASE
// SUBSCRIPTIONS
char subName[100][99] = {"Astro TV Pack", "Astro WiFi Plan", "Premium Movie+"};
int subDuration[100] = {30, 30, 30}; // in months or etc
int subPrice[100] = {30, 35, 40}; // in RM

int subQuantity[100] = {};
int subPurchased[100] = {};

// PROMOTIONS
char promName[100][99] = {"iQIYI Premium VIP Pass", "Home of Kids Day-pass", "MasterChef US Pass"};
int promDuration[100] = {1, 30, 30}; // in months or etc
int promPrice[100] = {5, 35, 35}; // in RM

int promQuantity[100] = {};
int promPurchased[100] = {};

// LOGIN & SIGNUPS
void signIn(void);
void signUp(void);

void staffSignIn(void);
void staffLoginScreen(void);

// MISCS
void selectionScreen(void);
void appTitle(void);

/* CUSTOMER PAGE */
// CONSTANTS
float tax = 0.06;

// GLOBAL VAR
int invoiceCount = 0;
float totalpayment = 0;

int 
quantityProm1 = 0,
quantityProm2 = 0,
quantityProm3 = 0;

int
duraProm1 = 1,
duraProm2 = 30,
duraProm3 = 30;

float
priceProm1 = 5,
priceProm2 = 35,
priceProm3 = 35;


void subscription(void);
void payment(char [], char[]);
void promotion(void);

/* STAFF PAGE */
int i,confirm;
char ServName[100];
float ServDura,ServPrice;

void addService(void);
void delService(void);
void editService(void);
void genReport(void);

// Hashmap or Dict
struct User {
    char userType[MAX_USERNAME_LENGTH];
    char firstName[MAX_FIRSTNAME_LENGTH];
    char lastName[MAX_LASTNAME_LENGTH];
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

//start of fakhrul part
void customerPage(char username[], char firstName[], char lastName[], char userType[]) {
    char option;
    while (1) {
        system("clear");
        pink();
        printf("\n>Selection Screen>Customer Login>Customer Page\n");
        removeColor();
        printf("\nWelcome %s %s (%s: \033[0;32m%s Account\033[0m)!\nWhat can we do for you?", firstName, lastName, username, userType);
        printf("\n\n[1] Subscriptions\n[2] Promotions\n[3] Payment\n[4] Back to User Select\n");
        printf("\n-------------------------------------------");
        printf("\nInsert the number : ");
        scanf(" %c", &option);
        
        switch (option) {
            case '1':
                subscription();
                break;
            case '2':
                promotion();
                break;
            case '3':
                payment(firstName, lastName);
                break;
            case '4':
                return;
            default:
                red();
                printf("\nInvalid choice.");
                removeColor();
        }
    }
}

void subscription() {
    int option, optionActual;
    char confirmation;

    while (1) {
        system("clear");
        pink();
        printf("\n>Selection Screen>Customer Login>Customer Page>Subscriptions\n");
        removeColor();
        printf("\nSubscriptions available:\n");

        for (i = 0; i<100; i++) {
            if (subDuration[i] == 0) {
                break;
            }
            printf("[%d] %-50s \t%3d days \tRM %3d\n", i+1, subName[i], subDuration[i], subPrice[i]);
        }
        printf("[0] Return");
        printf("\n-------------------------------------------");
        printf("\nInsert the number : ");
        scanf("%d", &option);
        printf("-------------------------------------------\n");

        optionActual = option - 1;

        if (option == 0) {
            return;
        }

        do {
            printf("Confirm purchase? (Y/n): ");
            scanf(" %c", &confirmation);
        } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

        if (confirmation == 'y' || confirmation == 'Y') {
            totalpayment += subPrice[optionActual];
            subQuantity[optionActual]++;
            printf("Item added to cart.\n");
        }
        else {
            printf("Item was not added to cart.\n");
            return;
        }
        
        do {
            printf("View other subscriptions? (Y/n): ");
            scanf(" %c", &confirmation);
        } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

        if (confirmation == 'n' || confirmation == 'n') {
            return;
        }
    }

    return;
}

void promotion() {
    int option, optionActual;
    char confirmation;

    while (1) {
        system("clear");
        pink();
        printf("\n>Selection Screen>Customer Login>Customer Page>Promotions\n");
        removeColor();
        printf("\nPromotions available:\n");
        for (i = 0; i<100; i++) {
            if (promDuration[i] == 0) {
                break;
            }
            printf("[%d] %-50s \t%3d days \tRM %3d\n", i+1, promName[i], promDuration[i], promPrice[i]);
        }
        printf("[0] Return");
        printf("\n-------------------------------------------");
        printf("\nInsert the number : ");
        scanf("%d", &option);
        printf("-------------------------------------------\n");

        optionActual = option - 1;

        if (option == 0) {
            return;
        }

        do {
            printf("Confirm purchase? (Y/n): ");
            scanf(" %c", &confirmation);
        } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

        if (confirmation == 'y' || confirmation == 'Y') {
            totalpayment += promPrice[optionActual];
            promQuantity[optionActual]++;
            printf("Item added to cart.\n");
        }
        else {
            printf("Item was not added to cart.\n");
            return;
        }
        
        do {
            printf("View other subscriptions? (Y/n): ");
            scanf(" %c", &confirmation);
        } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

        if (confirmation == 'n' || confirmation == 'n') {
            return;
        }
    }

    return;
}

void payment(char firstName[], char lastName[]) {
    float taxpayment, paymentwtax;
    int option;
    int bankNum;

    system("clear");
    pink();
    printf("\n>Selection Screen>Customer Login>Customer Page>Payment\n");
    removeColor();
    printf("\n<{Total payment required to pay : RM %.2f}>", totalpayment);
    printf("\n\n[1] Pay\n[2] Return\n\n");
    
    printf("-------------------------------------------\n");
    printf("Insert the Number : ");
    scanf("%d", &option);
    printf("-------------------------------------------\n");
    
    switch (option) 
    {
        case 1:
            if (totalpayment == 0) {
                red();
                printf("\nYou have not added any product.\n");
                printf("Returning to homepage...\n");
                sleep(2);
                break;
            }

            else 
            {
                printf("\nInsert your bank card number: ");
                scanf("%d", &bankNum);

                taxpayment = tax * totalpayment;
                paymentwtax = taxpayment + totalpayment;
                invoiceCount++;

                // PREREQUISITES FOR TIME
                struct tm* ptr;
                time_t t;
                t = time(NULL);
                ptr = localtime(&t);
                
                system("clear");
                green();
                printf("\n>>Payment successful<<\n\n-------------------------------------------");
                removeColor();
                printf("\n\nInvoice:\n");
                printf("\n**************************************************************************************\n\n");
                printf("Invoice no : %05d\nBill to : %s %s\n", invoiceCount, firstName, lastName);
                printf("Date: %s", asctime(ptr)); //PRINTS TIME
                printf("\n**************************************************************************************\n\n");
                printf("%-56s[Duration]\t[Price]\n", "[Item]");
                
                for (int i = 0; i<100; i++) {
                    if (subQuantity[i] != 0) {
                        printf("%-50s \t(%3d days) \tRM %3d\n", subName[i], subDuration[i] * subQuantity[i], subPrice[i]*subQuantity[i]);
                        subPurchased[i] += subQuantity[i];
                        subQuantity[i] = 0;
                    }
                }

                for (int i = 0; i<100; i++) {
                    if (promQuantity[i] != 0) {
                        printf("%-50s \t(%3d days) \tRM %3d\n", promName[i], promDuration[i] * promQuantity[i], promPrice[i]*promQuantity[i]);
                        promPurchased[i] += promQuantity[i];
                        promQuantity[i] = 0;
                    }
                }
                
                printf("\n**************************************************************************************");
                printf("\nTotal payment : RM%.2f\nTax service charge (6 percent) : RM%.2f\n\n", totalpayment, taxpayment);
                printf("Total payment wth tax : RM%.2f\n**************************************************************************************\n", paymentwtax);
                
                green();
                printf("\nThis screen will close in 10 seconds\n");
                removeColor();
                sleep(10);
                
                totalpayment=0;
                break;
            }
        case 2:
            return;
        default:
            printf("\nInvalid choice...\n");
    }
}

//end of fakhrul part

void signIn() {
    char username[MAX_USERNAME_LENGTH]; //Local
    char password[MAX_PASSWORD_LENGTH]; //Local
    char retry;
    
    system("clear");
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
            printf("Redirecting to customer page...\n");
            sleep(3);
            removeColor();

            customerPage(username, users[i].firstName, users[i].lastName, users[i].userType);
            return;
        }
    }

    red();
    printf("\nLogin failed...\n");
    printf("Redirecting back...\n");
    sleep(3);
    removeColor();
    return;
}

void signUp() {
    char password[20];
    char confirmPassword[20];
    char businessOption;

    system("clear");

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
            sleep(3);
            removeColor();
            return;
        }
    }

    printf("Enter first name: ");
    scanf("%s", users[numUsers].firstName);

    printf("Enter last name: ");
    scanf("%s", users[numUsers].lastName);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Confirm password: ");
    scanf("%s", confirmPassword);

    do {
        printf("Register as business account? (Y/n): ");
        scanf(" %c", &businessOption);

        if (businessOption != 'y' && businessOption != 'n' && businessOption != 'Y' && businessOption != 'N') {
            red();
            printf("Invalid, please retry...\n");
            removeColor();
        }
    } while(businessOption != 'y' && businessOption != 'n' && businessOption != 'Y' && businessOption != 'N');

    if (businessOption == 'y' || businessOption == 'Y') {
        strcpy(users[numUsers].userType, "Business");
    }
    else {
        strcpy(users[numUsers].userType, "Residential");
    }

    if (strcmp(password, confirmPassword) == 0) {
        strcpy(users[numUsers].password, confirmPassword);
        numUsers++;

        green();
        printf("\nSignup successful!\n");
        sleep(2);
        removeColor();
        printf("Redirected to sign-in page...");
        signIn();
    }
    else {
        red();
        printf("\nPassword does not match Confirm Password.");
        printf("\nSignup unsuccessful...\n");
        sleep(3);
        removeColor();
        return;
    }
}

void customerLogin() {
    char choice;
    
    while (1) {
        system("clear");
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
//start of mira part
void staffPage(char name[]) {
    int opt1, confirm;

    while (1) {
        system("clear");
        pink();
        printf("\n>Selection Screen>Staff Login>Staff Page\n");
        removeColor();
        printf("\nWelcome staff: %s\n", name);
        printf("\n[1] Add Services\n[2] Delete Services\n[3] Edit Services\n[4] Generate Report\n[5] Back to Staff Login\n\nInsert Number: ");
        scanf("%d",&opt1);
        
        switch(opt1){
            case 1 : //add service
                addService();
                break;
                
            case 2: //delete service
                delService();
                break;
                
            case 3: // edit service
                editService();
                break;
            
            case 4: // generate report
                genReport();
                break;
            
            case 5: // exit to homepage
                return;
                break;

            default:
                printf("Invalid choice...\n");
        }
    }
}

void addService (void){
	float tempServDura,tempServPrice;
	char tempServName[100];
    int emptySlot, option;
    system("clear");
    pink();
    printf("\n>Selection Screen>Staff Login>Staff Page>Add Service\n");
    removeColor();
    printf("\nADD SERVICE:\n");
    printf("[1] Subscriptions\n");
    printf("[2] Promotions\n");
    printf("[3] Back\n\n");

    printf("Enter choice: ");
    scanf("%d", &option);


    system("clear");
    switch (option) {
        case 1:
            do {
                printf("Insert Subscription Name: ");
                scanf("%s", tempServName);
                printf("Insert Subscription Duration: ");
                scanf("%f", &tempServDura);
                printf("Insert Subscription Price:RM ");
                scanf("%f", &tempServPrice);
                
                printf("\nCONFIRM?\n1. YES\t2. NO\nanswer:");
                scanf("%d", &confirm);
                    
                if(confirm==1)
                {
                    strcpy(ServName, tempServName);
                    ServDura=tempServDura;
                    ServPrice= tempServPrice;
                    printf("\nService Have Added\n\n");
                } 
            } while (confirm!=1);

            for (emptySlot = 0; emptySlot<100; emptySlot++) {
                if (subDuration[emptySlot] == 0) {
                    break;
                }
            }

            strcpy(subName[emptySlot], ServName);
            subDuration[emptySlot] = ServDura;
            subPrice[emptySlot] = ServPrice;
            
            system("clear");
            pink();
            printf("\n%-45s\t\t\tDuration\tPrice\n", "Service");
            removeColor();
            for (i = 0; i<100; i++) {
                if (subDuration[i] == 0) {
                    break;
                }
                printf("Item [%d]:%-50s \tDuration:%-3d \tPrice:%-3d\n",i+1, subName[i], subDuration[i], subPrice[i]);
            }
            printf("\nReturning in 5 seconds...\n");
            sleep(5);
            break;
        case 2:
            do {
                printf("Insert Promotion Name: ");
                scanf("%s", tempServName);
                printf("Insert Promotion Duration (days): ");
                scanf("%f", &tempServDura);
                printf("Insert Promotion Price: RM ");
                scanf("%f", &tempServPrice);
                
                printf("\nCONFIRM?\n1. YES\t2. NO\nanswer:");
                scanf("%d", &confirm);
                    
                if(confirm==1)
                {
                    strcpy(ServName, tempServName);
                    ServDura=tempServDura;
                    ServPrice= tempServPrice;
                    printf("\nPromotion have been added.\n\n");
                } 
            } while (confirm!=1);

            for (emptySlot = 0; emptySlot<100; emptySlot++) {
                if (promDuration[emptySlot] == 0) {
                    break;
                }
            }

            strcpy(promName[emptySlot], ServName);
            promDuration[emptySlot] = ServDura;
            promPrice[emptySlot] = ServPrice;
            
            system("clear");
            pink();
            printf("\n%-45s\t\t\tDuration\tPrice\n", "Service");
            removeColor();

            for (i = 0; i<100; i++) {
                if (promDuration[i] == 0) {
                    break;
                }
                printf("Item [%d]:%-50s \tDuration:%-3d \tPrice:%-3d\n",i+1, promName[i], promDuration[i], promPrice[i]);
            }
            printf("\nReturning in 5 seconds...\n");
            sleep(5);

            break;
        case 3:
            return;
        default:
            printf("Invalid choice...\n");
            printf("\nReturning in 5 seconds...\n");
            sleep(5);
    }
    return;
}

void delService(void){
	int delServ, option, remainder;
    system("clear");
    pink();
    printf("\n>Selection Screen>Staff Login>Staff Page>Delete Service\n");
    removeColor();
	printf("\nDelete Service:\n");
    printf("[1] Subscriptions\n");
    printf("[2] Promotions\n");
    printf("[3] Back\n\n");

    printf("Enter choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            pink();
            printf("\n%-45s\t\t\tDuration\tPrice\n", "Subscription");
            removeColor();
            for (i = 0; i<100; i++) { //this part Safrul need to do correction
                if (subDuration[i] == 0) {
                        break;
                    }
                printf("Item [%d]:%-50s \tDuration:%-3d \tPrice:%-3d\n",i+1, subName[i], subDuration[i], subPrice[i]);
            }

            printf("\nChoose Item to delete: ");
            scanf("%d", &delServ);
                    
            printf("\nCONFIRM?\n1 YES\t2 NO\nanswer: ");
            scanf("%d", &confirm);

            remainder = 100 - delServ;
                    
            if(confirm==1){
                for (int i = delServ; i<remainder; i++) {
                    if (subDuration[i] == 0) {
                        strcpy(subName[i-1], "");
                        subDuration[i-1] = 0;
                        subPrice[i-1] = 0;
                        break;
                    }
                    strcpy(subName[i-1], subName[i]);
                    subDuration[i-1] = subDuration[i];
                    subPrice[i-1] = subPrice[i];
                }

                system("clear");
                pink();
                printf("\n%-45s\t\t\tDuration\tPrice\n", "Subscription");
                removeColor();
                for (i = 0; i<100; i++) {
                    if (subDuration[i] == 0) {
                        break;
                    }
                    printf("Item [%d]:%-50s \tDuration:%-3d \tPrice:%-3d\n",i+1, subName[i], subDuration[i], subPrice[i]);
                }
                printf("\nReturning in 5 seconds...\n");
                sleep(5);
                break;
            }
        case 2:
            pink();
            printf("\n%-45s\t\t\tDuration\tPrice\n", "Promotion");
            removeColor();
            for (i = 0; i<100; i++) { //this part Safrul need to do correction
                if (promDuration[i] == 0) {
                        break;
                    }
                printf("Item [%d]:%-50s \tDuration:%-3d \tPrice:%-3d\n",i+1, promName[i], promDuration[i], promPrice[i]);
            }

            printf("\nChoose Item to delete: ");
            scanf("%d", &delServ);
                    
            printf("\nCONFIRM?\n1 YES\t2 NO\nanswer: ");
            scanf("%d", &confirm);

            remainder = 100 - delServ;
                    
            if(confirm==1){
                for (int i = delServ; i<remainder; i++) {
                    if (promDuration[i] == 0) {
                        strcpy(promName[i-1], "");
                        promDuration[i-1] = 0;
                        promPrice[i-1] = 0;
                        break;
                    }
                    strcpy(promName[i-1], promName[i]);
                    promDuration[i-1] = promDuration[i];
                    promPrice[i-1] = promPrice[i];
                }
                
                system("clear");
                pink();
                printf("\n%-45s\t\t\tDuration\tPrice\n", "Promotion");
                removeColor();
                for (i = 0; i<100; i++) {
                    if (promDuration[i] == 0) {
                        break;
                    }
                    printf("Item [%d]:%-50s \tDuration:%-3d \tPrice:%-3d\n",i+1, promName[i], promDuration[i], promPrice[i]);
                }
            }
            printf("\nReturning in 5 seconds...\n");
            sleep(5);
            break;
        case 3:
            break;
        default:
            printf("Invalid choice...");
            break;
    }
    return;
}


void editService(void){
	int item, edit, choice;
	char newName[100];
	float newDura,newPrice;
    system("clear");
	pink();
    printf("\n>Selection Screen>Staff Login>Staff Page>Edit Service\n");
    removeColor();
	printf("\nEdit Service:\n");
    printf("[1] Subscriptions\n");
    printf("[2] Promotions\n");
    printf("[3] Back\n\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            system("clear");
            pink();
            printf("\n%-45s\t\t\tDuration\tPrice\n", "Service");
            removeColor();
            for (i = 0; i<100; i++) { //this part Safrul need to do correction
                if (subDuration[i] == 0) {
                        break;
                    }

                printf("Item [%d]:%-50s \tDuration:%-3d \tPrice:%-3d\n",i+1, subName[i], subDuration[i], subPrice[i]);
            }
            
            printf("\nEnter item to edit:");
            scanf("%d", &item);
            item--;
            
            printf("Edit:\n1.Name\n2.Duration\n3.Price\nanswer:");
            scanf("%d", &edit);

            if (edit==1){
                //edit name
                printf("Re-enter Name:");
                scanf("%s", newName);
                strcpy(subName[item], newName);
                
                printf("Item[%d]:%-50s Duration:%-3d Price:%-3d",item+1, subName[item], subDuration[item], subPrice[item]);
                
            }
            else if(edit==2){
                //edit duration
                printf("Re-enter Duration:");
                scanf("%f", &newDura);
                subDuration[item] = newDura;
                
                printf("Item[%d]:%-50s Duration:%-3d Price:%-3d",item+1, subName[item], subDuration[item], subPrice[item]);
            }
            else if (edit==3){
                //edit price
                printf("Re-enter Price:");
                scanf("%f", &newPrice);
                subPrice[item] = newPrice;
                
                printf("Item[%d]:%-50s Duration:%-3d Price:%-3d",item+1, subName[item], subDuration[item],subPrice[item]);
            }
            system("clear");
            break;
        case 2:
            system("clear");
            pink();
            printf("\n%-45s\t\t\tDuration\tPrice\n", "Service");
            removeColor();
            for (i = 0; i<100; i++) { //this part Safrul need to do correction
                if (promDuration[i] == 0) {
                        break;
                    }

                printf("Item [%d]:%-50s \tDuration:%-3d \tPrice:%-3d\n",i+1, promName[i], promDuration[i], promPrice[i]);
            }
            
            printf("\nEnter item to edit:");
            scanf("%d", &item);
            item--;
            
            printf("Edit:\n1.Name\n2.Duration\n3.Price\nanswer:");
            scanf("%d", &edit);

            if (edit==1){
                //edit name
                printf("Re-enter Name:");
                scanf("%s", newName);
                strcpy(promName[item], newName);
                
                printf("Item[%d]:%-50s Duration:%-3d Price:%-3d",item+1, promName[item], promDuration[item], promPrice[item]);
                
            }
            else if(edit==2){
                //edit duration
                printf("Re-enter Duration:");
                scanf("%f", &newDura);
                promDuration[item] = newDura;
                
                printf("Item[%d]:%-50s Duration:%-3d Price:%-3d",item+1, promName[item], promDuration[item], promPrice[item]);
            }
            else if (edit==3){
                //edit price
                printf("Re-enter Price:");
                scanf("%f", &newPrice);
                promPrice[item] = newPrice;
                
                printf("Item[%d]:%-50s Duration:%-3d Price:%-3d",item+1, promName[item], promDuration[item],promPrice[item]);
            }
            system("clear");
            break;
        case 3:
            break;
        default:
            red();
            printf("Invalid choice... Returning.");
            sleep(3);
    }
}

void genReport(void){
	int item,genRep,totalPurc, sale=4, emptySlot;
    system("clear");
    pink();
    printf("\n>Selection Screen>Staff Login>Staff Page>Generate Report\n");
    removeColor();
	printf("\nGenerate report:\n\n");
    printf("[1] Subscriptions\n");
    printf("[2] Promotions\n");
    printf("[3] Overview\n");
    printf("[4] Back\n\n");

    printf("\nEnter choice: ");
	scanf("%d", &genRep);

    switch (genRep) {
        case 1:
            system("clear");
            printf("Item [0]: All\n");
            for (int i = 0; i<100; i++) { 
                if (subDuration[i] == 0) {
                        break;
                }
                printf("Item [%d]:%-50s\n",i+1, subName[i]);
            }
            
            printf("\nWhich item would you like to generate report?: ");
            scanf("%d", &genRep);
            
            // FIND EMPTY
            for (emptySlot = 0; emptySlot<100; emptySlot++) {
                if (subDuration[emptySlot] == 0) {
                    break;
                }
            }

            if(genRep == 0) {
                for (int i = 0; i<100; i++) { 
                    if (subDuration[i] == 0) {
                            break;
                    }
                    printf("\n-----REPORT ON ITEM[%d]-----\n",i+1);
                    printf("Purchase Count: %d\n", subPurchased[i]);
                    printf("Total Sale: RM%d\n", subPrice[i] * subPurchased[i]);
                }
                sleep(5);
            }
            else {
                    printf("\n-----REPORT ON ITEM[%d]-----\n",genRep);
                    printf("Purchase Count: %d\n", subPurchased[genRep-1]);
                    printf("Total Sale: RM%d\n", subPrice[genRep-1] * subPurchased[genRep-1]);
                    sleep(5);
            }
            break;
        case 2:
            system("clear");
            printf("Item [0]: All\n");
            for (int i = 0; i<100; i++) { 
                if (subDuration[i] == 0) {
                        break;
                }
                printf("Item [%d]:%-50s\n",i+1, promName[i]);
            }
            
            printf("\nWhich item would you like to generate report?: ");
            scanf("%d", &genRep);
            
            // FIND EMPTY SLOT
            for (emptySlot = 0; emptySlot<100; emptySlot++) {
                if (promDuration[emptySlot] == 0) {
                    break;
                }
            }

            if(genRep == 0) {
                for (int i = 0; i<100; i++) { 
                    if (promDuration[i] == 0) {
                            break;
                    }
                    printf("\n-----REPORT ON ITEM[%d]-----\n",i+1);
                    printf("Purchase Count: %d\n", promPurchased[i]);
                    printf("Total Sale: RM%d\n", promPrice[i] * promPurchased[i]);
                }
                sleep(5);
            }
            else {
                    printf("\n-----REPORT ON ITEM[%d]-----\n",genRep);
                    printf("Purchase Count: %d\n", promPurchased[genRep-1]);
                    printf("Total Sale: RM%d\n", promPrice[genRep-1] * promPurchased[genRep-1]);
                    sleep(5);
            }
            break;
        case 3:
            system("clear");
            // FIND EMPTY
            for (emptySlot = 0; emptySlot<100; emptySlot++) {
                if (promDuration[emptySlot] == 0) {
                    break;
                }
            }

            for (int i = 0; i<100; i++) { 
                if (subDuration[i] == 0) {
                        break;
                }
                printf("\n-----REPORT ON SUBSCRIPTION[%d]-----\n",i+1);
                printf("Purchase Count: %d\n", subPurchased[i]);
                printf("Total Sale: RM%d\n", subPrice[i] * subPurchased[i]);
            }
            for (int i = 0; i<100; i++) { 
                if (promDuration[i] == 0) {
                        break;
                }
                printf("\n-----REPORT ON PROMOTION[%d]-----\n",i+1);
                printf("Purchase Count: %d\n", promPurchased[i]);
                printf("Total Sale: RM%d\n", promPrice[i] * promPurchased[i]);
            }
            sleep(5);
            break;
        case 4:
            break;
        default:
            red();
            printf("\nInvalid choice... Returning to Staff page\n");
            removeColor();
            sleep(3);
    }
    return;
}

//end of mira part

void staffSignIn() {
    system("clear");
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
    sleep(3);
    removeColor();
    staffPage(username);
}

void staffLoginScreen() {
    char action;
    
    while (1) {
        system("clear");
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
        system("clear");
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
            system("clear");
            pink();
            printf("\nThank you for using Astro Application. See you!");
            removeColor();
            return;
        }
    }
}

void appTitle() {
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

    appTitle(); //subroutine to application Title

    printf("Welcome to Astro Application");
    printf("\nPress enter to continue... ");
    scanf("%c", &start);
    
    selectionScreen();
    return 0;
}
