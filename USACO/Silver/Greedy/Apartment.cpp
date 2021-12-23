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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> app(n);
    vector<ll> apart(m);
    for(ll i = 0; i < n; i++){
        cin >> app[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> apart[i];
    }
    sort(app.begin(), app.end());
    sort(apart.begin(), apart.end());
    ll i = 0; ll j = 0;
    ll ans = 0;
    while(i < n && j < m){
        ll left = apart[j] - k;
        ll right = apart[j] + k;
        if(left <= app[i] && app[i] <= right){
            ans++;
            i++;
            j++;
        } else if(app[i] > right){
            j++;
        } else if(app[i] < left){
            i++;
        }
    }
    cout << ans << endl;
}
