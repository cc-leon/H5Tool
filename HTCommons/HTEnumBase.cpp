#include "stdafxCommons.h"
#include "HTEnumBase.h"

HTEnumBase::HTEnumBase() {
	_value = 0;
}

HTEnumBase::HTEnumBase(int const input) {
	_value = input;
}

HTEnumBase::HTEnumBase(HTEnumBase const& anotherBase) {
	_value = anotherBase._value;
}

HTEnumBase::~HTEnumBase() {
}

HTEnumBase const HTEnumBase::operator= (int const input) {
	_value = input;
	return *this;
}

HTEnumBase const HTEnumBase::operator= (unsigned char const input) {
	_value = input;
	return *this;
}

HTEnumBase const HTEnumBase::operator= (unsigned int const input) {
	_value = static_cast<int>(input);
	return *this;
}

HTEnumBase const HTEnumBase::operator= (short const input) {
	_value = static_cast<int>(input);
	return *this;
}

HTEnumBase const HTEnumBase::operator= (long const input) {
	_value = static_cast<int>(input);
	return *this;
}

HTEnumBase const HTEnumBase::operator= (unsigned long const input) {
	_value = static_cast<int>(input);
	return *this;
}

HTEnumBase const HTEnumBase::operator= (HTEnumBase const& rightOperand) {
	_value = rightOperand._value;
	return *this;
}

HTEnumBase::operator int() const {
	return static_cast<int>(_value);
}
