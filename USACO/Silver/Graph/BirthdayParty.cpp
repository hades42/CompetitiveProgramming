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
bool G[105][105];
bool vis[105];

void dfs(ll u){
    vis[u] = true;
    for(ll i = 0; i < n; i++){
        if(!vis[i] && G[u][i]){
            dfs(i);
        }
    }
}

void solve(){
    memset(G, false, sizeof(G));
    vector<pr> edges;
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        G[u][v] = true;
        G[v][u] = true;
        edges.push_back({u, v});
    }

    for(auto p : edges){
        G[p.first][p.second] = false;
        G[p.second][p.first] = false;
        memset(vis, false, sizeof(vis));
        dfs(0);
        for(ll i = 0; i < n; i++){
            if(!vis[i]){
                cout << "Yes" << endl;
                return;
            }
        }
        G[p.first][p.second] = true;
        G[p.second][p.first] = true;
    }
    cout << "No" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    while(cin >> n >> m && (n || m)){
        solve();
    }
}
