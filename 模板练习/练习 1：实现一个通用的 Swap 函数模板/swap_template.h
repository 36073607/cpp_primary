#pragma once

template<typename T>
void swapValues(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

