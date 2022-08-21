
 #include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<ctype.h>


 struct Medicine{
   int id,price,quantity;
   char medicneName[100],Company[100],Mfg_Date[11],Exp_Date[11],info[5000];
  }m[100];

 void DataInput(int number);
 void ThresholdValue(int number);
 void PurchaseMedicine(int number);
 
 main()
 {
   int i,j,choice,number=0,c;
   for(i=0;i<100;i++)
   {
    m[i].id=0;
   m[i].price=0;
   m[i].quantity=0;
   strcpy(m[i].Mfg_Date,"");
  strcpy(m[i].Exp_Date,"");
   strcpy(m[i].medicneName,"");
   strcpy(m[i].Company,"");
   strcpy(m[i].info,"");
   }
   m[0].id=1;
   m[0].price=120;
   m[0].quantity=30;
   strcpy(m[0].Mfg_Date,"23-04-2016");
  strcpy(m[0].Exp_Date,"24-04-2020");
   strcpy(m[0].medicneName,"Paracetmol");
   strcpy(m[0].Company,"ABCD");
   strcpy(m[0].info,"Good Medicine for Fever");
   do{
   printf("Enter\n1 - Purchase Medicine\n2 - Enter Information about a Medicine\n3 - Stock of Medicine in Store\n4 - Medicine Information\n5 - Add Medicine\n6 - Delete a Medicine\n7 - Change Quantity of Medicine\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
    {
     DataInput(number+1);
     break;
    }
     case 2:
    {
     ThresholdValue(number+1);
     break;
    }
      case 3:
      {
       PurchaseMedicine(number+1);
     break;
      }
    
   }
     printf("To Continue with other Options Enter 1 Else any other number\n");
     scanf("%d",&c);
   }while(c==1);
   
 }
//R1: DATA INPUT
  void DataInput(int number)
 {
  int i,flag=0,c;
  char name[100],info[100];
  printf("Enter Name of the medicine you want to Review or include Info\n");
  fflush(stdin);
  gets(name);
  for(i=0;i<number;i++)
  {
   if(strcmp(m[i].medicneName,name)==0)
   {
    flag=1;
    printf("These are the details of Medicine\n");
    printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
    if(strcmp(m[i].info,"")!=0)
    {
     printf("Review Already Available!\nIf you want to Add a Review Enter 1 else Any other number\n");
     fflush(stdin);
     scanf("%d",&c);
    }
    else
    {
     printf("Enter review(less than 100 Characters)\n");
     fflush(stdin);
     gets(m[i].info);
    }
    if(c==1)
    {
     printf("Enter review(less than 100 Characters)\n");
     fflush(stdin);
     gets(info);
     strcat(m[i].info,"; ");
     strcat(m[i].info,info);
    }
    
   }
  }
  if(flag==0)
  {
   printf("Entered Name Not Found\n");
  }
 }
//R2: THRESHOLD VALUE
 void ThresholdValue(int number){
  int i;
  if(number!=0)
  {
      printf("All Available Items are\n");
   for(i=0;i<number;i++)
   {
    if(m[i].id!=0){
    printf("Id=%d\nName=%s\t\tPrice=%d\tAvailable Quantity=%d\nCompany=%s\t\tMfg Date=%s\tExp Date=%s\n",m[i].id,m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
    if(strcmp(m[i].info,"")!=0)
    {
     printf("Review or Info=%s\n",m[i].info);
    }
    else
    {
     printf("Review or Info=Not Available\n");
    }
      }
   }  
  }
  else{
   printf("No Items or Medicines Available\n");
  } 
 }
//R3: PURCHASE MEDICINE
 void PurchaseMedicine(int number)
 {
  int id,check,i,quantity,flag=0;
  char name[100];
  printf("Enter 1 if you know ID else any other number to enter Name of Medicine\n");
  fflush(stdin);
  scanf("%d",&check);
  if(check==1)
  {
   printf("Enter Id to purchase Medicine\n");
   fflush(stdin);
   scanf("%d",&id);
   for(i=0;i<number;i++)
   {
    if(m[i].id==id)
    {
     flag=1;
     int c;
     printf("These are the details of Medicine\n");
     printf("Name%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
      if(strcmp(m[i].info,"")==0)
      {
       printf("Medicine Review/Info=Not Available\n");
      }
      else
      {
       printf("Medicine Review/Info=%s\n",m[i].info);
      }
     printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number\n",m[i].medicneName);
     fflush(stdin);
     scanf("%d",&c);
     if(c==1)
     {
      printf("Enter Quantity to Purchase\n");
      scanf("%d",&quantity);
      if(m[i].quantity>quantity)
      {
       printf("Total Price to be paid=%d\n",quantity*m[i].price);
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
    printf("Entered Id Not Found\n");
   }
  }
  else
  {
   printf("Enter Name to search and Purchase\n");
   fflush(stdin);
   gets(name);
   for(i=0;i<number;i++)
   {
    if(strcmp(m[i].medicneName,name)==0)
    {
     flag=1;
     int c;
     printf("These are the details of Medicine\n");
     printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
      if(strcmp(m[i].info,"")==0)
      {
       printf("Medicine Review/Info=Not Available\n");
      }
      else
      {
       printf("Medicine Review/Info=%s\n",m[i].info);
      }
     printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number\n",m[i].medicneName);
     fflush(stdin);
     scanf("%d",&c);
     if(c==1)
     {
      printf("Enter Quantity to Purchase\n");
      scanf("%d",&quantity);
      if(m[i].quantity>quantity)
      {
       printf("Total Price to be paid=%d\n",quantity*m[i].price);
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
 }
