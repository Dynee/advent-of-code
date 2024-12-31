#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::string ltrim(const std::string& s) {
	auto start = std::find_if_not(s.begin(), s.end(), [](unsigned char c) { return std::isspace(c); });
	return std::string(start, s.end());
}

std::tuple<std::vector<int>, std::vector<int>> read_input(std::string file_name) {
	std::ifstream inputFile(file_name);

	std::string line;
	std::string delim = " ";

	std::vector<int> left;
	std::vector<int> right;

	if (inputFile.is_open())
	{
		while (std::getline(inputFile, line))
		{
			std::string lNum = line.substr(0, line.find(delim));
			std::string rNum = ltrim(line.substr(line.find(delim), line.size() - 1));
			left.push_back(std::stoi(lNum));
			right.push_back(std::stoi(rNum));
		}
		inputFile.close();
	}

	return {left, right};
}

int get_sum_of_smallest(std::vector<int> left, std::vector<int> right) {
	int total = 0;
	
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	for (int i = 0; i < left.size(); i++) {
		int diff = std::abs(left[i] - right[i]);
		total += diff;
	}
	
	return total;
}

int main() {
	auto [left, right] = read_input("input.txt");	
	
	int total = get_sum_of_smallest(left, right);	

	std::cout << total << "\n";

	return 0;
}
