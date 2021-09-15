// equation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string simplification(double num, double den)
{
	if (num / den == round(num / den))
	{
		return to_string(static_cast<int>(num / den));
	}
	else if (num != round(num) || den != round(den))
	{
		return to_string(num / den) + "(~" + to_string(round(num / den)) + ")";
	}
	else
	{
		double MKD;
		int x = num;
		int y = den;
		for (int i = 0; i >= 0; i++)
		{
			if (x == 0)
			{
				MKD = abs(y);
				break;
			}
			else if (y == 0)
			{
				MKD = abs(x);
				break;
			}
			else if (abs(x) > abs(y))
			{
				x %= abs(y);
			}
			else if (abs(x) < abs(y))
			{
				y %= abs(x);
			}
		}
		if (num < 0 && den < 0) return to_string(static_cast<int>(-num / MKD)) + "/" + to_string(static_cast<int>(-den / MKD));
		else if (num > 0 && den > 0) return to_string(static_cast<int>(num / MKD)) + "/" + to_string(static_cast<int>(den / MKD));
		else return "-" + to_string(static_cast<int>(abs(num) / MKD)) + "/" + to_string(static_cast<int>(abs(den) / MKD));
	}
}
int main()
{
	while (true)
	{
		double e, a, x, c, b, d, x1, x2;
		cout << "What type the equation is?: 1,ax^2+c=0, 2.ax^2+bx=0, 3.ax^2+bx+c=0" << "\n";
		cin >> e;
		if (e == 1)
		{
			cout << "Enter a " << "\n";
			cin >> a;
			cout << "Enter c " << "\n";
			cin >> c;
			if (-c < 0 && a > 0)
			{
				//x = sqrt(c / a);
				cout << "The equation is Impossible in R " << "\n";
				cout << "x is equal to +-" << simplification(sqrt(c), sqrt(a)) << "i in C" << "\n";
			}
			else if (-c > 0 && a < 0)
			{
				//x = sqrt(-c / -a);
				cout << "The equation is Impossible in R " << "\n";
				cout << "x is equal to +-" << simplification(sqrt(-c), sqrt(-a)) << "i in C" << "\n";
			}
			else if (a == 0 && -c != 0)
			{
				cout << "The equation is Impossible in R " << "\n";
			}
			else if (a == 0 && -c == 0)
			{
				cout << "The equation is an identity: it is true for all values" << "\n";
			}
			else {
				x = sqrt(-c / a);
				if (x == 0)
				{
					cout << "x is equal to " << 0 << "\n";
				}
				else {
					cout << "x is equal to +-" << simplification(sqrt(-c), sqrt(a)) << "\n";
				}
			}
		}
		if (e == 2)
		{
			cout << "Enter a" << "\n";
			cin >> a;
			cout << "Enter b" << "\n";
			cin >> b;
			if (a == 0 && b == 0)
			{
				cout << "The equation is an identity: it is true for all values" << "\n";
			}
			else if (a != 0 && b == 0 || a == 0 && b != 0)
			{
				cout << "x is equal to 0 " << "\n";
			}
			else {
				x1 = 0;
				//x2 = -b / a;
				cout << "x is equal to " << x1 << " or " << simplification(sqrt(-b), sqrt(a)) << "\n";
			}
		}
		if (e == 3)
		{
			cout << "Enter a" << "\n";
			cin >> a;
			cout << "Enter b" << "\n";
			cin >> b;
			cout << "Enter c" << "\n";
			cin >> c;
			d = b * b - 4 * a * c;
			if (a == 0 && b == 0 && c == 0)
			{
				cout << "The equation is an identity: it is true for all values " << "\n";
			}
			else if (a == 0 && b == 0 && c != 0)
			{
				cout << "The equation is Impossible R " << "\n";
			}
			else if (a == 0 && b != 0 && c == 0 || a == 0 && b != 0 && c != 0)
			{
				//x = -c / b;
				cout << "x is equal to " << simplification(sqrt(-c), sqrt(b)) << "\n";
			}
			else if (a != 0 && b == 0)
			{
				x = sqrt(-c / a);
				if (x == 0)
				{
					//Μπαινει γιατι εκτυπωνε -0 λογω του -c στη γραμμη 97  
					cout << "x is equal to " << 0 << "\n";
				}
				else if (-c < 0 && a>0)
				{
					//x = sqrt(c / a);
					cout << "The equation is Impossible in R " << "\n";
					cout << "x is equal to +-" << simplification(sqrt(c), sqrt(a)) << "i in C" << "\n";
				}
				else if (-c > 0 && a < 0)
				{
					//x = sqrt(-c / -a);
					cout << "The equation is Impossible in R " << "\n";
					cout << "x is equal to +-" << simplification(sqrt(-c), sqrt(-a)) << "i in C" << "\n";
				}
				else {
					cout << "x is equal to +- " << simplification(sqrt(-c), sqrt(a)) << "\n";
				}
			}
			else if (d < 0)
			{
				cout << "D=" << d << "<0 " << "The equation is Impossible in R " << "\n" << endl;
				//x1 = (-b - sqrt(-d)) / (2 * a);
				//x2 = (-b + sqrt(-d)) / (2 * a);
				cout << "x is equal to " << simplification(-b - sqrt(-d), 2 * a) << " or " << simplification(-b + sqrt(-d), 2 * a) << " in C " << "\n";
			}
			else if (d == 0)
			{
				//x1 = (-b - sqrt(d)) / (2 * a);
				//x2 = (-b + sqrt(d)) / (2 * a);
				cout << "D=" << d << "x is equal to " << simplification(-b - sqrt(d), 2 * a) << " (double solution) " << "\n";
			}
			else
			{
				//x1 = (-b - sqrt(d)) / (2 * a);
				//x2 = (-b + sqrt(d)) / (2 * a);
				cout << "D=" << d << ">0 " << "x is equal to " << simplification(-b - sqrt(d), 2 * a) << " or " << simplification(-b + sqrt(d), 2 * a) << "\n";
			}
		}
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
