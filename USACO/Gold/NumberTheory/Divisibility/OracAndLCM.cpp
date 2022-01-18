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
    vector<ll> arr(n+1);
    vector<ll> a1(n+1);
    vector<ll> a2(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> arr[i];
    }
    a1[n] = arr[n];
    for(ll i = n-1; i >= 1; i--){
        a1[i] = gcd(arr[i], a1[i+1]);
    }
    //print(a1);
    for(ll i = 1; i < n; i++){
        a2[i] = (a1[i+1] * arr[i]) / gcd(a1[i+1], arr[i]);
    }
    ll ans = a2[1];
    for(ll i = 2; i < n; i++){
        ans = gcd(ans, a2[i]);
    }
    cout << ans << endl;
}
