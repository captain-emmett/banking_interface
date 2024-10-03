#include <stdio.h>
#include "record.h"

extern int debugmode;

int addRecord (struct record **head, int accNum, char name[],char address[]) {
    if(debugmode) {
    printf("\n**DEBUG SECRETS**\n");
    printf("addRecord called:\naccNum: %d\nname: %s\naddress:\n%s\n\n", accNum, name, address);
    }
    return 0;
}
void printAllRecords(struct record *head) {
    if(debugmode) {
    printf("\n**DEBUG SECRETS**\n");
    printf("printAllRecords called.\n\n");
    }
}
int findRecord (struct record *head, int accNum) {
    if(debugmode) {
    printf("\n**DEBUG SECRETS**\n");
    printf("find records called with accnum: %d\n\n", accNum);
    }
    return 0;
}
int deleteRecord(struct record **head, int accNum) {
    if(debugmode) {
    printf("\n**DEBUG SECRETS**\n");
    printf("delete records called with accnum: %d\n\n", accNum);
    }
    return 0;
}
