/**
 * Write a C program to accept two inputs from user Temperature in Celsius & Category (Human/Dog/Cat). Output should be equivalent Fahrenheit and kelvin & whether the category is in fever or not. The program should have only functions for each steps and no logic or calculations should be there in “main”.
 * Normal Temperature:
 * Human: Between 98.6 to 99 degrees Fahrenheit
 * Dog: Between 99 and 102.5 degrees Fahrenheit
 * Cat: Between 99 and 102.5 degrees Fahrenheit
 *
 * Follow MISRA C Guidelines
 *
 * The program inputs the temperature in celcius and the category of the animal.
 * It then converts the temperature to fahrenheit and kelvin and prints it.
 * It then checks if the temperature is normal or not and prints the result.
 *
 * Algorithm:
 * 1. Input the temperature in celcius and the category of the animal.
 * 2. Convert the temperature to fahrenheit using the formula (temp_celcius * 9 / 5) + 32 and print it.
 * 3. Convert the temperature to kelvin using the formula temp_celcius + 273.15 and print it.
 * 4. Check if the temperature is normal or not using the normal temperature ranges for each category.
 * 5. If the temperature falls within the normal range, print "Normal Temperature. No fever detected".
 * 6. If the temperature falls outside the normal range, print "Abnormal Temperature! Fever detected."
 */

#include <stdio.h>

/**
 * Defining the normal temperature ranges for each category
 */

#define MAX_TEMP_HUMAN 99
#define MIN_TEMP_HUMAN 98.6

#define MAX_TEMP_DOG 102.5
#define MIN_TEMP_DOG 99

#define MAX_TEMP_CAT 102.5
#define MIN_TEMP_CAT 99

/**
 * Defining the categories as enum
 */

enum categories
{
    HUMAN,
    DOG,
    CAT
};

double celcius_to_fahrenheit(double);
double celcius_to_kelvin(double);
void fever_check(double, enum categories);

/**
 * Main function
 * Inputs the temperature in celcius and the category of the animal
 * Converts the temperature to fahrenheit and kelvin and prints it
 * Checks if the temperature is normal or not.
 */

int main()
{
    double temp_celcius, temp_fahrenheit;
    int category;

    printf("Enter the temperature in celcius: ");
    scanf("%lf", &temp_celcius);
    printf("Enter the category (0 - Human, 1 - Dog, 2 - Cat): ");
    scanf("%d", &category);

    temp_fahrenheit = celcius_to_fahrenheit(temp_celcius);
    printf("Temperature in Fahrenheit: %lf\n", temp_fahrenheit);
    printf("Temperature in Kelvin: %lf\n", celcius_to_kelvin(temp_celcius));
    fever_check(temp_fahrenheit, (enum categories)category);

    return 0;
}

/**
 * Function to convert temperature from celcius to fahrenheit
 * @param temp_celcius Temperature in celcius
 * @return Temperature in fahrenheit
 */

double celcius_to_fahrenheit(double temp_celcius)
{
    return (temp_celcius * 9 / 5) + 32;
}

/**
 * Function to convert temperature from celcius to kelvin
 * @param temp_celcius Temperature in celcius
 * @return Temperature in kelvin
 */

double celcius_to_kelvin(double temp_celcius)
{
    return temp_celcius + 273.15;
}

/**
 * Function to check if the temperature is normal or not
 * @param temp_fahrenheit Temperature in Fahrenheit
 * @param category Category of the animal
 *
 * Prints the result of the check
 * If the temperature is normal, prints "Normal Temperature. No fever detected"
 * If the temperature is abnormal, prints "Abnormal Temperature! Fever detected."
 */

void fever_check(double temp_fahrenheit, enum categories category)
{
    switch (category)
    {
    case HUMAN:
        if (temp_fahrenheit >= MIN_TEMP_HUMAN && temp_fahrenheit <= MAX_TEMP_HUMAN) // Checks if the temperature is within the permissible limit
        {
            printf("Normal Temperature. No fever detected\n");
            return;
        }
        break;
    case DOG:
        if (temp_fahrenheit >= MIN_TEMP_DOG && temp_fahrenheit <= MAX_TEMP_DOG)
        {
            printf("Normal Temperature. No fever detected\n");
            return;
        }
        break;
    case CAT:
        if (temp_fahrenheit >= MIN_TEMP_CAT && temp_fahrenheit <= MAX_TEMP_CAT)
        {
            printf("Normal Temperature. No fever detected\n");
            return;
        }
        break;
    default:
        break;
    }
    printf("Abnormal Temperature! Fever detected.\n");
}
