#ifndef EMPLOYEES_H
#define EMPLOYEES_H

typedef struct {
    int id;
    char name[50];
    char department[30];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

#define MAX_EMPLOYEES 100

void addEmployee();
void displayEmployees();
void searchEmployee(int id);
float calculateSalary(Employee e);

#endif