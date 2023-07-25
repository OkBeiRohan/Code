/**
 * Write a C program to take the word as input string and generates the output as print one character only once. Eg: Input: EXCELLENT, Output: EXCLNT
 * MISRA C Guidelines Must Be Followed
 *
 * Algorithm:
 * 1. Accept a string from the user
 * 2. Iterate through the string
 * 3. For each character in the string, check if the character is already printed (iterate from the beginning of the string till the current index and check if the character exists)
 * 4. If the character is not already printed, print the character
 * 5. If the character is already printed, do not print the character
 */

#include <stdio.h>
#include <string.h>

void print_one_char_once(char[]);
int check_if_char_already_printed(char[], char, int);

int main()
{
    char input_string[100];

    printf("Enter a string: ");
    gets(input_string);

    print_one_char_once(input_string);

    return 0;
}

/**
 * Prints each character in the string only once
 *
 * @param input_string The string to be printed
 */

void print_one_char_once(char input_string[])
{
    int string_length, string_counter, char_already_printed;

    string_length = (int)strlen(input_string);

    for (string_counter = 0; string_counter < string_length; string_counter++)
    {
        char_already_printed = check_if_char_already_printed(input_string, input_string[string_counter], string_counter);

        if (char_already_printed == 0)
        {
            printf("%c", input_string[string_counter]);
        }
    }
}

/**
 * Checks if the given character is already printed in the string
 * Function iterates through the string from the beginning till the current index and checks if the character exists
 * If the character is already printed, function returns 1. If the character is not already printed, function returns 0
 *
 * @param input_string The string to be checked
 * @param character The character to be checked
 * @return 1 if the character is already printed, 0 if the character is not already printed
 */

int check_if_char_already_printed(char input_string[], char character, int current_index)
{
    int string_counter;

    for (string_counter = 0; string_counter < current_index; string_counter++)
    {

        if (input_string[string_counter] == character)
        {
            return 1;
        }
    }

    return 0;
}