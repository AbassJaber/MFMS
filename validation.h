#ifndef VALIDATION_H
#define VALIDATION_H

int getValidatedIntegerInput(const char *prompt, int min, int max);
float getValidatedPositiveFloatInput(const char *prompt);
void getValidatedStringInput(const char *prompt, char *buffer, int maxLength);

#endif