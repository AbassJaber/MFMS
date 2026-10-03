#include <stdio.h>
#include <string.h>
#include "validation.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}

int getValidatedIntegerInput(const char *prompt, int min, int max) {
    int value;
    int status;
    do {
        printf("%s", prompt);
        status = scanf("%d", &value);
        if (status == 1 && value >= min && value <= max) {
            clearInputBuffer();
            return value;
        } 
        else {
            printf("Entrance not valid. Please enter a number between %d and %d.\n", min, max);
            clearInputBuffer();
        }
    } 
    while (status !=1 || value < min || value > max );
    clearInputBuffer();
    return value;
}

float getValidatedPositiveFloatInput(const char *prompt) {
    float value;
    int status;
    do {
        printf("%s", prompt);
        status = scanf("%f", &value);
        if (status == 1 && value > 0) {
            clearInputBuffer();
            return value;
        } 
        else {
            printf("Entrance not valid. Please enter a positive number.\n");
            clearInputBuffer();
        }
    } 
    while (status != 1 || value <= 0);
    clearInputBuffer();
    return value;
}

void getValidatedStringInput(const char *prompt, char *buffer, int maxLength) {
    int valid = 1;
    do {
        printf("%s", prompt);
        if (fgets(buffer, maxLength, stdin) != NULL) {
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len - 1] == '\n') {
                buffer[len - 1] = '\0'; 
            }
            if (strlen(buffer) > 0 ) {
                break;
            }
           
        } 
        else {
            printf("Entrance cannot be empty. Please try again.\n");
            clearInputBuffer();
            valid = 0; 
        }
    } 
    while (!valid);
}
