#include<iostream>
#include<math.h>

using namespace std;

// to check: 1 + r + r^2 + r^3 + ... + r^n == b^2 

void print_result (int sum, int p, int r) {
	cout << sum << " = ";
	for (int i = 0; i < p; i++) {
		cout << r << "^" << i << " + ";
	}
	cout << r << "^" << p << endl;
}

int main () {

	int n = 1000;
	for (int r = 2; r < 1000000; r++) {
		long long int sum = 1;
		for (int p = 1; p < n; p++) { // p => power
			sum += pow(r, p);
			int sq_root = sqrt(sum);
			if (sq_root*sq_root == sum && p > 2) {
				print_result(sum, p, r);
			}
		}
	}

	return 0;
}
