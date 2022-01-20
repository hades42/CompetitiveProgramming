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
    ll n, q; cin >> n >> q;
    map<ll, vector<ll>> mp;
    for(ll i = 1; i <= n; i++){
        ll num; cin >> num;
        mp[num].push_back({i});
    }
    for(ll i = 0; i < q; i++){
        ll x, k; cin >> x >> k;
        if(mp.count(x)){
            if(k <= mp[x].size()){
                cout << mp[x][k-1] << endl;
            } else{
                cout << -1 << endl;
            }
        } else{
            cout << -1 << endl;
        }
    }
}
