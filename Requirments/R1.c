#include<stdio.h>

void datainput(){

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
}
