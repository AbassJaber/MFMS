#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

static void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

static float readPurchaseValue(void) {
    float value;
    int ok;

    while (1) {
        printf("Enter Purchase Value: ");
        ok = scanf("%f", &value);
        clearInputBuffer();

        if (ok != 1) {
            printf("Error: Purchase value must be a number.\n");
            continue;
        }
        if (value < 0) {
            printf("Error: Purchase value cannot be negative.\n");
            continue;
        }
        return value;
    }
}

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("Asset list is full. Cannot add more assets.\n");
        return;
    }

    Asset newAsset;

    printf("Enter Asset ID: ");
    if (scanf("%d", &newAsset.assetID) != 1) {
        printf("Error: Asset ID must be a number.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < assetCount; i++) {
        if (assets[i].assetID == newAsset.assetID) {
            printf("Error: Asset ID %d already exists.\n", newAsset.assetID);
            return;
        }
    } 

    printf("Enter Asset Name: ");
    scanf(" %49[^\n]", newAsset.name);
    if (strlen(newAsset.name) == 0) {
        printf("Error: Asset name cannot be empty.\n");
        return;
    } 

    printf("Enter Asset Type (e.g. Vehicle, Equipment, Building): ");
    scanf(" %29[^\n]", newAsset.type);
    if (strlen(newAsset.type) == 0) {
        printf("Error: Asset type cannot be empty.\n");
        return;
    }

    newAsset.purchaseValue = readPurchaseValue();

    printf("Enter Department: ");
    scanf(" %29[^\n]", newAsset.department);
    if (strlen(newAsset.department) == 0) {
        printf("Error: Department cannot be empty.\n");
        return;
    }

    printf("Enter Condition (New/Good/Fair/Poor): ");
    scanf(" %19[^\n]", newAsset.condition);
    if (strlen(newAsset.condition) == 0) {
        printf("Error: Condition cannot be empty.\n");
        return;
    } 

    assets[assetCount] = newAsset;
    assetCount++;

    printf("Asset has been added\n");
}

void displayAssets(void) {
    if (assetCount == 0) {
        printf("No assets to display.\n");
        return;
    }

    float totalValue = 0;

    printf("\n==== ASSET LIST ====\n");
    for (int i = 0; i < assetCount; i++) {
        printf("ID: %d, Name: %s, Type: %s, Value: N$%.2f, Department: %s, Condition: %s\n",
               assets[i].assetID,
               assets[i].name,
               assets[i].type,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
        totalValue += assets[i].purchaseValue;
    }

    printf("\nTotal Asset Value: N$%.2f\n", totalValue);
}

void searchAsset(int assetID) {
    int found = 0;

    for (int i = 0; i < assetCount; i++) {
        if (assets[i].assetID == assetID) {
            printf("Asset Found: ID: %d, Name: %s, Type: %s, Value: N$%.2f, Department: %s, Condition: %s\n",
                   assets[i].assetID,
                   assets[i].name,
                   assets[i].type,
                   assets[i].purchaseValue,
                   assets[i].department,
                   assets[i].condition);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Asset with ID %d not found.\n", assetID);
    }
}

void assetMenu(void) {
    int choice = 0;
    int searchId;

    do {
        printf("\n=== ASSET MANAGEMENT MENU ===\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset (by ID)\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Invalid input. Please enter a number from 1 to 4.\n");
            choice = 0;
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addAsset();
                break;
            case 2:
                displayAssets();
                break;
            case 3:
                printf("Enter Asset ID to search: ");
                if (scanf("%d", &searchId) == 1) {
                    clearInputBuffer();
                    searchAsset(searchId);
                } else {
                    clearInputBuffer();
                    printf("Invalid ID input.\n");
                }
                break;
            case 4:
                printf("Returning to main system menu...\n");
                break;
            default:
                printf("Invalid selection!\n");
        }
    } while (choice != 4);
}
