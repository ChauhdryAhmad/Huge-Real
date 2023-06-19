#pragma once
#include<fstream>
using namespace std;

class HugeReal
{
private:
	int size;
	int* Vs;
	int pLoc;
	int dptr;
	bool isNeg;
	int b;
	void assign(const HugeReal&);
	const HugeReal AddQuantity(const HugeReal&)const;
	const HugeReal SubQuantity(const HugeReal&)const;
	bool GreaterQuantity(const HugeReal&)const;
	bool LesserQuantity(const HugeReal&)const;
	bool EqualQuantity(const HugeReal&)const;
	void trim();
	const HugeReal flipArr(const HugeReal&);
	static HugeReal one();
	static HugeReal zero();
public:
	HugeReal();
	HugeReal(int s);
	HugeReal(const HugeReal&);
	HugeReal(ifstream&);
	void load(ifstream&);
	void print();
	
	void base(int base);

	friend ostream& operator<<(ostream&, const HugeReal&);
	friend istream& operator>>(istream&, HugeReal&);
	friend ifstream& operator>>(ifstream&, HugeReal&);

	HugeReal operator=(const HugeReal&);
	int& operator[](int i);
	int operator[](int i)const;

	const HugeReal operator-();
	const HugeReal operator+(const HugeReal&)const;
	const HugeReal operator+=(const HugeReal&);
	const HugeReal operator-(HugeReal&)const;
	const HugeReal operator-=(HugeReal&);

	bool operator>(const HugeReal&)const;
	bool operator>=(const HugeReal&)const;
	bool operator<(const HugeReal&)const;
	bool operator<=(const HugeReal&)const;
	bool operator==(const HugeReal&)const;
	bool operator!=(const HugeReal&)const;

	HugeReal operator++();
	HugeReal operator--();
	HugeReal operator++(int d);
	HugeReal operator--(int d);

	bool isNum(const HugeReal&)const;

	HugeReal operator*(const HugeReal&)const;
	const HugeReal operator*=(HugeReal&);
	HugeReal operator/(const HugeReal&)const;
	const HugeReal operator/=(HugeReal&);






};

