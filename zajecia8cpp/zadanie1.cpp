#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

// Structure to hold the first and last numbers and their positions in a line
struct Numbers {
    int firstNumber;
    int lastNumber;
    int firstNumberPos;
    int lastNumberPos;
};

// Function to extract the first and last numbers from a line
Numbers numbersExtraction(const string &line){
    Numbers numbers = {-1, -1, -1, -1};
    for(size_t i = 0; i < line.length(); i++){
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
vector<string> extractWords(const string &line) {
    regex wordRegex("(one|two|three|four|five|six|seven|eight|nine)");
    vector<string> words;
    sregex_iterator it(line.begin(), line.end(), wordRegex);
    sregex_iterator end;
    while (it != end) {
        words.push_back(it->str());
        it++;
    }
    return words;
}

// Function to convert a word to a number
int wordToNumber(const string &word) {
    if (word == "one") return 1;
    if (word == "two") return 2;
    if (word == "three") return 3;
    if (word == "four") return 4;
    if (word == "five") return 5;
    if (word == "six") return 6;
    if (word == "seven") return 7;
    if (word == "eight") return 8;
    if (word == "nine") return 9;
    return -1;
}

int main() {
    ifstream file("/Users/mikolaj/CLionProjects/untitled1/zajecia8cpp/input.txt");
    if (!file.is_open()) {
        cout << "Plik nie istnieje!" << endl;
        return 1;
    }

    string line;
    long long int sum = 0;
    int line_number = 0;

    // Read the file line by line
    while (getline(file, line)) {
        line_number++;
        Numbers numbers = numbersExtraction(line);
        vector<string> words = extractWords(line);
        int count = words.size();

        if (count > 0) {
            size_t firstWordPos = line.find(words[0]);
            size_t lastWordPos = line.rfind(words[count - 1]);
            string first, last;
            if (firstWordPos < numbers.firstNumberPos || numbers.firstNumber == -1) {
                first = to_string(wordToNumber(words[0]));
            } else {
                first = to_string(numbers.firstNumber);
            }
            if (lastWordPos > numbers.lastNumberPos || numbers.lastNumber == -1) {
                last = to_string(wordToNumber(words[count - 1]));
            } else {
                last = to_string(numbers.lastNumber);
            }
            string wholeNumber = first + last;
            cout << "Line " << line_number << ": Whole number: " << wholeNumber << endl;
            sum += stoll(wholeNumber);
        } else if (numbers.firstNumber == -1 && numbers.lastNumber == -1) {
            cout << "Line " << line_number << ": No numbers or words found in the line." << endl;
        } else {
            string wholeNumber;
            if (numbers.firstNumber == -1) numbers.firstNumber = 0;
            if (numbers.lastNumber == -1) numbers.lastNumber = 0;
            wholeNumber = to_string(numbers.firstNumber) + to_string(numbers.lastNumber);
            cout << "Line " << line_number << ": Whole number: " << wholeNumber << endl;
            sum += stoll(wholeNumber);
        }
    }

    file.close();
    cout << "Sum of all numbers: " << sum << endl;
    return 0;
}
