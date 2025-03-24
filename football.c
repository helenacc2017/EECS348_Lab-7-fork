// C standard IO library include
#include <stdio.h>
// Include prototypes for core functions
#include "football.h"

/*
Count the # of scoring combinations for arbitrary game
(integer points input) Score to count combinations for
(integer combination count) Returns number of possible combinations
*/
int count_combinations(int points) {
    // Init counter to be zero at start
    int count = 0;
    // Declares needed local variables
    int td2pt, td1pt, td, fg, safety;
    // Max TD with 2-point conversions (8 pts)
    int max_td2pt = points / 8;
    // Max TD with 1-point field goals (7 pts)
    int max_td1pt = points / 7;
    // Max TD without conversions (6 pts)
    int max_td = points / 6;
    // Max FG (3 pts)
    int max_fg = points / 3;
    // Max safeties (2 pts)
    int max_safety = points / 2;

    // Nested loops to generate all unique combos
    // Loop through all possible TD+2pt combs
    for (td2pt = 0; td2pt <= max_td2pt; td2pt++) {
        // Loop through all possible TD+FG combos
        for (td1pt = 0; td1pt <= max_td1pt; td1pt++) {
            // Loop through all possible TD combos
            for (td = 0; td <= max_td; td++) {
                // Loop through all possible FG combos
                for (fg = 0; fg <= max_fg; fg++) {
                    // Loop through all possible safety combos
                    for (safety = 0; safety <= max_safety; safety++) {
                        // Calculate total points from this combo
                        int total = (td2pt * 8) + (td1pt * 7) + (td * 6) + (fg * 3) + (safety * 2);
                        // If we found a valid combo, increment the counter
                        if (total == points) {
                            count++;  // Increment counter for each valid combo
                        }
                    }
                }
            }
        }
    }
    // Return valid combo total count
    return count;
}

/*
Print all possible combinations of scoring plays for a given NFL score.
(input integers points) The points of interest to print the all unique combos for
*/
void print_combinations(int points) {
    // Init counter for tracking valid combinations
    int combination_count = 0;
    // Declare variables for each scoring play type
    int td2pt, td1pt, td, fg, safety;
    // Calculate maximum possible number of each scoring play based on total points
    // Max touchdowns with 2-point conversions (8 points each)
    int max_td2pt = points / 8;
    // Max touchdowns with 1-point field goals (7 points each)
    int max_td1pt = points / 7;
    // Max touchdowns without conversions (6 points each)
    int max_td = points / 6;
    // Max field goals (3 points each)
    int max_fg = points / 3;
    // Max safeties (2 points each)
    int max_safety = points / 2;

    // Print header for the results
    printf("Possible combinations of scoring plays if a team's score is %d:\n", points);

    // Use nested loops to generate all unique combos
    for (td2pt = 0; td2pt <= max_td2pt; td2pt++) {
        // Loop through all possible TD+2pt counts
        for (td1pt = 0; td1pt <= max_td1pt; td1pt++) {
            // Loop through all possible TD+FG counts
            for (td = 0; td <= max_td; td++) {
                // Loop through all possible TD counts
                for (fg = 0; fg <= max_fg; fg++) {
                    // Loop through all possible field goal counts
                    for (safety = 0; safety <= max_safety; safety++) {
                        // Calculate total points from this combo
                        int total = (td2pt * 8) + (td1pt * 7) + (td * 6) + (fg * 3) + (safety * 2);
                        // If we found a valid combo
                        if (total == points) {
                            // Print the valid combo in the required format
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td2pt, td1pt, td, fg, safety);
                            combination_count++;  // Increment the counter for valid combos
                        }
                    }
                }
            }
        }
    }

    // If no combo are found, print a message
    if (combination_count == 0) {
        printf("No valid combinations found for score %d\n", points);
    }
}

