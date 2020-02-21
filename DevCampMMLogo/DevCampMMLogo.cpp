// DevCampMMLogo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class MMLogo
{
public:
	bool CheckInputValidity(int N)
	{
		if (N % 2 == 0 && (N < 3 || N > 9999))
		{
			cout << "Error! The entered number must be odd and in the range between 3 and 9999 (inclusive)!";
			return false;
		}
		else if (N % 2 == 0)
		{
			cout << "Error! The entered number is even. Please, enter an odd number!";
			return false;
		}
		else if (N < 3 || N > 9999)
		{
			cout << "Error! The entered number must be in the range between 3 and 9999 (inclusive)!";
			return false;
		}
		else return true;
	}

	void DrawStars(int a)
	{
		for (int i = 0; i < a; i++)
		{
			cout << "*";
		}
	}
	void DrawDashes(int a)
	{
		for (int i = 0; i < a; i++)
		{
			cout << "-";
		}
	}

	void Draw(int N)
	{
		int columns = N + 1;
		int dashes = N;
		int dashesOuter = N;
		int dashesInner = dashesOuter * 2;
		int stars = N;
		int starsInner = stars * 2 - 1;
		int columnNumber = 0;

		while (columnNumber != columns / 2) // Draw the first half of the logo.
		{
			columnNumber++;

			DrawDashes(dashesOuter);
			DrawStars(stars);
			DrawDashes(dashes);
			DrawStars(stars);
			DrawDashes(dashesInner);
			DrawStars(stars);
			DrawDashes(dashes);
			DrawStars(stars);
			DrawDashes(dashesOuter);
			cout << endl;

			dashesOuter--;
			dashes -= 2;
			dashesInner -= 2;
			stars += 2;
		}
		while (columnNumber != columns) // Draw the second half of the logo.
		{
			stars = N;
			dashes += 2;

			DrawDashes(dashesOuter);
			DrawStars(stars);
			DrawDashes(dashes);
			DrawStars(starsInner);
			DrawDashes(dashes);
			DrawStars(stars);
			DrawDashes(dashesInner);
			DrawStars(stars);
			DrawDashes(dashes);
			DrawStars(starsInner);
			DrawDashes(dashes);
			DrawStars(stars);
			DrawDashes(dashesOuter);
			cout << endl;

			dashesOuter--;
			dashesInner -= 2;
			starsInner -= 2;
			columnNumber++;
		}
	}
};

int main()
{
	int N;
	MMLogo MMLogo;
	cout << "Welcome to the MM Logo creator!\nEnter an odd number in the range between 3 and 9999 (inclusive)!\nN = ";
	cin >> N;
	if (MMLogo.CheckInputValidity(N) == true)
	{
		MMLogo.Draw(N);
	}
	cout << "\nPress any key to continue...";
	cin.ignore();
	cin.get();
}