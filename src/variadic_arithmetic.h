/*
 * variadic_arithmetic.h
 *
 *  Created on: Jan 15, 2016
 *      Author: arun
 */

#ifndef VARIADIC_ARITHMETIC_H_
#define VARIADIC_ARITHMETIC_H_

struct  Sum {
template <class T>
static T sum(T n)
{
	return n;
}

template <class T, class... Args>
static auto sum(T n, Args... args) //-> decltype(n + sum(args...))
{
	return n + sum(args...);
}

};



#endif /* VARIADIC_ARITHMETIC_H_ */
