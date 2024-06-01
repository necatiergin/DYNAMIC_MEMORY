#include <iostream>

int main()
{
	char buffer[sizeof(int)];
	std::cout << "address is : " << static_cast<void*>(buffer) << '\n';

	int* ip = new (buffer)int;

	std::cout << "address is : " << ip << '\n';
}
