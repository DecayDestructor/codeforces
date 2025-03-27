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
map<int, pair<int, int>> mpp;
vi arr = {4, 8, 15, 16, 23, 42};
void solve() {
    set<int> stt;
    vi answer(6, 0);
    cout << "? " << 1 << " " << 2 << endl;
    int a;
    cin >> a;
    stt.insert(mpp[a].first);
    stt.insert(mpp[a].second);
    answer[1] = a;
    cout << "? " << 1 << " " << 3 << endl;
    cin >> a;
    answer[2] = a;
    // int start = -1;
    if (stt.count(mpp[a].first)) {
        answer[0] = mpp[a].first;
    } else {
        answer[0] = mpp[a].second;
    }
    cout << "? " << 1 << " " << 4 << endl;
    cin >> a;
    answer[3] = a;
    cout << "? " << 1 << " " << 5 << endl;
    cin >> a;
    answer[4] = a;
    for (int i = 1; i < 6; i++) {
        answer[i] /= answer[0];
    }
    for (auto &it : arr) {
        bool ok = false;
        for (auto &j : answer) {
            if (it == j) {
                ok = true;
            }
        }
        if (!ok) {
            answer[5] = it;
        }
    }
    cout << "! ";
    for (auto &it : answer) {
        cout << it << " ";
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mpp[arr[i] * arr[j]] = {arr[i], arr[j]};
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}