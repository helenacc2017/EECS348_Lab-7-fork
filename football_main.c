// C standard IO library include
#include <stdio.h>
// Include custom header file with function declarations
#include "football.h"

/*
Main function to execute the NFL score combo finder.
Forever prompts for a score until 0 or 1 is entered.
For each valid score, prints all possible combinations of scoring plays.
 */
int main(int argc, char *argv[]) {
    // Declare variable to store the user-input score
    int score;
    // Display initial instruction to the user
    printf("Enter 0 or 1 to STOP\n");
    // Loop forever
    while (1) {
        // Get user input
        printf("Enter the NFL score: ");
        // Read the score from user
        scanf("%d", &score);
        // Exit condition: if score is 0 or 1, exit the program
        if (score <= 1) {
            // Print termination message
            printf("Program terminated.\n");
            break;  // Exit the while loop
        }
        // Print all possible combo for the given score
        print_combinations(score);
        printf("\n");
    }
    return 0;
}


