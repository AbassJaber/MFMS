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
        printf("Error: Allocated buget cannot be nagtive.\n");
        return;
    }

    printf("Enter expenditure: ");
    scanf("%f", &newBudget.expenditure);

    if (newBudget.expenditure < 0) {
        printf("Error: Expenditure cannotbe negative.\n");
        return;
    
    }

    budgets[budgetCount] = newBudget;
    budgetCount++;

    printf("Budget added successfully for %s.\n", newBudget.department);

}

int main() {
    addBudget();
    return 0;
}