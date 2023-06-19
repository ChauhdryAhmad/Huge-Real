#include "bscs22026-HugeReal.h"
#include<string>
#include<iostream>
using namespace std;

void HugeReal::assign(const HugeReal& R)
{
	size = R.size;
	Vs = new int[size];
	for (int i = 0; i < size; i++)
	{
		Vs[i] = R.Vs[i];
	}
	pLoc = R.pLoc;
	isNeg = R.isNeg;
	dptr = R.dptr;
	//b = R.b;
}

void HugeReal::base(int ba)
{
	b = ba;
}

HugeReal::HugeReal()
{
	size = 0;
	Vs = nullptr;
	pLoc = 0;
	isNeg = false;
	dptr = 0;
}

HugeReal::HugeReal(int s)
{
	size = s;
	Vs = new int[size]{};
	pLoc = 0;
	isNeg = false;
	dptr = 0;
}

HugeReal::HugeReal(const HugeReal& R)
{
	this->assign(R);
}

HugeReal::HugeReal(ifstream& rdr)
{
	this->load(rdr);
}

void HugeReal::load(ifstream& rdr)
{


	rdr >> (*this);


	//if (rdr.peek() == '-')
	//{
	//	rdr.ignore();
	//	isneg = true;
	//}
	//else
	//{
	//	isneg = false;
	//}
	//string aline;
	//getline(rdr, aline);
	//bool findpoint = false;
	//for (int i = 0; i < aline.size(); i++)
	//{
	//	if (aline[i] == '.')
	//	{
	//		findpoint = true;
	//		ploc = i;
	//		break;
	//	}
	//}
	//if (findpoint)
	//{
	//	size = aline.size() - 1;
	//}
	//else
	//{
	//	size = aline.size();
	//	ploc = size;
	//}
	//size = aline.size() - 1;
	//vs = new int[size];
	//ploc = 0;
	//int a = 0;

	//for (int i = size - 1; i >= 0; i--)
	//{
	//	/*if (aline[a] == '.')
	//	{
	//		findpoint = true;
	//		a++;
	//		i++;
	//		continue;
	//	}
	//	else
	//	{*/
	//		if (aline[a] >= '0' && aline[a] <= '9')
	//		{
	//			vs[i] = aline[a] - '0';
	//			a++;
	//		}
	//		else if (aline[a] >= 'a' && aline[a] <= 'z')
	//		{
	//			vs[i] = aline[a] - 'a';
	//			vs[i] += 10;
	//			a++;
	//		}
	//		else
	//		{
	//			a++;
	//			i--;
	//		}
	//	/*}
	//	if (!findpoint)
	//	{
	//		ploc++;
	//	}*/
	//}
	///*if (!findpoint)
	//{
	//	ploc = size;
	//}*/
}

ifstream& operator>>(ifstream& rdr, HugeReal& H)
{
	if (rdr.peek() == '-')
	{
		rdr.ignore();
		H.isNeg = true;
	}
	else
	{
		H.isNeg = false;
	}
	string aline;
	getline(rdr, aline);
	bool findPoint = false;
	for (int i = 0; i < aline.size(); i++)
	{
		if (aline[i] == '.')
		{
			findPoint = true;
			H.pLoc = i;
			break;
		}
	}
	if (findPoint)
	{
		H.size = aline.size() - 1;
	}
	else
	{
		H.size = aline.size();
		H.pLoc = H.size;
	}
	
	H.Vs = new int[H.size];
	H.dptr = H.size - H.pLoc;
	int a = 0;

	for (int i = H.size - 1; i >= 0; i--)
	{
		/*if (aline[i] - '0' >= H.b)
		{
			cout << "BSDK";
			exit(1);
		}*/
		if (aline[a] >= '0' && aline[a] <= '9')
		{
			H.Vs[i] = aline[a] - '0';
			a++;
		}
		else if (aline[a] >= 'A' && aline[a] <= 'Z')
		{
			H.Vs[i] = aline[a] - 'A';
			H.Vs[i] += 10;
			a++;
		}
		else
		{
			a++;
			i++;
		}

		
	}
	
	return rdr;
}

void HugeReal::print()
{
	if (isNeg)
		cout << "-";
	else
		cout << "+";
	int a = 0;
	if (pLoc == 0)
	{
		cout << "0.";
	}
	char s;
	for (int i = size - 1; i >= 0; i--)
	{
		
		if (Vs[i] >= 10)
		{
			s = Vs[i] + 55;
			cout << s;
		}
		else
			cout << Vs[i];
		if (pLoc != size)
		{
			a++;
			if (a == pLoc)
				cout << '.';
		}
	}
}

