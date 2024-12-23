#include <iostream>
#include <new>
#include <vector>

std::vector<int*> pvec;

void func()
{
	for (int i = 0; i < 1000; ++i) {
		if (auto p = new(std::nothrow)int[1'000'000]) {
			pvec.push_back(p);
			std::cout << '.';
		}
		else {
			std::cout << "\nallocation failed\n";
			break;
		}
	}

	std::cout << "pvec.size() " << pvec.size() << '\n';
	for (auto p : pvec) {
		operator delete(p, std::nothrow);
	}
}


int main()
{
	func();
}
