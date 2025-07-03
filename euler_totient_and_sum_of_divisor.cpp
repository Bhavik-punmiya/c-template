#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vll vector<long long>
#define endl "\n"

const int INF = 1e18;
const int MOD = 1e9 + 7;

int phi(int n){
    int result  = n;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0){
                n = n / i;
            }
            result -= result/i;
        }
    }

    if(n > 1){
        result -= result/n;
    }
    return result;
}

void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

long long numberOfDivisors(long long num) {
    long long total = 1;
    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);
            total *= e + 1;
        }
    }
    if (num > 1) {
        total *= 2;
    }
    return total;
}


long long binpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

long long SumOfDivisors(long long num) {
    long long total = 1;

    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            while (num % i == 0) {
                e++;
                num /= i;
            }
            long long sum = (binpow(i, e + 1) - 1) / (i - 1);
            total *= sum;
        }
    }

    if (num > 1) {
        total *= (1 + num);
    }

    return total;
}

void solve(){
    int n;
    cin >> n;
    cout<<numberOfDivisors(n)<< endl;
}

int32_t main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
