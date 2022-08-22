#include<stdio.h>

void main(){

//R1: Storing item details
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

 //ordering medicines
 void PurchaseMedicine(int number)
 {
  int code,check,i,quantity,flag=0;
  char name[100];
  printf("Enter 1 if you know ID else any other number to enter Name of Medicine\n");
  fflush(stdin);
  scanf("%d",&check);
  if(check==1)
  {
   printf("Enter Medicine code to purchase Medicine\n");
   fflush(stdin);
   scanf("%d",&code);
   for(i=0;i<number;i++)
   {
    if(item[i].code==code)
    {
     flag=1;
     int c;
     printf("These are the details of Medicine\n");
     printf("S.N.| NAME | CODE | QUANTITY | PRICE | MFG.DATE | EXP.DATE |\n");
     printf("%d %-15s %-d %-5d %-5d%d/%d/%d%d%d%d\n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].mfg.day,item[i].mfg.month,item[i].mfg.year,item[i].exp.day,item[i].exp.month,item[i].exp.year);

       printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number\n",item[i].name);
     fflush(stdin);
     scanf("%d",&c);
     if(c==1)
     {
      printf("Enter Quantity to Purchase\n");
      scanf("%d",&quantity);
      if(item[i].qty>quantity)
      {
       printf("Total Price to be paid=%d\n",quantity*item[i].price);
      }
      else{
       printf("Please Enter quantity below Available Quantity\n");
      }
     }
     break;
     }
     else{
       printf("Invalid code, try again \n");
      }

    }
   }
   if(flag==0)
   {
    printf("Entered Id Not Found\n");
   }
/*
  else
  {
   printf("Enter Name to search and Purchase\n");
   fflush(stdin);
   gets(name);
   for(i=0;i<number;i++)
   {
    if(item[i].name = name)
    {
     flag=1;
     int c;
   printf("These are the details of Medicine\n");
     printf("S.N.| NAME | CODE | QUANTITY | PRICE | MFG.DATE | EXP.DATE |\n");
     printf("%d %-15s %-d %-5d %-5d%d/%d/%d%d%d%d\n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].mfg.day,item[i].mfg.month,item[i].mfg.year,item[i].exp.day,item[i].exp.month,item[i].exp.year);
      printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number\n",item[i].name);
     fflush(stdin);
     scanf("%d",&c);
     if(c==1)
     {
      printf("Enter Quantity to Purchase\n");
      scanf("%d",&quantity);
      if(item[i].qty>quantity)
      {
       printf("Total Price to be paid=%d\n",quantity*item[i].price);
      }
      else{
       printf("Please Enter quantity below Available Quantity\n");
      }
     }
     break;
    }
   }
   if(flag==0)
   {
    printf("Entered Name Not Found\n");
   }
  }
  */
 }
}
