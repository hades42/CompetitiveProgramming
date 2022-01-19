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
    ll n; cin >> n;
    ll sum = n*(n+1)/2;
    if(sum % 2){
        cout << 0 << endl;
        return 0;
    }
    ll need = sum / 2;

    vector<ll> dp(need + 1);
    dp[0] = 1;
    for(ll i = 1; i < n; i++){
        for(ll j = need; j >= 1; j--){
            if(j - i >= 0){
                dp[j] = (dp[j] + dp[j-i]) % MOD;
            }
        }
    }

    //print(dp);
    cout << dp[need]  << endl;
}
