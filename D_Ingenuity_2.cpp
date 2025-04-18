#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(s, n) for (ll i = s; i < n; i++)
#define all(a) a.begin(), a.end()
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vch vector<char>
template <typename T1, typename T2>
#define int long long
using vpp = vector<pair<T1, T2>>;
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
bool RSORT(ll a, ll b) {
    return a > b;
}
template <typename T>
vector<T> factorization(int n) {
    vector<T> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}
// Prime Factorization
void primeFactorisation(ll n, map<ll, ll> &mpp) {
    for (ll i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            mpp[i]++;
            n = n / i;
        }
    }
    if (n != 1)
        mpp[n]++;
}
// Sieve of Eratosthenes
vector<ll> sieveOfEratosthenes(int n) {
    vector<ll> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;  // 0 and 1 are not primes
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = 0;  // Mark multiples of i as non-prime
            }
        }
    }
    return sieve;  // Return the sieve vector
}
// Sum of first n natural numbers
ll sumOfNaturalNumbers(ll n) {
    return (1LL * n * (n + 1)) / 2;  // Formula to calculate the sum
}
// DFS Traversal Validation
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll> &visited) {
    return row < n && col < m && row >= 0 && col >= 0 && !visited[row][col];
}
// Binary Exponentiation
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mpp;
    if (n % 2) {
        pn;
        return;
    } else if (n == 2 && s[0] != s[1]) {
        pn;
        return;
    } else {
        string ans = "";
        vi distribute(4);  // N S E W
        for (auto &ch : s) {
            mpp[ch]++;
            if (ch == 'N') {
                distribute[0] = mpp[ch] / 2;
            }
            if (ch == 'S') {
                distribute[1] = mpp[ch] / 2;
            }
            if (ch == 'E') {
                distribute[2] = mpp[ch] / 2;
            }
            if (ch == 'W') {
                distribute[3] = mpp[ch] / 2;
            }
        }
        for (auto &it : mpp) {
            it.second %= 2;
        }
        for (auto &it : distribute) it = (it << 1);
        if (mpp['N'] != mpp['S'] || mpp['E'] != mpp['W']) {
            pn;
            return;
        }
        for (char &ch : s) {
            // cout << "N : " << distribute[0] << nl << "S : " << distribute[1] << nl << "E : " << distribute[2] << nl << "W : " << distribute[3] << nl;
            if (ch == 'N') {
                if (distribute[0] > 0) {
                    ans += distribute[0] % 2 == 0 ? "R" : "H";
                    distribute[0]--;
                } else
                    ans += "R";
            }
            if (ch == 'S') {
                if (distribute[1] > 0) {
                    ans += distribute[1] % 2 == 0 ? "R" : "H";
                    distribute[1]--;
                } else
                    ans += "R";
            }
            if (ch == 'E') {
                if (distribute[2] > 0) {
                    ans += distribute[2] % 2 == 0 ? "R" : "H";
                    distribute[2]--;
                } else
                    ans += "H";
            }
            if (ch == 'W') {
                if (distribute[3] > 0) {
                    ans += distribute[3] % 2 == 0 ? "R" : "H";
                    distribute[3]--;
                } else
                    ans += "H";
            }
        }
        cout << ans << nl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}