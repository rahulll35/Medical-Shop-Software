#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//for creating inventory
struct details{
      char name[20];
      float price;
      int code;
      int qty;
      char manufacturer[50];
      char mfg[10];//22-01-2003
      char exp[10];
};

//for generating bill
struct recipt{
    char name[40];
    float price;
    int qty;
};

//for storing daily revenue
struct revenue{
    int code;
    int qty;
    char manufacturer[50];
};

//for storing monthly revenue(name needs work)
struct revenue2{
    float daily_revenue;
};

//defining types for structures
typedef struct details Details;
typedef struct recipt Recipt;
typedef struct revenue Revenue; 

//initialising structures
Recipt bill[50];


//test values
Details items[50]={{"sfsd",123,1,23,"abc","11-11-1111","11-11-1111"},
                {"sfsd",123,2,23,"def","11-11-1111","11-11-1111"},
                {"sfsd",123,3,23,"ghi","11-11-1111","11-11-1111"},
                {"sfsd",123,4,23,"jkl","11-11-1111","11-11-1111"},
                {"sfsd",123,5,23,"lmn","11-11-1111","11-11-1111"},
                };

Revenue daily_transactions[100]={{1,22,"abc"},{2,33,"def"},{3,33,"ghi"}};

//defining Linked list funcions for item storage
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


//defining variables for R5 and R6
int item_index = 0;
int no_of_items_in_inventory = 5;
int no_of_items_in_bill = -1;

//defining variables for R7
no_of_daily_transactions=0; 

//function protypes for R5 and R6
void gen_recipt();
void print_bill(int lenght,float total_cost);
int finalize_bill();

//function protypes for R7 R7.1 R7.2
float gen_daily_revenue();
void gen_month_revenue();
void gen_graph();

void main(){
    
}



//R5 and R6
void gen_recipt(){
    int choice=0,code,qty,loop=1,tmp;
    while (loop==1){
        printf("1:Enter item\n2:Delete from bill\n3:Display bill\n4:finalize bill\n5:Exit\n:");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            printf("Enter code of item to enter: ");
            scanf("%d",&code);
            item_index = get_item_index(code,no_of_items_in_inventory);
            if (item_index == -2){printf("Med Code not found try again\n");break;}
            printf("Enter quantity: ");
            scanf("%d",&qty);
            insertFirst(items[item_index].code, items[item_index].name,items[item_index].price,qty);
            display();
            break;
        case 2:
            display();
            printf("Enter code of item to delete");
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
        //keeping track of stuff
        no_of_items_in_bill++;
        no_of_daily_transactions ++;

        //adding to bill
        strcpy(bill[no_of_items_in_bill].name,temp->name);
        bill[no_of_items_in_bill].price=temp->price;
        bill[no_of_items_in_bill].qty=temp->qty;

        //calculating total cost
        total_cost += (temp->price*temp->qty);

        //adding to daily transaction
        daily_transactions[no_of_daily_transactions].qty = temp->qty;
        daily_transactions[no_of_daily_transactions].code = temp->code;
        daily_transactions[no_of_daily_transactions].manufacturer = items[get_item_index(temp->code, no_of_items_in_inventory)].manufacturer;
        
        //moving to next link
        temp = temp->next;
    }

    //keeping track of stuff
        no_of_items_in_bill ++;
        no_of_daily_transactions ++;

        //adding to bill
        strcpy(bill[no_of_items_in_bill].name,temp->name);
        bill[no_of_items_in_bill].price=temp->price;
        bill[no_of_items_in_bill].qty=temp->qty;

        //calculating total cost
        total_cost += (temp->price*temp->qty);

        //adding to daily transaction
        daily_transactions[no_of_daily_transactions].qty = temp->qty;
        daily_transactions[no_of_daily_transactions].code = temp->code;
        daily_transactions[no_of_daily_transactions].manufacturer = items[get_item_index(temp->code, no_of_items_in_inventory)].manufacturer;
        
        //moving to next link
        temp = temp->next;

    return total_cost;
}

void print_bill(int lenght,float total_cost){
    printf("Your bill is:\n");
    for (int x=0;x<lenght+1;x++){
        printf("%s , %d, %d\n",bill[x].name,bill[x].price,bill[x].qty);
    }
    printf("Total is: %f\n",total_cost);
}
//R5 and R6 ends

//R7 begins

float gen_daily_revenue(){
    float total_revenue=0;
    int tmp;

    for(int x=0;x<no_of_daily_transactions;x++){
        tmp = get_item_index(daily_transactions[x].code,no_of_items_in_inventory);
        total_revenue += (items[tmp].price * daily_transactions[x].qty);
    }


    return total_revenue;
}


//R7 ends