#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum bool {false,true};

//structure for details
struct details{
      char name[20];
      float price;
      int code;
      int qty;
      char mfg[10];//22-01-2003
      char exp[10];
};

struct recipt{
    char name[40];
    float price;
    int qty;
};

typedef struct details Details;
typedef struct recipt Recipt;
typedef struct store_revenue Store_revenue;

Recipt bill[50]; //to store values in R6

//test values
Details items[50]={{"sfsd",123,1,23,"11-11-1111","11-11-1111"},
                {"sfsd",123,2,23,"11-11-1111","11-11-1111"},
                {"sfsd",123,3,23,"11-11-1111","11-11-1111"},
                {"sfsd",123,4,23,"11-11-1111","11-11-1111"},
                {"sfsd",123,5,23,"11-11-1111","11-11-1111"},
                };

Store_revenue daily_revenue[30];
int no_of_items = 0; //stores no of items in inventory
int no_of_sales = 0; //stores no of sales


//defining Linked list funcions for item storage for R5 and R6
struct node {
   char name[40];
    float price;
    int qty;
    int code;
   struct node *next;
};

//defining head and currrent
struct node *head = NULL;
struct node *current = NULL;

//display the list
void display() {
   printf("\n\n");
   struct node *temp = head;
   printf("Current bill \n\n");
	if (head == NULL)
    {
        printf("Empty bill\n\n");
        return;
    }
   //start from the beginning
   while(temp != NULL) {
      printf("%d %s %f %d\n",temp->code,temp->name,temp->price,temp->qty);
        temp = temp->next;
   }
	//printf("%d %s %d %d\n",temp->code,temp->name,temp->price,temp->qty);
    printf("\n\n");
}

//insert link at the first location
void insertFirst(int code,char name[50],float price,int qty) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   strcpy(link -> name,name);
    link->price = price;
    link->qty=qty;
    link->code=code;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

//delete a link with given key
struct node* delete_item(int code) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->code != code) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

//linked list functions ends

//function to get item index
int get_item_index(int code,int lenght){
    for (int x=0;x<lenght;x++){
        if (code == items[x].code){
            return x;
        }
    }
    return -2;
}

//function protypes for R5 and R6
void gen_recipt();
void print_bill(int lenght,float total_cost);
int finalize_bill();

//R7
//R7  ends

//defining variables for R5 and R6
int item_index = 0;
int lenght = 5;
int no_of_items_in_bill = -1;

//defining variables for login  
char login[4][20]={"Manager","password","Clerk","password1"};
int loginID = -1;
int loop = 1;


//R1 - Inventory input
/*void datainput(){
    int n;
    printf("Enter number of items:");
    scanf("%d",&n);
    fflush(stdin);
    for(int i=no_of_items;i< no_of_items+n;i++){
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
    for(int i=0;i<no_of_items;i++)
        printf("%d %-15s %-d %-5d %-5d%d/%d/%d%d%d%d\n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].mfg.day,item[i].mfg.month,item[i].mfg.year,item[i].exp.day,item[i].exp.month,item[i].exp.year);
    printf("------------------------------------------------------------------\n");
    getchar();
}
*/

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
            //datainput();
            break;
        case 2:
            
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
        printf(" 1:Create Bill\n 2:fun2\n 3:fun3\n 4:fun4\n 5:fun5\n 6:fun6\n 7:exit\n\n");
        printf("Enter option: ");
        scanf("%d",&entry);

        switch (entry){
        case 1:
                gen_recipt();
                break;
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


//R5 and R6
void gen_recipt(){
    int choice=0,code,qty,loop=1,tmp;
    while (loop==1){
        printf("1:Enter item\n2:Delete from bill\n3:Display bill\n4:finalize bill\n5:Exit\n");
        printf("Enter option: ");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            printf("Enter code of item to enter: ");
            scanf("%d",&code);
            item_index = get_item_index(code,lenght);
            if (item_index == -2){printf("Med Code not found try again\n");break;}
            printf("Enter quantity: ");
            scanf("%d",&qty);
            insertFirst(items[item_index].code, items[item_index].name,items[item_index].price,qty);
            display();
            break;
        case 2:
            display();
            printf("\nEnter code of item to delete: ");
            scanf("%d",&code);
            delete_item(code);
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            tmp = finalize_bill();
            if (tmp==-2){
                break;
            }
            print_bill(no_of_items_in_bill,tmp);
            loop=0;
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

int finalize_bill(){
    float total_cost=0;

    if (head== NULL){
        printf("Empty bill");
        return -2;
    }

    struct node *temp = head;
    while (temp->next != NULL){
        no_of_items_in_bill++;
        strcpy(bill[no_of_items_in_bill].name,temp->name);
        bill[no_of_items_in_bill].price=temp->price;
        bill[no_of_items_in_bill].qty=temp->qty;
        total_cost += temp->price*temp->qty;
        temp = temp->next;
    }

    no_of_items_in_bill++;
    strcpy(bill[no_of_items_in_bill].name,temp->name);
    bill[no_of_items_in_bill].price=temp->price;
    bill[no_of_items_in_bill].qty=temp->qty;
    total_cost += temp->price*temp->qty;
    temp = temp->next;    

    return total_cost;
}

void print_bill(int lenght,float total_cost){
    printf("\nYour bill is:\n");
    for (int x=0;x<lenght+1;x++){
        printf("%s , %d, %d\n",bill[x].name,bill[x].price,bill[x].qty);
    }
    printf("Total is: %f\n",total_cost);
}
//R5 and R6 ends