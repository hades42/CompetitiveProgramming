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
    setIO("lepus");
    ll n; cin >> n;
    string input; cin >> input;
    char swamp = 'w';
    char empty = '.';
    char grass = '"';
    vector<ll> dp(n, -1);
    dp[0] = 0;
    for(ll i = 1; i < n; i++){
        if(input[i] != swamp){
            ll score = input[i] == grass;
            if(dp[i -1] != -1){
                dp[i] = max(dp[i], dp[i - 1] + score);
            }
            if(i >= 3 && dp[i - 3] != -1){
                dp[i] = max(dp[i], dp[i - 3] + score);
            }

            if(i >= 5 && dp[i - 5] != -1){
                dp[i] = max(dp[i], dp[i - 5] + score);
            }
        }
    }
    cout << dp[n-1] << endl;
}
