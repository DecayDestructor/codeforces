#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(n) for (int i = 0; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define vch vector<char>
template <typename T1, typename T2>
using vpp = vector<pair<T1, T2>>;
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
// Template functions for input and output
template <typename T>
void inputArray(vector<T> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <typename T>
void outputArray(vector<T> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << nl;
    }
}
template <typename T>
vector<T> factorization(int n)
{
    vector<T> factors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i * i != n)
            {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}
// Sieve of Eratosthenes
vector<ll> sieveOfEratosthenes(int n)
{
    vector<ll> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0; // 0 and 1 are not primes
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = 0; // Mark multiples of i as non-prime
            }
        }
    }
    return sieve; // Return the sieve vector
}
// DFS Traversal Validation
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll> &visited)
{
    return row < m && col < n && row >= 0 && col >= 0 && !visited[row][col];
}
void solve()
{
    vll sieve = sieveOfEratosthenes(3000);
    vll primes;
    for (int i = 0; i <= 3000; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
        }
    }
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ll counter = 0;
        for (auto it : primes)
        {
            if (!(i % it))
            {

                counter++;
            }
            if (counter > 2)
            {
                break;
            }
        }
        if (counter == 2)
        {
            ans++;
        }
    }
    cout << ans << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}