#include <stdio.h>
#include <string.h>
#include "budget.h"

Budget budgets[MAX_BUDGET];
int budgetCount = 0;

static float readAmount(const char *prompt, const char *label) {
    float value;
    int ok, c;

    while (1) {
        printf("%s", prompt);
        ok = scanf("%f", &value);
        while ((c = getchar()) != '\n' && c != EOF); 

        if (ok != 1) {
            printf("Error: %s must be a number.\n", label);
            continue;
        }

        if (value < 0) {
            printf("Error: %s cannot be negative.\n", label);
            continue;
        }

        return value;
    }

}

void addBudget() {
    if (budgetCount >= MAX_BUDGET) {
        printf("Budget list is full. Cannot add more departments.\n");
        return;
    }

    Budget newBudget;
    char name[50];
    int c, i, duplicate;

    while (1) {
        printf("Enter department name: ");
        if (fgets(name, sizeof(name), stdin) == NULL) {
            return;
        }

        if (strchr(name, '\n') == NULL) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Error: Department name is too long (maximum 48 characters).\n");
            continue;
        }

        name[strcspn(name, "\n")] = '\0';

        if (strlen(name) == 0) {
            printf("Error: Department name cannot be empty.\n");
            continue;
        }

        duplicate = 0;
        for (i = 0; i < budgetCount; i++) {
            if (strcmp(budgets[i].department, name) == 0) {
                duplicate = 1;
            }
        }
        if (duplicate) {
            printf("Error: That department already has a budget.\n");
            continue;
        }

        break;
    }

    strcpy(newBudget.department, name);

    newBudget.allocated = readAmount("Enter allocated budget: ", "Allocated budget");
    newBudget.expenditure = readAmount("Enter expenditure: ", "Expenditure");

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

