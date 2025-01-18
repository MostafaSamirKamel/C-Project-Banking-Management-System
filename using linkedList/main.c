#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"

int main() {
    int choice, id, to_id;
    double amount;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Create a new customer\n");
        printf("2. Edit a customer\n");
        printf("3. Print customer details\n");
        printf("4. Transfer money\n");
        printf("5. Delete a customer\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                creat_amel();
                break;
            case 2:
                printf("Enter customer ID to edit: ");
                scanf("%d", &id);
                edit_amel(id);
                break;
            case 3:
                printf("Enter customer ID to print details: ");
                scanf("%d", &id);
                print_data(id);
                break;
            case 4:
                printf("Enter sender ID: ");
                scanf("%d", &id);
                printf("Enter recipient ID: ");
                scanf("%d", &to_id);
                printf("Enter amount to transfer: ");
                scanf("%lf", &amount);
                transfer_money(id, to_id, amount);
                break;
            case 5:
                printf("Enter customer ID to delete: ");
                scanf("%d", &id);
                delete_amel(id);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}