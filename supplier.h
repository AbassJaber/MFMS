#include <stdio.h>
#include <string.h>
#include "suppliers.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

void addSupplier()
{
    if (supplierCount < MAX_SUPPLIERS) {
        Supplier newSupplier;

        printf("Enter Supplier ID: ");
        scanf(" %19[^\n]", newSupplier.supplierID);

        for (int i = 0; i < supplierCount; i++) {
            if (strcmp(suppliers[i].supplierID, newSupplier.supplierID) == 0) {
                printf("Error: Supplier ID %s already exists.\n", newSupplier.supplierID);
                return;
            }
        } // stop adding this supplier if they already exist

        if (strlen(newSupplier.supplierID) == 0) {
            printf("Error: Supplier ID cannot be empty.\n");
            return;
        } // making sure the ID is not empty

        printf("Enter Supplier Name: ");
        scanf(" %49[^\n]", newSupplier.name);

        if (strlen(newSupplier.name) == 0) {
            printf("Error: Name cannot be empty.\n");
            return;
        } // making sure the name is not empty

        printf("Enter Email Address: ");
        scanf(" %49[^\n]", newSupplier.email);

        if (strlen(newSupplier.email) == 0) {
            printf("Error: Email cannot be empty.\n");
            return;
        } // making sure the email is not empty

        printf("Enter Telephone Number: ");
        scanf(" %19[^\n]", newSupplier.phone);

        if (strlen(newSupplier.phone) == 0) {
            printf("Error: Telephone number cannot be empty.\n");
            return;
        } // making sure the phone is not empty

        printf("Enter Town/Location: ");
        scanf(" %29[^\n]", newSupplier.location);

        if (strlen(newSupplier.location) == 0) {
            printf("Error: Location cannot be empty.\n");
            return;
        } // making sure the location is not empty

        suppliers[supplierCount] = newSupplier;
        supplierCount++;

        printf("Supplier has been added\n");
    } else {
        printf("List is Full\n");
    }
}

void displaySuppliers()
{
    if (supplierCount == 0) {
        printf("No suppliers currently registered.\n");
        return;
    }

    printf("\n--- SUPPLIER LIST ---\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("ID: %s | Name: %s | Email: %s | Phone: %s | Location: %s\n",
               suppliers[i].supplierID,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].location);
    }
}

void searchSupplier()
{
    if (supplierCount == 0) {
        printf("No suppliers registered to search.\n");
        return;
    }

    char searchTerm[50];
    printf("Enter Supplier ID or Name to search: ");
    scanf(" %49[^\n]", searchTerm);

    int found = 0;
    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].supplierID, searchTerm) == 0 || strcmp(suppliers[i].name, searchTerm) == 0) {
            printf("\nSupplier Found:\n");
            printf("ID:       %s\n", suppliers[i].supplierID);
            printf("Name:     %s\n", suppliers[i].name);
            printf("Email:    %s\n", suppliers[i].email);
            printf("Phone:    %s\n", suppliers[i].phone);
            printf("Location: %s\n", suppliers[i].location);
            found = 1;
        }
    }

    if (!found) {
        printf("No supplier record matching '%s' was found.\n", searchTerm);
    }
}

void compareSuppliers()
{
    if (supplierCount == 0) {
        printf("No suppliers registered to filter.\n");
        return;
    }

    char searchLocation[30];
    printf("Enter Town/Location to filter: ");
    scanf(" %29[^\n]", searchLocation);

    int count = 0;
    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].location, searchLocation) == 0) {
            printf("ID: %s | Name: %s | Email: %s | Phone: %s\n",
                   suppliers[i].supplierID,
                   suppliers[i].name,
                   suppliers[i].email,
                   suppliers[i].phone);
            count++;
        }
    }

    if (count == 0) {
        printf("No suppliers are registered under location '%s'.\n", searchLocation);
    }
}

void supplierMenu()
{
    int choice = 0;

    do {
        printf("\n=== SUPPLIER MANAGEMENT MENU ===\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier (by ID/Name)\n");
        printf("4. Filter/Compare Suppliers by Location\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                compareSuppliers();
                break;
            case 5:
                printf("Returning to main system menu...\n");
                break;
            default:
                printf("Invalid selection!\n");
        }
    } while (choice != 5);
}

int main()
{
    supplierMenu();
    return 0;
}