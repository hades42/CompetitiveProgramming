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
ll n, k; 
vector<vector<ll>> G;
vector<bool> visited;
vector<bool> cycle(25);
ll origin;
ll ans = 0;

void dfs(ll u){
    visited[u] = true;
    
    if(u == origin){
        cycle[u] = true;
        return;
    }

    for(ll v : G[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> k;
    G.resize(n);
    visited.resize(n, false);

    for(ll i = 0; i < k; i++){
        ll a, b, sa, sb; cin >> a >> b >> sa >> sb;
        a--;
        b--;
        if(sa > sb){
            G[b].push_back(a);
        } else{
            G[a].push_back(b);
        }
    }

    for(ll i = 0; i < n; i++){
        origin = i; 
        for(ll i = 0; i < n; i++) visited[i] = false;

        for(ll u : G[i]){
            dfs(u);
        }
    }
    
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(cycle[i]) ans++;
    }
    cout << ans << endl;
}
