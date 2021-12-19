#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;
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
    ll n; ll target; cin >> n >> target;
    vector<ll> prefix(n+1);
    for(ll i = 1; i <= n; i++){
        ll num; cin >> num;
        prefix[i] = prefix[i-1] + num;
    }
    ll ans = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    for(ll i = 1; i <= n; i++){
        if(mp.find(prefix[i] - target) != mp.end()){
            ans += mp[prefix[i] - target];
        }
        mp[prefix[i]]++;
    }
    cout << ans << endl;
}
