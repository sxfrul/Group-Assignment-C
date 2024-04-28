#include<stdio.h>
#include<string.h>

void addService ();
void delService ();
void editService();
void genReport();

// GLOBAL
char name[100][99] = {"Primary Pack", "Movie Pack ", "Sports Pack"};
int duration[100] = {1, 1, 1}; // in months or etc
int price[100] = {40, 60, 30}; // in RM
int i,confirm;
char ServName[100];
float ServDura,ServPrice;

int main()
{
	int opt1, confirm;

    while (1) {
        printf("Welcome to Staff Homepage!\n");
        printf("---MENU---\n1 Add Services\n2 Delete Services\n3 Edit Services\n4 Generate Report\n5 Exit\n\nInsert Number: ");
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
                printf("Exiting Staff Homepage.\n");
                return 0;
                break;

            default:
                printf("Invalid choice...\n");
        }
    }
}

void addService (void){
	float tempServDura,tempServPrice;
	char tempServName[100];
    int emptySlot;

    printf("\nADD SERVICE\n");
    do {
        printf("Insert Service Name: ");
        scanf("%s", tempServName);
        printf("Insert Service Duration: ");
        scanf("%f", &tempServDura);
        printf("Insert Service Price:RM ");
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
        if (duration[emptySlot] == 0) {
            break;
        }
    }
    
    printf("Empty slot on #%d\n", emptySlot);
    strcpy(name[emptySlot], ServName);
    duration[emptySlot] = ServDura;
    price[emptySlot] = ServPrice;
    
    printf("\nService\t\t\tDuration\tPrice\n");

    for (i = 0; i<50; i++) {
        printf("Item [%d]:%s \tDuration:%d \tPrice:%d\n",i+1, name[i], duration[i], price[i]);
    }

    return;
}

void delService(void){
	int delServ;
	printf("\n-----DELETE SERVICE-----");
    printf("\nService\t\t\tDuration\tPrice\n");
    for (i = 0; i<50; i++) { //this part Safrul need to do correction
            printf("Item [%d]:%s \tDuration:%d \tPrice:%d\n",i+1, name[i], duration[i], price[i]);
    }

	printf("\nChoose Item to delete: ");
	scanf("%d", &delServ);
			
	printf("\nCONFIRM?\n1 YES\t2 NO\nanswer: ");
	scanf("%d", &confirm);
			
	if(confirm==1){
		delServ--;
		strcpy(name[delServ], "");
        duration[delServ] = 0;
		price[delServ] = 0;
    		
		printf("\nService\t\t\tDuration\tPrice\n");
		for (i = 0; i<4; i++) {
    	    printf("Item [%d]:%s \tDuration:%d \tPrice:%d\n",i+1, name[i], duration[i], price[i]);
    	}
	}
}


void editService(void){
	int item,edit;
	char newName[100];
	float newDura,newPrice;
	
	printf("\n-----EDIT SURVICE-----");
	printf("\nService\t\t\tDuration\tPrice\n");
	for (i = 0; i<50; i++) { //this part Safrul need to do correction
        printf("Item [%d]:%s \tDuration:%d \tPrice:%d\n",i+1, name[i], duration[i], price[i]);
	}
	
	printf("\nEnter item to edit:");
	scanf("%d", &item);
	item--;
	
	printf("which part to edit?\n1.Name\n2.Duration\n3.Price\nanswer:");
	scanf("%d", &edit);

	if (edit==1){
		//edit name
		printf("Re-enter Name:");
		scanf("%s", newName);
		strcpy(name[item], newName);
		
		printf("Item[%d]:%s Duration:%d Price:%d",item+1, name[item], duration[item], price[item]);
		
	}
	else if(edit==2){
		//edit duration
		printf("Re-enter Duration:");
		scanf("%f", &newDura);
		duration[item] = newDura;
		
		printf("Item[%d]:%s Duration:%d Price:%d",item+1, name[item], duration[item], price[item]);
	}
	else if (edit==3){
		//edit price
		printf("Re-enter Price:");
		scanf("%f", &newPrice);
		price[item] = newPrice;
		
		printf("Item[%d]:%s Duration:%d Price:%d",item+1, name[item], duration[item], price[item]);
		}

}

void genReport(void){
	int item,genRep,totalPurc, sale=4;
	printf("\n-----GENERATE REPORT-----");
		printf("\nService\t\t\tDuration\tPrice\n");
		for (i = 0; i<4; i++) { //this part Safrul need to do correction 
        	    printf("Item [%d]:%s \tDuration:%d \tPrice:%d\n",i+1, name[i], duration[i], price[i]);
		}
	
	printf("\nChoose Item to Generate report(0 for All):");
	scanf("%d", &genRep);
	
	item=genRep;
	
	if(genRep==1||genRep==2||genRep==3){
		genRep--;
		totalPurc= price[genRep]*sale;
			printf("\n-----REPORT ON ITEM[%d]-----\n",item);
			printf("Total Item Sale for Item[%d] is %d item\n",item, sale);
			printf("Total Purchase for Item[%d] is RM%d\n",item, totalPurc);
	}
	else if(genRep==0){
		for(item=0;item<4;item++){
			totalPurc= price[item]*sale;
			printf("\n-----REPORT ON ITEM[%d]-----\n",item+1);
			printf("Total Item Sale for Item[%d] is %d item\n",item+1, sale);
			printf("Total Purchase for Item[%d] is RM%d\n",item+1, totalPurc);
		}
	}

}
