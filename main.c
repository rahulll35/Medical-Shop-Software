#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum bool {false,true};

struct date{
      int day;
      int month;
      int year;
   };
struct details{
      char name[20];
      int price;
      int code;
      int qty;
      struct date mfg;
      struct date exp;
   };

struct details item[50];


char login[4][20]={"Manager","password","Clerk","password1"};
int loginID = -1;
int loop = 1;


//R1 - Inventory input
void datainput(){

    int n,i;
    printf("Enter number of items:");
    scanf("%d",&n);
    fflush(stdin);
    for(i=0;i<n;i++){
        fflush(stdin);
        printf("Item name:");
        scanf("%s",item[i].name);
        fflush(stdin);
        printf("Item code:");
        scanf("%d",&item[i].code);
        fflush(stdin);
        printf("Quantity:");
        scanf("%d",&item[i].qty);
        fflush(stdin);
        printf("price:");
        scanf("%d",&item[i].price);
        fflush(stdin);
        printf("Manufacturing date(dd-mm-yyyy):");
        scanf("%d-%d-%d",&item[i].mfg.day,&item[i].mfg.month,&item[i].mfg.year);
        fflush(stdin);
        printf("Expiry date(dd-mm-yyyy):");
        scanf("%d-%d-%d",&item[i].exp.day,&item[i].exp.month,&item[i].exp.year);
    }
    printf(" ***** INVENTORY *****\n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.| NAME | CODE | QUANTITY | PRICE | MFG.DATE | EXP.DATE |\n");
    printf("------------------------------------------------------------------\n");
    for(i=0;i<n;i++)
        printf("%d %-15s %-d %-5d %-5d%d/%d/%d%d%d%d\n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].mfg.day,item[i].mfg.month,item[i].mfg.year,item[i].exp.day,item[i].exp.month,item[i].exp.year);
    printf("------------------------------------------------------------------\n");
    getchar();
}


//Manager menu
void MangerMenu(){
    int entry;
    char quit;
    int logoutflag =1;
    while (1)
    {
        printf("\nHello what would you like to do ? \n");
        printf(" 1:Input Data\n 2:fun2\n 3:fun3\n 4:fun4\n 5:fun5\n 6:fun6\n 7:exit\n");
        printf("Enter option: ");
        scanf("%d",&entry);

        switch (entry){
        case 1:
            datainput();
            break;
        case 2:
            printf("%d %-15s %-d %-5d %-5d%d/%d/%d%d%d%d\n",1,item[1].name,item[1].code,item[1].qty,item[1].price,item[1].mfg.day,item[1].mfg.month,item[1].mfg.year,item[1].exp.day,item[1].exp.month,item[1].exp.year);
            break;
        case 6:
            printf("Logout ? y or n");
            scanf(" %c",&quit); //leave this space for scanf

            if (quit == 'y'){
                logoutflag =0;
                break;
            }
            else if(quit == 'n'){
                break;
            }
            else{
                printf("\ninvalid input try again \n");
                break;
            }

        case 7:
            printf("\nAre you sure you want to exit the Program(y or n): ");
            scanf(" %c",&quit); //leave this space for scanf

            if (quit == 'y'){
                exit(0);
            }
            else if(quit == 'n'){
                break;
            }
            else{
                printf("\ninvalid input try again \n");
                break;
            }

        default:
            printf("Invalid choice try again");
            break;
        }
    }

}

//Clerk menu
void ClerkMenu(){
    int entry; 
    char quit;
    while (1)
    {
        printf("\nHello what would you like to do ? \n");
        printf(" 1:fun1\n 2:fun2\n 3:fun3\n 4:fun4\n 5:fun5\n 6:fun6\n 7:exit\n");
        printf("Enter option: ");
        scanf("%d",&entry);

        switch (entry){
        case 7:
            printf("\nAre you sure you want to exit the Program(y or n): ");
            scanf(" %c",&quit); //leave this space for scanf

            if (quit == 'y'){
                exit(0);
            }
            else if(quit == 'n'){
                continue;
            }
            else{
                printf("\ninvalid input try again \n");
            }
        
        default:
            printf("Invalid choice try again");
            continue;        
        }
    } 
}

void main(){
    while (loop == 1){

        printf("Welcome please login \n");
        char user[20];
        char password[20];

        printf("Enter username: ");
        scanf("%s", user);

        printf("Enter password: ");
        scanf("%s", password);

        //printf("%s \n",user);
        //printf("%s \n",password);

        //printf("%s \n",login[0]);
        //printf("%s \n",login[1]);

        if(strcmp(login[0],user) == 0 && strcmp(login[1],password) == 0) {
            printf("Welcome Manager \n");
            loginID = 1;
        }

        if(strcmp(login[2],user) == 0 && strcmp(login[3],password) == 0) {
            printf("Welcome Clerk \n");
            loginID = 0;
        }

        switch(loginID){
            case 1:
                    printf("executing mainapp \n");
                    MangerMenu();
                    break;
            case 0:
                    ClerkMenu();
                    break;
            case -1:
                printf("Wrong username/password combo try again \n");
                break;
                
        }

    }
}
