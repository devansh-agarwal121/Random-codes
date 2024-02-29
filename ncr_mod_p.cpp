#include <bits/stdc++.h>

long long power(long long x, int y, int p) {
    int ans = 1; 
    x = x % p; 
 
    while (y > 0) {
        if (y & 1) ans = (ans * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    
    return ans;
}

// Calculating (1/n)%p 
long long modInverse(long long n, int p) {
    return power(n, p - 2, p); //using Fermat's Little Theorem (1/n)%p == (n^(p-2))%p
}
 
long long nCrModP(long long n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
 
    vector <long long> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p) % p;
}


int main (){
    int n, r; cin >> n >> r;
    long int ans = nCrModP(n, r, 1e9+7);
    cout << ans << endl;
    return 0;
}