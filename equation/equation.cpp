// equation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	float e, a, x, c, b, d, x1, x2;

	cout << "What type the equation is?: 1,ax^2=c, 2.ax^2+bx=0, 3.ax^2+bx+c=0" << "\n";
	cin >> e;
	if (e == 1)
	{


		cout << "Enter a " << "\n";
		cin >> a;
		cout << "Enter c " << "\n";
		cin >> c;
		if (c < 0 && a>0)
		{
			cout << "x is Infinity in R " << "\n";
		}
		else if (a == 0 && c != 0)
		{
			cout << "x is Infinity in R " << "\n";
		}
		else if (a == 0 && c == 0)
		{
			cout << "Tautothta(x could be any number in R)" << "\n";
		}
		else {
			x = sqrt(c / a);
			if (x == 0)
			{
				cout << "x is equal to " << x << "\n";
			}
			else {
				cout << "x is equal to +-" << x << "\n";

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
			cout << "Tautothta(x could be any number in R)" << "\n";
		}
		else if (a != 0 && b == 0 || a == 0 && b != 0)
		{
			cout << "x is equal to 0 " << "\n";
		}
		else {
			x1 = 0;
			x2 = -b / a;
			cout << "x is equal to " << x1 << " or " << x2 << "\n";
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
			cout << "The equation is a contradiction in R: it has no solutions " << "\n";
		}
		else if (a == 0 && b != 0 && c == 0 || a == 0 && b != 0 && c != 0)
		{
			x = -c / b;
			cout << "x is equal to " << x << "\n";
		}
		else if (a != 0 && b == 0)
		{
			x = sqrt(-c / a);
			if (x == 0)
			{
				x = 0;//Μπαινει γιατι εκτυπωνε -0 λογω του -c στη γραμμη 97  
				cout << "x is equal to " << x << "\n";
			}
			else {
				cout << "x is equal to +- " << x << "\n";
			}

		}
		else if (d < 0)
		{
			cout << "D=" << d << "<0 " << "x is Infinity in R " << "\n" << endl;
			x1 = (-b - sqrt(-d)) / (2 * a);
			x2 = (-b + sqrt(-d)) / (2 * a);
			cout << "x is equal to " << x1 << " or " << x2 << " in C " << "\n";

		}
		else if (d == 0)
		{
			x1 = (-b - sqrt(d)) / (2 * a);
			x2 = (-b + sqrt(d)) / (2 * a);
			cout << "D=" << d << "x is equal to " << x1 << " (double solution) " << "\n";
		}
		else
		{
			x1 = (-b - sqrt(d)) / (2 * a);
			x2 = (-b + sqrt(d)) / (2 * a);
			cout << "D=" << d << ">0 " << "x is equal to " << x1 << " or " << x2 << "\n";

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
