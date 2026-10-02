#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50

typedef struct {
    char supplierID[20];
    char name[50];
    char email[50];
    char phone[20];
    char location[50];
} Supplier;

void addSupplier();
void displaySuppliers();
void searchSupplier();
void compareSuppliers();
void supplierMenu();

#endif



