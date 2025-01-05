#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <sstream>

bool is_valid(const char& c, const char& last) {
    if (c == 'm' && last == 'm') {
        return true;
    }

    if (c == 'u' && last == 'm') {
        return true;
    }

    if (c == 'l' && last == 'u') {
        return true;
    }

    if (c == '(' && last == 'l') {
        return true;
    }

    if (isdigit(c) && (last == '(' || isdigit(last))) {
        return true;
    }

    if (c == ',' && isdigit(last)) {
        return true;
    }

    if (isdigit(c) && last == ',') {
        return true;
    }

    if (c == ')' && isdigit(last)) {
        return true;
    }

    return false;
}

int main() {
    std::cout << "Enter a file: ";
    std::string file_name;
    std::cin >> file_name;

    std::ifstream file(file_name);
    std::string input;

    while (std::getline(file, input)) {
        std::ostringstream oss;

        std::vector<std::string> muls;

        char last = 'm';

        for (int i = 0; i < input.size(); i++) {
            if (is_valid(input[i], last)) {
                oss << input[i];
                last = input[i];

                if (input[i] == ')') {
                    muls.push_back(oss.str());
                    oss.str("");
                    last = 'm';
                }
            } else {
                oss.str("");
                last = 'm';
            }
        }

        for (auto &mul : muls) {
            std::cout << "mul: " << mul << "\n";
        }
    }

    return 0;
}