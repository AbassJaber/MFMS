#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "supplier.h"
#include "assets.h"
#include "validation.h"

extern Employee employees[MAX_EMPLOYEES];
extern int employeeCount;

extern Budget budgets[MAX_BUDGET];
extern int budgetCount;

extern Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;

extern Asset assets[MAX_ASSETS];
extern int assetCount;


/* ---------------- EMPLOYEE REPORT ---------------- */
void employeeReport(void)
{
    printf("\n========== EMPLOYEE REPORT ==========\n");

    if (employeeCount == 0) {
        printf("No employees registered yet.\n");
        return;
    }

    /* Salary used here = basic + housing + transport (calculateSalary) */
    float first = calculateSalary(employees[0]);
    float highest = first;
    float lowest = first;
    int highestIndex = 0;
    int lowestIndex = 0;
    double total = 0.0;

    for (int i = 0; i < employeeCount; i++) {
        float salary = calculateSalary(employees[i]);
        total += salary;

        if (salary > highest) {
            highest = salary;
            highestIndex = i;
        }
        if (salary < lowest) {
            lowest = salary;
            lowestIndex = i;
        }
    }

    printf("Total Employees: %d\n", employeeCount);
    printf("Total Monthly Payroll: N$%.2f\n", total);
    printf("Average Salary: N$%.2f\n", total / employeeCount);
    printf("Highest Salary: N$%.2f (%s)\n", highest, employees[highestIndex].name);
    printf("Lowest Salary: N$%.2f (%s)\n", lowest, employees[lowestIndex].name);
}

/* ---------------- BUDGET REPORT ---------------- */
void budgetReport(void)
{
    printf("\n=========== BUDGET REPORT ===========\n");

    if (budgetCount == 0) {
        printf("No budgets entered yet.\n");
        return;
    }

    float totalAllocated = 0;
    float totalExpenditure = 0;

    for (int i = 0; i < budgetCount; i++) {
        totalAllocated += budgets[i].allocated;
        totalExpenditure += budgets[i].expenditure;
    }

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Total Remaining Budget: N$%.2f\n", totalAllocated - totalExpenditure);

    printf("\nDepartments exceeding budget:\n");
    int overCount = 0;

    for (int i = 0; i < budgetCount; i++) {
        if (budgets[i].expenditure > budgets[i].allocated) {
            printf("  - %s (over by N$%.2f)\n", budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocated);
            overCount++;
        }
    }

    if (overCount == 0) {
        printf("  None - all departments are within budget.\n");
    }
}

/* ---------------- SUPPLIER REPORT ---------------- */
void supplierReport(void)
{
    printf("\n========== SUPPLIER REPORT ==========\n");
    
    if (supplierCount == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }

    printf("Total Suppliers Registered: %d\n\n", supplierCount);
    printf("%-8s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Location");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < supplierCount; i++) {
        printf("  - ID: %d, Name: %s, Email: %s, Phone: %s, Location: %s\n",
               suppliers[i].supplierID, 
               suppliers[i].name, 
               suppliers[i].email,
               suppliers[i].phone, 
               suppliers[i].location);
    }
}

/* ---------------- ASSET REPORT ---------------- */
void assetReport(void)
{
    printf("\n=========== ASSET REPORT ============\n");
   
    if (assetCount == 0) {
        printf("No municipalassets registered yet.\n");
        return;
    }

    float totalAssetValue = 0.0f;

    printf("Total Assets Registered: %d\n\n", assetCount);
    printf("%-8s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Type", "Purchase Value", "Department", "Condition");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < assetCount; i++) {
        printf("  - ID: %d, Name: %s, Type: %s, Purchase Value: N$%.2f, Department: %s, Condition: %s\n",
               assets[i].assetID, 
               assets[i].name, assets[i].type, 
               assets[i].purchaseValue,
               assets[i].department, 
               assets[i].condition);
        totalAssetValue += assets[i].purchaseValue;
    }

    printf("\nTotal Accumulated Municipal Asset Value: N$%.2f\n", totalAssetValue);
}

/* ---------------- REPORTS SUB-MENU ---------------- */
void displayReports(void)
{
    int choice = 0;

    do {
        printf("\n========================================\n");
        printf("               REPORTS MENU\n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number from 1 to 5.\n");
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport();   break;
            case 3: supplierReport(); break;
            case 4: assetReport();    break;
            case 5: break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
        }
    } while (choice != 5);
}