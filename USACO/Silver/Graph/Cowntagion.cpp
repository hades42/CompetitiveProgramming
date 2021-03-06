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

vector<vector<ll>> G;
vector<bool> visited;

ll dfs(ll u, ll pu){
    ll ans = 0;
    ll cows = G[u].size();
    if(pu == -1){
        cows++;
    }
    ll days = 0;
    ll currCow = 1;
    while(currCow < cows){
        days++;
        currCow*= 2;
    }

    ans += days;
    for(ll v : G[u]){
        if(v != pu){
            ans += dfs(v, u) + 1;
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n; cin >> n;
    G.resize(n);
    for(ll i = 0; i < n-1; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    visited.resize(n, false);
    ll ans = dfs(0, -1);
    cout << ans << endl;
}
