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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, sum; cin >> n >> sum;
    vector<ll> price(n);
    vector<ll> page(n);
    for(ll i = 0; i < n; i++) cin >> price[i];
    for(ll i = 0; i < n; i++) cin >> page[i];
   
    vector<ll> dp(sum + 1);
    dp[0] = 0;
    ll ans = 0;
    for(ll j = 0; j < n; j++){
        for(ll i = sum; i >= 1; i--){
            if(i - price[j] >= 0){
                dp[i] = max(dp[i], dp[i - price[j]] + page[j]);
            }
        } 
    }
    cout << dp[sum] << endl;
}
