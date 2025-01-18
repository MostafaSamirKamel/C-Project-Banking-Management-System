#ifndef BANK_H
#define BANK_H

typedef struct customer {
    char name[50];
    double cash;
    char account_type[10];
    int id;
} amel;

// Function prototypes
void creat_amel(void);
void edit_amel(int id); 
void print_data(int id);
void transfer_money(int from_id, int to_id, double money);
void delete_amel(int id);

#endif
