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
    string input; cin >> input;
    ll q; cin >> q;
    vector<vector<ll>> dp(26, vector<ll>(n+1));
    for(ll j = 1; j <= n; j++){
        ll curr = input[j-1] - 'a';
        dp[curr][j]++;
    }
    for(ll i = 0; i < 26; i++){
        for(ll j = 1; j <= n; j++){
            dp[i][j] = dp[i][j-1] + dp[i][j];
        }
    }

    for(ll i = 0; i < q; i++){
        ll num; cin >> num;
        char color; cin >> color;
        color -= 'a';

        ll ans = 1;
        ll l = 1;
        ll r = 1;
        while(r <= n){
            ll count = dp[color][r] - dp[color][l-1] + num;
            if(count < r - l + 1){
                l++;
            } else{
                ans = max(r - l + 1, ans);
                r++;
            }
        }
        cout << ans << endl;
    }
}
