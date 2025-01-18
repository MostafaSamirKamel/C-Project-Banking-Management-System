#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

extern int flag;
extern amel depot[10];

void creat_amel(void) {
    amel new_amel;

    printf("Enter Name customer Number %i: ", flag + 1);
    scanf(" %[^\n]%*c", new_amel.name); 

    printf("Enter Cash customer Number %i: ", flag + 1);
    scanf("%lf", &(new_amel.cash)); 

    printf("Enter Account Type customer Number %i <debit or credit>: ", flag + 1);
    scanf(" %[^\n]%*c", new_amel.account_type); 

    printf("Enter ID customer Number %i: ", flag + 1);
    scanf("%i", &(new_amel.id)); 

    printf("\n\n");

    depot[flag] = new_amel;
    flag++;
}

void edit_amel(int id) {
    int i, found = 0;

    for (i = 0; i < flag; i++) {  
        if (id == depot[i].id) {
            found = 1; 

            printf("Editing details for customer with ID %i:\n", id);

            printf("Enter New Name: ");
            scanf(" %[^\n]%*c", depot[i].name);

            printf("Enter New Cash: ");
            scanf("%lf", &(depot[i].cash));

            printf("Enter New Account Type <debit or credit>: ");
            scanf(" %[^\n]%*c", depot[i].account_type);

            printf("Enter New ID: ");
            scanf("%i", &(depot[i].id));

            printf("Customer details updated successfully.\n\n");
            break; 
        }
    }

    if (!found) {
        printf("Customer with ID %i not found.\n", id);
    }
}

void print_data(int id){
    int i, found = 0;

    for (i = 0; i < flag; i++) {  
        if (id == depot[i].id) {
            found = 1; 

            printf("Name Customer ID %i is : %s\n", id, depot[i].name);  
            printf("Cash Customer ID %i is : %.2lf\n", id, depot[i].cash);  
            printf("Account Type Customer ID %i is : %s\n", id, depot[i].account_type);  
            printf("Customer ID %i is : %i\n", id, depot[i].id);  

            break;
        }
    }

    if (!found) {
        printf("Customer with ID %i not found.\n", id);
    }
}

void transfer_money(int from_id, int to_id, double money){
    int i ;
    int from_index = -1;
    int to_index = -1;

    for (i = 0; i < flag; i++) {  
        if (from_id == depot[i].id) {
            from_index = i;
        }
        if (to_id == depot[i].id) {
            to_index = i;
        }
    }

    if (from_index == -1) {
        printf("Sender with ID %i not found.\n", from_id);
        return;
    }

    if (to_index == -1) {
        printf("Recipient with ID %i not found.\n", to_id);
        return;
    }

    if (money > depot[from_index].cash) {
        printf("Cash not Enough in Sender account with ID %i.\n", from_id);
        return;
    }

    depot[to_index].cash += money;
    depot[from_index].cash -= money;

    printf("Transfer of %.2lf from ID %i to ID %i completed successfully.\n", money, from_id, to_id);
    printf("Transfer of %.2lf from ID %s to ID %s completed successfully.\n", money, depot[from_index].name, depot[to_index].name);
}

void delete_amel(int id){
    int i, index = -1;

    for (i = 0; i < flag; i++) {  
        if (id == depot[i].id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Customer with ID %i not found.\n", id);
        return;
    }

    for (i = index; i < flag - 1; i++) {  
        depot[i] = depot[i + 1];
    }

    flag--;

    printf("Customer with ID %i deleted successfully.\n", id);
}