ostream& operator<<(ostream& cout, const HugeReal& H)
{
	if (H.isNeg)
		cout << "-";
	else
		cout << "+";
	int a = 0;
	if (H.pLoc == 0)
	{
		cout << "0.";
	}
	char s;
	for (int i = H.size - 1; i >= 0; i--)
	{

		if (H.Vs[i] >= 10)
		{
			s = H.Vs[i] + 55;
			cout << s;
		}
		else
			cout << H.Vs[i];
		if (H.pLoc != H.size)
		{
			a++;
			if (a == H.pLoc)
				cout << '.';
		}
	}
	return cout;
}

istream& operator>>(istream& cin, HugeReal& H)
{
	string aline;
	getline(cin,aline);
	
	if (cin.peek() == '-')
	{
		H.isNeg = true;
		cin.ignore();
	}
	else
	{
		H.isNeg = false;
	}
	
	bool findPoint = false;
	for (int i = 0; i < aline.size(); i++)
	{
		if (aline[i] == '.')
		{
			findPoint = true;
			H.pLoc = i;
			break;
		}
	}
	if (findPoint)
	{
		H.size = aline.size() - 1;
	}
	else
	{
		H.size = aline.size();
		H.pLoc = H.size;
	}
	H.dptr = H.size - H.pLoc;
	H.Vs = new int[H.size];
	//H.pLoc = 0;
	int a = 0;
	//bool findPoint = false;

	for (int i = H.size - 1; i >= 0; i--)
	{
		if (aline[i] - '0' >= H.b)
		{
			cout << "Wrong";
			exit(1);
		}
		if (aline[a] >= '0' && aline[a] <= '9')
		{
			H.Vs[i] = aline[a] - '0';
			a++;
		}
		else if (aline[a] >= 'A' && aline[a] <= 'Z')
		{
			H.Vs[i] = aline[a] - 'A';
			H.Vs[i] += 10;
			a++;
		}
		else
		{
			a++;
			i++;
		}
		
	}
	return cin;
}

HugeReal HugeReal::operator=(const HugeReal& H)
{
	if (this == &H)
		return *this;
	delete[]Vs;
	this->assign(H);
	return *this;
}

int& HugeReal::operator[](int i)
{
	return this->Vs[i];
}

int HugeReal::operator[](int i)const
{
	if (i >= size || i < 0)
		return 0;
	return this->Vs[i];
}

const HugeReal HugeReal::flipArr(const HugeReal& H)
{
	HugeReal R = H;
	for (int i = 0; i < H.size; i++)
	{
		R.Vs[i] = H.Vs[H.size - i - 1];
	}
	return R;
}

const HugeReal HugeReal::AddQuantity(const HugeReal& H)const
{
	int mp = max(pLoc, H.pLoc);
	int md = max(dptr, H.dptr);
	HugeReal R(mp + md + 1);
	
	int diff = dptr - H.dptr;
	//diff++;
	int a = 0;
	int carry = 0, ans = 0;
	if (diff < 0)
	{
		diff *= -1;
		for (int i = 0; i < R.size; i++)
		{
			if ((*this)[a - diff] < 10 && H[a] < 10)
			{
				ans = ((*this)[a - diff] + H[a] + carry);
				ans = ans % this->b;
				carry = ((*this)[a - diff] + H[a] + carry) / this->b;
			}
			else
			{
				ans = ((*this)[a - diff] + H[a] + carry);
				ans = ans % this->b;
				carry = ((*this)[a - diff] + H[a] + carry) / this->b;
			}
			R[i] = ans;
			a++;
		}
	}
	else
	{
		for (int i = 0; i < R.size; i++)
		{
			if ((*this)[a] < 10 && H[a - diff] < 10)
			{
				ans = ((*this)[a] + H[a - diff] + carry);
				ans = ans % this->b;
				carry = ((*this)[a] + H[a - diff] + carry) / this->b;
			}
			else
			{
				ans = ((*this)[a] + H[a - diff] + carry);
				ans = ans % this->b;
				carry = ((*this)[a] + H[a - diff] + carry) / this->b;
			}
			R[i] = ans;
			a++;
		}
	}
	int maxi = max(dptr, H.dptr);
	R.pLoc = abs(R.size - maxi);
	R.trim();

	return R;


}

