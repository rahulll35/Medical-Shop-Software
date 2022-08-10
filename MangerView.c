#include <string.h>
#include <stdlib.h>
#include "R1.c"

//enum manbool {false,true};


void MangerMenu(){
    int entry; 
    char quit;
    while (1)
    {
        printf("\nHello what would you like to do ? \n");
        printf(" 1:Input Data\n 2:fun2\n 3:fun3\n 4:fun4\n 5:fun5\n 6:fun6\n 7:exit\n");
        printf("Enter option: ");
        scanf("%d",&entry);

        switch (entry){
        case 1:
            datainput();
        
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