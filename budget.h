#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGET 50

typedef struct {
    char department[50];
    float allocated;
    float expenditure;

} Budget;

void addBudget();
void displayBudgets();
void showOverspentDepartments();
#endif