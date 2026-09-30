#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

extern Employee employees[MAX_EMPLOYEES];
extern int employeeCount;

extern Budget budgets[MAX_BUDGET];
extern int budgetCount;

/* Clears leftover characters after a failed scanf */
static void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* discard */
    }
}

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
    /* TODO: replace once suppliers.h/.c are uploaded.
       Expected pattern:
         extern Supplier suppliers[...]; extern int supplierCount;
         loop 0..supplierCount-1 and print ID, name, email, phone, town */
    printf("Supplier module not connected yet.\n");
}

/* ---------------- ASSET REPORT ---------------- */
void assetReport(void)
{
    printf("\n=========== ASSET REPORT ============\n");
    /* TODO: replace once assets.h/.c are uploaded.
       Expected pattern:
         extern Asset assets[...]; extern int assetCount;
         loop and print ID, name, type, value, department, condition;
         optionally add a total asset value */
    printf("Asset module not connected yet.\n");
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