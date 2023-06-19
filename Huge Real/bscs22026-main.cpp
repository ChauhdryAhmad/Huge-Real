#include<fstream>
#include<iostream>
#include"bscs22026-HugeReal.h"
using namespace std;

void LoadNumbers(HugeReal*& Allnum, int& size, string fname, int b)
{
	ifstream rdr(fname);
	rdr >> size;
	Allnum = new HugeReal[size];
	for (int i = 0; i < size; i++)
	{
		while (rdr.peek() == '\n' || rdr.peek() == ' ')
			rdr.ignore();
		Allnum[i].base(b);
		rdr >> Allnum[i];
		
	}
}

void InputNumbers(HugeReal*& Allnum, int& size ,int b)
{
	cout << "\nHow many numbers you want to enter : ";
	cin >> size;
	Allnum = new HugeReal[size];
	for (int i = 0; i < size; i++)
	{

		cout << "\nEnter " << i + 1 << " number :\n";
		while (cin.peek() == '\n' || cin.peek() == ' ')
			cin.ignore();
		Allnum[i].base(b);
		cin >> Allnum[i];
		
	}
}

void PrintNumbers(HugeReal* Allnum, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\nn" << i + 1 << " : ";
		cout << Allnum[i];
	}
}


int main()
{
	int ba;
	cout << "Enter Base upto 36 : ";
	cin >> ba;

	/*HugeReal a, b;
	cin >> a >> b;
	cout << a / b;*/




	HugeReal* AllNum;
	HugeReal R;
	int size = 0, ch = 0, n1, n2;
	cout << "\n1-Load\n2-Input\n";
	cin >> ch;
	if (ch == 1)
	{
		LoadNumbers(AllNum, size, "bscs22026-input.txt", ba);
	}
	else
	{
		InputNumbers(AllNum, size, ba);
	}
	cout << "\nNumbers Are :\n";

	PrintNumbers(AllNum, size);
	while (true)
	{
		cout << "\n\nPress 0 to End\nPress 1 to continue\n";
		cin >> ch;
		if (ch == 0)
		{
			break;
		}
		system("cls");
		cout << "Numbers Are :\n";
		PrintNumbers(AllNum, size);
		cout << "\nOperations :\n1- +\n2- -\n3- *\n4- /\n5- +=\n6- -=\n7- *=\n8- /=\n9- <\n10- >\n11- <=\n12- >=\n13- ==\n14- !=\n15 -(Negation)\n16- ++(Pre Increment)\n17- --(Pre Decrement)\n18- ++(Post Increment)\n19- --(Post Decrement)\n20- END\n";
		cin >> ch;
		if (ch >= 15 && ch < 20)
		{
			cout << "\nIt is Unary Operator\nEmter Number( 1 - " << size << " ) : ";
			cin >> n1;
		}
		else
		{
			cout << "\nEnter First Number( 1 - " << size << " ) :";
			cin >> n1;
			cout << "\nEnter Second Number( 1 - " << size << " ) :";
			cin >> n2;
		}
		switch (ch)
		{
		case 1:
			R = AllNum[n1 - 1] + AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " + n" << n2;
			cout << "\nR = " << R;
			break;
		case 2:
			R = AllNum[n1 - 1] - AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " - n" << n2;
			cout << "\nR = " << R;
			break;
		case 3:
			R = AllNum[n1 - 1] * AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " * n" << n2;
			cout << "\nR = " << R;
			break;
		case 4:
			R = AllNum[n1 - 1] / AllNum[n2 - 1];
			cout << "\nR = n" << n1 << " / n" << n2;
			cout << "\nR = " << R;
			break;
		case 5:
			AllNum[n1 - 1] += AllNum[n2 - 1];
			cout << "\nn" << n1 << " += n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 6:
			AllNum[n1 - 1] -= AllNum[n2 - 1];
			cout << "\nn" << n1 << " -= n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 7:
			AllNum[n1 - 1] *= AllNum[n2 - 1];
			cout << "\nn" << n1 << " *= n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 8:
			AllNum[n1 - 1] /= AllNum[n2 - 1];
			cout << "\nn" << n1 << " /= n" << n2;
			cout << "\nn" << n1 << " = " << AllNum[n1 - 1];
			break;
		case 9:
			if (AllNum[n1 - 1] < AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is smaller then n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not smaller then n" << n2;
			break;
		case 10:
			if (AllNum[n1 - 1] > AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is greater then n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not greater then n" << n2;
			break;
		case 11:
			if (AllNum[n1 - 1] <= AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is smaller then and equal to n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not smaller then and equal to n" << n2;
			break;
		case 12:
			if (AllNum[n1 - 1] >= AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is greater then and equal to n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not greater then and equal to n" << n2;
			break;
		case 13:
			if (AllNum[n1 - 1] == AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is equal to n" << n2;
			}
			else
				cout << "\nn" << n1 << " is not equal to n" << n2;
			break;
		case 14:
			if (AllNum[n1 - 1] != AllNum[n2 - 1])
			{
				cout << "\nn" << n1 << " is not equal to n" << n2;
			}
			else
				cout << "\nn" << n1 << " is equal to n" << n2;
			break;
		case 15:
			R = -AllNum[n1 - 1];
			cout << "\nR = -n" << n1;
			cout << "\nR = " << R;
			break;
		case 16:
			R = ++AllNum[n1 - 1];
			cout << "\nR = ++n" << n1;
			cout << "\nR = " << R;
			break;
		case 17:
			R = --AllNum[n1 - 1];
			cout << "\nR = --n" << n1;
			cout << "\nR = " << R;
			break;
		case 18:
			R = AllNum[n1 - 1]++;
			cout << "\nR = n++" << n1;
			cout << "\nR = " << R;
			break;
		case 19:
			R = AllNum[n1 - 1]--;
			cout << "\nR = n--" << n1;
			cout << "\nR = " << R;
			break;
		default:
			break;
		}
		if (ch == 20)
		{
			break;
		}
	}
	return 0;
}