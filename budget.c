#include <stdio.h>
#include <string.h>
#include "budget.h"

Budget budgets[MAX_BUDGET];
int budgetCount = 0;


void addBudget() {
    if (budgetCount >= MAX_BUDGET) {
        printf("Budget list is full. Cannot add more departments.\n");
        return;

    }

    Budget newBudget;

    printf("Enter department name: ");
    scanf(" %[^\n]", newBudget.department);


    printf("Enter allocated budget: ");
    scanf("%f", &newBudget.allocated);

    if (newBudget.allocated < 0) {
        printf("Error: Allocated budget cannot be negative.\n");
        return;
    }

    printf("Enter expenditure: ");
    scanf("%f", &newBudget.expenditure);

    if (newBudget.expenditure < 0) {
        printf("Error: Expenditure cannot be negative.\n");
        return;
    
    }

    budgets[budgetCount] = newBudget;
    budgetCount++;

    printf("Budget added successfully for %s.\n", newBudget.department);

}

void displayBudgets() {
    if (budgetCount == 0) {
        printf("No budgets to display.\n");
        return;
    }
    
    printf("\n==== BUDGET REPORT ====\n");

    for (int i = 0; i < budgetCount; i++) {
        float remaining = budgets[i].allocated - budgets[i].expenditure;

        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: N$%.2f\n", budgets[i].allocated);
        printf("Expenditure: N$%.2f\n", budgets[i].expenditure);
        printf("Remaining Budget: N$%.2f\n", remaining);

        if (budgets[i].expenditure > budgets[i].allocated) {
            printf("Status: Over Budget\n");
        } else {
            printf("Status: Within Budget\n");
        }

    }
    
}

void showOverspentDepartments() {
    int found = 0;
    printf("\n==== DEPARTMENTS OVER BUDGET ====\n");

    for (int i = 0; i < budgetCount; i++) {
        if (budgets[i].expenditure > budgets[i].allocated) {
            printf("\nDepartment: %s\n", budgets[i].department);
            printf("Allocated Budget: N$%.2f\n", budgets[i].allocated);
            printf("Expenditure: N$%.2f\n", budgets[i].expenditure);
            printf("Overspent Amount: N$%.2f\n", budgets[i].expenditure - budgets[i].allocated);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No departments are currently over budget.\n");

    }
}

int main() {
    addBudget();
    addBudget();
    displayBudgets();
    showOverspentDepartments();
    return 0;
}