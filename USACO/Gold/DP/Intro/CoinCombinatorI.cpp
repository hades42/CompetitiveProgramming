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
    ll n, target; cin >> n >> target;
    vector<ll> coin(n);
    for(ll i = 0; i < n; i++){
        cin >> coin[i];
    }
    vector<ll> dp(target+1); 
    dp[0] = 1;
    for(ll i = 1; i <= target; i++){
        for(ll j = 0; j < n; j++){
            if(i - coin[j] >= 0){
                dp[i] = (dp[i] + dp[i - coin[j]]) % MOD;
            }
        }
    }
    cout << dp[target] << endl;
}
