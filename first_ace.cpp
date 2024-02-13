#include <iostream>

using namespace std;

int main () {

/*
- Problem: On average, how many cards you need to flip from a deck of 52 cards, to get an ace?

- Code Solution:
	The code below is basically the brute force approach to solve the problem, i.e. it solves for the following equation
 	E = (4/52 * 1)  +  (48/52 * 4/51 * 2)  +  (48/52 * 47/51 * 4/50 * 3)  +  ...  +  (48/52 * 47/51 * ... * 1/5 * 4/4 * 48)
  	Note: The code's run time can be optimised by using previously solved frac's in next iteration.

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
