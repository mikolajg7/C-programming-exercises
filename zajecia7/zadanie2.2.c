#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the English shorts for each color
const char englishShorts[] = {'r', 'g', 'b'};

// Function to check the dice numbers in a line
int checkDices(const char *line) {
    int maxRed = 0, maxGreen = 0, maxBlue = 0; // Variables to store the maximum dice numbers for each color
    int tempNumber = 0; // Temporary variable to store the current dice number
    while (*line != ':') { // Skip the characters until the colon
        line++;
    }
    while(*line != '\0'){ // Parse the rest of the line
        if (isdigit(*line) && tempNumber == 0) { // If the current character is a digit and tempNumber is 0, store the digit in tempNumber
            tempNumber = *line - '0';
        } else if (isdigit(*line) && tempNumber != 0) { // If the current character is a digit and tempNumber is not 0, append the digit to tempNumber
            tempNumber = tempNumber * 10 + (*line - '0');
        } else if (tempNumber > 0 && strchr(englishShorts, *line)) { // If tempNumber is greater than 0 and the current character is in englishShorts, check the color
            if (*line == 'r' && tempNumber > maxRed) { // If the color is red and tempNumber is greater than maxRed, update maxRed
                maxRed = tempNumber;
            } else if (*line == 'g' && tempNumber > maxGreen) { // If the color is green and tempNumber is greater than maxGreen, update maxGreen
                maxGreen = tempNumber;
            } else if (*line == 'b' && tempNumber > maxBlue) { // If the color is blue and tempNumber is greater than maxBlue, update maxBlue
                maxBlue = tempNumber;
            }
            tempNumber = 0; // Reset tempNumber
        }
        line++; // Move to the next character
    }
    return maxBlue * maxRed * maxGreen; // Return the product of the maximum dice numbers for each color
}

int main() {
    // Open the file
    FILE *file = fopen("/Users/mikolaj/CLionProjects/untitled1/zajecia7/input_2.txt", "r");
    if (file == NULL) { // If the file could not be opened, print an error message and exit with a failure status
        perror("File opening error");
        return EXIT_FAILURE;
    }

    char linia[255]; // Buffer to hold a line from the file
    int gamesSum = 0; // Variable to store the total sum of the game numbers
    while (fgets(linia, sizeof(linia), file) != NULL) { // Read the file line by line
        gamesSum += checkDices(linia); // Add the result of checkDices for the line to gamesSum
    }
    printf("%d", gamesSum); // Print the total sum of the game numbers

    // Close the file
    fclose(file);
    return 0; // Exit with a success status
}