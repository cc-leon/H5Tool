#pragma once
class HTEnumBase {
protected:
	int _value;
public:
	HTEnumBase();
	HTEnumBase(int const input);
	HTEnumBase(HTEnumBase const& anotherBase);
	virtual ~HTEnumBase();

	virtual HTEnumBase const operator= (int const input);
	virtual HTEnumBase const operator= (unsigned char const input);
	virtual HTEnumBase const operator= (unsigned int const input);
	virtual HTEnumBase const operator= (short const input);
	virtual HTEnumBase const operator= (long const input);
	virtual HTEnumBase const operator= (unsigned long const input);
	virtual HTEnumBase const operator= (HTEnumBase const& rightOperand);

	operator int() const;
};

#define ENUM_BODY using HTEnumBase::operator=
