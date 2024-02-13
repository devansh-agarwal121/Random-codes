#include <iostream>

using namespace std;

int main () {

/*
- Problem: On average, how many cards you need to flip from a deck of 52 cards, to get an ace?
- The code below is basically the brute force approach to solve the problem.

- Probabilistic Solution:
	The four aces divide the space of 48 leftover cards into five parts each of size 48/5
	In order to obtain the first ace you need to flip, on average, 48/5 + 1 = 10.6 cards 
*/

	double E = 0.0;
	for (double n = 1; n <= 48; n++) {
		double curr = n - 1;
		double num = 48;
		double den = 52;
		double frac = n;
		while (curr--) {
			frac *= (num / den);
			num--; den--;
		}
		frac *= (4 / den);
		E += frac;
	}

	cout << E << endl;

	return 0;
}