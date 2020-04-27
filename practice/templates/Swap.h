// Template for swap
// Swap.h
#ifndef swap_h
#define swap_h

template<typename T>
void swap(T& a, T& b) {
	T c;
	c = a;
	a = b;
	b = c;
}

#endif