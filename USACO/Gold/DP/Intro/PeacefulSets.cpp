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
    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    vector<vector<ll>> sum(n+1, vector<ll>(n+1));
   
    dp[0][0] = 1;
    for(ll i = 0; i <= n; i++){
        sum[0][i] = 1;
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= i; j++){
            dp[i][j] = sum[i - j][j / 2];
            sum[i][j] = dp[i][j] + sum[i][j-1];
        }
        for(ll j = i + 1; j <= n; j++){
            sum[i][j] = sum[i][j-1];
        }
    }
    print2d(dp);
    cout << endl;
    print2d(sum);
}
