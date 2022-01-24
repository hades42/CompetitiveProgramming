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
    //setIO("slalom");
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n);
    for(ll i = 1; i <= n; i++){
       for(ll j = 0; j < i ; j++){
           ll num;
           cin >> num;
           arr[i-1].push_back(num);
       } 
    }
    //print2d(arr);
    vector<vector<ll>> dp(n, vector<ll>(n, -INF));
    dp[0][0] = arr[0][0];
    for(ll i = 1; i < n; i++){
        for(ll j = 0; j < i + 1; j++){
            if(j < i){
                dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i][j]);
            }
            if(j - 1 >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + arr[i][j]);
            }
        }
    }
    //print2d(dp);
    cout << *max_element(dp[n-1].begin(), dp[n-1].end()) << endl;
}
