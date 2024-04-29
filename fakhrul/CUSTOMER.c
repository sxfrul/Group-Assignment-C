
#include <stdio.h>

// CONSTANTS
float tax = 0.06;

// GLOBAL VAR
float totalpayment = 0;

// QUANTITY
int 
quantitySub1 = 0,
quantitySub2 = 0,
quantitySub3 = 0,
quantityProm1 = 0,
quantityProm2 = 0,
quantityProm3 = 0;

void subscription(void);
void payment(void);
void promotion(void);

int main()
{
    int option;
    while (1) {
        printf("-------------------------------------------\n");
        printf("\nWelcome to Customer Homepage!\nWhat can we do for you?");
        printf("\n\n[1]-Subscriptions\n[2]-Payment\n[3]-Promotions\n[4]-Exit\n");
        printf("\n-------------------------------------------");
        printf("\nInsert the number : ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                subscription();
                break;
            case 2:
                payment();
                break;
            case 3:
                promotion();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice.");
        }
    }
}

void subscription() {
    int option;
    char confirmation;

    while (1) {
        printf("-------------------------------------------\n");
        printf("\n>>>Subscriptions available!<<<\n\n[1]-Sports 4 life! (30 days) - RM30");
        printf("\n[2]-Midnight Blockbuster (30 days) - RM 35\n[3]-Premium Movie+ (30 days) - RM 40\n[4]-Return\n");
        printf("\n-------------------------------------------");
        printf("\nInsert the number : ");
        scanf("%d", &option);
        printf("-------------------------------------------\n");

        switch (option) {
            case 1:
                do {
                    printf("Confirm purchase? (Y/n): ");
                    scanf(" %c", &confirmation);
                } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

                if (confirmation == 'y' || confirmation == 'Y') {
                    totalpayment += 30;
                    quantitySub1++;
                    printf("Item added to cart.\n");
                    break;
                }
                else {
                    printf("Item was not added to cart.\n");
                    return;
                    break;
                }
            case 2:
                do {
                    printf("Confirm purchase? (Y/n): ");
                    scanf(" %c", &confirmation);
                } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

                if (confirmation == 'y' || confirmation == 'Y') {
                    totalpayment += 35;
                    quantitySub2++;
                    printf("Item added to cart.\n");
                    break;
                }
                else {
                    printf("Item was not added to cart.\n");
                    break;
                }
            case 3:
                do {
                    printf("Confirm purchase? (Y/n): ");
                    scanf(" %c", &confirmation);
                } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

                if (confirmation == 'y' || confirmation == 'Y') {
                    totalpayment += 40;
                    quantitySub3++;
                    printf("Item added to cart.\n");
                    break;
                }
                else {
                    printf("Item was not added to cart.\n");
                    break;
                }
            case 4:
                return;
                break;
            default:
                printf("\nInvalid choice...\n");
                break;
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
    int option;
    char confirmation;

    while (1) {
        printf("-------------------------------------------\n");
        printf("\n>>>Promotions available!<<<\n\n[1]-Home of Kids Day - Pass (1 day) - RM 5");
        printf("\n[2]-iQIYI Premium VIP Pass (30 days) - RM 35\n[3]-MasterChef US Pass (30 days) - RM 35\n[4]-Return\n");
        printf("\n-------------------------------------------");
        printf("\nInsert the number : ");
        scanf("%d", &option);
        printf("-------------------------------------------\n");

        switch (option) {
            case 1:
                do {
                    printf("Confirm purchase? (Y/n): ");
                    scanf(" %c", &confirmation);
                } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

                if (confirmation == 'y' || confirmation == 'Y') {
                    totalpayment += 5;
                    quantityProm1++;
                    printf("Item added to cart.\n");
                    break;
                }
                else {
                    printf("Item was not added to cart.\n");
                    return;
                    break;
                }
            case 2:
                do {
                    printf("Confirm purchase? (Y/n): ");
                    scanf(" %c", &confirmation);
                } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

                if (confirmation == 'y' || confirmation == 'Y') {
                    totalpayment += 35;
                    quantityProm2++;
                    printf("Item added to cart.\n");
                    break;
                }
                else {
                    printf("Item was not added to cart.\n");
                    break;
                }
            case 3:
                do {
                    printf("Confirm purchase? (Y/n): ");
                    scanf(" %c", &confirmation);
                } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

                if (confirmation == 'y' || confirmation == 'Y') {
                    totalpayment += 35;
                    quantityProm3++;
                    printf("Item added to cart.\n");
                    break;
                }
                else {
                    printf("Item was not added to cart.\n");
                    break;
                }
            case 4:
                return;
                break;
            default:
                printf("\nInvalid choice...\n");
                break;
        }
        do {
            printf("View other promotions? (Y/n): ");
            scanf(" %c", &confirmation);
        } while (confirmation!='Y'&&confirmation!='y'&&confirmation!='N'&&confirmation!='n');

        if (confirmation == 'n' || confirmation == 'n') {
            return;
        }
    }

    return;
}

void payment() {
    float taxpayment, paymentwtax;
    int option;
    int bankNum;

    printf("-------------------------------------------\n");
    printf("\n<{Total payment required to pay : RM %.2f}>", totalpayment);
    printf("\n\n>>Choose option<<\n[1]-Pay\n[2]-Return\n\n");
    
    printf("-------------------------------------------\n");
    printf("Insert the Number : ");
    scanf("%d", &option);
    printf("-------------------------------------------\n");
    
    switch (option) 
    {
        case 1:
            if (totalpayment == 0) {
                printf("\nYou have not added any product.\n");
                break;
            }

            else 
            {
                printf("\nInsert your bank card number: ");
                scanf("%d", &bankNum);

                taxpayment = tax * totalpayment;
                paymentwtax = taxpayment + totalpayment;

                printf("\n>>Payment successful<<\n\n-------------------------------------------");
                printf("\n\nYour Invoice has been sent :\n\n**************************************************************************************\n\n");
                printf("Invoice no : 00001\nBill to : Astro Company Ltd\n");
                printf("\n**************************************************************************************\n\n");
                printf("[Item]\t\t\t\t\t[Duration]\t\t[Price]\n");
                
                if(quantitySub1>0){
                    printf("\nSports 4 life! \t\t\t\t(30 days)\t\tRM 30\n");
                    quantitySub1=0;
                }
                    
                if(quantitySub2>0){
                    printf("\nMidnight Blockbuster \t\t\t(30 days)\t\tRM 35\n");
                    quantitySub2=0;
                }
                    
                if(quantitySub3>0){
                    printf("\nPremium Movie+ \t\t\t\t(30 days)\t\tRM 40\n");
                    quantitySub3=0;
                }
                
                if(quantityProm1>0){	
                    printf("\nHome of Kids Day - Pass \t\t\t(1 day)\t\tRM 5\n");
                    quantityProm1=0;
                }
                    
                if(quantityProm2>0){
                    printf("\niQIYI Premium VIP Pass \t\t\t(30 days)\t\tRM 35\n");
                    quantityProm2=0;
                }
                    
                if(quantityProm3>0){
                    printf("\nMasterChef US Pass \t\t\t(30 days)\t\tRM 35\n");
                    quantityProm3=0;
                }
                
                printf("\n**************************************************************************************");
                printf("\nTotal payment : RM%.2f\nTax service charge (6 percent) : RM%.2f\n\n", totalpayment, taxpayment);
                printf("Total payment wth tax : RM%.2f\n**************************************************************************************\n", paymentwtax);
                
                totalpayment=0;
                break;
            }
        case 2:
            return;
        default:
            printf("\nInvalid choice...\n");
    }
}
