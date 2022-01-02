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
vector<bool> vis;
vector<ll> color;
bool bad = false;

void dfs(ll u, ll c){
    vis[u] = true;
    color[u] = c;
    for(ll v : G[u]){
        if(!vis[v]){
            dfs(v, !c);
        } else{
            if(color[v] == c){
                bad = true;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n, m; cin >> n >> m;
    G.resize(n);
    color.resize(n);
    vis.resize(n, false);
    for(ll i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(ll i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }

    if(bad){
        cout << "IMPOSSIBLE" << endl;
    } else{
        for(ll i = 0; i < n; i++){
            cout << color[i] + 1 << " ";
        }
    }
}