const HugeReal HugeReal::SubQuantity(const HugeReal& H)const
{
	int mp = max(pLoc, H.pLoc);
	int md = max(dptr, H.dptr);
	HugeReal R(mp + md + 1);

	int diff = dptr - H.dptr;
	
	//diff++;
	int a = 0;
	int carry = 0, ans = 0;
	int n = 0;
	if (diff < 0)
	{
		diff *= -1;
		for (int i = 0; i < R.size; i++)
		{
			if ((*this)[a - diff] < 10 && H[a] < 10)
			{
				n = (*this)[a - diff] - carry;
				if ((*this)[a - diff] < H[a])
				{
					carry = 1;
					ans = (b + n) - H[a];
				}
				else
				{
					ans = n - H[a];
					carry = 0;
				}
			}
			else
			{
				n = (*this).Vs[a - diff] - carry;
				if ((*this)[a - diff] < H[a])
				{
					carry = 1;
					ans = (b + n) - H[a];
				}
				else
				{
					ans = n - H[a];
					carry = 0;
				}
			}
			R[i] = ans;
			a++;
		}
	}
	else
	{
		for (int i = 0; i < R.size; i++)
		{
			if ((*this)[a] < 10 && H[a - diff] < 10)
			{
				n = (*this)[a] - carry;
				if ((*this)[a] < H[a - diff])
				{
					carry = 1;
					ans = (10 + n) - H[a - diff];
				}
				else
				{
					ans = n - H[a - diff];
					carry = 0;
				}
			}
			else
			{
				(*this).Vs[a] -= carry;
				if ((*this)[a] < H[a - diff])
				{
					carry = 1;
					ans = (36 + (*this)[a]) - H[a - diff];
				}
				else
				{
					ans = (*this)[a] - H[a - diff];
					carry = 0;
				}
			}
			R[i] = ans;
			a++;
		}
	}
	int maxi = max(dptr, H.dptr);
	R.pLoc = abs(R.size - maxi);
	R.trim();
	return R;
}

bool HugeReal::GreaterQuantity(const HugeReal& H)const
{
	HugeReal c1, c2;
	c1 = *this; c2 = H;
	c1.trim();
	c2.trim();
	int si = max(c1.size, c2.size);
	if (c1.pLoc > c2.pLoc)
	{
		return true;
	}
	if (c1.pLoc < c2.pLoc)
	{
		return false;
	}
	int a = c1.size - 1, b = c2.size - 1;
	for (int i = si - 1; i >= 0; i--)
	{
		if (c1.Vs[a] > c2.Vs[b])
			return true;
		if (c1.Vs[a] < c2.Vs[b])
			return false;
		a--;
		b--;
	}
	return false;
}

bool HugeReal::LesserQuantity(const HugeReal& H)const
{
	HugeReal c1, c2;
	c1 = *this; c2 = H;
	c1.trim();
	c2.trim();
	int si = max(c1.size, c2.size);
	if (c1.pLoc < c2.pLoc)
	{
		return true;
	}
	if (c1.pLoc > c2.pLoc)
	{
		return false;
	}
	int a = c1.size - 1, b = c2.size - 1;
	for (int i = si - 1; i >= 0; i--)
	{
		if (c1.Vs[a] < c2.Vs[b])
			return true;
		if (c1.Vs[a] > c2.Vs[b])
			return false;
		a--;
		b--;
	}
	return false;
}

bool HugeReal::EqualQuantity(const HugeReal& H)const
{
	if (this->GreaterQuantity(H) || this->LesserQuantity(H))
		return false;
	return true;
}

void extractFromEnd(int*& Vs, int& size)
{
	int* Hp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		Hp[i] = Vs[i];
	}
	delete[]Vs;
	Vs = Hp;
	size--;
}

void HugeReal::trim()
{
	int a = 0;
	for (int i = size - 1; i >= pLoc - 1; i--)
	{
		if (size == pLoc)
		{
			a = 1;
		}
		if (Vs[i] != 0)
		{
			break;
		}
		extractFromEnd(Vs, size);
		pLoc--;
		if (a == 1 && pLoc == 1)
		{
			break;
		}
	}
	HugeReal fp;
	*this = this->flipArr(*this);
	for (int i = size - 1; i > pLoc - 1; i--)
	{
		if (size == pLoc)
		{
			a = 1;
		}
		if (Vs[i] != 0)
		{
			break;
		}
		extractFromEnd(Vs, size);
		dptr--;
		if (a == 1 && pLoc == 1)
		{
			break;
		}
	}
	*this = this->flipArr(*this);

}

