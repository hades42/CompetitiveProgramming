#include <bits/stdc++.h>
#define ll long long

using namespace std;

typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;
const ll INF = 1e18;

template <typename T> void print(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, " "));
  cout << endl;
}

template <typename T> void print2d(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin >> n;
    vector<ll> coprimes;
    for(ll i = 1; i < n; i++){
        if(gcd(i, n) == 1){
            coprimes.push_back(i);
        }
    }
    vector<ll> prefix(coprimes.size());
    prefix[0] = 1;
    for(ll i = 1; i < prefix.size(); i++){
        prefix[i] = (coprimes[i] * prefix[i-1]) % n;
    }
    ll ans = 1;
    for(ll i = 0;i  < prefix.size(); i++){
        if(prefix[i] == 1){
            ans = i + 1;
        }
    }
    cout << ans << endl;
    for(ll i = 0; i < ans; i++){
        cout << coprimes[i] << " ";
    }
}
