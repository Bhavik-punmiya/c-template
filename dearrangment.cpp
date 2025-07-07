#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

vector<int> fact(MAXN), inv_fact(MAXN);

// Binary exponentiation
int binpow(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void preprocess() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = binpow(fact[i], MOD - 2);
    }
}

int dearrangement(int n) {
    int res = 0;
    for (int k = 0; k <= n; k++) {
        int term = inv_fact[k];
        if (k % 2) term = MOD - term; // alternate signs: -1^k
        res = (res + term) % MOD;
    }
    return fact[n] * res % MOD;
}

void solve() {
    int n;
    cin >> n;
    cout << dearrangement(n) << endl;
}

int32_t main() {
    fast_io;
    preprocess();
    solve();
    return 0;
}
