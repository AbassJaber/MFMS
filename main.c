#include <stdio.h>
#include "employees.h"

int main() {
    addEmployee();
    displayEmployees();
    int searchId;
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);
    searchEmployee(searchId);

    return 0;
}