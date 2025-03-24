#ifndef __REPORT_H__
#define __REPORT_H__

/* Add any function signatures you need here but do not modify the existing ones */

/**
 * @brief Convert temperature in Celsius to Fahrenheit
 * 
 * @param celsius
 * @return float
 */
float celsius_to_fahrenheit(float celsius);

/**
 * @brief Convert temperature in Fahrenheit to Celsius
 * 
 * @param fahrenheit
 * @return float
 */
float fahrenheit_to_celsius(float fahrenheit);

/**
 * @brief Convert temperature in Celsius to Kelvin
 * 
 * @param celsius
 * @return float
 */
float celsius_to_kelvin(float celsius);

/**
 * @brief Convert temperature in Kelvin to Celsius
 * 
 * @param kelvin
 * @return float
 */
float kelvin_to_celsius(float kelvin);

/**
 * @brief Convert temperature in Fahrenheit to Kelvin
 *
 * @param fahrenheit
 * @return float
 */
float fahrenheit_to_kelvin(float fahrenheit);

/**
 * @brief Convert temperature in Kelvin to Fahrenheit
 *
 * @param kelvin
 * @return float
 */
float kelvin_to_fahrenheit(float kelvin);

/**
 * @brief Categorize temperature and provide weather advisory
 *
 * @param celsius Temperature value in Celsius
 * @param category Pointer to store the category string
 * @param advisory Pointer to store the advisory string
 */
void categorize_temperature(float celsius, char *category, char *advisory);

/**
 * @brief Convert temperature between different scales
 *
 * @param temp Original temperature value
 * @param from_scale Original temperature scale (1-Celsius, 2-Fahrenheit, 3-Kelvin)
 * @param to_scale Target temperature scale (1-Celsius, 2-Fahrenheit, 3-Kelvin)
 * @param result Pointer to store the converted temperature
 * @return int 1 if successful, 0 if error occurred
 */
int convert_temperature(float temp, int from_scale, int to_scale, float *result);

#endif /* __REPORT_H__ */