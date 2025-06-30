#include <regex>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
// Define the function that deletes the second binary number
void deleteSecondBinaryNumber(string &str) {
    smatch match;
    regex binaryRegex("\\b[01]+\\b");
    int binaryCount = 0;
    size_t pos = 0;

    while (regex_search(str.cbegin() + pos, str.cend(), match, binaryRegex)) {
        ++binaryCount;
        if (binaryCount == 2) {
            str.erase(match.position(0) + pos, match.length(0));
            break;
        }
        pos += match.position(0) + match.length(0);
    }
}

bool isBinaryNumber(const char* token) {
    for (size_t i = 0; token[i] != '\0'; i++) {
        if (token[i] != '0' && token[i] != '1') {
            return false;
        }
    }
    return true;
}
void findAndProcessBinaryNumbers(const char* str, const char* delimiters) {
    char buffer[256];
    strncpy(buffer, str, sizeof(buffer)); // Создаем копию строки для изменения
    buffer[sizeof(buffer) - 1] = '\0';   // Убеждаемся, что строка завершена

    char* token = strtok(buffer, delimiters);
    cout << "Found by strtol in line 1:" << endl;

    while (token != nullptr) {
        char* end; // Указатель на остаток строки после strtol
        long binaryValue = strtol(token, &end, 2); // Преобразуем токен в число

        // Проверяем, что весь токен был обработан (end указывает на конец токена)
        if (*end == '\0') {
            cout << "Binary: " << token << " -> Dec: " << binaryValue << endl;
        }

        token = strtok(nullptr, delimiters); // Берем следующий токен
    }
}

// Quick sort function
void quickSort(char* arr[], int low, int high) {
    if (low < high) {
        char* pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (strcmp(arr[j], pivot) < 0) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Open the input and output files
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Read the lines from the input file
    char line1[256], line2[256], delimiters[256];
    inputFile.getline(line1, 256);
    inputFile.getline(line2, 256);
    inputFile.getline(delimiters, 256);

    // Split the lines into tokens
    char* tokens1[256], * tokens2[256];
    int count1 = 0, count2 = 0;

    char* token = strtok(line1, delimiters);
    while (token != nullptr) {
        tokens1[count1++] = token;
        token = strtok(nullptr, delimiters);
    }
    outputFile << "L1: " << "\n";
    for (int i = 0; i < count1; ++i) {
        outputFile << tokens1[i] << " ";
    }

    outputFile << "\n";
    token = strtok(line2, delimiters);
    while (token != nullptr) {
        tokens2[count2++] = token;
        token = strtok(nullptr, delimiters);
    }
    outputFile << "L2: " << "\n";
    for (int i = 0; i < count2; ++i) {
        outputFile << tokens2[i] << " ";
    }
    outputFile << "\n";
    // Create a new string with unique tokens from the second line
    char* uniqueTokens[256];
    int uniqueCount = 0;

    for (int i = 0; i < count2; ++i) {
        bool found = false;
        for (int j = 0; j < count1; ++j) {
            if (strcmp(tokens2[i], tokens1[j]) == 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueTokens[uniqueCount++] = tokens2[i];
        }
    }
    outputFile << "Unique tokens: "<<"\n";
    for (int i = 0; i < uniqueCount; ++i) {
        outputFile << uniqueTokens[i] << " ";
    }
    outputFile <<"\n";
    findAndProcessBinaryNumbers(line1, delimiters);
    // Replace binary numbers in the unique tokens with numbers from the first line


    for (int i = 0; i < uniqueCount; ++i) {
        if (isBinaryNumber(uniqueTokens[i])) {
            uniqueTokens[i] = tokens1[0]; // Replace with any number from the first line
        }
    }
    outputFile << "Replaced " <<"\n";
    for (int i = 0; i < uniqueCount; ++i) {
        outputFile << uniqueTokens[i] << " ";
    }
    outputFile <<"\n";
    // Sort the unique tokens using quick sort
    quickSort(uniqueTokens, 0, uniqueCount - 1);

    // Write the sorted unique tokens to the output file
    outputFile << "sorted: " <<"\n";
    for (int i = 0; i < uniqueCount; ++i) {
        outputFile << uniqueTokens[i] << " ";
    }
    outputFile << "\n";

    string str1;
    for (int i = 0; i < count1; ++i) {
        str1.append(tokens1[i]);
        str1.append(" ");
    }
    int N, M;

    cout << "Enter the number to find: ";
    cin >> M;
    cout << "Enter the number to replace with: ";
    cin >> N;

    size_t pos = str1.find(to_string(M));
    while (pos != string::npos) {
        str1.replace(pos, to_string(M).length(), to_string(N));
        pos = str1.find(to_string(M), pos + to_string(N).length());
    }
    outputFile << "String after replacing a number: " << str1 << "\n";
    // Function call to delete second binary number
    deleteSecondBinaryNumber(str1);

    outputFile << "String after deleting second binary number: " << str1 << "\n";


    //convert to c-string using c_str()
    string my_char = str1.c_str();

    //print
    for(int i =0; i<my_char.length();i++)
    {
        cout<< my_char[i];
    }
    cout << "\n";
    cout << str1 << "\n";

    // Close the files
    inputFile.close();
    outputFile.close();

return 0;
}