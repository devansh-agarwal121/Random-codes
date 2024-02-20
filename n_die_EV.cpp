#include <iostream>

using namespace std;

/* 
Problem Statement:
	A casino offers you a game with a six-sided die where you are paid the value of the roll.
	If you choose to keep the roll, the game ends and you are paid the value, 
	else you can let go of your current roll and play again. You can do this n (input) times.

Solution: 
	The following code, takes into account the optimal strategy (described below) 
	and calculates the fair value of this game.

Optimal Strategy:
1. For n == 2 		=> Re-roll for {1,2,3}
2. For 3 ≤ n ≤ 5	=> Re-roll for {1,2,3,4}
3. For n ≥ 6		=> Re-roll for {1,2,3,4,5}


*/


int main() {
	
	int n;
	cout << "Enter the number of die:";
	cin >> n;

	int curr = 1;
	double ans = 3.5;
	if (curr == n) {
		cout << ans << endl;
	}
	else {
		while (curr != n) {
			if (3 < ans && ans < 4) {
				ans = (3.0 / 6) * (5.0) + (3.0 / 6) * (ans);
			} 
			else if (4 < ans && ans < 5) {
				ans = (2.0 / 6) * (5.5) + (4.0 / 6) * (ans);
			}
			else {
				ans = (1.0 / 6) * (6.0)  +  (5.0 / 6) * (ans);
			}
			curr++;
		}
	}

	cout << ans << endl;



	return 0;
}