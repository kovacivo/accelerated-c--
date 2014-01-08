#include <iostream>

int main()
{
	std::cout << "Generating the product of the numbers in the range [1, 10)" << std::endl;

	int sum = 0;
	for (int i = 1; i < 10; i++) 
		sum += i;
	std::cout << "the sum is " << sum << "." << std::endl;

	return 0;
}
