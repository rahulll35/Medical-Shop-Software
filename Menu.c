#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum bool {false,true};

char login[4][20]={"Manager","password","Clerk","password1"};
int loginID = 1;
int loop = 1;

void mainapp(){
    int entry; 
    char quit;
    while (true)
    {
        printf("\nHello what would you like to do ? \n");
        printf(" 1:fun1\n 2:fun2\n 3:fun3\n 4:fun4\n 5:fun5\n 6:fun6\n 7:exit\n");
        printf("Enter option: ");
        scanf("%d",&entry);

        switch (entry){
        case 7:
            printf("\nAre you sure you want to exit the Program");
            scanf(" %c",&quit); //leave this space for scanf

            printf("%c \n",quit);

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
    int entry; 
    while (true)
    {
        printf("Hello what would you like to do ? \n");
        printf("1:fun1\n 2:fun2\n 3:fun3\n 4:fun4\n 5:fun5\n 6:fun6\n 7:exit\n");
        printf("Enter option: ");
        scanf("%c",&entry);


        switch (entry){
        case 7:
            printf("Are you sure you want to exit the Program");
            char quit;
            scanf("%c",&quit);
            if (quit == 'y'){
                exit(0);
            }
            else if(quit == 'n'){
                continue;
            }
            else{
                printf("invalid input try again");
            }
            break;
        
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

        int user_check = strcmp(login[0],user);
        int pass_check = strcmp(login[1],password);

        if(strcmp(login[0],user) == 0 && strcmp(login[1],password) == 0) {
            printf("Welcome manager \n");
            loginID = 1;
        }

        if(strcmp(login[2],user) == 0 && strcmp(login[3],password) == 0) {
            printf("Welcome clerk \n");
            loginID = 0;
        }

        switch(loginID){
            case 1:
                    printf("executing mainapp \n");
                    mainapp();
                    
            case 0:
                    continue;
        }

    }
}
