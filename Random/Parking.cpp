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
    vector<ll> cost(4);
    cin >> cost[1] >> cost[2] >> cost[3];
    vector<ll> arr(101);
    for(ll i = 0; i < 3; i++){
        ll a, b; cin >> a >> b;
        arr[a]++;
        arr[b]--;
    }

    for(ll i = 1; i < arr.size(); i++){
        arr[i]+= arr[i-1] ;
    }

    ll ans = 0;
    for(ll i = 0; i < arr.size(); i++){
        ans += (cost[arr[i]] * arr[i]);
    }

    cout << ans << endl;
}
