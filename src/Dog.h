/*
 * Dog.h
 *
 *  Created on: Jan 15, 2016
 *      Author: arun
 */

#ifndef DOG_H_
#define DOG_H_

namespace Sandbox {

class Dog {
	int m_age;
	double m_weight;
public:
	Dog() = default;
	Dog(int age, double weight) : m_age(age), m_weight(weight) {}
	virtual ~Dog();
};

} /* namespace Sandbox */

#endif /* DOG_H_ */
