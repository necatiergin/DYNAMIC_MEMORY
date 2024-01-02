#include <iostream>
#include <new>

class Nec {
public:
	void* operator new(size_t n) //static member function
	{
		std::cout << "Nec::operator::new(size_t n) n = " << n << '\n';
		void* vp = std::malloc(n);
		if (!vp) {
			throw std::bad_alloc{};
		}
		std::cout << "address of allocated block : " << vp << '\n';
		return vp;
	}

	void operator delete(void* vp) //static member function
	{
		std::cout << "Nec::operator delete(void *p) " << vp << '\n';
		std::free(vp);
	}

};

int main()
{
	Nec* p1 = ::new Nec;
	::delete p1;

	Nec* p2 = new Nec;
	delete p2;
}
