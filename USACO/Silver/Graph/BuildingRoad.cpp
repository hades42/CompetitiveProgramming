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
vector<vector<ll>> G;
vector<bool> visited;

void dfs(ll u){
    visited[u] = true; 
    for(ll i = 0; i < G[u].size(); i++){
        if(!visited[G[u][i]]){
            dfs(G[u][i]);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m;
    G.resize(n+1);
    visited.resize(n+1);
    for(ll i = 0; i <= n; i++) visited[i] = false;
    vector<ll> ans;
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for(ll i = 1; i <= n; i++){
        if(!visited[i]){
            ans.push_back(i);
            dfs(i);
        }
    }
    cout << ans.size() - 1 << endl;
    for(ll i = 0; i < ans.size() - 1; i++){
        cout << ans[i] << " " << ans[i+1] << endl;
    }
}
