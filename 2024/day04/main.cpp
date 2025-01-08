#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::string file_name = "day04-default-input.txt";
  std::ifstream file(file_name);

  std::string line;

  std::vector<std::vector<char>> rows;

  while (std::getline(file, line)) {
    std::vector<char> row;
    for (int i = 0; i < line.size(); i++) {
      row.push_back(line[i]);
    }
    rows.push_back(row);
  }

  int n = 4;

  int sum = 0;

  for (int i = 0; i < rows.size(); i++) {
    std::cout << "row: " << i << "\n";
    for (int j = 0; j < rows[i].size(); j++) {
      std::string right_horizontal = "";
      std::string left_horizontal = "";
      std::string left_diagonal = "";
      std::string vertical = "";
      std::string right_diagonal = "";
      std::string top_left_diagonal = "";

      for (int k = 0; k < n; k++) {
        // the horizontal
        std::cout << rows[i][k + j];
        right_horizontal += rows[i][k + j];
      }

      if (right_horizontal == "XMAS" || right_horizontal == "SAMX") {
        sum++;
      }

      std::cout << "\n";

      if (rows.size() - i >= n) {
        for (int l = 0; l < n; l++) {
          // the right diagonal
          std::cout << rows[i + l][j + l];
          right_diagonal += rows[i + l][j + l];
        }

        if (right_diagonal == "XMAS" || right_horizontal == "SAMX") {
          sum++;
        }

        std::cout << "\n";

        for (int m = 0; m < n; m++) {
          // The vertical
          std::cout << rows[i + m][j];
          vertical += rows[i + m][j];
        }
        std::cout << "\n";
        if (vertical == "XMAS" || vertical == "SAMX") {
          sum++;
        }

        for (int o = 0; o < n; o++) {
          // the left diagonal
          std::cout << rows[i + o][j - o];
          left_diagonal += rows[i + o][j - o];
        }
        if (left_diagonal == "XMAS" || left_diagonal == "SAMX") {
          sum++;
        }
      }

      std::cout << "\n";

      for (int p = 0; p < n; p++) {
        // the left horizontal
        std::cout << rows[i][j - p];
        left_horizontal += rows[i][j - p];
      }
      if (left_horizontal == "XMAS" || left_horizontal == "SAMX") {
        sum++;
      }

      std::cout << "\n";
    }
    std::cout << "\n";
  }

  std::cout << "answer: " << sum << "\n";

  return 0;
}
