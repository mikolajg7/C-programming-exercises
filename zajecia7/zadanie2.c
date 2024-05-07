#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the border values for each color
const int borderValue[] = {12, 13, 14};
// Define the English shorts for each color
const char englishShorts[] = {'r', 'g', 'b'};

// Function to extract the game number from a line
int gameNumber(const char *line){
    int number;
    // Use sscanf to find the first number in the line, which is the game number
    if (sscanf(line, "%*[^0-9]%d", &number) == 1) {
        return number;
    }
    return 0;
}

// Function to check the dice numbers in a line
int checkDices(const char *line) {
    int tempNumber = 0;
    const char *ptr = line;
    // Skip the characters until the colon
    while (*ptr != ':'){
        ptr++;
    }
    // Parse the rest of the line
    while (*ptr != '\0') {
        // If the current character is a digit and tempNumber is 0, store the digit in tempNumber
        if (isdigit(*ptr) && tempNumber == 0) {
            tempNumber = *ptr - '0';
        }
            // If the current character is a digit and tempNumber is not 0, append the digit to tempNumber
        else if (isdigit(*ptr) && tempNumber != 0) {
            tempNumber = tempNumber * 10 + (*ptr - '0');
        }
            // If tempNumber is greater than 0 and the current character is in englishShorts, check the border value
        else if (tempNumber > 0 && strchr(englishShorts, *ptr)) {
            int index = strchr(englishShorts, *ptr) - englishShorts;
            // If tempNumber exceeds the border value, return 0
            if (tempNumber > borderValue[index]) {
                return 0;
            }
            tempNumber = 0;
        }
        ptr++;
    }
    // If the loop ended without returning 0, return the game number
    return gameNumber(line);
}

int main() {
    // Open the file
    FILE *file = fopen("/Users/mikolaj/CLionProjects/untitled1/zajecia7/input_2.txt", "r");
    if (file == NULL) {
        perror("File opening error");
        return EXIT_FAILURE;
    }

    char linia[255];
    int gamesSum = 0;
    // Read the file line by line
    while (fgets(linia, sizeof(linia), file) != NULL) {
        // Add the result of checkDices for the line to gamesSum
        gamesSum += checkDices(linia);
    }
    // Print the total sum of the game numbers
    printf("%d", gamesSum);

    // Close the file
    fclose(file);
    return 0;
}