#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

// Define the English shorts for each color
const char englishShorts[] = {'r', 'g', 'b'};

// Function to check the dice numbers in a line
int checkDices(const std::string &line) {
    int maxRed = 0, maxGreen = 0, maxBlue = 0; // Variables to store the maximum dice numbers for each color
    int tempNumber = 0; // Temporary variable to store the current dice number
    size_t i = 0;
    for (; i < line.size(); ++i) { // Parse the line character by character
        if (line[i] == ':') { // If the current character is a colon, stop parsing
            break;
        }
    }
    for (; i < line.size(); ++i) { // Parse the rest of the line
        if (isdigit(line[i]) && tempNumber == 0) { // If the current character is a digit and tempNumber is 0, store the digit in tempNumber
            tempNumber = line[i] - '0';
        } else if (isdigit(line[i]) && tempNumber != 0) { // If the current character is a digit and tempNumber is not 0, append the digit to tempNumber
            tempNumber = tempNumber * 10 + (line[i] - '0');
        } else if (tempNumber > 0 && strchr(englishShorts, line[i])) { // If tempNumber is greater than 0 and the current character is in englishShorts, check the color
            if (line[i] == 'r' && tempNumber > maxRed) { // If the color is red and tempNumber is greater than maxRed, update maxRed
                maxRed = tempNumber;
            } else if (line[i] == 'g' && tempNumber > maxGreen) { // If the color is green and tempNumber is greater than maxGreen, update maxGreen
                maxGreen = tempNumber;
            } else if (line[i] == 'b' && tempNumber > maxBlue) { // If the color is blue and tempNumber is greater than maxBlue, update maxBlue
                maxBlue = tempNumber;
            }
            tempNumber = 0; // Reset tempNumber
        }
    }
    return maxBlue * maxRed * maxGreen; // Return the product of the maximum dice numbers for each color
}

int main() {
    std::ifstream file("/Users/mikolaj/CLionProjects/untitled1/zajecia8cpp/input_2.txt"); // Open the file
    if (!file.is_open()) { // If the file could not be opened, print an error message and exit with a failure status
        std::cerr << "File opening error" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line; // String to hold a line from the file
    int gamesSum = 0; // Variable to store the total sum of the game numbers
    while (std::getline(file, line)) { // Read the file line by line
        gamesSum += checkDices(line); // Add the result of checkDices for the line to gamesSum
    }
    std::cout << gamesSum; // Print the total sum of the game numbers

    file.close(); // Close the file
    return 0; // Exit with a success status
}
