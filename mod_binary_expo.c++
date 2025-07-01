#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vll vector<long long>
#define endl "\n"

const int INF = 1e18;
const int MOD = 1e9 + 7;

int power(int a, int n, int mod) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) result = (result * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return result;
}

void solve(){
    int a, n;
    cin >> a >> n;

    int ans = power(a, n, MOD);

    cout<<ans<<endl;
    return ;
}

int32_t main() {
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
