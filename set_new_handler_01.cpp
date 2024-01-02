#include <new>
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;


struct Nec {
	char buffer[1024];
};

vector<Nec*> nvec;

//void * operator new(size_t n)
//{
//	while (true) {
//		void *vp = malloc(n);
//		if (vp)
//			return vp;
//		auto fptr = get_new_handler();
//		if (!fptr)
//			throw std::bad_alloc{};
//		(*fptr)();
//	}
//}


void mynewhandler()
{
	static int cnt{};
	cout << "ben bellek alani elde etmekten sorumlu fonksiyonum beni " << ++cnt << " .kez cagirdilar....\n";
	cout << "bellek alani elde etmeye calisiyorum...\n";
	_getch();
	if (cnt == 5) {
		cout << "bellek alani elde edemedim.... exception throw ediyorum\n";
		//throw std::bad_alloc{};
		set_new_handler(nullptr);
	}
}


int main()
{
	auto fp = set_new_handler(mynewhandler);

	try {
		while (true) {
			nvec.push_back(new Nec);
		}
	}
	catch (const std::exception& ex) {
		std::cout << "hata yakalandi : " << ex.what() << "\n";
	}
}
