#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


int is_safe(const std::vector<int> &report)
{
	int i = 0;
	int j = 1;

	std::vector<int> order;

	while (j != report.size()) {
		if (report[i] > report[j]) {
			int diff = report[i] - report[j];
			if (diff > 3 || diff == 0) return 0;
			order.push_back(1);
		} else if (report[i] < report[j]) {
			int diff = report[j] - report[i];
			if (diff > 3 || diff == 0) return 0;
			order.push_back(0);
		} else {
			return 0;
		}
		i++;
		j++;
	}

	// The vector should contain all 0's or all 1's.
	if (order.empty()) return 0;

	for (size_t v = 0; v < order.size(); v++) {
		if (order[v] != order[0]) return 0;
	}

	return 1;
}

std::vector<std::string> split(const std::string& str, const char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::stringstream ss(str);

	while (std::getline(ss, token, delimiter)) {
		tokens.push_back(token);
	}

	return tokens;
}

int solve(const std::string& file_name)
{
	int safe_report_count = 0;

	std::ifstream file(file_name);

	if (!file.is_open())
		return -1;

	std::string line;

	while (std::getline(file, line)) {
		std::cout << line << "\n";
		std::vector<std::string> tokens = split(line, ' ');

		std::vector<int> report;

		report.reserve(tokens.size());

		for (auto &c : tokens) {
			std::cout << c << "\n";
			report.push_back(std::stoi(c));
		}

		int safe_count = is_safe(report);
		std::cout << "safe: " << safe_count << "\n";
		safe_report_count += safe_count;
	}

	return safe_report_count;
}

int main()
{
	std::string file_name;
	std::cout << "Enter file name: ";
	std::cin >> file_name;

	int result = solve(file_name);
	std::cout << "answer: " << result << "\n";

	return 0;
}
