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
ll n, m; 
vector<ll> X;
vector<ll> Y;
vector<vector<ll>> G;
vector<bool> visited;
ll a, b, c, d;

void dfs(ll u){
    visited[u] = true; 
    a = min(a, X[u]);
    b = max(b, X[u]);
    c = min(c, Y[u]); 
    d = max(d, Y[u]);

    for(ll v : G[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("fenceplan");
    cin >> n >> m;
    X.resize(n); 
    Y.resize(n);
    G.resize(n);
    visited.resize(n, false);
    for(ll i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        X[i] = a;
        Y[i] = b;
    }
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans = INF; 
    for(ll i = 0; i < n; i++){
        if(!visited[i]){
            a = INF;
            b = 0;
            c = INF;
            d = 0;
            dfs(i);
            ll temp = 2 * ((b - a) + (d - c));
            ans = min(ans, temp);
        }
    }
    cout << ans << endl;
}
