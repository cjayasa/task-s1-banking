#include <stdio.h>
#include <stdlib.h>

typedef struct Person Person;
struct Person
{
    char name[30];
    int age, bank_balance, overdraft;
};

// start class methods

Person * createPerson(Person *p, char * name, int age, int bank_balance, int overdraft) {
    // p.name = *name;
    p->age = age;
    p->bank_balance = bank_balance;
    p->overdraft = overdraft;

    return p;
}

char * getName(Person * p) {
    return p->name;
}

int makeDeposit(Person * p, int amount) {
    p->bank_balance += amount;
    return 0;
}

int makeWithdrawal(Person * p, int amount) {
    int provitional_balance;
    provitional_balance = p->bank_balance - amount;

    if (provitional_balance > -(p->overdraft)) {
        p->bank_balance = provitional_balance;
        return 1;
    }
    return 0;
}

int getBalance(Person * p) {
    return p->bank_balance;
}

// end of class methods


int addCustomer(Person * p) {
    int age, overdraft;
	char name[30];

    printf("Customer name: ");
    scanf("%s", &name);
    printf("Customer age: ");
    scanf("%d", &age);
    printf("Customer overdraft: ");
    scanf("%d", &overdraft);


    printf("Customer added! %s\n", name);
    createPerson(p, name, age, 0, overdraft);
    return 0;
}

int manageCustomer(Person * p) {

    int amount;
    int choice = 1;

    while( choice != 0 ) {
        printf("Chose an option from the menu!\n");
        printf(" 0: exit manageAccount!\n");
        printf(" 1: make deposit\n");
        printf(" 2: make withdrawal\n");
        printf(" 3: get balance\n");
        printf(" Select an option: \n");
        scanf("%d", &choice);
        printf("Your selection is %d\n", choice);

        switch ( choice ) {
            case 0:
                printf("Exiting program\n");
                break;
            case 1:
                printf("How much will you deposit? \n");
                scanf("%d", &amount);
                makeDeposit(p, amount);
                break;
            case 2:
                printf("How much will you withdraw? \n");
                scanf("%d", &amount);
                makeWithdrawal(p, amount);
                break;
            case 3:
                // print balance
                printf("Current balance is %s\n", p->bank_balance);  
                break;
            default:
                printf("You entered an invalid choice you idiot!!!\n");  
        }
    }

    printf("Customer managed!\n");
    return 0;
}


int main (int argc , char **argv){

    // Person person;

    // person = _Person();
    // printf(person.getBalance(&person));

    // local variables for main menu
    int choice;
    int pers_index= 0;
    int next_free= 0;

    struct Person * p = malloc(sizeof(struct Person));

    printf("Main Menu\n");
    printf(" 0: exit !\n");
    printf(" 1: add customer record\n");
    printf(" 2: manage customer account\n");
    printf(" Option?\n");
    scanf("%d", &choice);
    printf("Your selection is %d\n", choice);


    switch (choice)
    {
    case 0:
        printf("Exiting program\n");
        break;
    case 1:
        // Create a new customer record
        printf("Adding customer\n");
        addCustomer(p);
        break;
    case 2:
        // Manage a customer record
        printf("Manage customer\n");
        printf("Which customer?\n");
        manageCustomer(p);
        break;
    default:
        printf("You entered an invalid choice you idiot!!!\n");
        break;
    }

    return 0;
}