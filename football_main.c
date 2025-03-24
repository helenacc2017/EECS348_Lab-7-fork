// C standard IO library include
#include <stdio.h>
// Include for standard library functions
#include <stdlib.h>
// Include for string manipulation functions
#include <string.h>
// Include custom header file with function declarations
#include "football.h"

/*
Main function to execute the NFL score combo finder.
Forever prompts for a score until 0 or 1 is entered.
For each valid score, prints all possible combinations of scoring plays.
Handles all types of invalid inputs including non-integers, negative numbers, and empty input.
 */
int main(int argc, char *argv[]) {
    // Declare variable to store the user-input score
    int score;
    // Character buffer to read the full input line
    char input_buffer[100];
    // Variable to check conversion success
    char *endptr;

    // Loop forever
    while (1) {
        // Get user input
        // Display initial instruction to the user
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");

        // Read the entire input line as a string
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            printf("Error reading input. Please try again.\n\n");
            continue;
        }

        // Check for empty input (just Enter key)
        if (input_buffer[0] == '\n') {
            printf("No input detected. Please enter an integer score.\n\n");
            continue;  // Skip to next iteration
        }

        // Remove newline character if present
        size_t len = strlen(input_buffer);
        if (len > 0 && input_buffer[len-1] == '\n') {
            input_buffer[len-1] = '\0';
        }

        // Check for empty input after removing potential white-space
        if (strlen(input_buffer) == 0) {
            printf("No input detected. Please enter an integer score.\n\n");
            continue;  // Skip to next iteration
        }

        // Convert string to integer and check if conversion was successful
        score = (int)strtol(input_buffer, &endptr, 10);

        // Check if conversion was successful (no non-digit characters except white-space)
        if (*endptr != '\0' && *endptr != ' ' && *endptr != '\t') {
            printf("Invalid input. Please enter an integer score.\n\n");
            continue;  // Skip to next iteration
        }

        // Check for negative scores
        if (score < 0) {
            printf("Invalid input. Football scores cannot be negative.\n\n");
            continue;  // Skip to next iteration
        }

        // Exit condition: if score is 0 or 1, exit the program
        if (score <= 1) {
            printf("Program terminated.\n");
            break;  // Exit the while loop
        }

        // Print all possible combo for the given score
        print_combinations(score);
        printf("\n");
    }
    return 0;
}