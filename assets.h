#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 50

typedef struct {
    int assetID;
    char name[50];
    char type[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

void addAsset(void);
void displayAssets(void);
void searchAsset(int assetID);
void assetMenu(void);

#endif
