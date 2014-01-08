// determine which of the two numbers is bigger one
#include <iostream>

int main()
{
	std::cout << "Give the two numbers please: ";
	int num1 = 0; int num2 = 0;
	std::cin >> num1;
	std::cin >> num2;

	if (num1 > num2)
		std::cout << "First number is bigger than second one." << std::endl;
	else if (num1 < num2)
			std::cout << "Second number is bigger than first one." << std::endl;
		 else
			std::cout << "The numbers are equal." << std::endl;

	return 0;
}
