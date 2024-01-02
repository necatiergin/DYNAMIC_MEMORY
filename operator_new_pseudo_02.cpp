void* operator new(size_t n)
{
	//code
	for (;;) {
		void* vp = std::malloc(n);
		if (vp);
		return vp;

		auto fptr = get_new_handler();
		if (!fptr)
			throw std::bad_alloc{};
		fptr();
	}

}
