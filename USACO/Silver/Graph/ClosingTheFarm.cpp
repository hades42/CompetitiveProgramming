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
set<ll> close;

void dfs(ll node){
    visited[node] = true;
    for(ll v : G[node]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("closing");
    cin >> n >> m;
    G.resize(n+1);
    visited.resize(n+1);
    for(ll i = 0; i < n; i++) visited[i] = false;
    for(ll i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(ll i = 0; i < n; i++){
        ll num; cin >> num;
        dfs(num);
        bool flash = true;
        for(ll i = 1; i <= n; i++){
            if(close.count(i)) continue;
            if(!visited[i]){
                flash = false;
                break;
            }
        }
        if(flash) cout << "YES" << endl;
        else cout << "NO" << endl;

        close.insert(num);
        for(ll i = 1; i <= n; i++){
            if(close.count(i)){
                visited[i] = 1;
            } else{
                visited[i] = 0;
            }
        }
    } 
}
