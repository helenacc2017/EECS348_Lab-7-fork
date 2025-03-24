// Standard C library
#include <stdio.h>
// Include custom header file with function declarations
#include "temperature.h"

/*
 brief Convert temperature in Celsius to Fahrenheit
 @param celsius Temperature value in Celsius
 @return float Converted temperature in Fahrenheit
*/
float celsius_to_fahrenheit(float celsius) {
    // F = (9/5)C + 32
    // Use floating-point literals (9.0, 5.0, 32.0) for precision
    return (9.0 / 5.0) * celsius + 32.0;
}

/*
 @brief Convert temperature in Fahrenheit to Celsius
 @param fahrenheit Temperature value in Fahrenheit
 @return float Converted temperature in Celsius
*/
float fahrenheit_to_celsius(float fahrenheit) {
    // C = (5/9)(F - 32)
    // First subtract 32, then multiply by 5/9 for correct conversion
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

/*
@brief Convert temperature in Celsius to Kelvin
@param celsius Temperature value in Celsius
@return float Converted temperature in Kelvin
*/
float celsius_to_kelvin(float celsius) {
    // K = C + 273.15
    // Simply add 273.15 (absolute zero in Celsius) to get Kelvin
    return celsius + 273.15;
}

/*
@brief Convert temperature in Kelvin to Celsius
@param kelvin Temperature value in Kelvin
@return float Converted temperature in Celsius
*/
float kelvin_to_celsius(float kelvin) {
    // C = K - 273.15
    // Subtract 273.15 to convert from Kelvin to Celsius
    return kelvin - 273.15;
}

/*
@brief Convert temperature in Fahrenheit to Kelvin
@param fahrenheit Temperature value in Fahrenheit
@return float Converted temperature in Kelvin
*/
float fahrenheit_to_kelvin(float fahrenheit) {
    // Convert Fahrenheit to Celsius first, then Celsius to Kelvin
    float celsius = fahrenheit_to_celsius(fahrenheit);
    // Convert from Celsius to Kelvin using existing function
    return celsius_to_kelvin(celsius);
}

/*
@brief Convert temperature in Kelvin to Fahrenheit
@param kelvin Temperature value in Kelvin
@return float Converted temperature in Fahrenheit
*/
float kelvin_to_fahrenheit(float kelvin) {
    // Convert Kelvin to Celsius first, then Celsius to Fahrenheit
    float celsius = kelvin_to_celsius(kelvin);
    // Convert from Celsius to Fahrenheit using existing function
    return celsius_to_fahrenheit(celsius);
}

/*
@brief Categorize temperature and provide weather advisory
@param celsius Temperature value in Celsius
@param category Pointer to store the category string
@param advisory Pointer to store the advisory string
*/
void categorize_temperature(float celsius, char *category, char *advisory) {
    // Categorize the temperature based on Celsius value
    if (celsius < 0) {
        // Below 0°C is freezing
        sprintf(category, "Freezing");
        // Set the category string to "Freezing"
        sprintf(advisory, "Stay indoors and dress very warmly if you must go out.");
    } else if (celsius < 10) {
        // 0°C to 10°C is cold
        sprintf(category, "Cold");
        // Set the category string to "Cold"
        sprintf(advisory, "Wear a jacket.");
    } else if (celsius < 25) {
        // 10°C to 25°C is comfortable
        sprintf(category, "Comfortable");
        // Set the category string to "Comfortable"
        sprintf(advisory, "You should feel comfortable.");
    } else if (celsius < 35) {
        // 25°C to 35°C is hot
        sprintf(category, "Hot");
        // Provide advisory for hot temps
        sprintf(advisory, "Stay hydrated and seek shade.");
    } else {
        // Above 35°C is extreme heat
        sprintf(category, "Extreme Heat");
        // Set the category string to "Extreme Heat"
        sprintf(advisory, "Avoid outdoor activities and stay hydrated.");
    }
}

/*
@brief Convert temperature between different scales
@param temp Original temperature value
@param from_scale Original temperature scale (1-Celsius, 2-Fahrenheit, 3-Kelvin)
@param to_scale Target temperature scale (1-Celsius, 2-Fahrenheit, 3-Kelvin)
@param result Pointer to store the converted temperature
@return int 1 if successful, 0 if error occurred
*/
int convert_temperature(float temp, int from_scale, int to_scale, float *result) {
    // Check for invalid inputs
    // Verify scale codes are within valid range
    if (from_scale < 1 || from_scale > 3 || to_scale < 1 || to_scale > 3) {
        return 0;
    }

    // Check for negative Kelvin values
    // Check if input is Kelvin and below absolute zero
    if (from_scale == 3 && temp < 0) {
        return 0;
    }

    // Check for same source and destination scales
    // Check for same source and destination scales
    if (from_scale == to_scale) {
        // Set the result to the original temperature (no conversion needed)
        *result = temp;
        return 1;
    }

    // Convert to Celsius as an intermediate step
    float celsius;
    // Switch based on input scale
    switch (from_scale) {
        case 1:  // From Celsius
            celsius = temp;
            break;
        case 2:  // From Fahrenheit
            celsius = fahrenheit_to_celsius(temp);
            break;
        case 3:  // From Kelvin
            celsius = kelvin_to_celsius(temp);  // Convert Kelvin to Celsius
            // Check if the conversion results in a valid temperature
            // Check if resulting Celsius value is below absolute zero
            if (celsius < -273.15) {
                return 0;
            }
            break;
        // Should never reach here due to earlier check
        default:
            return 0;  // Return 0 to indicate invalid scale
    }

    // Convert from Celsius to target scale
    // Switch based on output scale
    switch (to_scale) {
        case 1:  // To Celsius
            *result = celsius;
            break;
        case 2:  // To Fahrenheit
            *result = celsius_to_fahrenheit(celsius);
            break;
        case 3:  // To Kelvin
            *result = celsius_to_kelvin(celsius);
            break;
        // Should never reach here due to earlier check
        default:
            return 0;  // Return 0 to indicate invalid scale
    }

    return 1;  // Return 1 to indicate successful conversion
}