HugeReal HugeReal::one()
{
	HugeReal R(1);
	R.Vs[0] = 1;
	R.pLoc = 1;
	R.dptr = 0;
	R.isNeg = false;
	R.b = 10;
	return R;
}

HugeReal HugeReal::zero()
{
	HugeReal R(1);
	R.Vs[0] = 0;
	R.pLoc = 1;
	R.dptr = 0;
	R.isNeg = false;
	return R;
}

const HugeReal HugeReal::operator-()
{
	HugeReal R = *this;
	R.isNeg = !isNeg;
	return R;
}

const HugeReal HugeReal::operator+(const HugeReal& H)const
{
	HugeReal R;
	if (isNeg == H.isNeg)
	{
		if (this->GreaterQuantity(H))
		{
			R = this->AddQuantity(H);
			R.isNeg = isNeg;
		}
		else if (this->LesserQuantity(H))
		{
			R = H.AddQuantity(*this);
			R.isNeg = H.isNeg;
		}
		else
		{
			R = H.AddQuantity(*this);
			R.isNeg = isNeg;
		}
	}
	else
	{
		if (this->GreaterQuantity(H))
		{
			R = this->SubQuantity(H);
			R.isNeg = isNeg;
		}
		else if(this->LesserQuantity(H))
		{
			R = H.SubQuantity(*this);
			R.isNeg = H.isNeg;
		}
		else
		{
			R = this->SubQuantity(H);
			R.isNeg = isNeg;
		}
	}
	return R;
}

const HugeReal HugeReal::operator+=(const HugeReal& H)
{
	*this = *this + H;
	return *this;
}

const HugeReal HugeReal::operator-(HugeReal& H)const
{
	HugeReal R;
	R = *this + (-H);
	return R;
}

const HugeReal HugeReal::operator-=(HugeReal& H)
{
	*this = *this - H;
	return *this;
}

bool HugeReal::operator>(const HugeReal& H)const
{
	if (isNeg == H.isNeg)
	{
		if (!isNeg)
		{
			if (this->GreaterQuantity(H))
				return true;
			else
				return false;
		}
		else
		{
			if (this->LesserQuantity(H))
				return true;
			else
				return false;
		}
	}
	else
	{
		if (!isNeg)
			return true;
		else
			return false;
	}
	return false;
}

bool HugeReal::operator>=(const HugeReal& H)const
{
	if ((*this > H) || (*this == H))
		return true;
	return false;
}

bool HugeReal::operator<(const HugeReal& H)const
{
	if (*this == H)
		return false;
	if (H > *this)
		return true;
	return false;
}

bool HugeReal::operator<=(const HugeReal& H)const
{
	if ((*this < H) || (*this == H))
		return true;
	return false;
}

bool HugeReal::operator==(const HugeReal& H)const
{
	if (isNeg == H.isNeg)
	{
		if (this->EqualQuantity(H))
			return true;
		else
			return false;
	}
	return false;
}

bool HugeReal::operator!=(const HugeReal& H)const
{
	if (*this == H)
		return false;
	return true;
}

HugeReal HugeReal::operator++()
{
	*this += HugeReal::one();
	return *this;
}

HugeReal HugeReal::operator--()
{
	HugeReal R;
	R = this->one();
	*this = *this - R;
	return *this;
}

HugeReal HugeReal::operator++(int d)
{
	HugeReal R;
	R = *this;
	*this += HugeReal::one();
	return R;
}

HugeReal HugeReal::operator--(int d)
{
	HugeReal R, r;
	r = this->one();
	R = *this;
	*this -= r;
	return R;
}

