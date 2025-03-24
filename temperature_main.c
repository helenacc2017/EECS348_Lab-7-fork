// Standard C library
#include <stdio.h>
#include <stdlib.h>
// Need for string
#include <string.h>
// Include our custom header file with function declarations
#include "temperature.h"

// Function to display temperature scale symbol
void display_temperature_scale(int scale);
// Function to clear input buffer after scanf
void clear_input_buffer(void);



/**
 * @brief Clear the input buffer to avoid issues with subsequent inputs
 */
void clear_input_buffer(void) {
    int c;  // Variable to store each character read
    // Read and discard characters until newline or EOF is encountered
    while ((c = getchar()) != '\n' && c != EOF) { }  // Empty loop body - just discarding characters
}

/**
 * Main function to execute the temperature conversion utility
 */
int main(int argc, char *argv[]) {  // Main function with command line arguments (unused here)
    float temperature;       // Var to store input temperature value
    int current_scale;       // Var to store input temperature scale
    int target_scale;        // Var to store target temperature scale
    float converted_temp;    // Var to store converted temperature value
    char category[20];       // Buffer to store temperature category
    char advisory[100];      // Buffer to store weather advisory
    int valid_input;         // Flag for validating input
    char scale_symbols[4] = {' ', 'C', 'F', 'K'}; // Array of symbols for temperature scales (index 0 unused)

    printf("Temperature Conversion Program\n");  // Print program title
    printf("-----------------------------\n\n");  // Print separator line

    // Start main program loop
    do {
        // Get temperature value from user
        do {
            // Start temperature input loop
            printf("Enter the temperature: ");  // Prompt user for temperature
            valid_input = scanf("%f", &temperature);  // Read temperature value from user
            clear_input_buffer();  // Clear any remaining characters in input buffer

            if (!valid_input) {  // If scanf failed to read a float
                printf("Error: Invalid temperature. Please enter a numeric value.\n");  // Print error message
            }
        } while (!valid_input);  // Repeat until valid temperature is entered

        // Get current temperature scale from user
        // Start scale input loop
        do {
            // Prompt user for current temperature scale
            printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            valid_input = scanf("%d", &current_scale);  // Read scale choice from user
            clear_input_buffer();  // Clear any remaining characters in input buffer

            // Validate scale choice and handle special case of negative Kelvin
            if (!valid_input || current_scale < 1 || current_scale > 3) {  // Invalid scale number
                printf("Error: Invalid choice. Please enter 1, 2, or 3.\n");  // Print error message
                valid_input = 0;  // Set flag to repeat the loop
            } else if (current_scale == 3 && temperature < 0) {  // Negative Kelvin is physically impossible
                printf("Error: Kelvin temperature cannot be negative (absolute zero is 0K).\n");  // Print error message
                valid_input = 0;  // Set flag to repeat the loop
            }
        } while (!valid_input);  // Repeat until valid scale is entered

        // Get target temperature scale from user
        do {
            // Start target scale input loop
            // Prompt user for target temperature scale
            printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
            valid_input = scanf("%d", &target_scale);  // Read target scale choice from user
            clear_input_buffer();  // Clear any remaining characters in input buffer

            // Validate target scale choice
            if (!valid_input || target_scale < 1 || target_scale > 3) {  // Invalid scale number
                printf("Error: Invalid choice. Please enter 1, 2, or 3.\n");  // Print error message
                valid_input = 0;  // Set flag to repeat the loop
            } else if (current_scale == target_scale) {  // Same source and target scales
                // Warn user but allow the conversion (it's not an error, just redundant)
                printf("Warning: Source and target scales are the same. No conversion needed.\n");
            }
        // Repeat until valid target scale is entered
        } while (!valid_input);

        // Perform the temperature conversion
        if (convert_temperature(temperature, current_scale, target_scale, &converted_temp)) {
            // Display the original and converted temperatures with appropriate scale symbols
            printf("\nOriginal temperature: %.2f%c\n",   // Print original temperature with 2 decimal places
                  temperature, scale_symbols[current_scale]);  // Use scale symbol from array
            printf("Converted temperature: %.2f%c\n",   // Print converted temperature with 2 decimal places
                  converted_temp, scale_symbols[target_scale]);  // Use scale symbol from array

            // Get temperature category and advisory
            float celsius_temp;  // Variable to store temperature in Celsius for categorization

            // Convert to Celsius for categorization (regardless of target scale)
            if (target_scale == 1) {  // If target scale is already Celsius
                celsius_temp = converted_temp;  // Use converted temp directly
            } else if (target_scale == 2) {  // If target scale is Fahrenheit
                celsius_temp = fahrenheit_to_celsius(converted_temp);  // Convert to Celsius
            } else { // target_scale == 3, Kelvin
                celsius_temp = kelvin_to_celsius(converted_temp);  // Convert to Celsius
            }

            // Categorize temperature and get advisory
            categorize_temperature(celsius_temp, category, advisory);  // Call function to get category and advisory
            printf("Temperature category: %s\n", category);  // Print the temperature category
            printf("Weather advisory: %s\n", advisory);  // Print the weather advisory
        } else {  // If conversion failed
            printf("Error: Failed to convert temperature. Please check your inputs.\n");  // Print error message
        }

        // Ask user if they want to perform another conversion
        printf("\nWould you like to perform another conversion? (1 for Yes, 0 for No): ");  // Prompt for continuation
        scanf("%d", &valid_input);  // Read user choice
        clear_input_buffer();  // Clear any remaining characters in input buffer
        printf("\n");  // Print blank line for readability

    } while (valid_input == 1);  // Continue loop if user entered 1

    // Print exit message
    printf("Thank you for using the Temperature Conversion Utility. Goodbye!\n");
    return 0;  // Return 0 to indicate successful program execution
}

/**
 * @brief Display the symbol for a temperature scale
 *
 * @param scale Temperature scale (1-Celsius, 2-Fahrenheit, 3-Kelvin)
 */
void display_temperature_scale(int scale) {
    switch (scale) {  // Switch based on scale code
        case 1:  // Celsius
            printf("°C");  // Print Celsius symbol
            break;
        case 2:  // Fahrenheit
            printf("°F");  // Print Fahrenheit symbol
            break;
        case 3:  // Kelvin
            printf("K");   // Print Kelvin symbol (no degree symbol for Kelvin)
            break;
        default:  // Invalid scale
            printf("Unknown scale");  // Print error message
    }
}

