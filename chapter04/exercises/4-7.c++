// write a program to calculate the average of the numbers stored in a vector<double>

#include <iostream>
#include <vector>

int main()
{
	std::cout << "Give the numbers you want to know the average ending with EOF." << std::endl;
	std::vector<double> numbers;
	double number = 0.0;
	double sum = 0.0;
	while(std::cin >> number) {
		numbers.push_back(number);
		sum += number;
	}

	std::cout << "The average of " << numbers.size() << " numbers was " << sum / numbers.size() << "." << std::endl;

	return 0;
}
