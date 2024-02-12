#include<iostream>

using namespace std;


/* The problem is as follows:
- 5 good candies and 5 bad candies are to be distributed in two boxes in such a way that maximises
the probability of picking a good candy. (Box will be chosen randomly)
*/


int main() {

	double ans;

	int max_n = -1;
	int max_m = -1;
	for (int n = 0; n <= 5; n++) {
		for (int m = 0; m <= 5; m++) {
			double curr = 0.0;
			double box1_prob = 0.0;
			if (n + m != 0) box1_prob = 0.5 * ((double)(n) / (n + m));
			double box2_prob = 0.0;
			if (10 - n - m != 0) box2_prob = 0.5 * ((double)(5 - n) / (10 - n - m));
			curr += (box1_prob + box2_prob);
			if (curr > ans) {
				ans = curr;
				max_m = m;
				max_n = n;
			}
		}
	}

	cout << "Optimal Strategy is:\n" << "Keep " << max_n << " good candies in box1 and " << max_m << " bad candies in box1\n";
	cout << "Thus optimal probability of winning is " << ans << endl; 

	return 0;
}