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
map<int, int> primeFactorisation(ll n) {
    map<int, int> mpp;
    for (ll i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            mpp[i]++;
            n = n / i;
        }
    }
    if (n != 1)
        mpp[n]++;
    return mpp;
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
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll mminvprime(ll a, ll m) {
    return binpow(a, m - 2, m);
}
ll mod_add(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
int ceil_div(int a, int b) { return (a + b - 1) / b; }
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + m + 1, 0);
    vi b(m + n + 1, 0);
    for (auto &it : a) cin >> it;
    for (auto &it : b) cin >> it;
    vvll pre(n + m + 2, vi(2));  // 0 = programmers, 1 = testers
    vvll suff(n + m + 2, vi(2));
    pre[0][0] = 0;
    pre[0][1] = 0;
    suff[n + m + 1][0] = 0;
    suff[n + m + 1][1] = 0;
    int total = n + m + 1;
    int programmers = 0, testers = 0;
    for (int i = 1; i <= total; i++) {
        if (programmers == n) {
            pre[i][0] = pre[i - 1][0];
            pre[i][1] = pre[i - 1][1] + b[i - 1];
            testers++;
        } else if (testers == m) {
            pre[i][1] = pre[i - 1][1];
            pre[i][0] = pre[i - 1][0] + a[i - 1];
            // cout << i << " : " << pre[i - 1][0] << " : " << a[i - 1] << nl;
            programmers++;
        } else {
            if (a[i] > b[i]) {
                pre[i][0] = pre[i - 1][0] + a[i - 1];
                pre[i][1] = pre[i - 1][1];
                programmers++;
            } else {
                pre[i][1] = pre[i - 1][1] + b[i - 1];
                pre[i][0] = pre[i - 1][0];
                testers++;
            }
        }
    }
    programmers = testers = 0;
    for (int i = total - 1; i >= 0; i--) {
        if (programmers == n) {
            suff[i][0] = suff[i + 1][0];
            suff[i][1] = suff[i + 1][1] + b[i];
            testers++;
        } else if (testers == m) {
            suff[i][1] = suff[i + 1][1];
            suff[i][0] = suff[i + 1][0] + a[i];
            programmers++;
        } else {
            if (a[i] > b[i]) {
                suff[i][0] = suff[i + 1][0] + a[i];
                suff[i][1] = suff[i + 1][1];
                programmers++;
            } else {
                suff[i][1] = suff[i + 1][1] + b[i];
                suff[i][0] = suff[i + 1][0];
                testers++;
            }
        }
    }
    for (auto &it : a) cout << it << " ";
    cout << nl;
    for (auto &it : b) cout << it << " ";
    cout << nl;
    for (auto &it : pre) cout << it[0] << " ";
    cout << nl;
    for (auto &it : pre) cout << it[1] << " ";
    cout << nl;
    for (auto &it : suff) cout << it[0] << " ";
    cout << nl;
    for (auto &it : suff) cout << it[1] << " ";
    cout << nl;
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