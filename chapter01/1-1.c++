// yes, they are valid
#include <iostream>
#include <string>

int main()
{

	const std::string hello = "hello";
	const std::string message = hello + ", world!" + "!";

	std::cout << message << std::endl;

	return 0;
}
