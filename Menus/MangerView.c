#include <string.h>
#include <stdlib.h>
#include "\Medical-Shop-Software\Requirments\R1.c"

//enum bool {false,true};

//extern item;

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