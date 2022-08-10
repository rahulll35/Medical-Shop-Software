#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MangerView.c"
#include "ClerkView.c"

enum bool {false,true};


char login[4][20]={"Manager","password","Clerk","password1"};
int loginID = -1;
int loop = 1;

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
                    
            case 0:
                    ClerkMenu();
            case -1:
                printf("Wrong username/password combo try again \n");
                
        }

    }
}
