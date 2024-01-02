#include <iostream>

int main()
{
	char buffer[sizeof(int)];
	std::cout << "addess is : " << static_cast<void*>(buffer) << '\n';

	int* ip = new (buffer)int;

	std::cout << "addess is : " << ip << '\n';
}
