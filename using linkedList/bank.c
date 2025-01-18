#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

amel *head = NULL; // Head of the linked list

void creat_amel(void) {
    amel *new_amel = (amel *)malloc(sizeof(amel));
    if (!new_amel) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]%*c", new_amel->name);

    printf("Enter Cash: ");
    scanf("%lf", &(new_amel->cash));

    printf("Enter Account Type <debit or credit>: ");
    scanf(" %[^\n]%*c", new_amel->account_type);

    printf("Enter ID: ");
    scanf("%i", &(new_amel->id));

    new_amel->next = head;
    head = new_amel;

    printf("Customer created successfully!\n\n");
}

void edit_amel(int id) {
    amel *current = head;
    while (current) {
        if (current->id == id) {
            printf("Editing details for customer with ID %i:\n", id);

            printf("Enter New Name: ");
            scanf(" %[^\n]%*c", current->name);

            printf("Enter New Cash: ");
            scanf("%lf", &(current->cash));

            printf("Enter New Account Type <debit or credit>: ");
            scanf(" %[^\n]%*c", current->account_type);

            printf("Enter New ID: ");
            scanf("%i", &(current->id));

            printf("Customer details updated successfully.\n\n");
            return;
        }
        current = current->next;
    }
    printf("Customer with ID %i not found.\n", id);
}

void print_data(int id) {
    amel *current = head;
    while (current) {
        if (current->id == id) {
            printf("Name: %s\n", current->name);
            printf("Cash: %.2lf\n", current->cash);
            printf("Account Type: %s\n", current->account_type);
            printf("ID: %i\n\n", current->id);
            return;
        }
        current = current->next;
    }
    printf("Customer with ID %i not found.\n", id);
}

void transfer_money(int from_id, int to_id, double money) {
    amel *from = NULL, *to = NULL;
    amel *current = head;

    while (current) {
        if (current->id == from_id) {
            from = current;
        }
        if (current->id == to_id) {
            to = current;
        }
        current = current->next;
    }

    if (!from) {
        printf("Sender with ID %i not found.\n", from_id);
        return;
    }

    if (!to) {
        printf("Recipient with ID %i not found.\n", to_id);
        return;
    }

    if (money > from->cash) {
        printf("Insufficient funds in sender's account.\n");
        return;
    }

    from->cash -= money;
    to->cash += money;

    printf("Transfer of %.2lf from ID %i to ID %i completed successfully.\n\n", money, from_id, to_id);
}

void delete_amel(int id) {
    amel *current = head;
    amel *previous = NULL;

    while (current) {
        if (current->id == id) {
            if (previous) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            printf("Customer with ID %i deleted successfully.\n\n", id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Customer with ID %i not found.\n", id);
}