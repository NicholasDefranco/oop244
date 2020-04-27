// Template for Array Classes
// Array.h
#ifndef array_h
#define array_h

template <class T, int N>
class Array {
	T a[N];
public:
	T & operator[](int i) { return a[i]; }
};

#endif