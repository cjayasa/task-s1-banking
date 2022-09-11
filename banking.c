#include <stdio.h>

typedef struct Person Person;
struct Person
{
    char name[30];
    int age, bank_balance, overdraft;

    // char[] (*getName)(Person *Person);
    int (*getAge)(Person *person);
};

int getAge(Person *person) {
    return person->age;
}

Person _Person() {
    Person p;

    p.age = 0;
    p.bank_balance = 0;
    p.overdraft = 0;
    p.getAge = getAge;

    return p;
}