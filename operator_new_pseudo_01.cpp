class Nec {
	//..
};

int main()
{
	Nec * p = new Nec();
	//pseudo code
	void* praw = operator new(sizeof(Nec));
	//operator new tarafindan gonderilebilecek exception yakalanmiyor
	try {
		p = new(praw) Nec();  // elde edilen adreste ctor. cagriliyor
	}
	catch (...) {
		// ctor exception throw ederse
		operator delete(praw); //bellek alani deallocate ediliyor
		throw;  // exception rethrow ediliyor
	}
}
