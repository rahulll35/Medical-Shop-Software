#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum bool {false,true};

struct recipt{
    char name[40];
    int price;
    int qty;
};

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

typedef struct details Details;
typedef struct recipt Recipt;
Details item[50];
Recipt bill[50];
int no_of_items = 0;
//linked list 
struct Node {
   char name[40];
    int price;
    int qty;
    int code;
   struct node *next;
}; 

typedef struct Node node;

node *head = NULL;
node* insertfirst(int code,char name[50],int price,int qty){
    node* temp= (node*) malloc(sizeof(node));
    
    strcpy(temp -> name,name);
    temp->price = price;
    temp->qty=qty;
    temp->code;

    temp ->next=head;
    temp = head;
}

void insertlast(int code,char name[50],int price,int qty){
    node *temp = (node *) malloc(sizeof(node));

    strcpy(temp -> name,name);
    temp->price = price;
    temp->qty=qty;
    temp->code;

    if (head == NULL)
    {
       head = temp;
       temp  = NULL;
       return; 
    }

    node *cur = head;

    while (cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    temp = NULL;
}

void bill_delete(int code){

    if (head == NULL)
    {
        printf("Empty list");
        return;
    }
    
    node* pre = NULL;
    node* cur = head;
    while (cur->code != code){   
        pre = cur;
        cur = cur->next;
    }

    if (pre == NULL){
        printf("Element not found");
        return;
    }


    node* temp = cur;
    pre ->next = cur -> next;
    temp ->next = NULL;
    free(temp);
}

void display(){
    if (head== NULL)
    {
        printf("Empty");
        return;
    }

    node* temp = head;
    while (temp->next != NULL)
    {
        printf("%d %s %d %d\n",temp->code,temp->name,temp->price,temp->qty);
        temp = temp->next;
    }

    printf("%d %s %d %d\n",temp->code,temp->name,temp->price,temp->qty);
}
//end linkd list

int get_item_index(int code,int lenght){
    for (int x=0;x<lenght;x++){
        if (code == item[x].code){
            return x;
        }
    }
}

void gen_recipt(){
    int choice=0,code,loop=1;
    while (loop==1){
        printf("1:Generate bill\n2:Delete from bill\n3:Display bill\n4:finalize bill\n5:Exit\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enter_details();
            display();
            break;
        case 2:
            display();
            printf("Enter code of item to delete");
            scanf("%d",&code);
            bill_delete(code);
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            finalize_bill();
            break;
        case 5:
            loop=0;
            break;
        default:
            printf("\nInvalid choice try again\n");
            break;
        }
    }
}

void enter_details(){
    int code,flag=0,index=0;

    printf("Enter med code");
    scanf("%d",&code);

    if (flag == 0){
        index=get_item_index(code,no_of_items);
        insertfirst(item[index].code,item[index].name,item[index].price,item[index].qty);
    }else{
        index = get_item_index(code,no_of_items);
        insertlast(item[index].code,item[index].name,item[index].price,item[index].qty);
    }
}

void finalize_bill(){


char login[4][20]={"Manager","password","Clerk","password1"};
int loginID = -1;
int loop = 1;


//R1 - Inventory input
void datainput(){
    int n,i;
    printf("Enter number of items:");
    scanf("%d",&n);
    fflush(stdin);
    for(i=no_of_items;i< no_of_items+n;i++){
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
    no_of_items += n;
    printf(" ***** INVENTORY *****\n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.| NAME | CODE | QUANTITY | PRICE | MFG.DATE | EXP.DATE |\n");
    printf("------------------------------------------------------------------\n");
    for(i=0;i<no_of_items;i++)
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
