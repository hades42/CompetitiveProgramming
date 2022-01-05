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

void dfs(ll u, ll c, vector<vector<ll>> &G, vector<vector<ll>> &color, vector<bool> &vis){
    vis[u] = true;
    color[c].push_back(u);
    for(ll v : G[u]){
        if(!vis[v]){
            dfs(v, !c, G, color, vis);
        }
    }
}

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> G(n);
    vector<vector<ll>> color(2);
    vector<bool> vis(n, false);
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(ll i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, 0, G, color, vis);
        }
    }
    for(ll i = 0; i < 2; i++){
        if(color[i].size() <= n/2){
            cout << color[i].size() << endl;
            for(ll j = 0; j < color[i].size(); j++){
                cout << color[i][j] + 1 << " ";
            }
            cout << endl;
            return;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll q; cin >> q;
    while(q--){
        solve();
    }
}
