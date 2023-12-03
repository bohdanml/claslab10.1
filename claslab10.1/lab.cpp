#include <iostream>
#include <fstream>
#include <cstring>

int Count(const char* str) {
    int k = 0;
    int len = strlen(str);

    for (int i = 0; i < len - 1; ++i) {
        if (str[i] == 'n' && str[i + 1] == 'o') {
            ++k;
        }
    }

    return k;
}

char* Change(const char* str) {
    int len = strlen(str);
    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';

    for (int i = 0; i < len; ++i) {
        if (i < len - 2 && str[i] == 'n' && str[i + 1] == 'o') {
            strncat_s(t, len * 2 + 1 - strlen(t), "**", 2);
            t += 2;
            ++i;
        }
        else {
            *t++ = str[i];
            *t = '\0';
        }
    }

    return tmp;
}

bool CheckCondition(const char* str, int i, int j) {
    int len = strlen(str);
    return (j > 0 && j < len - 1 && str[j - 1] == 'n' && str[j + 1] == 'o');
}

int main() {
    const int maxInputSize = 100;
    char input[maxInputSize];

    std::cout << "Enter the filename: " << std::endl;
    std::cin.getline(input, maxInputSize);

    std::ifstream file(input);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int line_number = 0;

    while (file.getline(input, maxInputSize)) {
        ++line_number;

        int count = Count(input);
        std::cout << "Line " << line_number << ": The count of occurrences of the pattern 'no': " << count << std::endl;

        char* dest = Change(input);
        std::cout << "Line " << line_number << ": Modified string (result): " << dest << std::endl;

        for (int j = 0; j < strlen(dest); ++j) {
            if (CheckCondition(dest, line_number, j)) {
                std::cout << "Condition met at line " << line_number << ", position " << j << std::endl;
            }
        }


    }

    file.close();

    return 0;
}