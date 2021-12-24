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

bool cmp(pr &a, pr &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("helpcross");
    ll c, n; cin >> c >> n;
    multiset<ll> chicken;
    vector<pr> cow(n);
    for(ll i = 0; i < c; i++){
        ll num; cin >> num;
        chicken.insert(num);
    }
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        cow[i] = {a, b};
    }
    sort(cow.begin(), cow.end(), cmp);
    //for(ll i = 0; i < n; i++){
        //cout << cow[i].first << " " << cow[i].second << endl;
    //}
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        auto it = chicken.lower_bound(cow[i].first);
        if(it != chicken.end() && *it <= cow[i].second){
            ans++;
            chicken.erase(it);
        }
        //it--; 
    }
    cout << ans << endl;
}
