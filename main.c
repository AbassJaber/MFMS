#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "supplier.h"
#include "assets.h"
#include "reports.h"
#include "validation.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayMainMenu(void) {
    printf("================================\n ");
    printf(" MUNICIPAL FINAMCIAL MANAGEMENT SYSTEM \n  ");
    printf("================================\n ");
    printf("1. Employee Management\n ");
    printf("2. Budget Management\n ");
    printf("3. Supplier Management\n ");
    printf("4. Asset management\n ");
    printf("5. Reports\n ");
    printf("6. Exit\n ");
}

void displayEmployeeMenu() {
    int choice = 0;
    do {
        printf("\n====== EMPLOYEE MANAGEMENT MENU ======\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Search employee\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice (1-4): ");

       if (scanf("%d", &choice) != 1) {
    printf("Invalid number. Please enter a number between 1 and 4.\n");
    clearInputBuffer();
    continue;
}

clearInputBuffer();

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                {
                    int searchId;
                    printf("Enter Employee ID to search: ");
                    if (scanf("%d", &searchId) ==1) {
                        searchEmployee(searchId);
                    } 
                    else {
                        printf("Invalid EmployeeID. Please enter a valid Employee ID.\n");
                    }
                    break;
                }
                break;
            case 4:
                printf("Returning to main menu.\n ");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 4); 
}

void displayBudgetMenu() {
    int choice = 0;
    do {
        printf("\n====== BUDGET MANAGEMENT MENU ======\n");
        printf("1. Add budget\n");
        printf("2. Display budgets\n");
        printf("3. Show overspent departments\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid number. Please enter a number between 1 and 4.\n");
            continue;
        }

    switch (choice) {
        case 1:
            addBudget();
            break;
        case 2:
            displayBudgets();
            break;
        case 3:
            showOverspentDepartments();
            break;
        case 4:
            printf("Returning to main menu.\n ");
            break;
        default:
            printf("Invalid choice. Please select a valid option (1-4).\n");
            break;
        }
    } while (choice != 4);
}

void displaySupplierMenu(){
    int choice = 0;

    do {
        printf("\n====== SUPPLIER MANAGEMENT MENU ======\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier (by ID/Name)\n");
        printf("4. Filter/Compare Suppliers by Location\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice (1-5): ");
       
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            continue;
        }

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
                printf("Returning to main menu.\n ");
                break;
            default:
                printf("Invalid selection! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);
}

void displayAssetsMenu() {
    int choice = 0;
    int searchId;

    do {
        printf("\n====== ASSET MANAGEMENT MENU ======\n");
        printf("1. Add Asset\n ");
        printf("2. Display All Assets\n ");
        printf("3. Search Asset (by ID)\n ");
        printf("4. Back to Main Menu\n ");
        printf("Enter your choice 1-4: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid number. Please enter a number from 1 to 4.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addAsset();
                break;
            case 2:
                displayAssets();
                break;
            case 3:
                printf("Enter Asset ID to search: ");
                if (scanf("%d", &searchId) == 1) {
                    searchAsset(searchId);
                } 
                else {
                    printf("Invalid ID input.\n");
                }
                break;
            case 4:
                printf("Returning to main menu.\n ");
                break;
            default:
                printf("Invalid selection! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
}

void displayReportsMenu() {
    int choice = 0;
     do {
        
        printf("====== REPORTS MENU ======\n");
        printf("1. Employee Report\n ");
        printf("2. Budget Report\n ");
        printf("3. Supplier Report\n ");
        printf("4. Asset Report\n ");
        printf("5. Back to Main Menu\n ");
        printf("Enter your choice 1-5: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid number. Please enter a number from 1 to 5.\n");
            continue;
        }

        switch (choice) {
            case 1: 
            employeeReport(); 
            break;
            case 2: 
            budgetReport();   
            break;
            case 3: 
            supplierReport(); 
            break;
            case 4: 
            assetReport();    
            break;
            case 5: 
            printf("Returning to main menu.\n ");
            break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n ");
        }
    } while (choice != 5);
}


int main() {
    int choice = 0;
    do {
        displayMainMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number from 1 to 6.\n ");
            continue;
        }

        switch (choice) {
            case 1:
                displayEmployeeMenu();
                break;
            case 2:
                displayBudgetMenu();
                break;
            case 3:
                displaySupplierMenu();
                break;
            case 4:
                displayAssetsMenu();
                break;
            case 5:
                displayReportsMenu();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n ");
                break;
            default:
                printf("Invalid choice. Please select a valid option (1-6).\n ");
        }
    } while (choice != 6);


    return 0;
}