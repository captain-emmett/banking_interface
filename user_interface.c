/*****************************************************************
//
//  NAME:        Emmett Saldivar
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 25,2024
//
//  FILE:        homework3b.c
//
//  DESCRIPTION:
//   create a ui to interact with a bank database
//
//
****************************************************************/
#include <stdio.h>
#include <string.h>
#include "record.h"
#include "database.h"

int debugmode = 0;

/*****************************************************************
//
//  Function name: getaddress()
//
//  DESCRIPTION:   gets input from the user
//
//  Parameters:    address array, array size
//
//  Return values:  void
//
****************************************************************/
void getaddress (char address[], int size) {
    char newline[200]= "";
    int end = 0;
    int i = 1;
    printf("\nPlease enter the address. You may enter as many lines as you like.\n"
    "When you are finished entering the address input 'q' on a blank line to submit.\n");

    while(!end) {
        printf("Address line %d: ", i);
        fgets(newline, 200, stdin);
        if(strlen(newline) == 2 &&  newline[0] == 'q') {
            end = 1;
            printf("Address submitted.\n");
        } else {
            
            if (strlen(address) + strlen(newline) + 1 < size) {
                strcat(address, newline);
            } else {
                printf("Address too long. Please limit your input.\n");
            }
            i++;
        }
        
    }
}

int main(int argc, char* argv[]) {
    struct record * start = NULL;
    char input[20] = "empty";
    char trash[80] = "trash";
    char name[45] = "noName";
    char address[200] = "";
    int numinput = 0;
    int is_valid = 0;
    int end = 0;

    if (argc > 2 || (argc == 2 && strcmp(argv[1], "debug") != 0)) {
        printf("Invalid command line argument. Please run the program without arguments or use 'debug'.\n");
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "debug") == 0) {
        debugmode = 1;
        printf("\n************************************************\n");
        printf("SUPA SECRET DEBUG MODE ON\n");
    }




    /*intro*/
    printf("*******************BankMaster*******************\n");
    printf(
    "\nHello!\n"
    "\nThis is BankMaster, the all inclusive banking software.\n"
    "BankMaster allows you to add and manage the accounts registerd at this bank.\n"
    "To get started please type one of the following commands:\n"
    "\nadd: add an account to the bank database\n"
    "printall: print all of the accounts in the bank database\n"
    "find: find an account given the account number\n");
    
    printf(
    "delete: delete an account record given the account number\n"
    "quit: exit BankMaster\n"
    "\nPartial inputs are ok! e.g. 'a' or 'ad' for add\n"
    "\n************************************************\n");


    /*get user input*/
    while (!end) {
        printf("\nPlease enter command: ");
        fgets(input, 20, stdin);

        /*check if input is too long*/
        if (strlen(input) == 19 && input[18] != '\n') {
            fgets(trash, 80, stdin);
            (printf("Invalid input please try again.\n"));
        } else {
           /*remove \n for comparison*/ 
           input[strcspn(input, "\n")] = 0;

           if (strncmp(input, "add", strlen(input)) == 0) {
            /*passes account number, name and address to add function*/
            printf("Please assign an account number: ");
                is_valid = 0;
                while (!is_valid) {
                    if (scanf("%d", &numinput) != 1 || numinput < 0) {
                        fgets(trash, 80, stdin);
                        printf("\nInvalid input. Please enter a positive integer: ");
                    } else {
                    is_valid = 1;
                    fgets(trash, 80, stdin);
                    }
                }

            printf("Please assign a name: ");
            is_valid = 0;
                while (!is_valid) {
                    fgets(name, 45, stdin);
                    if (strlen(name) == 44 && name[43] != '\n') {
                        fgets(trash, 80, stdin);
                        printf("\nInput too long. Please try again:");
                    } else {
                    is_valid = 1;
                    }
                } 

            getaddress(address, 200);

            addRecord(&start, numinput, name, address);
            printf("\n************************************************\n");



            } else if(strncmp(input, "printall", strlen(input)) == 0) {
                printAllRecords(start);
                printf("\n************************************************\n");

            } else if(strncmp(input, "find", strlen(input)) == 0) {
                /*pass to find function*/
                printf("Please enter the number of the account you would like to find: ");
                is_valid = 0;
                while (!is_valid) {
                    if (scanf("%d", &numinput) != 1 || numinput < 0) {
                        fgets(trash, 80, stdin);
                        printf("\nInvalid input. Please enter a positive integer: ");
                    } else {
                    is_valid = 1;
                    fgets(trash, 80, stdin);
                    }
                }
                findRecord(start, numinput);
                printf("\n************************************************\n");

            } else if(strncmp(input, "delete", strlen(input)) == 0) {
                /*pass to delete function*/
                printf("Please enter the number of the account you would like to delete: ");
                is_valid = 0;
                while (!is_valid) {
                    if (scanf("%d", &numinput) != 1 || numinput < 0) {
                        fgets(trash, 80, stdin);
                        printf("\nInvalid input. Please enter a positive integer: ");
                    } else {
                    is_valid = 1;
                    fgets(trash, 80, stdin);
                    }
                }
                deleteRecord(&start, numinput);
                printf("\n************************************************\n");


            } else if(strncmp(input, "quit", strlen(input)) == 0) {
                printf("Ending program.\n");
                printf("\n************************************************\n");
                end = 1;

            } else {
                printf("Command not found, please try again.\n");
            }
            
        }
    }


    printf("\nThanks for using BankMaster, goodbye!\n");
    printf("\n************************************************\n");
    return 0;

}