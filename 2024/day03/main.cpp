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

int product_of_mul(const std::string& mul) {
    std::cout << "mul: " << mul << "\n";
    int product = 0;
    std::string leftStr = "";
    std::string rightStr = "";
    bool seen_separator = false;

    for (int i = 0; i < mul.size(); i++) {
        if (isdigit(mul[i]) && seen_separator) {
            std::cout << "right: " << mul[i] << "\n";
            rightStr += mul[i];
        } else if (mul[i] == ',') {
            std::cout << "seen separator\n";
            seen_separator = true;
        }
        else if (isdigit(mul[i])) {
            std::cout << "left: " << mul[i] << "\n";
            leftStr += mul[i];
        }
    }

    std::cout << "left: " << leftStr << " right: " << rightStr << "\n";
    if (rightStr == "") {
        return 0;
    }
    product = std::stoi(leftStr) * std::stoi(rightStr);
    return product;
}

int main() {
    std::cout << "Enter a file: ";
    std::string file_name;
    std::cin >> file_name;

    std::ifstream file(file_name);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string input = buffer.str();

    std::ofstream out("output.txt");

    std::cout << "input size: " << input.size() << "\n";
    std::ostringstream oss;

    std::vector<std::string> muls;

    char last = 'm';

    for (auto i = 0; i < input.size(); i++) {
        if (is_valid(input[i], last)) {
            oss << input[i];
            last = input[i];

            if (input[i] == ')') {
                muls.push_back(oss.str());
                oss.str("");
                oss.clear();
                last = 'm';
            }
        } else {
            oss.str("");
            oss.clear();
            last = 'm';
        }
    }

    long sum = 0;

    for (auto &mul : muls) {
        out << mul << "\n";
        sum += product_of_mul(mul);
    }

    std::cout << "answer: " << sum << "\n";

    return 0;
}