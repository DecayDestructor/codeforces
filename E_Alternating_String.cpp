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
    int n;
    string s;
    cin >> n >> s;
    vector<vi> preOdd(n + 1, vi(26));
    vector<vi> preEven(n + 1, vi(26));
    if (n % 2 == 0) {
        vi temp(26, 0);
        int evenMax = 0;
        int oddMax = 0;
        for (int i = 0; i < n; i += 2) {
            temp[s[i] - 'a']++;
            evenMax = max(evenMax, temp[s[i] - 'a']);
        }
        temp.assign(26, 0);
        for (int i = 1; i < n; i += 2) {
            temp[s[i] - 'a']++;
            oddMax = max(oddMax, temp[s[i] - 'a']);
        }
        cout << n - oddMax - evenMax << nl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            preOdd[i] = preOdd[i - 1];
            preOdd[i][s[i - 1] - 'a'] = preOdd[i - 1][s[i - 1] - 'a'] + 1;
        } else
            preOdd[i] = preOdd[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            preEven[i] = preEven[i - 1];
            preEven[i][s[i - 1] - 'a'] = preEven[i - 1][s[i - 1] - 'a'] + 1;
        } else
            preEven[i] = preEven[i - 1];
    }
    int answer = n;
    for (int i = 2; i < n; i++) {
        vi evenTemp = preEven[n];
        vi oddTemp = preOdd[n];
        if (i % 2 == 0) {
            for (int j = 0; j < 26; j++) {
                evenTemp[j] -= preEven[i][j];
                evenTemp[j] += preOdd[i - 1][j];
                oddTemp[j] += preEven[i - 2][j];
                oddTemp[j] -= preOdd[i - 1][j];
            }
        } else {
            for (int j = 0; j < 26; j++) {
                oddTemp[j] -= preOdd[i][j];
                oddTemp[j] += preEven[i - 1][j];
                evenTemp[j] += preOdd[i - 2][j];
                evenTemp[j] -= preEven[i - 1][j];
            }
        }
        int evenMax = *max_element(all(evenTemp));
        int oddMax = *max_element(all(oddTemp));
        answer = min(answer, n - 1 - evenMax - oddMax);
    }
    // deleting first index
    vi evenTemp = preEven[n];
    vi oddTemp = preOdd[n];
    for (int i = 0; i < 26; i++) {
        evenTemp[i] -= preEven[1][i];
        oddTemp[i] -= preOdd[1][i];
    }
    int evenMax = *max_element(all(evenTemp));
    int oddMax = *max_element(all(oddTemp));
    answer = min(answer, n - 1 - evenMax - oddMax);
    // deleting last index
    evenTemp = preEven[n - 1];
    oddTemp = preOdd[n - 1];
    evenMax = *max_element(all(evenTemp));
    oddMax = *max_element(all(oddTemp));
    answer = min(answer, n - 1 - evenMax - oddMax);
    cout << answer + 1 << nl;
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