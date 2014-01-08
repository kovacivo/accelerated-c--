// no, they are not valid
#include <iostream>
#include <string>

int main()
{

	const std::string exclam = "!";
	const std::string message2 = "hello" + ", world" + exclam;

	std::cout << message2 << std::endl;
	return 0;
}
