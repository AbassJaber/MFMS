#include <stdio.h>
#include <string.h>
#include "employees.h"


#define MAX_EMPLOYEES 100
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee()
{
    
    if (employeeCount < MAX_EMPLOYEES){
        Employee newEmployee;

       

        printf("Enter Employee ID:");
        scanf("%d", &newEmployee.id);

        for(int i=0; i<employeeCount; i++) {
            if(employees[i].id == newEmployee.id){
                printf("Error: Employee ID %d already exists.\n", newEmployee.id);
                return;
            }
        } //stop addind this employee they already exist

        printf("Enter Employee Name: ");
        scanf(" %49[^\n]", newEmployee.name);  

        if (strlen(newEmployee.name) == 0) {
    printf("Error: Name cannot be empty.\n");
    return;
} //Making sure the name is not empty

        printf("Enter Employee Department: ");
        scanf(" %29[^\n]", newEmployee.department); 

        if (strlen(newEmployee.department) == 0) {
    printf("Error: Department cannot be empty.\n");
    return;
}// making sure the department is not empty

        printf("Enter Basic Salary: ");
        scanf("%f", &newEmployee.basicSalary);

         if(newEmployee.basicSalary<0) {
    printf("Invalid salary: Salary cannot be negative.\n ");
    return;
           } //salary validation

        printf("Enter Housing Allowance: ");
        scanf("%f", &newEmployee.housingAllowance);

        printf("Enter Transport Allowance: ");
        scanf("%f", &newEmployee.transportAllowance);

        employees[employeeCount] = newEmployee;

        employeeCount++;

        printf("Employee has been added\n");
    } else{
        printf("List is Full\n");


    }
}

 
void displayEmployees() {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
    } else {
        printf("\nEmployee List:\n");
        for (int i = 0; i < employeeCount; i++) {
            printf("ID: %d, Name: %s, Department: %s, Basic Salary: %.2f, Housing Allowance: %.2f, Transport Allowance: %.2f, Salary Calculated: %.2f\n",
                employees[i].id,
                employees[i].name,
                employees[i].department,
                employees[i].basicSalary,
                employees[i].housingAllowance,
                employees[i].transportAllowance,
                calculateSalary(employees[i]));
        }
    }
}

void searchEmployee(int id) {
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Employee Found: ID: %d, Name: %s, Department: %s, Basic Salary: %.2f, Salary Calculated: %.2f\n",
                employees[i].id,
                employees[i].name,
                employees[i].department,
                employees[i].basicSalary,
                calculateSalary(employees[i]));
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", id);
    }
}


float calculateSalary(Employee e) {
        float total = e.basicSalary + e.housingAllowance + e.transportAllowance;
    return total;
}
