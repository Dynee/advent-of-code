#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int is_safe(const std::vector<int> &report)
{
	int i = 0;
	int j = 1;
	int res = 0;

	bool is_increasing = false;

	while (j != report.size())
	{
		std::cout << report[i] << " " << report[j] << "\n";
		// increasing
		if (report[i] < report[j])
		{
			if (is_increasing && report[j] < report[i - 1])
			{
				return 0;
			}

			is_increasing = true;
			int diff = report[j] - report[i];

			if (diff > 3)
			{
				std::cout << "not safe" << "\n";
				return 0;
			}
		}
		// decreasing
		else if (report[i] > report[j])
		{
			if (!is_increasing && report[j] > report[i - 1])
			{
				return 0;
			}

			is_increasing = false;
			int diff = report[i] - report[j];
			if (diff > 3)
			{
				std::cout << "not safe" << "\n";
				return 0;
			}
		}
		i++;
		j++;
	}

	std::cout << "safe" << "\n";
	return 1;
}

int solve(std::string file_name)
{
	int safe_report_count = 0;

	std::ifstream inputFile(file_name);

	std::string line;
	std::string delim = " ";

	if (inputFile.is_open())
	{
		while (std::getline(inputFile, line))
		{
			std::cout << "line: " << line << "\n";
			std::vector<int> report;

			for (char &c : line)
			{
				if (c != ' ')
				{
					report.push_back(c - '0');
				}
			}

			// determine if report is safe.
			safe_report_count += is_safe(report);
		}
		inputFile.close();
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
