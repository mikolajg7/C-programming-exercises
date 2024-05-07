#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

// Structure to hold the first and last numbers and their positions in a line
typedef struct {
    int firstNumber;
    int lastNumber;
    int firstNumberPos;
    int lastNumberPos;
} Numbers;

// Function to free the memory allocated for words
void freeWords(char **words, int count) {
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
}

// Function to extract the first and last numbers from a line
Numbers numbersExtraction(const char *line){
    Numbers numbers = {-1, -1, -1, -1};
    for(int i = 0; line[i] != '\0'; i++){
        if(isdigit(line[i])){
            if(numbers.firstNumber == -1){
                numbers.firstNumber = line[i] - '0';
                numbers.firstNumberPos = i;
            }
            numbers.lastNumber = line[i] - '0';
            numbers.lastNumberPos = i;
        }
    }
    return numbers;
}

// Function to extract words from a line
char** extractWords(const char *line, int *count) {
    regex_t regex;
    int reti;
    char msgbuf[100];

    // Compile the regex for the words
    reti = regcomp(&regex, "(one|two|three|four|five|six|seven|eight|nine)", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(EXIT_FAILURE);
    }

    regmatch_t matches[1];
    int num_matches = 0;
    char **words = NULL;

    const char *current_pos = line;
    // Extract all matches for the regex in the line
    while (regexec(&regex, current_pos, 1, matches, 0) == 0) {
        int start = matches[0].rm_so;
        int end = matches[0].rm_eo;
        int length = end - start;
        char *word = malloc(length + 1);
        if (word == NULL) {
            perror("Memory allocation error");
            freeWords(words, num_matches);
            exit(EXIT_FAILURE);
        }
        strncpy(word, current_pos + start, length);
        word[length] = '\0';

        num_matches++;
        words = realloc(words, num_matches * sizeof(char*));
        if (words == NULL) {
            perror("Memory allocation error");
            freeWords(words, num_matches);
            exit(EXIT_FAILURE);
        }
        words[num_matches - 1] = word;

        current_pos += end;
    }

    regfree(&regex);
    *count = num_matches;

    return words;
}

// Function to convert a word to a number
int wordToNumber(const char *word) {
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1;
}

int main() {
    // Open the file
    FILE *file = fopen("/Users/mikolaj/CLionProjects/untitled1/zajecia7/input.txt", "r");
    if (file == NULL) {
        printf("Plik nie istnieje!\n");
        return 1;
    }

    char linia[255]; // Buffer to hold a line from the file
    int count;
    long long int sum = 0;
    int line_number = 0;

    // Read the file line by line
    while (fgets(linia, sizeof(linia), file) != NULL) {
        line_number++;
        Numbers numbers = numbersExtraction(linia);
        char **words = extractWords(linia, &count);
        if (count > 0) {
            int firstWordPos = strstr(linia, words[0]) - linia;
            int lastWordPos = -1;
            for (int i = strlen(linia); i >= 0; --i) {
                if (strncmp(&linia[i], words[count - 1], strlen(words[count - 1])) == 0) {
                    lastWordPos = i;
                    break;
                }
            }
            char first[20], last[20];
            if (firstWordPos < numbers.firstNumberPos || numbers.firstNumber == -1) {
                sprintf(first, "%d", wordToNumber(words[0]));
            } else {
                sprintf(first, "%d", numbers.firstNumber);
            }
            if (lastWordPos > numbers.lastNumberPos || numbers.lastNumber == -1) {
                sprintf(last, "%d", wordToNumber(words[count - 1]));
            } else {
                sprintf(last, "%d", numbers.lastNumber);
            }
            char wholeNumber[40];
            strcpy(wholeNumber, first);
            strcat(wholeNumber, last);
            printf("Line %d: Whole number: %s\n", line_number, wholeNumber);
            sum += atoll(wholeNumber);
        } else if (numbers.firstNumber == -1 && numbers.lastNumber == -1) {
            printf("Line %d: No numbers or words found in the line.\n", line_number);
        } else {
            char wholeNumber[40];
            if (numbers.firstNumber == -1) numbers.firstNumber = 0;
            if (numbers.lastNumber == -1) numbers.lastNumber = 0;
            sprintf(wholeNumber, "%d%d", numbers.firstNumber, numbers.lastNumber);
            printf("Line %d: Whole number: %s\n", line_number, wholeNumber);
            sum += atoll(wholeNumber);
        }
        freeWords(words, count);
    }

    // Close the file
    fclose(file);
    printf("Sum of all numbers: %lld\n", sum);
    return 0;
}