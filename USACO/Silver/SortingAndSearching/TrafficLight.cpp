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
    ll x; ll n; cin >> x >> n;
    set<ll> light;
    multiset<ll> dist;
    light.insert(0);
    light.insert(x);
    dist.insert(x);        
    for(ll i = 0; i < n; i++){
        ll num; cin >> num;
        auto it1 = light.upper_bound(num);
        auto it2 = it1;
        it2--;
        dist.erase(dist.find(*it1 - *it2));
        dist.insert(*it1 - num);
        dist.insert(num - *it2);
        light.insert(num);
        auto ans = dist.end();
        ans--;
        cout << *(ans) << " ";
    }
}