HugeReal HugeReal::operator*(const HugeReal& H)const
{
	HugeReal T, A, B, R, f, count;
	R.base(b);
	T.base(b);
	f.base(b);
	count = this->one();
	count.base(10);
	//T = this->zero();
	A = *this;
	A.isNeg = false;
	A.pLoc = A.size;
	A.dptr = 0;

	B = H;
	B.isNeg = false;
	B.pLoc = B.size;
	B.dptr = 0;

	f = this->zero();
	while (B != f)
	{
		R = A; count = this->one();
		while ((count + count) <= B)
		{
			R += R;
			count += count;
		}
		T += R; B -= count;
	}
	if (this->isNeg == H.isNeg)
		T.isNeg = false;
	else
		T.isNeg = true;
	T.pLoc = T.size - (dptr + H.dptr);
	T.dptr = T.size - T.pLoc;
	if (T.pLoc < 0)
	{
		HugeReal Temp((dptr + H.dptr) + 1);
		for (int i = 0; i < T.size; i++)
		{
			Temp[i] = T[i];
		}
		Temp.pLoc = Temp.size - (dptr + H.dptr);
		Temp.dptr = Temp.size - Temp.pLoc;
		return Temp;
	}
	return T;
}

const HugeReal HugeReal::operator*=(HugeReal& H)
{
	*this = *this * H;
	return *this;
}

bool HugeReal::isNum(const HugeReal& H)const
{
	HugeReal F = H;
	F.trim();
	for (int i = 1; i < F.size; i--)
	{
		if (F.Vs[i] != 0)
			return false;
	}
	return true;
}

HugeReal HugeReal::operator/(const HugeReal& H)const
{
	HugeReal T, A, B, R, f, count, ten(2);
	T.base(b);
	R.base(b);
	f.base(b);
	count.base(10);
	ten.base(b);
	ten.Vs[0] = 0;
	ten.Vs[1] = 1;
	count = this->one();
	if (*this == H)
	{
		return count;
	}
	T = this->zero();
	A = *this;
	A.pLoc = A.size;
	A.isNeg = false;
	A.dptr = 0;
	A.b = b;
	B = H;
	B.isNeg = false;
	B.b = b;
	B.pLoc = B.size;
	B.dptr = 0;
	f = this->zero();
	int c = 0;
	while (c <= 10 && A != f)
	{
		R = B; count = this->one();
		while (R + R <= A )
		{
			R += R;
			count += count;
		}
		if (A > B)
		{
			T += count;
			A -= R;
			c++;

		}
		else
		{
			T *= ten;
			A *= ten;
		}
	}
	if (this->isNeg == H.isNeg)
		T.isNeg = false;
	else
		T.isNeg = true;
	T.pLoc = abs(pLoc-H.pLoc+1);
	T.dptr = T.size - T.pLoc;
	if (isNum(*this) && isNum(H))
	{
		if (*this > H)
		{
			HugeReal C((*this).dptr);
			C.base(b);
			for (int i = 0; i < C.size; i++)
			{
				C.Vs[C.size - 1 - i] = (*this).Vs[i];
			}
			C.pLoc = C.size;
			C.dptr = 0;
			C.isNeg = T.isNeg;
			return C;
		}
		else
		{
			HugeReal C(this->dptr - H.dptr + 1);
			C.base(b);

			for (int i = 0; i < C.size; i++)
			{
				C.Vs[i] = (*this).Vs[i];
			}
			C.pLoc = 1;
			C.dptr = C.size - C.pLoc;
			C.isNeg = T.isNeg;
			return C;
		}
	}
	//else if (this->pLoc == 1 || H.pLoc == 1)
	//{
	//	if (this->pLoc == 1 && this->Vs[this->size - 1] == 0)
	//	{
	//		T.pLoc = this->pLoc + H.pLoc;
	//	}
	//	if (H.pLoc == 1 && H.Vs[H.size - 1] == 0)
	//	{
	//		T.pLoc = this->pLoc + H.pLoc;
	//	}
	//	T.pLoc -= 1;
	//	T.dptr += 1;
	//}
	else if (*this < H)
	{
		HugeReal Temp(T.size + H.dptr);
		Temp.base(b);

		for (int i = Temp.size - 1; i > Temp.size - 1 - H.dptr; i--)
		{
			Temp.Vs[i] = T.Vs[i];
		}
		for (int i = Temp.size - 1 - H.dptr; i >= 0; i--)
		{
			Temp.Vs[i] = 0;

		}
		Temp.pLoc = 1;
		Temp.dptr = Temp.size - Temp.pLoc;
		Temp.isNeg = T.isNeg;
		//Temp.trim();
		return Temp;
	}
	T.trim();
	return T;
}

const HugeReal HugeReal::operator/=(HugeReal& H)
{
	*this = *this / H;
	return *this;
}











